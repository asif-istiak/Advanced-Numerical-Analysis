#3 python modules
import numpy as np 
import matplotlib.pyplot as plt
import math


Nodes = np.array([[0,0],[1,0],[1,1],[0,1]])

plt.plot(Nodes[:,0],Nodes[:,1],'o')
plt.show()


from scipy.spatial import Delaunay
tri = Delaunay(points)

plt.triplot(points[:,0], points[:,1], tri.simplices)
plt.plot(points[:,0], points[:,1], 'o')
plt.show()