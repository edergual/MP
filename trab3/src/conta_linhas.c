#include <stdio.h>
#include <stdlib.h>
#include "conta_linhas.h"


FILE* abrir_arquivo(char *nome_arquivo) {
	FILE* fp = NULL;
	return fp;
}
int contar_linhas_codigo(FILE* fp) {
	int comentario=0;
	char linha[121];
	fgets(linha,121,fp);
	comentario = identificar_linha_comentario(linha,comentario);
	return 0;
}
int identificar_linha_comentario(char *linha, int comentario_aberto) {
	return 0;
}

