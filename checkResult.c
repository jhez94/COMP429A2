#include <stdlib.h>
#include <stdio.h>

void outputResult(char** currWorld, char* outputFileName, int nx, int ny){

	int i, j;
	FILE *fp;
	fp = fopen(outputFileName, "w");

	if(fp == NULL){
	  fprintf(stderr, "Can't open output file %s!\n", outputFileName);
	  exit(1);
	}

	for(i=1;i<nx-1;i++){
	    for(j=1;j<ny-1;j++) {
	    	fprintf(fp, "%d ", currWorld[i][j]);
	    }
	    fprintf(fp, "\n");
	}
	fclose(fp);
	return;
}

void resultVerifier(char** currWorld, char* inputFileName, int nx, int ny){

	int i, j;
	FILE *fp;
	fp = fopen(inputFileName, "r");
	char temp;

	if(fp == NULL){
	  fprintf(stderr, "Can't open inputput file %s!\n", inputFileName);
	  exit(1);
	}

	for(i=1;i<nx-1;i++){
	    for(j=1;j<ny-1;j++) {
	    	fscanf(fp, "%d ", &temp);
	    	if( temp != currWorld[i][j] ){ printf("Wrong Result!! currWorld[%d][%d]=%d != GoldenValue=%d\n",i,j,currWorld[i][j],temp); }
	    }
	}
	printf("resultVerifier is end, if u don't have any warning then it's correct!!\n");
	fclose(fp);
	return;
}
