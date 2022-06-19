#3 python modules
import numpy as np 
import matplotlib.pyplot as plt
import math

#0 - Define Paraneters
L = 0.1
h = 0.05
r = 0.02

nb_element = 20

#1-1 Create Nodes
#Nodes = np.array([[0,0],[0,1],[1,0],[1,1]])

Nodes = []

#Nodes=np.array([])
#add nodes within the array for loop

for x in np.linspace(0, L, num=nb_element): #np.linspace(start point, end point, num of element)
    #nested loop for x and y value
  
        for y in np.linspace(0, h, num=nb_element):#np.linspace(start point, end point, num of element)
            Nodes.append([x,y]) #appending and adding elements to the end of the List
            


#1-2 Display Nodes

points = np.array(Nodes)

plt.plot(points[:,0],points[:,1],'o')
plt.show()

#discretize the domain