typedef struct lista Lista;

Lista* cria();
Lista* inserir(Lista *l, char c);
int vazia(Lista *l);
Lista* inserir_fim(Lista *l, char x);
void imprimir(Lista *l);
void libera(Lista *l);
int tamanho_lista(Lista *l);
Lista* ultimo_no(Lista *l);
Lista* proximo_no(Lista *l);
Lista* no_anterior(Lista *l);
Lista* nova_igual(Lista *l);
char getValor(Lista *l);
void setValor(Lista *l, char c);
