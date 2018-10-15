/* Copyright 2018 <Copyright Eder Souza Gualberto> */

#ifndef TRAB3_INCLUDE_CONTA_LINHAS_H_
#define TRAB3_INCLUDE_CONTA_LINHAS_H_

/**
 * Funcao: Abrir Arquivo
 * Descricao:
 * 	Esta funcao abre um arquivo, cujo nome e indicado em char nome[15]
 * Parametros:
 * 	nome - string com o nome do arquivo a ser aberto
 * Valor Retornado:
 * 	Retorna um ponteiro, do tipo FILE, para o arquivo que foi aberto
 * Assertiva de entrada
 * 	char nome[15] deve conter um  nome de arquivo valido, existente no
 * diretorio (na implementacao atual, o nome deve ter no maximo 14
 * caracteres.
 */ 
FILE* abrir_arquivo(char nome[15]);

/**
 * Funcao: Fechar Arquivo
 * Descricao:
 * 	Esta funcao fecha um arquivo, cuja referencia esta contida no pon-
 * teiro do tipo FILE, de nome fp
 * Parametros:
 * 	fp - ponteiro do tipo FILE para o arquivo a ser fechado
 * Valor Retornado:
 * 	Retorna um inteiro = 0, quando o arquivo e fechado com sucesso
 * Assertiva de entrada
 * 	FILE* fp deve conter uma referencia para o arquivo a ser fechado,
 * nao pode apontar para NULL por exemplo.
 */ 
int fechar_arquivo(FILE* fp);

/**
 * Funcao: Contar Linhas de Codigo
 * Descricao:
 * 	Esta funcao recebe uma referencia para um arquivo e calcula quantas
 * linhas de codigo C ou C++ contem no mesmo.
 * Parametros:
 * 	fp - ponteiro do tipo FILE para o arquivo a ser examinado, com rela-
 * cao ao numero de linhas de codigo
 * Valor Retornado:
 * 	Retorna um inteiro que indica a quantidade de linhas de codigo
 * Assertiva de entrada
 * 	FILE* fp deve conter uma referencia para o arquivo a ser examinado,
 * nao pode apontar para NULL por exemplo.
 */ 
int contar_linhas_codigo(FILE* fp);

/**
 * Funcao: Identificar Linha de Comentario
 * Descricao:
 * 	Esta funcao indentifica se uma linha e de comentario, em branco ou
 * de codigo. Recebe uma linha do arquivo que esta sendo examinado 
 * pela funcao contar_linhas_codigo, e uma indicacao da linha anterior
 * com relacao aos comentarios (0 linha de codigo, 1 linha de comentario
 * iniciada e terminada, 2 linha de codigo iniciada e ainda nao fechada.
 * Parametros:
 * 	linha - string com a linha extraida do arquivo apontado por fp
 * 	comentario - estado da linha anterior com relacao a um comentario
 * inicalmente aberto, mas nao fechado (2), iniciado e fechado (1) ou
 * inexistente(0, linha de codigo).
 * Valor Retornado:
 * 	Retorna int comentario, que indica o estado da linha em questao, 
 * com relacao aos comentarios (0 linha de codigo, 1 linha de comentario
 * iniciada e terminada, 2 linha de codigo iniciada e ainda nao fechada.
 * Assertiva de entrada
 * 	linha deve ser uma string valida, obtida do arquivo apontado por fp
 * 	comentario deve ter um valor igual a 0, 1 ou 2
 */
int identificar_linha_comentario(char *linha, int comentario);

#endif  // TRAB3_INCLUDE_CONTA_LINHAS_H_
