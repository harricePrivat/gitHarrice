#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TriageEtudiant.h"

int main(){
	FILE *file;
	int nbr;
	file = fopen("info_Etudiant.csv","a+");
	printf("Donnez le nombre"); scanf("%d",&nbr);
	Etudiant *e=malloc(sizeof(Etudiant)*nbr);
	//fprintf(file,"Nom,Prenom,Date de naissance,Age,Adresse,Téléphone\n");
	for(int i=0 ; i<nbr ; i++){
		printf("Nom : "),scanf("%s",e[i].nom);
		printf("Prenom : "),scanf("%s",e[i].prenom);
		printf("Tel : "),scanf("%s",e[i].tel);
		printf("Mail : "),scanf("%s",e[i].mail);
		printf("Adresse : "),scanf("%s",e[i].adresse);
		printf("Date de naissance : ");scanf("%s",e[i].date);
		printf("lieu de naissance: "),scanf("%s",e[i].lieu);
		printf("Année du Bacc : "),scanf("%s",e[i].anne);
		printf("CIN : "),scanf("%s",e[i].cin);
		printf("URL du compte Github: ");scanf("%s",e[i].url);
		fprintf(file,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",e->nom,e->prenom,e->tel,e->mail,e->adresse,e->date,e->lieu,e->anne,e->genre,e->cin,e->url);
	}
	fclose(file);
	return 0;
}
