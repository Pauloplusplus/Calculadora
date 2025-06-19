#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int showMenu(){
    char option;
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
    scanf(" %c", &option); // espaço antes do %c é ESSENCIAL aqui
    return option - '0';   // converte o caractere numérico para inteiro
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
    printf("Resultado: %.2lf / %.2lf = %.2lf\n", a, b, r);
}

int main() {
    int option;

    do {
        option = showMenu();

        if(option < 1 || option > 5){
            printf("\nOpção inválida. Tente novamente.\n\n");
            continue;
        }

        if(option == 5) break;

        double a, b;
        printf("Digite o primeiro número: ");
        scanf("%lf", &a);
        printf("Digite o segundo número: ");
        scanf("%lf", &b);

        switch(option){
            case 1: sum(a, b); break;
            case 2: subtract(a, b); break;
            case 3: multiply(a, b); break;
            case 4: divide(a, b); break;
        }

        char op;
        printf("Você deseja realizar outra operação? (s ou n): ");
        scanf(" %c", &op); // também usa espaço para ignorar o '\n'
        while(tolower(op) != 's' && tolower(op) != 'n'){
            printf("Resposta inválida, você quer realizar outra operação (s ou n): ");
            scanf(" %c", &op);
        }

        if(tolower(op) != 's') break;
        system("cls"); // limpa a tela (pode não funcionar no GDB online)

    } while(1);

    printf("Adeus, obrigado por usar a calculadora :D\n");
    return 0;
}
