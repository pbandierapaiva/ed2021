####
# Makefile para Estruturas abstratas de dados
###

C = gcc
# Para depuração "-g"
COPT = -g
# Para produção
# COPT =

all: pilha fila lc dl arvore

clean:
	rm *.o

pilha: pilha.o lista.o
	$(C) pilha.o lista.o -o pilha

fila: fila.o  lista.o
	$(C) fila.o lista.o -o fila

lc: lc.o  lista.o
	$(C) lc.o lista.o -o lc

dl: dl.o listadl.o
	$(C) dl.o listadl.o -o dl


arvore: arvore.o
	$(C) arvore.o -o arvore


lista.o: lista.c lista.h
	$(C) $(COPT) -c lista.c

listadl.o: listadl.c listadl.h
		$(C) $(COPT) -c listadl.c

pilha.o: pilha.c lista.h
	$(C) $(COPT) -c pilha.c

fila.o: fila.c lista.h
	$(C) $(COPT) -c fila.c

lc.o: lc.c lista.h
	$(C) $(COPT) -c lc.c

dl.o: dl.c listadl.h
	$(C) $(COPT) -c dl.c

arvore.o: arvore.c arvore.h
		$(C) $(COPT) -c arvore.c
