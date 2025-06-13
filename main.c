/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 #include <stdlib.h>
#include <ctype.h>

int showMenu(){
    int option;
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");
    scanf("%d", &option);
    return option;
}

void sum (double a, double b){
    double r = a + b;
    printf("Resultado: %.2lf + %.2lf = %.2lf\n", a, b, r);
}

void subtract (double a, double b){
    double r = a - b;
    printf("Resultado: %.2lf - %.2lf = %.2lf\n", a, b, r);
}

void multiply (double a, double b){
    double r = a * b;
    printf("Resultado: %.2lf x %.2lf = %.2lf\n", a, b, r);
}

void divide (double a, double b){
    if(b == 0){
        printf("Erro: Divisão por zero não é permitida.\n");
        return;
    }
    double r = a / b;
    printf("Resultado: %lf / %lf = %.2lf\n", a, b, r);
}

int main()
{
    int option = showMenu();
    while(option != 5){
        if(option < 1 || option > 5 || option == EOF){
            printf("Opção inválida, coloque uma opção válida.\n");
            option = showMenu();
            continue;
        }
        
        double a, b;
        printf("Digite o primeiro número: ");
        scanf("%lf", &a);
        printf("Digite o segundo número: ");
        scanf("%lf", &b);
        switch(option){
            case 1 :
            sum(a, b);
            break;
            case 2 :
            subtract(a, b);
            break;
            case 3 :
            multiply(a, b);
            break;
            case 4 :
            divide(a, b);
            break;
        }
        
        char op;
        printf("Você deseja realizar outra operação? (s ou n) ");
        scanf("%c", &op);
        while(tolower(op) != 's' && tolower(op) != 'n'){
            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não: ");
            scanf("%c", &op);
        }
        
        if(tolower(op) == 's'){
            system("cls");
        } else {
            break;
        }
        option = showMenu();
    }

    printf("Adeus, obrigado por usar a calculadora :D");
    return 0;
}
