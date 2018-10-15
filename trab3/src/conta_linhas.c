/* Copyright 2018 <Copyright Eder Souza Gualberto> */

#include <stdio.h>
#include <stdlib.h>
#include "conta_linhas.h"

/**
 * Funcao: Abrir Arquivo
 * Descricao:
 * 	Esta funcao abre um arquivo, cujo nome e indicado em char nome[15]
 * Parametros:
 * 	nome - string com o nome do arquivo a ser aberto
 * Valor Retornado:
 * 	Retorna um ponteiro, do tipo FILE, para o arquivo que foi aberto
 * 
 * Assertiva de entrada
 * 	char nome[15] deve conter um  nome de arquivo valido, existente no
 * diretorio (na implementacao atual, o nome deve ter no maximo 14
 * caracteres.
 * 
 * Assertiva de saida
 * 	Esta funcao deve fornecer para aquelas funcoes que a utilizam, um
 * ponteiro valido, do tipo FILE, que aponte para o arquivo que sera
 * verificado
 * 
 * Assertiva de contrato
 * 	AssertivaEntrada
 * 	!ExisteArquivo(nome);
 * 	AssertivaSaida
 * 	ExisteArquivo(fp);
 */ 
FILE* abrir_arquivo(char nome[15]) {
    FILE* fp = NULL;
    fp = fopen(nome, "rt");
    return fp;
}

/**
 * Funcao: Fechar Arquivo
 * Descricao:
 * 	Esta funcao fecha um arquivo, cuja referencia esta contida no pon-
 * teiro do tipo FILE, de nome fp
 * Parametros:
 * 	fp - ponteiro do tipo FILE para o arquivo a ser fechado
 * Valor Retornado:
 * 	Retorna um inteiro = 0, quando o arquivo e fechado com sucesso
 * 
 * Assertiva de entrada
 * 	FILE* fp deve conter uma referencia para o arquivo a ser fechado,
 * nao pode apontar para NULL por exemplo.
 * 
 * Assertiva de saida
 * 	Esta funcao deve fechar o arquivo indicado no parametro e fornecer
 * o inteiro 0 como confirmacao para as funcoes clientes desta
 * 
 *  * Assertiva de contrato
 * 	AssertivaEntrada
 * 	!ExisteArquivo(fp);
 * 	AssertivaSaida
 * 	ArquivoFechado(int=0);
 */ 
int fechar_arquivo(FILE* fp) {
    int fechado = fclose(fp);
    return fechado;
}

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
 * 
 * Assertiva de entrada
 * 	FILE* fp deve conter uma referencia para o arquivo a ser examinado,
 * nao pode apontar para NULL por exemplo.
 * 
 * Assertiva de saida
 * Esta funcao deve fornecer o numero de linha de codigo de um arquivo,
 * representado aqui pelo inteiro n_linhas. Deve contabilizar apenas li-
 * nhas que nao comecem com / e *, * / (* se vier entre os dois primei-
 * ros) e "//".
 * 
 *  * Assertiva de contrato
 * 	AssertivaEntrada
 * 	!ExisteArquivo(fp);
 * 	AssertivaSaida
 * 	Igual(n_linhas);
 */ 
int contar_linhas_codigo(FILE* fp) {
    int n_linhas = 0;
    int comentario = 0;
    char linha[121];
    while (fgets(linha, 121, fp) != NULL) {
        comentario = identificar_linha_comentario(linha, comentario);
        /**
         * a variavel inteiro comentario, indica o estado da ultima li-
         * nha verificada, se 0, e uma linha de codigo, caso contrario
         * uma linha em branco ou de comentario
         */
        if (comentario == 0) {
            n_linhas++;
        }
    }
    fechar_arquivo(fp);
    return n_linhas;
}

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
 * 
 * Assertiva de entrada
 * 	linha deve ser uma string valida, obtida do arquivo apontado por fp
 * 	comentario deve ter um valor igual a 0, 1 ou 2
 * 
 * Assertiva de saida
 * 	Deve fornecer uma avaliacao da linha passada para analise, baseando-
 * se em suas caracteristicas e no estado da linha anterior. O estado
 * e representado por meio de um inteiro comentario, que e 0 se a linha 
 * e de codigo, 1 se e um comentario finalizado e 2 se e um comentario
 * ainda aberto
 * 
 *  Assertiva de contrato
 * 	AssertivaEntrada
 * 	!ExisteLinha(linha);
 * 	AssertivaSaida
 * 	Igual(comentario); (comentario = estado do comentario)
 * 
 */
int identificar_linha_comentario(char *linha, int comentario) {
    char c1, c2, c3;
    /**
     * Sao lidos e armazenados os 3 primeiros caracteres da linha em
     * c1, c2 e c3 respectivamente, para analisar a linha em verificacao
     */
    int n = sscanf(linha, "%c%c%c", &c1, &c2, &c3);
    if (n > 0) {
        switch (c1) {
			/**
			 * Se /, entao para comentario tem q vir seguido de outra /
			 * ou de um *. Caso nao venha seguido de um desses, e codi-
			 * go
			 */
            case '/':
            switch (c2) {
                case '/':
                    comentario = 1;
                    return comentario;
                    break;
                case '*':
                    comentario = 2;
                    return comentario;
                    break;
                default:
                    comentario = 0;
                    break;
            }
            break;
            /**
             * Se branco, tem que analisar se e seguido de um * e depois
             * uma / (para fechar o comentario), ou se o comentario se-
             * gue pra proxima linha
             */
            case ' ':
            if ((c2 == '*') && (comentario == 2)) {
                if (c3 == '/') {
                    comentario = 1;
                } else {
                    comentario = 2;
                }
                return comentario;
            }
                break;
                /**
                 * caso nao entre em nenhuma das anteriores, e linha de 
                 * codigo
                 */
            default:
                comentario = 0;
                break;
        }
    }

    return 0;
}

