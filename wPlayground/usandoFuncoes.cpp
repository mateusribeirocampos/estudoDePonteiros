#include <iostream>

void trocaComPonteiros(int *&pNum1, int *&pNum2)
{
    int *temp = pNum1;
    pNum1 = pNum2;
    pNum2 = temp;
}

int somaComPonteiros(int *&pSoma, int *&pNum1, int *&pNum2){
    *pSoma = *pNum1 + *pNum2;
    return *pSoma;
}

void imprimirTroca(int num1, int num2)
{
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
}

void imprimirSomaPtr(int soma, int num1, int num2){

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "Soma: " << soma << std::endl;
}

int main()
{
    int num1 = 10;
    int num2 = 20;
    int soma = 0;

    int *pNum1 = &num1;
    int *pNum2 = &num2;
    int *pSoma = &soma;

    trocaComPonteiros(pNum1, pNum2);

    imprimirTroca(*pNum1, *pNum2);

    somaComPonteiros(pSoma, pNum1, pNum2);

    imprimirSomaPtr(*pSoma, *pNum1, *pNum2);

    return 0;
}