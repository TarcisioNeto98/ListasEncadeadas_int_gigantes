#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	char v;
	struct lista *prox;
	struct lista *ant;
};

Lista* cria(){
	return NULL;
}

Lista* inserir(Lista *l, char c){
	Lista *n = (Lista*)malloc(sizeof(Lista));
	n->v = c;
	if(l != NULL) l->ant = n;
	n->prox = l;
	n->ant = NULL;
	return n;
}

int vazia(Lista *l){
	return l == NULL;
}

Lista* inserir_fim(Lista *l, char x){
	Lista *atual = l, *ant = NULL;
	while(atual != NULL){
		ant = atual;
		atual = atual->prox;
	}
	if(vazia(ant)) return inserir(l, x);
	else{
		Lista *n = (Lista*)malloc(sizeof(Lista));
		n->v = x;
		ant->prox = n;
		n->ant = ant;
		n->prox = NULL;
		return l;
	}
}

void imprimir(Lista *l){
	Lista *p = l;
	while(p != NULL){
		printf("%c", p->v);
		p = p->prox;
	}
	printf("\n");
}

void libera(Lista *l){
	Lista *p = l;
	while(p != NULL){
		Lista *t = p;
		p = p->prox;
		free(t);
	}
}


int tamanho_lista(Lista *l){
	int i = 0;
	Lista *p = l;
	while(p != NULL){
		i++;
		p = p->prox;
	}
	return i;
}

Lista* ultimo_no(Lista *l){
	Lista *ant = NULL, *atual = l;
	while(atual != NULL){
		ant = atual;
		atual = atual->prox;
	}
	return ant;
}

Lista* proximo_no(Lista *l){
	return l->prox;
}

Lista* no_anterior(Lista *l){
	return l->ant;
}

Lista* nova_igual(Lista *l){
	Lista *igual = cria(), *p = l;
	while(p != NULL){
		igual = inserir_fim(igual, p->v);
		p = p->prox;
	}
	return igual;
}

char getValor(Lista *l){
	return l->v;
}

void setValor(Lista *l, char c){
	l->v = c;
}
