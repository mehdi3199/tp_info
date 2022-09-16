#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.141592654

 float f(double x){
      	float t=x+3*PI/8;
    //return(x*x*x-4); // f(x)= x^3-4
   // return(x+1);
   return cos(t);
   }
   
int main(int argc, char *argv[])
{
int i =0;
double EPS,t;
double x0,x1,x2,f1,f2;
printf("Précision voulue: ");
scanf("%lf",&EPS);
printf("entrer la valeur initiale X0: ");
scanf("%lf",&x0);
printf("entrer la valeur initiale X1: ");
scanf("%lf",&x1);
	do{
	  f1=f(x0);
	  f2=f(x1);
		x2 = x1 - ((f2*(x1-x0))/(f2-f1));
		x0=x1;
		x1=x2;
			if(f2<0)
			t=fabs(f2);
			else
			t=f2;
			i++;
	}while(t>EPS);

printf("%lf\n",x2);
printf("nbr d'iteration' : %d\n", i);
system("PAUSE");
  return 0;
}

