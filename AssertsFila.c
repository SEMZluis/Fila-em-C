#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include <assert.h>

void testCriarFilaAsserts() {
    Fila *fila = criarFila(0);

    assert(estaVazia(fila));
    assert(estaCheia(fila));
    assert(fila->tamanho == 0);
    assert(fila->capacidade == 0);

    free(fila);
}



void testFilaAddAsserts() {
    Fila* fila = criarFila(5);
    assert(estaVazia(fila));
    assert(!estaCheia(fila));
    assert(fila->tamanho == 0);

    inserir(fila, 10);
    assert(!estaVazia(fila));
    assert(!estaCheia(fila));
    assert(fila->tamanho == 1);
    assert(verRecente(fila) == 10);

    inserir(fila, 20);
    inserir(fila, 30);
    inserir(fila, 40);
    inserir(fila, 50);
    assert(!estaVazia(fila));
    assert(estaCheia(fila));
    assert(fila->tamanho == 5);
    assert(verAntigo(fila) == 10);
    assert(verRecente(fila) == 50);

    inserir(fila, 60);
    assert(estaCheia(fila));
    assert(fila->tamanho == 5);
    assert(verAntigo(fila) == 10);
    assert(verRecente(fila) == 50);

    assert(remover(fila) == 10);
    assert(fila->tamanho == 4);
    inserir(fila, 60);

    assert(!estaVazia(fila));
    assert(estaCheia(fila));
    assert(fila->tamanho == 5);
    assert(verAntigo(fila) == 20);
    assert(verRecente(fila) == 60);

    free(fila);
}

void testFilaRemover() {
    Fila* fila = criarFila(5);
    
    assert(remover(fila) == -1);
    assert(estaVazia(fila));
    assert(!estaCheia(fila));
    assert(fila->tamanho == 0);

    inserir(fila, 10);
    inserir(fila, 20);
    inserir(fila, 30);
    inserir(fila, 40);
    inserir(fila, 50);
    assert(estaCheia(fila));
    assert(fila->tamanho == 5);

    assert(remover(fila) == 10);
    assert(remover(fila) == 20);
    assert(remover(fila) == 30);

    assert(!estaVazia(fila));
    assert(!estaCheia(fila));
    assert(fila->tamanho == 2);
    assert(verAntigo(fila) == 40);
    assert(verRecente(fila) == 50);

    free(fila);
}

void main() {
    testCriarFilaAsserts();
    testFilaAddAsserts();
    testFilaRemover();
    printf("Todos os testes passaram.");
}

