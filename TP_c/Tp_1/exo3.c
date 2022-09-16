#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

FILE *fichier;

int f(int x) ; // prototype de la fonction f()
int main()
{
int y,x;
fichier=fopen("sortie_puissance.txt","w");
for(x=-10;x<=10;x++){
y= f(x);
//printf("x= %d, y=%d \n",x,y);

fprintf(fichier,"x= %d, y=%d \n",x,y);
}
fclose(fichier);
return 0;
}


int f(int x) // définition de la fonction f, Tout ce que la fonction fait c’est d’envoyer en sortie l’entrée x au carré
{
return x*x;
}
