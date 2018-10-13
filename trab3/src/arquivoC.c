/* Copyright 2018 <Copyright Eder Souza Gualberto> */
/**
 * Neste arquivo sao feitos testes com qualquer uma das implementacoes
 * de pilha (em vetor ou em fila), pois o cabecalho e o mesmo
 * para a implementacao em fila, fazer: make pilha-lista, e para a imple
 * mentacao em vetor, fazer make pilha-vetor. Ambos as compilacoes ja
 * incluem as flags para o gcov
 */
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {
Pilha *p = createStack();
ItemType *item = createItemType();
item -> dado_int = 1;
for (int i = 0; i < 30; i++) {
  item -> dado_int = 0;
  push(p, item);
}
imprime(p);
printf("\n %d \n", p -> itens);
for (int i = 0; i <= 25; i++) {
  pop(p);
}
imprime(p);
printf("\n Tamanho %d \n", size(p));
setSize(40, p);
setSize(35, p);
imprime(p);
printf("\n Tamanho %d \n", size(p));
printf("\n esta cheia: %d \n", isFull(p));
printf("\n esta vazia: %d \n", isEmpty(p));
item = top(p);
destroyStack(p);
printf("\n esta vazia: %d \n", isEmpty(p));
printf("\n \n \n tamanho final: %d \n \n", size(p));

return 0;
}
