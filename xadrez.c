#include <stdio.h>

/*
Cavalo -> move duas casas para a direita e uma para cima (Direita, Direita, Cima)
Bispo -> move cinco casas para a diagonal (Cima, Direita)
Rainha -> move oito casas para a esquerda (Esquerda)
Torre -> move cinco casas para a direita (Direita)
*/

void Cavalo(int i, int j){ // função coom loop aninhado para movimentar o cavalo
        for(i = 0; i < 1; i++){
            for(j = 0; j < 2; j++){
                printf("Direita, ", j);
            }
            printf("Cima\n", i);
    }
}

void BispoRecursivo(int bispoFinal){ // função recursiva para movimentar o bispo
    if(bispoFinal == 0){
        return;
    }
    printf("Direita, ");
    printf("Cima\n");
    BispoRecursivo(bispoFinal - 1);
}

void Bispo(int i, int bispoInicial, int bispoFinal){ // função com loop para chamar o bispoRecursivo
    for(i = 0; i < bispoInicial; i++){
        BispoRecursivo(bispoFinal);
    }
}

void Rainha(int rainha, char esquerda){ // função recursiva para movimentar a rainha
    if(rainha > 0){
        printf("%csquerda\n", esquerda);
        Rainha(rainha - 1, esquerda);
    }
}

void Torre(int torre, char direita){ // função recursiva para movimentar a torre
    if(torre > 0){
        printf("%cireita\n", direita);
        Torre(torre - 1, direita);
    }
}

int main(){

    // declaração das variáveis
    int i, j; 
    int peca, rainha = 8, torre = 5, bispoFinal = 5, bispoInicial = 1;
    char direita = 'D', esquerda = 'E', cima = 'C';

    // menu interativo para escolher qual peça o usuário deseja mover
    printf("***Jogo de Xadrez***\n"); 
    printf("1. Cavalo\n");
    printf("2. Bispo\n");
    printf("3. Rainha\n");
    printf("4. Torre\n");
    printf("Selecione uma das peças abaixo para jogar: \n");
    scanf("%d", &peca);

if(peca == 1){ // se a peça escolhida for o cavalo 
    printf("Movimentação do cavalo:\n");
    Cavalo(i, j);
} else if(peca == 2){ // se a peça escolhida for o bispo
    printf("Movimentação do bispo:\n");
    Bispo(i, bispoInicial, bispoFinal);
} else if(peca == 3){ // se a peça escolhida for a rainha
    printf("Movimentação da rainha:\n");
    Rainha(rainha, esquerda);
} else if(peca == 4){ // se a peça escolhida for a torre
    printf("Movimentação da torre:\n");
    Torre(torre, direita);
} else { // opção inválida caso qualquer valor diferente de 1 a 4 for selecionado
    printf("Opção inválida\n");
}

    return 0;

}