#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int converteParaInt(char c){
	return c - '0';
}

char converteParaChar(int n){
	return n + '0';
}

Lista* le_numero(Lista *l, int n){
	while(n > 0){
		int digito = n % 10;
		l = inserir(l, converteParaChar(digito));
		n /= 10;
	}
	return l;
}

Lista* soma(Lista *aux1, Lista *aux2, Lista *l3){
	Lista *r = cria();
	char n1, n2, n3;
	r = inserir(r, '0');
	while(aux1 != NULL){//+'0' converte para char
//-'0' converte para inteiro
		if(aux2 != NULL){ 
			n1 = getValor(aux1);
			n2 = getValor(aux2);
			n3 = getValor(r);
			int soma = converteParaInt(n1)+converteParaInt(n2)+converteParaInt(n3);
			if(soma < 10){
				l3 = inserir(l3, converteParaChar(soma));
				setValor(r, '0');
			}
			else{
				l3 = inserir(l3, converteParaChar(soma%10));
				soma = soma/10;
				r = inserir(r, converteParaChar(soma%10));
			}
			aux2 = no_anterior(aux2);
		}
		else if(vazia(aux2)){//r->v != '0'){
			n1 = getValor(aux1);
			n2 = getValor(r);
			int soma = converteParaInt(n1)+converteParaInt(n2);
			if(soma < 10){
				l3 = inserir(l3, converteParaChar(soma));
				setValor(r, '0');
			}
			else{
				l3 = inserir(l3, converteParaChar(soma%10));
				soma = soma/10;
				r = inserir(r, converteParaChar(soma%10));
			}
		}
		aux1 = no_anterior(aux1);
	}
	if(vazia(aux1) && getValor(r) != '0')
		l3 = inserir(l3, getValor(r));
	libera(r);
	return l3;
}

Lista* adicao(Lista *l1, Lista *l2){
	Lista *l3 = cria();
	if(vazia(l1) || vazia(l2)){
		if(vazia(l1) && vazia(l2)) return inserir(l3, '0');
		else if(vazia(l1) && l2 != NULL){
			Lista *s = nova_igual(l2);
			return s;
		}
		else if(vazia(l2) && l1 != NULL){
			Lista *s = nova_igual(l1);
			return s;
		}
	}
	Lista *aux1, *aux2;
	aux1 = ultimo_no(l1);
	aux2 = ultimo_no(l2);	
	if(tamanho_lista(l1) > tamanho_lista(l2)){
		l3 = soma(aux1, aux2, l3);
		return l3;
	}
	else{
		l3 = soma(aux2, aux1, l3);
		return l3;
	}
}

int comparacao(Lista *l1, Lista *l2){
	if(tamanho_lista(l1) > tamanho_lista(l2)) return 1;
	else if(tamanho_lista(l1) < tamanho_lista(l2)) return -1;
	else{
		Lista *aux1 = l1, *aux2 = l2;
		while(aux1 != NULL){
			if(getValor(aux1) > getValor(aux2)) return 1;
			else if(getValor(aux1) < getValor(aux2)) return -1;
			aux1 = proximo_no(aux1);
			aux2 = proximo_no(aux2);
		}
	}
	return 0;
}

Lista* multiplicar(Lista *l1, Lista *l2){
	Lista *r = cria(), *aux1 = l1, *aux2 = l2, *soma = cria(), *numero = cria();
	soma = inserir(soma, '0');
	int contador = 1;
	r = inserir(r, '0');
	while(aux2 != NULL){
		while(aux1 != NULL){
			int multiplicacao = converteParaInt(getValor(aux1))*converteParaInt(getValor(aux2))+converteParaInt(getValor(r));
			if((multiplicacao > 9) && vazia(no_anterior(aux1))){
				numero = inserir(numero, converteParaChar(multiplicacao%10));
				multiplicacao /= 10;
				numero = inserir(numero, converteParaChar(multiplicacao%10));
				setValor(r, '0');
			}
			else if(multiplicacao > 9){
				numero = inserir(numero, converteParaChar(multiplicacao%10));
				multiplicacao /= 10;
				r = inserir(r, converteParaChar(multiplicacao%10));
			}
			else{
				numero = inserir(numero, converteParaChar(multiplicacao));
				setValor(r, '0');
			}
			aux1 = no_anterior(aux1);
		}
		if(contador > 1){
			int i;
			for(i = 2; i <= contador; i++)
				numero = inserir_fim(numero, '0');
		}
		contador++;
		soma = adicao(soma, numero);
		libera(numero);
		numero = cria();
		aux1 = l1;
		aux2 = no_anterior(aux2);
	}
	libera(r);
	libera(numero);
	return soma;
}

Lista* multiplicacao(Lista *l1, Lista *l2){
	Lista *aux1 = ultimo_no(l1), *aux2 = ultimo_no(l2);
	return multiplicar(aux1, aux2);
}

