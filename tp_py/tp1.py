#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 16 11:52:30 2022

@author: mmerah
"""


"""

"""
import time
from math import cos, sin

def f(x) :
    #return cos(x+3*3.14/8)
    return 2*x+1

# a, b, eps, fb, c, fc

gauche=float(input('a de ta fonction: '))
droite=float(input('b de ta fonction: '))
eps=float(input('la precision:  '))
print("------methode de la dichotomie-----") 
i=0
a=gauche
b=droite
c=0.0
start_time = time.time()

fb=f(b)

while  (b-a)>eps :
      i +=1
      
      c = (a + b)/2
      fc = f(c)
      if (fb*fc < 0) :
         a = c
      else : 
         b = c
         fb = fc
         if abs(c)<eps : break
     

print("temps: %s sec" %(time.time()-start_time))
print("le zero : ",c) 
print("nombre d'iteration: ",i)  


#secante 
print("\n------methode de la seconte --------") 
i=0
a=gauche
b=droite
fa=f(a)
fb=f(b)
start_time = time.time()
while abs(fb-fa) > 0.001 :
  i+=1
  fa=f(a)
  fb=f(b)
  #print("fa fb ",fa,fb)
  c=b-(fb*(b-a))/(fb-fa)
  a=b
  b=c
  if c<0 :
      t=abs(fb)
  else :
          t=fb		
  if t>eps   : break 

print("temps: %s sec" %(time.time()-start_time))
print("le zero : ",c) 
print("nombre d'iteration: ",i)



print("---------methode de newton---------") 
# Dérivé de la fonction f
def df(x):
    return 2


def newton(fonction,derivee,a,e):
    delta = 1
    while delta > e:
        x = -fonction(a)/derivee(a) + a
        delta = abs(x - a)
        a = x
        #if abs(x)<eps : break
        
    return x

start_time = time.time()     
c=newton(f , df , gauche , eps)
print("temps: %s sec" %(time.time()-start_time))
print("le zero : ",c) 
print("nombre d'iteration: ",i)
