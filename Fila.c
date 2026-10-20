#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;   // Ponteiro para o array que irá guardar os dados (alocado dinamicamente)
    int primeiro;
    int ultimo;
    int tamanho;
    int capacidade;
} Fila;


/**
 *  CONSTRUTOR DA FILA
 * 
 *  RECEBE: A capacidade máxima da fila.
 *  RETORNA: Um ponteiro para a fila em si. Se retornassémos a fila "inteira", seria um gasto 
 *  muito grande e desnecessário de memória.
 * 
 *  O que deve ser feito:
 *      1. Alocação de espaço na memória para a fila (inicialização da fila)
 *      2. Alocação de espaço na memória para o array que a fila deve conter (inicialização do array)
 *      3. Configuração dos atributos da fila (primeiro, ultimo, etc.
 *      4. Retorno da referência (ou do apontador) da fila na memória
 */
Fila* criarFila(int capacidade) {                       // Em Java, essas linhas equivalem a:
    Fila *fila = (Fila*) malloc(sizeof(Fila));          // Fila fila = new Fila();
    fila->array = malloc(sizeof(int) * capacidade);     // fila.array = new int[capacidade];

    //Checar se deu errado a alocação de memória
    if (fila == NULL || fila->array == NULL) {
        printf("Erro ao alocar memória, faltou!");
        return NULL;
    }

    fila->capacidade = capacidade;
    fila->primeiro = -1;
    fila->ultimo = -1;
    fila->tamanho = 0;

    return fila;
}


/**
 *  FUNÇÕES DE ESTADO
 *  Devem checar se a pilha está cheia ou vazia mediante a variável de tamanho.
 */

int estaCheia(Fila* fila) {
    if (fila->capacidade == fila->tamanho) return 1;
    return 0;
}

int estaVazia(Fila* fila) {
    if (fila->tamanho == 0) return 1;
    return 0;
}

/**
 *  INSERÇÃO CIRCULAR
 *  RECEBE: O apontador/objeto da fila em si e o valor que será inserido nela.
 * 
 *  O que a função deve fazer:
 *      1. Checar se a fila já está cheia
 *      2. Se a fila não está cheia, aumentar o ponteiro do primeiro elemento se ela estiver vazia e no fim
 *         aumentar o ponteiro do último elemento.
 *      3. Guardar o valor do array com o ponteiro do último elemento.
 *      4. Aumentar o atributo de tamanho da fila.
 */
void inserir(Fila* fila, int valor) {
    if (estaCheia(fila) == 1) {
        printf("Fila cheia! Acabou a RAM!");
        return;
    }

    if (estaVazia(fila) == 1) {
        fila->primeiro += 1;
    }

    fila->ultimo = (fila->ultimo+1) % fila->capacidade;
    fila->array[fila->ultimo] = valor;

    fila->tamanho++;
}

/**
 *  REMOÇÃO CIRCULAR
 *  RECEBE: O apontador/objeto da fila em si.
 * 
 *  O que a função deve fazer:
 *      1. Checar se a fila já está vazia e retornar -1 se for o caso. 
 *      2. Se a fila não está cheia, aumentar o ponteiro do primeiro elemento se ela estiver vazia e no fim
 *         aumentar o ponteiro do último elemento.
 *      3. Guardar o valor do array com o ponteiro do último elemento.
 *      4. Aumentar o atributo de tamanho da fila.
 */
int remover(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia!");
        return -1;
    }

    int valor = fila->array[fila->primeiro];
    fila->primeiro = (fila->primeiro+1) % fila->capacidade;

    fila->tamanho--;

    return valor;
}

/**
 *  FUNÇÕES DE LEITURA
 *  Devem checar se o array está vazio e, se não, envia o dado que está nos extremos.
 */

int verRecente(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Tá vazia a fila!");
        return -1;
    }
    return fila->array[fila->ultimo];
}

int verAntigo(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Tá vazia a fila!");
        return -1;
    }
    return fila->array[fila->primeiro];
}

/** 
 *  ÍNDICE DE UM VALOR. 
 *  RECEBE: Um valor específico.
 *  RETORNA: A posição em que aquele valor se encontra na fila.
 * 
 *  O que a função deve fazer:
 *      1. Checar se a fila está vazia.
 *      2. Se a fila não está vazia, itera pelo array da fila.
 *      4. Se encontrar o valor, retornar o índice. Se não encontrar, retornar -1.
 */
int procurarIndiceDe(Fila* fila, int v) {
    if (estaVazia(fila)) {
        printf("Tá vazia a fila!");
    } else {
        for (int i = 0; i < fila->tamanho; i++) {
            int pos = (fila->primeiro+i) % fila->capacidade;
            if (fila->array[pos] == v) return i;
        }
    }

    return -1;
}

/** 
 *  ÚLTIMO ÍNDICE DE UM VALOR. 
 *  RECEBE: Um valor específico.
 *  RETORNA: A posição em que aquele valor se encontra na fila.
 * 
 *  O que a função deve fazer:
 *      1. Checar se a fila está vazia.
 *      2. Se a fila não está vazia, criar uma variável para armazenar o último índice encontrado para o elemento.
 *      3. Iterar pelo array da fila armazenando na variável de índice quando o elemento é encontrado.
 *      4. Retorna o índice. Se o valor não é encontrado, retorna -1.
 */
int procurarUltimoIndiceDe(Fila* fila, int v) {
    int indice = -1;

    if (estaVazia(fila)) {
        printf("Tá vazia a fila!");
    } else {
        for (int i = fila->tamanho-1; i >= 0; i--) {
            int pos = (fila->ultimo+i) % fila->tamanho;
            if (fila->array[pos] == v) return i;
        }
    }
    
    return indice;
}