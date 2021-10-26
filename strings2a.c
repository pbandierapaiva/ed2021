/*****************************************************************************
strings2a.c - Exercício 2 
*/

#include <stdio.h>
#include <string.h>

int main(){
	char name[512];
	int r,c=0;
	do{
		r = scanf(" %s",name);
		if(r==EOF) break;
		c++;
	}while(strcmp(name,"end")!=0); /*strcmp compara strings*/
	
	printf("%d palavras\n",c);
	return 0;
}
