#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TriageEtudiant.h"

int main(){
	FILE *fic= fopen("info_Etudiant.csv","r");
	FILE *tri= fopen("info_trie.csv","w+");
	int isa=0;
	if(tri == NULL || fic == NULL){
		printf("ça marche pas");
	}
	isa=manisa(isa,fic);
	Etudiant *about= malloc(sizeof(Etudiant)*isa);
	rewind(fic);
	about = get(fic , isa);
	about = triage(about , isa);
	
	for(int i=0;i<26;i++){
		printf("%s\n",about[i].prenom);
	}
	tri = inserer( about ,  isa);
	fclose(fic); 
	fclose(tri);
	
	return 0;
}

