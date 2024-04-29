#include <stdio.h>
#include <stdlib.h>

int main(){
    const char *nomes[] = {"Miller", "Jones", "Anderson"};

    printf("%c\n", *(*(nomes+1)+2));
    printf("%c\n", nomes[1][2]);

    return 0;
}