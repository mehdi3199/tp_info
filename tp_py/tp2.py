 
from cgitb import grey
from PIL import  Image
import numpy as np
import matplotlib.pyplot as plt

image_RGB=Image.open('lena24'+'.bmp')
image_RGB.show()
image_gris=image_RGB.convert('L')
image_gris.show()
array_RGB=np.array(image_RGB)
print(np.shape(array_RGB))
array_gris=np.array(image_gris)
print(np.shape(array_gris))

"""
plt.figure(1)
plt.imshow(array_RGB)
plt.title('image rgb 2')
plt.show()

plt.figure(2)
plt.imshow(array_gris,cmap="gray")
plt.title('image gray 2')
plt.show()
"""
array1_RGB=np.copy(array_RGB)

#print(array_RGB[0,0,:])

for i in range(512) : array1_RGB[i,i,:] = [255,255,255]

""""
plt.figure(1)
plt.imshow(array1_RGB)
plt.title('image rgb 2')
plt.show()
"""


array1_RGB[:,:,[0,1]] =0


plt.figure(1)
plt.imshow(array1_RGB)
plt.title('image rgb 3')
plt.show()