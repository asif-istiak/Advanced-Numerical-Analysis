* ---------------------------------------------------------------------
 *
 * Copyright (C) 1999 - 2021 by the deal.II authors
 *
 * This file is part of the deal.II library.
 *
 * The deal.II library is free software; you can use it, redistribute
 * it, and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * The full text of the license can be found in the file LICENSE.md at
 * the top level directory of deal.II.
 *
 * ---------------------------------------------------------------------
 
 */
 
* func are hyperlinked in the website

 * top-helper function
 * then call helper function
 *  the very high functions that call the other functions 
 * bottom main func



* everything related to mesh[documenmted too]

#include <deal.II/grid/tria.h> 
#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_out.h>
 
#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace dealii;
 
 
void first_grid()
{
  Triangulation<2> triangulation;  * Collection of cell-triangulation [number in <n> bracket base _dimenion (here square) (box-3)(interval _01, triangylation 1)]
 
  GridGenerator::hyper_cube(triangulation); * generate  mesh; hyper_cube-square _for _2D, cube _for _3D, _[0,1] _for _1D
  triangulation.refine_global(4);

  *we split every square or every quadrilateral into four child cells in 3d it would be into the eight sub cubes and so _if we _do _this
* once we end up with four cells _if we _do it twice we end up with 16 cells and so on the four so four times means we get cells

* discretized into form a mesh of the unit squirt

 
  std::ofstream out("grid-1.svg");               * Output file stream
  GridOut       grid_out;                        * outputs a mesh into a file
  grid_out.write_svg(triangulation, out);
  std::cout << "Grid written to grid-1.svg" << std::endl;
}
 
 
 * divide and split the mesh adaptively
 
void second_grid()
{
  Triangulation<2> triangulation;
 
  const Point<2> center(1, 0); *(x,y)
  const double   inner_radius = 0.5, outer_radius = 1.0;
  GridGenerator::hyper_shell(                                    
    
     * go to docu
   *the argument list is a triangulation a point in dim dimensional space
   *2d of course is just an annulus 


    triangulation, center, inner_radius, outer_radius, 10);  *center, outer_radius, a number of quadrilaterals
  for (unsigned int step = 0; step < 5; ++step)
    {
      for (auto &cell : triangulation.active_cell_iterators())
      
      * triangulation is not just a
*collection of cells but it actually is
*also a collection of vertices _for
*example collection of faces faces are the
* interfaces between two cells so in in 2d
* _for example the faces are line segments

*in 3d faces between cells are quadrilaterals
* so the triangulation also has a type that is not called cell iterator but it is called face iterator 



        {
          for (const auto v : cell->vertex_indices())
            {
              const double distance_from_center =
                center.distance(cell->vertex(v));
 
              if (std::fabs(distance_from_center - inner_radius) <=
                  1e-6 * inner_radius)
                {
                  cell->set_refine_flag();
                  break;
                }
            }
        }
 
      triangulation.execute_coarsening_and_refinement();  

      *it takes all of the cells that are marked _for refinement and replaces them
* by the _for child cells it also takes all of the cells that are marked _for
* coarsening and if all children of one cell are marked for coarsening and it
*going to _throw away the children and go back to the original cell 
    }
 
 
  std::ofstream out("grid-2.svg");
  GridOut       grid_out;
  grid_out.write_svg(triangulation, out);
 
  std::cout << "Grid written to grid-2.svg" << std::endl;
}
 
 
 
 
int main()
{
  first_grid(); *
  second_grid();
}

* Run cd directory, cmake . , make, ./step, okular grid-1.svg