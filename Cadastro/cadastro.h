// cadastro.h
// Arquivo com protótipos e definições

#define MAXLIN 10000
#define MAXCPO 80

#define ARQUIVOCSV "/data/datasets/ed2021/cadastro2020.csv"
#define ARQUIVOIND "cadastro2020.index"


typedef struct  {
	char nome[MAXCPO];
	char lotacao[MAXCPO];
	int  local;
	} REGIND; 

typedef struct  {
	char nome[MAXCPO];  // NOME
	char lotacao[MAXCPO]; // ORGSUP_LOTACAO
	char cargo[MAXCPO];	// DESCRICAO_CARGO
	char olotacao[MAXCPO];  	//COD_ORG_LOTACAO
	char ulotacao[MAXCPO];		//COD_UORG_LOTACAO
	} REGISTRO;
	
typedef struct No {
	REGISTRO registro;
	struct No *prox;
	} NO; 



// Arquivo gerado automaticamente 
#define Id_SERVIDOR_PORTAL 0
#define NOME 1
#define CPF 2
#define MATRICULA 3
#define DESCRICAO_CARGO 4
#define CLASSE_CARGO 5
#define REFERENCIA_CARGO 6
#define PADRAO_CARGO 7
#define NIVEL_CARGO 8
#define SIGLA_FUNCAO 9
#define NIVEL_FUNCAO 10
#define FUNCAO 11
#define CODIGO_ATIVIDADE 12
#define ATIVIDADE 13
#define OPCAO_PARCIAL 14
#define COD_UORG_LOTACAO 15
#define UORG_LOTACAO 16
#define COD_ORG_LOTACAO 17
#define ORG_LOTACAO 18
#define COD_ORGSUP_LOTACAO 19
#define ORGSUP_LOTACAO 20
#define COD_UORG_EXERCICIO 21
#define UORG_EXERCICIO 22
#define COD_ORG_EXERCICIO 23
#define ORG_EXERCICIO 24
#define COD_ORGSUP_EXERCICIO 25
#define ORGSUP_EXERCICIO 26
#define TIPO_VINCULO 27
#define SITUACAO_VINCULO 28
#define DATA_INICIO_AFASTAMENTO 29
#define DATA_TERMINO_AFASTAMENTO 30
#define REGIME_JURIDICO 31
#define JORNADA_DE_TRABALHO 32
#define DATA_INGRESSO_CARGOFUNCAO 33
#define DATA_NOMEACAO_CARGOFUNCAO 34
#define DATA_INGRESSO_ORGAO 35
#define DOCUMENTO_INGRESSO_SERVICOPUBLICO 36
#define DATA_DIPLOMA_INGRESSO_SERVICOPUBLICO 37
#define DIPLOMA_INGRESSO_CARGOFUNCAO 38
#define DIPLOMA_INGRESSO_ORGAO 39
#define DIPLOMA_INGRESSO_SERVICOPUBLICO 40
