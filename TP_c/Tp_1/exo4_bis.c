#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float f(float x)
{
/* Cette fonction est juste un exemple.
   Elle doit etre remplacee  */
   float t=x+3*PI/8;
   return (x +1) ;
   //return t;
}

float myabsf(float n) 
{
	if(n>0) return n;
	else return -1.f*n;
}

int main()
{
   /* Declarations  */
   #define MAX 1000
   float a, b, precision, gauche, droite, fg, fc, c,cp;
   int i;
   
/*  Lecture des donnees  */
   printf("Intervalle a etudier?: ");
   scanf("%f%f", &a,&b);
   printf("Precision necessaire?: ");
   scanf("%f", &precision);
 
/*  Initialisations */
   i = 0;
   gauche = a; droite = b;
   fg = f(gauche);

/*  Boucle d'iteration */
   while ((droite - gauche)/2. > precision) 
   {
      cp= c = (gauche + droite)/2;
      
      fc = f(c);
      
      if (fg*fc < 0)
      {
      	 droite = c;
      	if(myabsf(cp)<precision)break;
	  }
	   else
	      {
	         if(myabsf(cp)<precision)break;	
	         gauche = c;
	         fg = fc;
	         
	      }
	      if (i++ > MAX)
	      {
	         printf("Convergence non obtenue\n");
	         exit(1);
	      }
	    
   }
   printf("x = %f\n",(gauche + droite)/2.);
 printf("i = %d\n", i);
   exit(0);
}


