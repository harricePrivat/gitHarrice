//typedef struct Machine;
typedef struct {
	char marque[30];
	char etiquette[30];
	char mac[40];
}Machine;

#ifndef PC_H_
#define PC_H_


typedef struct Pc{
	char mac[35];
	char etiquette[30];
	char marque[20];
} Pc;

/*-------------------------------------------*/

Pc*get_info(FILE*fp,Pc*pc1,int i,int occ){
	for(i=0;i<occ;i++){
		printf("Entrez respectivement les infos:\n");
	//	scanf("%s %s %s %s %s %s",e1.nom,e1.mention,e1.parcours,e1.grade,e1.niveau,e1.num_inscription);
		fgets(pc1[i].mac,35,stdin);pc1[i].mac[strcspn((pc1[i].mac),"\n")]='\0';
		fgets(pc1[i].etiquette,30,stdin);pc1[i].etiquette[strcspn((pc1[i].etiquette),"\n")]='\0';
		fgets(pc1[i].marque,20,stdin);pc1[i].marque[strcspn((pc1[i].marque),"\n")]='\0';
		  
		fprintf(fp,"%s;%s;%s\n",pc1[i].mac,pc1[i].etiquette,pc1[i].marque);
	}
	return pc1;
}

/*--------------------------------------------*/

Pc* recupere_info(FILE* fp , int count){
	char line[1000];
	Pc *pc1 = malloc(sizeof(Pc)*count);
	for(int i=0;fgets(line,1000,fp) != NULL;i++){
		sscanf(line,"%[^;];%[^;];%[^\n]",pc1[i].mac,pc1[i].etiquette,pc1[i].marque);
	}
	return pc1;
}

Pc* tri_pc(Pc* pc1 , int count){
	for(int i=1 ; i<count ; i++){
		for(int j=i+1 ; j<count ; j++){
			if(strcmp(pc1[i].etiquette,pc1[j].etiquette)>1){
				char tmp[300];
				strcpy(tmp , pc1[j].mac);strcpy(pc1[j].mac , pc1[i].mac);strcpy(pc1[i].mac , tmp);
				strcpy(tmp , pc1[j].etiquette);strcpy(pc1[j].etiquette , pc1[i].etiquette);strcpy(pc1[i].etiquette , tmp);
				strcpy(tmp , pc1[j].marque);strcpy(pc1[j].marque , pc1[i].marque);strcpy(pc1[i].marque , tmp);
				
			}
		}
	}
	
	return pc1;
}

FILE* redirige(Pc* pc1 , int count){
	FILE* fp1 = fopen("pc1.csv","a+");
	
	for(int i=0;i<count;i++){
		fprintf(fp1,"%s;%s;%s\n",pc1[i].mac,pc1[i].etiquette,pc1[i].marque);
	}
	
	
	return fp1;
}


/*-------------------------------------------------------------------*/

int count_line(int count , FILE *file){
	
	while (! feof (file)){
			if(fgetc(file) == '\n'){
				count++;
			}
	}
	
	return count;
}
#endif

