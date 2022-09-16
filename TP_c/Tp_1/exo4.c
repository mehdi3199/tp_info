#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float f(float x)
{
/* Cette fonction est juste un exemple.
   Elle doit etre remplacee  */
   float t=x+3*PI/8;
   return cosf(t);
   //return t;
}


int main()
{
   /* Declarations  */
   #define MAX 1000
   float a, b, precision, gauche, droite, fd, fc, c;
   int i;
   
/*  Lecture des donnees  */
   printf("Intervalle a etudier?: ");
   scanf("%f%f", &a,&b);
   printf("Precision necessaire?: ");
   scanf("%f", &precision);
 
/*  Initialisations */
   i = 0;
   gauche = a; droite = b;
   fd = f(droite);
/*  Boucle d'iteration */
   while ((droite - gauche) > precision) 
   {
      c = (gauche + droite)/2;
      fc = f(c);
      if (fd*fc < 0)
         gauche = c;
      else
      {
         droite = c;
         fd = fc;
      }
      if (i++ > MAX)
      {
         printf("Convergence non obtenue\n");
         exit(1);
      }
   }
   printf("x = %f\n",(gauche + droite)/2.);
   exit(0);
}


