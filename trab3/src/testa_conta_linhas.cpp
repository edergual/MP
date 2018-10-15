/* Copyright 2018 <Copyright Eder Souza Gualberto> */

#include <iostream>
#include <cstdlib>
#include "conta_linhas.h"
#include "gtest/gtest.h"

/**
 * Testes com a funcao abrir_arquivo
 */
TEST(AbrirArquivo, ArquivoAbertoComSucesso) {
    char nome[15] = "arquivoC.c";
    FILE* fp = abrir_arquivo(nome);
    EXPECT_NE(fp, nullptr);
    fclose(fp);
}

/**
 * Testes com a funcao fechar_arquivo
 */
TEST(FecharArquivo, ArquivoFechadoComSucesso) {
    char nome[15] = "arquivoC.c";
    FILE* fp = abrir_arquivo(nome);
    EXPECT_EQ(fechar_arquivo(fp), 0);
}

/**
 * Testes com a funcao contar_linhas_codigo
 */
TEST(ContaLinhas, ContaLinhasFunciona) {
    char nome[15] = "arquivoC.c";
    FILE* fp = abrir_arquivo(nome);
    EXPECT_EQ(contar_linhas_codigo(fp), 31);
    fclose(fp);
}

/**
 * Testes com a funcao identificar_linhas_comentario
 */
TEST(IdentificarComentarios, IdentificaComentariosFunciona) {
    char linha[121];
    char nome[15] = "arquivoC.c";
    FILE* fp = abrir_arquivo(nome);
    fgets(linha, 121, fp);
    EXPECT_EQ(identificar_linha_comentario(linha, 0), 2);
    fclose(fp);
}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
