/*
 * Copyright 2018 <Copyright Eder Souza Gualberto>
 * */
 
 /**
 * Neste arquivo estao os prototipos das funcoes utilizadas e os
 * tipos de dados criados. Os prototipos de cada funcao possuem duas
 * implementacoes com a mesma assinatura (uma em vetor e outra em lista)
 */

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define MAX 50

 /**
 * O tipo itemtype e o elemento principal da pilha, ele pode armazenar 
 * qualquer tipo de dados nativo (int, float, char ou double) por meio
 * da union
 */
struct itemtype {
	struct itemtype *prox;
	union
	{
	int dado_int;
	float dado_float;
	char dado_char;
	double dado_double;
	};

};

 /**
 * O tipo pilha controla por meio de ponteiro o ultimo elemento inserido
 * na pilha, a quantidade de itens e no caso da implementacao em vetor
 * utiliza vet
 */
struct pilha {
	struct itemtype* prim;
	int itens;
	struct itemtype vet[MAX];
};

typedef struct itemtype ItemType;
typedef struct pilha Pilha;



void push (Pilha* p, ItemType* v);
void pop (Pilha* p);
ItemType* top (Pilha* p);
int size(Pilha* p);
void setSize(int size, Pilha* p);
int isFull (Pilha* p);
int isEmpty (Pilha* p);
Pilha* createStack (void);
ItemType* createItemType (void);
void destroyStack (Pilha* p);

void imprime (Pilha* p);

#endif
