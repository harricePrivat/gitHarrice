#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PC.h"

int main(){
	FILE*fp;
	FILE*fp1;
	fp=fopen("pc.csv","r");
	fp1=fopen("pc1.csv","w");
	if(fp==NULL)
		exit(EXIT_FAILURE);
	if(fp1==NULL)
		exit(EXIT_FAILURE);
	int count=0; 
	count=count_line(count,fp);
	rewind(fp);
	Pc*pc2=malloc(sizeof(Pc)*count);
	pc2=recupere_info(fp,count);
	pc2=tri_pc(pc2,count);
	fp1=redirige(pc2,count);
	fclose(fp);
	fclose(fp1);
	return 0;
}

