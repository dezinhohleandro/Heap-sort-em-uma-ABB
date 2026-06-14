#include "arq_interface.h"
#define MAX_SIZE 14

// retorna o indice do noh pai
int pai(int i){
    return (i - 1) / 2;
}

// devolve o indice do filho esquerdo
int filhoEsq(int i){
    return 2*i + 1;
}

// devolve o indice do filho direito
int filhoDir(int i){
    return 2*i + 2;
}

// troca os valores para realizar o heap entre pai e filho esq/dir
void troca(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// insere o valor em uma posicao adequada
void insere(int v[], int dados, int *n){
    if(*n >= MAX_SIZE){
        printf("%s\n", "O heap esta cheio\n");
        return ;
    }

    // primeiro insere o valor na ultima posicao do vetor
    // e move-o para cima
    v[*n] = dados;
    *n = *n + 1;

    // move ate que o heap seja realizado
    int i = *n - 1;
    while(i != 0 && v[pai(i)] < v[i]){ // verifica se o elemento inserido eh maior ou igual ao pai
        troca(&v[pai(i)], &v[i]);
        i = pai(i);
    }
}

// move o item na posição i do vetor v
// em sua devida posicao
void maxHeapify(int v[], int i, int n){
    // encontrar noh filho esquerdo
    int esq = filhoEsq(i);
    // encontrar noh filho direito
    int dir = filhoDir(i);
    // encontra o maior entre os tres nos
    int maior = i;
    // verifica se o noh esq eh maior do que o noh atual
    if(esq <= n && v[esq] > v[maior]){
        maior = esq;
    }
    if(dir <= n && v[dir] > v[maior]){
        maior = dir;
    }

    // troca o maior noh com o noh atual
    // e repete este processo ate que o noh atual seja maior
    if(maior != i){
        troca(&v[i], &v[maior]);
        maxHeapify(v, maior, n);
    }
}

// constroi o max heap
void buildMaxHeap(int v[], int n){
    int i;
    for(i = n/2 - 1; i >= 0; i--){
        maxHeapify(v, i, n - 1);
    }
}

// ordena usando heap sort
void heapSort(int v[], int n){
    buildMaxHeap(v, n);

    int i;
    for(i = n - 1; i > 0; i--){
        troca(&v[0], &v[i]);

        maxHeapify(v, 0, i - 1);
    }
}

// funcao que imprime o heap
void imprimeHeap(int v[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Posicao: %d: %d\n", i, v[i]);
    }
    printf("\n");
}

int main(){
    int n = 0;
    int v[MAX_SIZE];

    imprimeHeap(v, n);

    insere(v, 225, &n);
    insere(v, 200, &n);
    insere(v, 100, &n);
    insere(v, 290, &n);
    insere(v, 250, &n);
    insere(v, 500, &n);
    insere(v, 900, &n);
    insere(v, 700, &n);
    insere(v, 300, &n);
    insere(v, 220, &n);
    insere(v, 215, &n);
    insere(v, 800, &n);
    insere(v, 600, &n);
    insere(v, 295, &n);

    printf("Max heap:\n");
    imprimeHeap(v, n);

    printf("Heap ordenado:\n");
    heapSort(v, n);
    imprimeHeap(v, n);

    return 0;
}
