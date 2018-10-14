#include <stdio.h>
#include <stdlib.h>
#include "conta_linhas.h"
#include "gtest/gtest.h"

TEST(AbrirArquivo, ArquivoAbertoComSucesso) {
	char nome[15] = "arquivoC.c";
	EXPECT_NE(nullptr, abrir_arquivo(nome));
}

TEST(ContaLinhas, ContaLinhasFunciona) {
	char nome[15] = "arquivoC.c";
	FILE* fp = abrir_arquivo(nome);
	EXPECT_EQ(contar_linhas_codigo(fp),0);
	fclose(fp);
}

TEST(IdentificarComentarios, IdentificaComentariosFunciona) {
	char linha[121];
	char nome[15] = "arquivoC.c";
	FILE* fp = abrir_arquivo(nome);
	fgets(linha,121,fp);
	EXPECT_EQ(identificar_linha_comentario(linha,0),0);
	fclose(fp);
}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
