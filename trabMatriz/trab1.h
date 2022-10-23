#include <iostream>
#include <string>

class MatrizQuadrada {
    private:
        int ordem_;     // tamanho da matriz quadrada   ordem x ordem
        int **p;

    public:
        MatrizQuadrada(int ordem);
        ~MatrizQuadrada();
        void LeMatriz();
        void CriaMatrizIdentidade();
        void CriaTransposta(MatrizQuadrada aux1);
        void Produto(MatrizQuadrada aux1, MatrizQuadrada aux2);
        void ImprimeMatriz();
        void Soma(MatrizQuadrada aux1, MatrizQuadrada aux2);
        bool Compara(MatrizQuadrada aux1);


};