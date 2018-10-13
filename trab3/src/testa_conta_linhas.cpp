#include <stdio.h>
#include <stdlib.h>
#include "conta_linhas.h"
#include "gtest/gtest.h"

TEST(AbrirArquivo, ArquivoAbertoComSucesso) {
	
	EXPECT_NE(abrir_arquivo("arquivoC.c"),NULL);
}

TEST(ContaLinhas, ContaLinhasFunciona) {
	FILE* fp = abrir_arquivo("arquivoC.c");
	EXPECT_EQ(contar_linhas_codigo(fp),0);
}

TEST(IdentificarComentarios, IdentificaComentariosFunciona) {
	FILE* fp = abrir_arquivo("arquivoC.c");
	fgets(linha,121,fp);
	EXPECT_EQ(identificar_linha_comentario(linha,0),0);
}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
