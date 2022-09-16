#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

int main()
{
    const int NMAX = 10, NMIN = 1;
    srand(time(NULL));
    int nbrand = (rand() % (NMAX - NMIN + 1)) + NMIN;

    bool nontrouve=true;
    int nb;
    while(nontrouve)
    {
      printf("donner un nombre entre 1 et 10: ");
      scanf("%d",&nb);
      printf("\n");
      if(nb==nbrand) nontrouve=false;
      else{
        if(nb<nbrand) printf("nombre tape plus petit\n");
        else printf("nombre tape plus grand\n");
      }
    }
     printf("bien joue nb:%d, nbrand:%d \n",nb,nbrand);

    return 0;
}