#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int nombreEntre=0, nombreMystere=0,coup=7;
	srand(time(NULL));
	nombreMystere= 1+(int)((100.0*rand())/(RAND_MAX+1.0));
	printf("Le but du jeu est de trouver un nombre mystere compris entre 1 et 100 en 7 coups.\n");
	printf("coup: %d", nombreMystere);
	while(nombreEntre!=nombreMystere && coup>0){
	if(coup>0){
	printf("Entrez un nombre:\n");
		scanf("%d", &nombreEntre);
		if(nombreEntre>nombreMystere){
			coup--;
		printf("Trop grand\t\t%d coups restants\n", coup);
		
	}
		else if(nombreEntre<nombreMystere){
			coup--;
		printf("Trop petit\t\t%d coups restants.\n", coup);
	}
		else{ 
			printf("Felicitation!! vous avez trouve le nombre mystere.\n");
		}	
		
}
		if(coup==0){
			printf("\n\nVous avez dépassezr les 7 coups.\n");
			printf("Vous avez perdu.\n");
			break;
			}
}
		return 0;
}
	
