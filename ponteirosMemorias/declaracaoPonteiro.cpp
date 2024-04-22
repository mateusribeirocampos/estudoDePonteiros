#include <iostream>

int main() {
    //tipos de ponteiros
    int *x; //ponteiro para inteiro
    float *y; //ponteiro para float
    char *z; //ponteiro para char

    //ponteiro para ponteiro
    int **ponteiroParaPonteiro;

    //ponteiro para função
    void (*ponteiroParaFuncao)(int);

    //ponteiro para função que retorna ponteiro
    int *(*ponteiroParaFuncaoQueRetornaPonteiro)(int);

    //exemplo de uso de ponteiro
    int a = 10;
    int *ponteiro = &a;

    std::cout << "Valor de x: " << a << std::endl;
    std::cout << "Endereco de x: " << &a << std::endl;
    std::cout << "Valor do ponteiro: " << ponteiro << std::endl;
    std::cout << "Endereco do ponteiro: " << &ponteiro << std::endl;
    std::cout << "Valor apontado pelo ponteiro: " << *ponteiro << std::endl;

    return 0;
}