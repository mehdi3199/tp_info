#include <stdio.h>
#include <stdlib.h>

#define LONGUEUR_ENTETE 54 // la taille de l’entête bmp

FILE* ouverture_fichier(char * str)
{
  FILE * fpl;
  fpl=fopen(str,"rb");
  if(!fpl)
  {
    printf("erreur d'ouverture!! \n");
    exit(1);
  }
  return fpl;
}

void lecture_entete(char * en_tete, FILE* fp)
{

fread (en_tete,sizeof(char),LONGUEUR_ENTETE,fp );

}

void get_width_height(char * en_tete, int* w, int* h)
{
   *w = *(int*)&en_tete[18];
   *h= *(int*)&en_tete[22];
}


void Lecture_ComposantesRGB(FILE* fp,unsigned char* B,unsigned char* G, unsigned char* R, int pixelTotal){
    char n;
    if (fp != NULL){ // On test si le fichier est ouvert
        printf("\n- Analyse des pixels: ... START\n");
        int i=0, j=0, k=0;
        //printf("\nle cursor actuel est : %d", ftell(fp));
        int pixelCourant=0;
        while( pixelCourant < (pixelTotal*3) && !feof(fp)){
             n= fgetc(fp); // On lit le caractère
            if(((ftell(fp)-56)%3)==0){
                B[i]=n;i++;
            }else if(((ftell(fp)-56)%3)==1){
                G[j]= n;j++;
            }else {
                R[k]= n;k++;
            }
            pixelCourant++;
        }
    }else {
        printf("@Error: fichier n'est pas ouvert");
        exit(1);
    }
    printf("- Analyse des pixels: ... FINISH\n");
}



int main(void)
{
FILE* fp; // Fichier de lecture
FILE* fp2; // Fichier pour écriture
char en_tete[LONGUEUR_ENTETE+1];

fp=ouverture_fichier("lena24.bmp"); // utilisez fopen


lecture_entete(en_tete, fp); // utilisez la fonction fread dedans

//for(int i=0; i<sizeof(en_tete);i++) printf("%c ",en_tete[i]);
//printf("%c ",en_tete[i]);
int width ;
int height ;
get_width_height(en_tete,&width,&height); // cette fonction doit retourner la taille de l’image en pixels (hauteur x largeur), alternativement utilisez une fonction
printf("%d , %d",width,height);
int nbPixels = width*height;
//Compléter ici ... allocation memoire.. etc.
unsigned char * B = malloc(nbPixels);
unsigned char * G = malloc(nbPixels);
unsigned char * R = malloc(nbPixels);

Lecture_ComposantesRGB(fp,R,G,B,nbPixels) ;

/*
filtrage_image(nbre_pixels, R,G,B);
ecriture_nouveau_fichier(«sortie.bmp »,en_tete,nbre_pixels,R,G,B ) ;

fclose(fp);
fclose(fp2) ;
*/
printf ("\n\nAppuyez sur une touche pour finir !");
return 0;
}