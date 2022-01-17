####
# Makefile para Cadastro
###

C = gcc
# Para depuração "-g"
COPT = -g
# para produção
# COPT =


all: criaind maxcampos buscaind buscalotacao buscanome buscabst

clean:
	rm *.o

buscaind: buscaind.o util.o
	$(C) buscaind.o util.o -o buscaind

buscabst: buscabst.o util.o
	$(C) buscabst.o util.o -o buscabst

buscanome: buscanome.o util.o
	$(C) buscanome.o util.o -o buscanome

buscalotacao: buscalotacao.o util.o
	$(C) buscalotacao.o util.o -o buscalotacao
		
criaind: criaind.o util.o
	$(C) criaind.o util.o -o criaind

maxcampos: maxcampos.o util.o
	$(C) maxcampos.o util.o -o maxcampos
	
buscaind.o: buscaind.c cadastro.h util.h
	$(C) $(COPT) -c buscaind.c

buscabst.o: buscabst.c cadastro.h util.h
	$(C) $(COPT) -c buscabst.c

buscanome.o: buscanome.c cadastro.h util.h
	$(C) $(COPT) -c buscanome.c

buscalotacao.o: buscalotacao.c cadastro.h util.h
	$(C) $(COPT) -c buscalotacao.c

criaind.o: criaind.c cadastro.h util.h
	$(C) $(COPT) -c criaind.c

maxcampos.o: maxcampos.c util.h cadastro.h
	$(C) $(COPT) -c maxcampos.c
	
util.o: util.c util.h cadastro.h
	$(C) $(COPT) -c util.c





