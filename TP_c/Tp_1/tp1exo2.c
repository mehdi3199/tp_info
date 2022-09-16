#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 


double f(double x) ; // prototype de la fonction f()
int main()
{
double y,x;
x=2;
y= f(x);
printf("y= %f\n",y);
return 0;
}


double f(double x) // définition de la fonction f, Tout ce que la fonction fait c’est d’envoyer en sortie l’entrée x au carré
{
return x*x;
}
