#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int main(){
	Lista *l1, *l2, *l3;
	int num1, num2;
	l1 = cria();
	l2 = cria();
	l3 = cria();
	printf("Digite o primeiro número para adicionar:\n");
	scanf("%d", &num1);
	printf("\nDigite o segundo número para adicionar:\n");
	scanf("%d", &num2);
	l1 = le_numero(l1, num1);
	l2 = le_numero(l2, num2);
	printf("O fatorial:\n");
	l3 = fatorial(l1);
	imprimir(l3);
	libera(l3);
	printf("A multiplicação:\n");
	l3 = multiplicacao(l1, l2);
	imprimir(l3);
	libera(l3);
	printf("O quadrado:\n");
	l3 = quadrado(l1);
	imprimir(l3);
	libera(l3);
	printf("A soma:\n");
	l3 = adicao(l1, l2);
	imprimir(l3);
	libera(l3);
	printf("O MDC:\n");
	l3 = mdc(l1, l2);
	imprimir(l3);
	libera(l3);
	printf("Numero 1:\n");
	imprimir(l1);
	printf("Numero 2:\n");
	imprimir(l2);
	printf("A exponenciacao:\n");
	l3 = exponenciacao(l1, l2);
	imprimir(l3);
	libera(l3);
	printf("O modulo:\n");
	l3 = modulo(l1, l2);
	imprimir(l3);
	libera(l3);
	libera(l1);
	libera(l2);
	return 0;
}
