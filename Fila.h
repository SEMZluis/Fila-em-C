typedef struct {
    int *array;
    int primeiro;
    int ultimo;
    int capacidade;
    int tamanho;
} Fila;

Fila* criarFila(int capacidade);
int estaCheia(Fila* fila);
int estaVazia(Fila* fila);
void inserir(Fila* fila, int valor);
int remover(Fila* fila);
int verRecente(Fila* fila);
int verAntigo(Fila* fila);
int procurarIndiceDe(Fila* fila, int valor);
int procurarUltimoIndiceDe(Fila* fila, int valor);