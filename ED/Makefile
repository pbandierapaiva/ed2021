####
# Makefile para Estruturas abstratas de dados
###

C = gcc
# Para depuração "-g"
COPT = -g
# Para produção
# COPT = 

all: pilha

clean:
	rm *.o

pilha: pilha.o lista.o
	$(C) pilha.o lista.o -o pilha

lista.o: lista.c lista.h 
	$(C) $(COPT) -c lista.c
	
pilha.o: pilha.c lista.h 
	$(C) $(COPT) -c pilha.c





