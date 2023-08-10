#include <stdio.h>
#include <stdlib.h>
#include "PC.h"

int main(){
	int nbr;
	FILE *file;
	file = fopen("PC.csv","a+");
	if(file == NULL)
		printf("Erreur lors de l'ouverture\n");
	printf("Donnez le nombre"); scanf("%d",&nbr);
	Machine *Pc=malloc(sizeof(Machine)*nbr);
	//fprintf(file,"Marque,Etiquette,Adresse MAC\n");
	for(int i=0 ; i<nbr ; i++){
		printf("Marque : "),scanf("%s",Pc[i].marque);
		printf("Etiquette : "),scanf("%s",Pc[i].etiquette);
		printf("Adresse MAC : "),scanf("%s",Pc[i].mac);
		fprintf(file,"%s,%s,%s\n",Pc[i].marque,Pc[i].etiquette,Pc[i].mac);
	}
	fclose(file);
	return 0;
}