Lista* quadrado(Lista *l){
	if(getValor(l) == '0')
		return l;
	Lista *aux1 = ultimo_no(l), *aux2 = ultimo_no(l), *quadrado;
	quadrado = multiplicar(aux1, aux2);
	return quadrado;
}

Lista* subtracao(Lista *l1, Lista *l2){
	int contador = 0;
	int comp = comparacao(l1, l2);
	Lista *aux1 = cria(), *aux2 = cria();
	aux2 = inserir(aux2, '1');
	if(comp == 0){
		Lista *l3 = cria();
		l3 = inserir(l3, '0');
		return l3;
	}
	else if(comp == 1){
		aux1 = nova_igual(l2);
		while(comparacao(l1, aux1) != 0){
			aux1 = adicao(aux1, aux2);
			contador += 1;
		}
		Lista *subtracao = cria();
		subtracao = le_numero(subtracao, contador);
		libera(aux1);
		libera(aux2);
		return subtracao;
	}
	else{
		aux1 = nova_igual(l1);
		while(comparacao(l2, aux1) != 0){
			aux1 = adicao(aux1, aux2);
 			contador += 1;
		}
		Lista *subtracao = cria();
		subtracao = le_numero(subtracao, contador);
		subtracao = inserir(subtracao, '-');
		libera(aux1);
		libera(aux2);
		return subtracao;
	}
}

Lista* divisor_comum(Lista *l1, Lista *l2){
	Lista *aux1 = cria(), *aux2 = cria(), *somador = cria(), *constante = cria(), *multiplicador = cria(), *aux3 = cria(), *reserva;
	somador = inserir(somador, '0');
	constante = inserir(constante, '1');
	aux3 = inserir(aux3, '1');
	aux1 = nova_igual(l1);
	aux2 = nova_igual(l2);
	while(getValor(aux3) != '0'){
		somador = adicao(somador, constante);
		libera(multiplicador);
		multiplicador = multiplicacao(aux2, somador);
		if(comparacao(aux1, multiplicador) == 1)
			aux3 = subtracao(aux1, multiplicador);
		else if(comparacao(aux1, multiplicador) == -1){
			reserva = aux1;
			aux1 = aux2;
			aux2 = aux3;
			libera(reserva);
			libera(somador);
			somador = cria();
			somador = inserir(somador, '0');
		}
		else aux3 = subtracao(aux1, multiplicador);
	}
	libera(aux1);
	libera(aux3);
	libera(constante);
	libera(multiplicador);
	libera(somador);
	return aux2;
}

Lista* mdc(Lista *l1, Lista *l2){
	if(comparacao(l1, l2) == 0){
		Lista *mdc = nova_igual(l1);
		return mdc;
	}
	else if(comparacao(l1, l2) == 1) return divisor_comum(l1, l2);
	else return divisor_comum(l2, l1);
}


Lista* fatorial(Lista *l){
	if(getValor(l) == '0') return inserir(NULL, '1');
	Lista *fatorial, *igual, *constante = cria(), *memoriaDesalocada;
	constante = le_numero(constante, 1);
	fatorial = nova_igual(l);
	igual = nova_igual(l);
	while(getValor(igual) != '0'){
		memoriaDesalocada = igual;
		igual = subtracao(igual, constante);
		if(getValor(igual) == '0') continue;
		libera(memoriaDesalocada);
		memoriaDesalocada = fatorial;
		fatorial = multiplicacao(igual, fatorial);
		libera(memoriaDesalocada);
	}
	libera(igual);
	libera(constante);
	return fatorial;
}

Lista* exponenciacao(Lista *l1, Lista *l2){
	Lista *l3 = nova_igual(l2), *constante = cria(), *resultado = nova_igual(l1), *memoriaDesalocada;
	constante = le_numero(constante, 1);
	l3 = subtracao(l3, constante);
	while(getValor(l3) != '0'){
		memoriaDesalocada = resultado;
		resultado = multiplicacao(l1, resultado);
		libera(memoriaDesalocada);
		memoriaDesalocada = l3;
		l3 = subtracao(l3, constante);
		libera(memoriaDesalocada);
	}
	libera(l3);
	libera(constante);
	return resultado;
}

Lista* modulo(Lista *l1, Lista *l2){
	Lista *resto = cria(), *resultado = cria(), *constante = cria(), *sub = cria(), *desalocador;
	constante = le_numero(constante, 1);
	Lista *resultadoAnterior = cria();
	while(l1 != NULL){
		libera(resultado);
		desalocador = sub;
		sub = adicao(sub constante);
		libera(desalocador);
		resultado = multiplicacao(l2, sub);
		if(comparacao(l1, resultado) == 0){
			libera(constante);
			libera(sub);
			libera(resultado);
			resto = inserir(resto, '0');
			return resto;
		}
		else if(comparacao(l1, resultado) == 1){
			libera(resultadoAnterior);
			resultadoAnterior = nova_igual(resultado);
		}
		else{
			resto = subtracao(l1, resultadoAnterior);
			libera(resultadoAnterior);
			libera(resultado);
			libera(constante);
			libera(sub);
			return resto;
		}
	}
}





















