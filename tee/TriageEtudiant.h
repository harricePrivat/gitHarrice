typedef struct {
	char nom[300];
	char prenom[300];
	char tel[300];
	char mail[300];
	char adresse[300];
	char date[300];
	char lieu[300];
	char anne[300];
	char genre[300];
	char cin[300];
	char url[300];
	
}Etudiant;

int manisa(int isa , FILE *fic);
Etudiant* get(FILE* fic,int isa);
Etudiant* triena(Etudiant* Info , int count);
FILE* inserer(Etudiant* about , int isa);


int manisa(int isa , FILE *fic){
	
	while (!feof(fic)){
			if(fgetc(fic) == '\n'){
				isa++;
			}
	}
	
	return isa;
}
Etudiant* get(FILE* fic,int isa){
	Etudiant *e=malloc(sizeof(Etudiant)*isa);
	char ligne[950];
	for(int i=0;fgets(ligne,750,fic) != NULL;i++)
		sscanf(ligne,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",e[i].nom,e[i].prenom,e[i].tel,e[i].mail,e[i].adresse,e[i].date,e[i].lieu,e[i].anne,e[i].genre,e[i].cin,e[i].url);
	
	return e;
}


Etudiant* triage(Etudiant* Info , int count){
	for(int i=1 ; i<count ; i++){
		for(int j=i+1 ; j<count ; j++){
			if(strcmp(Info[i].nom,Info[j].nom)>1){
				char tmp[300];
				strcpy(tmp , Info[j].nom);strcpy(Info[j].nom , Info[i].nom);strcpy(Info[i].nom , tmp);
				strcpy(tmp , Info[j].prenom);strcpy(Info[j].prenom , Info[i].prenom);strcpy(Info[i].prenom , tmp);
				strcpy(tmp , Info[j].tel);strcpy(Info[j].tel , Info[i].tel);strcpy(Info[i].tel , tmp);
				strcpy(tmp , Info[j].mail);strcpy(Info[j].mail , Info[i].mail);strcpy(Info[i].mail , tmp);
				strcpy(tmp , Info[j].adresse);strcpy(Info[j].adresse , Info[i].adresse);strcpy(Info[i].adresse , tmp);
				strcpy(tmp , Info[j].date);strcpy(Info[j].date , Info[i].date);strcpy(Info[i].date , tmp);
				strcpy(tmp , Info[j].lieu);strcpy(Info[j].lieu , Info[i].lieu);strcpy(Info[i].lieu , tmp);
				strcpy(tmp , Info[j].anne);strcpy(Info[j].anne , Info[i].anne);strcpy(Info[i].anne , tmp);
				strcpy(tmp , Info[j].genre);strcpy(Info[j].genre , Info[i].genre);strcpy(Info[i].genre , tmp);
				strcpy(tmp , Info[j].cin);strcpy(Info[j].cin , Info[i].cin);strcpy(Info[i].cin , tmp);
				strcpy(tmp , Info[j].url);strcpy(Info[j].url , Info[i].url);strcpy(Info[i].url , tmp);
			}
		}
	}
	
	return Info;
}

FILE* inserer(Etudiant* about , int isa){
	FILE* voafantina = fopen("info_trie.csv","a+");
	
	for(int i=0;i<isa;i++){
		fprintf(voafantina,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",about[i].nom,about[i].prenom,about[i].tel,about[i].mail,about[i].adresse,about[i].date,about[i].lieu,about[i].anne,about[i].genre,about[i].cin,about[i].url);
	
	}
	
	
	return voafantina;
}
