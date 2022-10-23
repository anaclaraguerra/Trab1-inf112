#include <iostream>
#include "trab1.h"


MatrizQuadrada::MatrizQuadrada(int ordem){      // construtor
    ordem_ = ordem;                            // matriz dinamica
    p = new int * [ordem_];
    for(int i=0; i<ordem_; i++){
        p[i] = new int[ordem_];
    }
}

void MatrizQuadrada::LeMatriz(){            
    for(int i=0; i<ordem_; i++){
        for(int j=0; j<ordem_; j++){
            std::cin >> p[i][j];
        }
    }

}

MatrizQuadrada::~MatrizQuadrada(){          // destrutor
    for(int i=0; i<ordem_; i++)
        delete[] p[i];
    
    delete[] p;
}

void MatrizQuadrada::CriaMatrizIdentidade(){        // matriz id, tem a diagonal composta por 1 e o resto 0
    for(int i=0; i<ordem_; i++){
        for(int j=0; j<ordem_; j++){
            if(i == j)
                p[i][j] = 1;
            else
                p[i][j] = 0;
        }
    }
}

void MatrizQuadrada::Produto(MatrizQuadrada aux1, MatrizQuadrada aux2){    // o produto de matrizes é feito com a soma da multiplicao da linha por coluna, a ordem altera a matriz resultante
    int soma = 0;                                                         // aux1 * aux2  !=  aux2 * aux1

    for(int i=0; i<ordem_; i++){
        for(int j=0; j<ordem_; j++){
            soma = 0;
            for(int k=0; k<ordem_; k++){                                    // k criado para percorrer dentro da matriz
                soma+= aux1.p[i][k] * aux2.p[k][j];
            }
            p[i][j] = soma;
        }
    }
}

void MatrizQuadrada::ImprimeMatriz(){
    for(int i=0; i<ordem_; i++){
        for(int j=0; j<ordem_; j++){
            if(j < ordem_ - 1)
                std::cout << p[i][j] <<  " ";
            else
                std::cout << p[i][j] << "\n";
        }
    }

    std::cout << "\n";

}

void MatrizQuadrada::Soma(MatrizQuadrada aux1, MatrizQuadrada aux2){        // soma de matrizes é feita somando elemento por elemento
    std:: cout << "ENTROUUUUU\n";
    
    for(int i=0; i<ordem_; i++){
        for(int j=0; j<ordem_; j++){
            p[i][j] = aux1.p[i][j] + aux2.p[i][j];
        }
    }
}

bool MatrizQuadrada::Compara(MatrizQuadrada aux1){          // se tiver algum valor diferente, ja retorna falso, senao retorna verdadeiro

    for(int i=0; i<ordem_; i++){
        for(int j=0; j<ordem_; j++){
            if(aux1.p[i][j] != p[i][j]){
                return false;
            }
        }
    }
    return true;
}

void MatrizQuadrada::CriaTransposta(MatrizQuadrada aux1){           // transposta troca linha por coluna da matriz aux1
    for(int i=0; i<ordem_; i++){
        for(int j=0; j<ordem_; j++){
            p[i][j] = aux1.p[j][i];
        }
    }
}
