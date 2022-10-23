#include "trab1.h"
#include <iostream>
#include <cstring>


int main(){
    int ordem;

    std::cin >> ordem;

    // alocacao dinaminca

    MatrizQuadrada *M1 = new MatrizQuadrada(ordem);         // usar a mesma ordem para todas as matrizes para permitir operacoes como multiplicacao e comparar
    MatrizQuadrada *M2 = new MatrizQuadrada(ordem);         // nao sera permitido ordens diferentes
    MatrizQuadrada *I = new MatrizQuadrada(ordem);
    MatrizQuadrada *R = new MatrizQuadrada(ordem);
    MatrizQuadrada *T = new MatrizQuadrada(ordem);

    M1->LeMatriz();             // ler a matriz M1 com a ordem ja passada e depois imprimir
    std::cout << "Matriz M1: \n";
    M1->ImprimeMatriz();

    I->CriaMatrizIdentidade();      
    std::cout << "Matriz I: \n";
    I->ImprimeMatriz();

    if(M1->Compara(*I)){        // comparando M1 com a id
        std::cout << "As matrizes M1 e I sao iguais\n";
        
    }else{
        std:: cout << "As matrizes M1 e I sao diferentes\n";
    }

    T->CriaTransposta(*M1);         // criando a transposta de M1
    std::cout << "Matriz T: \n";
    T->ImprimeMatriz();

    M2->Soma(*T, *M1);             // M2 = T + M1
    std::cout << "Matriz M2: \n";
    M2->ImprimeMatriz();

    R->Produto(*T, *M1);            // R = T * M1
    std::cout << "Matriz R: \n";
    R->ImprimeMatriz();

    // liberando memoria da alocacao dinamica
    delete M1;
    delete M2;
    delete I;
    delete T;
    delete R;

    return 0;
}