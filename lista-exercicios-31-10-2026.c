#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    
    system("clear");

    {
        /*
        Exercicio 01
        Faça um programa em C que leia um valor em metros e imprima o correspondente em decímetros, centímetros e milímetros.
        */
        printf("Exercicio 01\n");
        int one_meter = 1;
        printf("Metro = %d\n", one_meter);
        printf("Decímetros = %d\n", (one_meter*10));
        printf("Centímetros = %d\n", (one_meter*100));
        printf("Milímetros = %d\n", (one_meter*1000));
        printf("===================================\n");
    }

    {
        /*
        Exercicio 02
        Faça um programa que solicite um número decimal e imprima o correspondente em hexadecimal.
        */
        printf("Exercicio 02\n");
        int decimal_number = 10;
        printf("Decimal = %d\n", decimal_number);
        printf("Hexadecimal = 0x%X\n", decimal_number);
        printf("Octal = %O\n", decimal_number);
        printf("===================================\n");
    }

    {
        /*
        Exercicio 03
        Faça um programa em C que leia um valor em graus Fahrenheit e imprima o correspondente em graus Celsius: 
        a) Usando double: C = (f - 32.0) * (5.0/9.0) 
        b) Usando int: C = (f - 32) * (5/9)
        */
        printf("Exercicio 03\n");
        double temperature_fahrenheit = 15.7;
        double temperature_celsius = (temperature_fahrenheit - 32.0) * (5.0/9.0);
        printf("Double = %.2f\n", temperature_celsius);
        printf("===================================\n");
    }

    {
        /*
        Exercicio 04
        Faça um programa que solicite dois números e calcule: 
        a) Soma 
        b) Produto do primeiro pelo quadrado do segundo 
        c) Quadrado do primeiro d) Raiz quadrada da soma dos quadrados 
        e) Seno da diferença 
        f) Módulo do primeiro número
        */
        printf("Exercicio 04\n");
        double number01 = 13.50, number02 = 22.70;
        printf("Soma = %.2f\n", (number01+number02));
        printf("Produto do primeiro pelo segundo = %.2f\n", (number01*number02));
        printf("Quadrado do primeiro = %.2f\n", pow(number01, 2));
        printf("Raiz quadrada da soma dos quadrados = %2.f\n", sqrt((number01+number02)));
        printf("Seno da diferenca = %2.f\n", sin((number01-number02)));
        printf("Modulo do primeiro = %.2f\n", abs(number01));
        printf("===================================\n");
    }

    {
        /*
        Exercicio 05
        Faça um programa que leia dois valores e informe se o primeiro é menor, maior ou igual ao segundo.
        */ 
        printf("Exercicio 05\n");
        int number01 = 76, number02 = 85;
        char *isEqual = (number01 == number02) ? "Eh igual" : "Nao eh igual";
        char *isGreater = (number01 > number02) ? "Primeiro eh maior que o segundo" : "Primeiro eh menor que o segundo";
        printf("Numero 01 = %d | Number 02 = %d\n", number01, number02);
        printf("Sao iguais = %c\n", isEqual);
        printf("Qual eh o maior ? %c\n", isGreater);
        printf("===================================\n");
    }

    {
        /*
        Exercicio 06
        . Faça um programa que imprima a tabela ASCII (decimal, hexadecimal e caractere) de 0 a 127
        */
        printf("Exercicio 06\n");
        for(int index = 0; index < 127; index++) {
            if(index < 32 || index == 127) {
                printf("Caractere = [CONTROLE]");
            } else {
                char caractere = index;
                printf("Caractere = %c", caractere);
            }
            printf(" | Decimal = %02d | Hexadecimal = %02X\n", index, index);
        }
        printf("===================================\n");

        /*
        Explicacao: A tabela ASCII vai de 0 a 127, com caracteres que são imprimidos e alguns que não.
        O tipo char aceita números e, para aparecer o caractere em texto, basta formatar esse número indicando caractere
        */
    }

    int isValidInterval(float studentNote) {
        return ((0.0f <= studentNote) && (studentNote <= 10.0f)) ? 1 : 0;
    }

    double averageNote(float *studentNote1, float *studentNote2) {
        return ((*studentNote1 + *studentNote2)/2.0f);
    }

    {
        /*
            Exercicio 07
            Faça um programa que leia as notas de duas provas de um aluno (entre 0 e 10). Calcule a média do aluno.
        */
        printf("Exercicio 07\n");

        float note01 = 5.0;
        float note02 = 8.0;
        if (isValidInterval(note01) && isValidInterval(note02)) {
            double final = averageNote(&note01, &note02);
            printf("Final = %.2f\n", final);
        } else {
            printf("Valores invalidos\n");
        }
        
        printf("===================================\n");
    }
    return 0;
}