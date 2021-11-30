####
# Makefile para Cadastro
###

C = gcc
# Para depuração "-g"
COPT =



all: criaind maxcampos buscaind buscacad

clean:
	rm *.o

buscaind: buscaind.o util.o
	$(C) buscaind.o util.o -o buscaind


buscacad: buscacad.o util.o
	$(C) buscacad.o util.o -o buscacad
		
criaind: criaind.o util.o
	$(C) criaind.o util.o -o criaind

maxcampos: maxcampos.o util.o
	$(C) maxcampos.o util.o -o maxcampos
	

buscaind.o: buscaind.c cadastro.h util.h
	$(C) $(COPT) -c buscaind.c

buscacad.o: buscacad.c cadastro.h util.h
	$(C) $(COPT) -c buscacad.c
		
criaind.o: criaind.c cadastro.h util.h
	$(C) $(COPT) -c criaind.c

maxcampos.o: maxcampos.c util.h cadastro.h
	$(C) $(COPT) -c maxcampos.c
	
util.o: util.c util.h cadastro.h
	$(C) $(COPT) -c util.c





