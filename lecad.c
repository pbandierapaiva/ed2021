/*
	Programa para ler cadastro do transparencia.gov.br


*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	int i=0;
	char linha[10000];
	char *inicio, *final;
	
	
	
	fp = fopen( "/data/datasets/ed2021/cadastro2020.csv", "r");
	
	if( !fp ) {
		printf("Erro de abertura de arquivo\n\n");
		exit(0);
		}
	
	while( ! feof( fp ) ) {       // lê primeira linha do arquivo
		fgets( linha, sizeof(linha), fp);
		//printf(linha);
		break;	
		}
	inicio=linha;
	final=linha;
	
	while( *final!='\0' ) {
	
		if( *final == ';' ) {
			
			*final = '\0';
			printf("%d %s\n", i, inicio);
			i++;
			final++;
			inicio=final;
		
			}
		else {
			final++;
			}	
		}
	printf("%d %s\n", i, inicio);
	
	// fseek(fp, 0, 0 );
		
		
	fclose(fp);

	return 0;
}



