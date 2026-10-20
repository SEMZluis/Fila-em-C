#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include <assert.h>

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
}

void main() {
    testFilaAddAsserts();
    printf("Todos os testes passaram.");
}

