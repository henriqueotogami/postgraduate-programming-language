#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    {
        // Exercicio 01
        int one_meter = 1;
        printf("Metro = %d\n", one_meter);
        printf("Decímetros = %d\n", (one_meter*10));
        printf("Centímetros = %d\n", (one_meter*100));
        printf("Milímetros = %d\n", (one_meter*1000));
    }

    {
        // Exercicio 02
        int decimal_number = 10;
        printf("Decimal = %d\n", decimal_number);
        printf("Hexadecimal = 0x%X\n", decimal_number);
        printf("Octal = %O\n", decimal_number);
    }

    {
        // Exercicio 03
        double temperature_fahrenheit = 15.7;
        double temperature_celsius = (temperature_fahrenheit - 32.0) * (5.0/9.0);
        printf("Double = %.2f\n", temperature_celsius);
    }

    {
        // Exercicio 04
        double number01 = 13.50, number02 = 22.70;
        printf("Soma = %.2f\n", (number01+number02));
        printf("Produto do primeiro pelo segundo = %.2f\n", (number01*number02));
        printf("Quadrado do primeiro = %.2f\n", pow(number01, 2));
        printf("Raiz quadrada da soma dos quadrados = %2.f\n", sqrt((number01+number02)));
        printf("Seno da diferenca = %2.f\n", sin((number01-number02)));
        printf("Modulo do primeiro = %.2f\n", abs(number01));
    }

    {
        // Exercicio 05
        int number01 = 76, number02 = 85;
        char *isEqual = (number01 == number02) ? "Eh igual" : "Nao eh igual";
        char *isGreater = (number01 > number02) ? "Primeiro eh maior que o segundo" : "Primeiro eh menor que o segundo";
        printf("Numero 01 = %d\n | Number 02 = %d\n", number01, number02);
        printf("Sao iguais = %c\n", isEqual);
        printf("Qual eh o maior ? %c\n", isGreater);
    }
    return 0;
}