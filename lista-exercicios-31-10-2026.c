#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int isValidInterval(float studentNote)
{
    return ((0.0f <= studentNote) && (studentNote <= 10.0f)) ? 1 : 0;
}

double averageNote(float *studentNote1, float *studentNote2)
{
    return ((*studentNote1 + *studentNote2) / 2.0f);
}

int sum(int number01, int number02)
{
    return (int)number01 + number02;
}

int subtraction(int number01, int number02)
{
    return (int)number01 - number02;
}

float averageNotess(float allNotes[5], int totalNotes)
{
    int answer = 0;
    for (int index = 0; index < totalNotes; index++)
    {
        printf("Nota [%d] = %.2f\n", index, allNotes[index]);
        answer += allNotes[index];
    }
    return (float)answer / totalNotes;
}

double poW(int number, int expoent)
{

    if (expoent == 0)
    {
        return 1.0;
    }

    if (number == 0)
    {
        return 0.0;
    }

    if (number == 1 || expoent == 1)
    {
        return (double)number;
    }

    double answer = 1.0;
    int exp_abs = expoent < 0 ? -expoent : expoent;

    for (int index = 0; index < exp_abs; index++)
    {
        answer *= number;
    }

    if (expoent < 0)
    {
        return 1.0 / answer;
    }

    return answer;
}

int isOkay(char condition[3]){
    if(strcmp(condition, "SIM") == 0){
        return 1;
    } else if (strcmp(condition, "NAO") == 0){
        return 0;
    } else {
        return -1;
    }
}

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
        printf("Decímetros = %d\n", (one_meter * 10));
        printf("Centímetros = %d\n", (one_meter * 100));
        printf("Milímetros = %d\n", (one_meter * 1000));
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
        printf("Octal = %o\n", decimal_number);
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
        double temperature_celsius = (temperature_fahrenheit - 32.0) * (5.0 / 9.0);
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
        printf("Soma = %.2f\n", (number01 + number02));
        printf("Produto do primeiro pelo segundo = %.2f\n", (number01 * number02));
        printf("Quadrado do primeiro = %.2f\n", pow(number01, 2));
        printf("Raiz quadrada da soma dos quadrados = %.2f\n", sqrt(pow(number01, 2) + pow(number02, 2)));
        printf("Seno da diferenca = %.2f\n", sin((number01 - number02)));
        printf("Modulo do primeiro = %.2f\n", fabs(number01));
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
        printf("Sao iguais = %s\n", isEqual);
        printf("Qual eh o maior ? %s\n", isGreater);
        printf("===================================\n");
    }

    {
        /*
        Exercicio 06
        . Faça um programa que imprima a tabela ASCII (decimal, hexadecimal e caractere) de 0 a 127
        */
        printf("Exercicio 06\n");
        for (int index = 0; index < 127; index++)
        {
            if (index < 32 || index == 127)
            {
                printf("Caractere = [CONTROLE]");
            }
            else
            {
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

    {
        /*
            Exercicio 07
            Faça um programa que leia as notas de duas provas de um aluno (entre 0 e 10). Calcule a média do aluno.
        */
        printf("Exercicio 07\n");

        float note01 = 5.0;
        float note02 = 8.0;
        if (isValidInterval(note01) && isValidInterval(note02))
        {
            double final = averageNote(&note01, &note02);
            printf("Final = %.2f\n", final);
        }
        else
        {
            printf("Valores invalidos\n");
        }

        printf("===================================\n");
    }

    {
        /*
        Exercicio 08
        Faça um programa que leia dois números e utilize funções soma() e subtracao() para exibir os resultados
        */
        printf("Exercicio 08\n");
        int number01 = 127;
        int number02 = 256;
        printf("Soma      = %d + %d = %d\n", number01, number02, sum(number01, number02));
        printf("Subtracao = %d + %d = %d\n", number01, number02, subtraction(number01, number02));
        printf("===================================\n");
    }

    {
        /**
         * Exercicio 09
         * Implemente uma função que calcule a potência: f(x, n) = x^n
         */
        printf("Exercicio 09\n");
        int base = 10;
        int expoent = 0;
        printf("Potencia = %d ^ %d = %0.f\n", base, expoent, poW(base, expoent));

        expoent = 1;
        printf("Potencia = %d ^ %d = %0.f\n", base, expoent, poW(base, expoent));

        base = 0;
        expoent = 2;
        printf("Potencia = %d ^ %d = %0.f\n", base, expoent, poW(base, expoent));

        base = 2;
        expoent = 2;
        printf("Potencia = %d ^ %d = %0.f\n", base, expoent, poW(2, 2));
        printf("===================================\n");
    }

    {
        /*
            Exercicio 10
            Simule o programa a seguir e informe o que cada valor impresso representa.
        */
        printf("Exercicio 10\n");
        int x = 10;
        int *y = &x;
        printf("x  = %d\n", x);
        printf("GEM - &x = %p\n", (void *)&x);
        printf("GEM - y  = %p\n", (void *)y);
        printf("GEM - &y = %p\n", (void *)&y);
        printf("*y = %d\n", *y);
        printf("===================================\n");
    }

    {
        /*
        Exercicio 11
        Faça uma função que receba um array de 5 notas e retorne a média.
        */
        printf("Exercicio 11\n");
        float allNotes[5] = {10.0, 7.25, 8.50, 4.75, 5.90};
        int size = sizeof(allNotes) / sizeof(allNotes[0]);
        printf("Media de notas = %.2f\n", averageNotess(allNotes, size));
        printf("===================================\n");
    }

    {
        /*
        Exercicio 12
        Faça um programa que leia uma string (até 80 caracteres) e informe:
        - Quantidade de caracteres
        - Quantidade de pontuação
        - Quantidade de números
        - Quantidade de letras minúsculas
        */
        printf("Exercicio 12\n");
        char text[81] = "Hoje e dia 06/11/2026! Vamos testar o codigo de C com 80 caracteres exatos agora.";
        char caracter;
        int countPontuation = 0;
        int countCharacter = 0;
        int countNumbers = 0;
        int countMinorLetters = 0;
        for (int index = 0; index < 81; index++)
        {

            caracter = text[index];

            if (caracter == '\n')
            {
                continue;
            }

            if (caracter == '\0')
            {
                break;
            }

            countCharacter++;

            if (32 < caracter)
            {

                if (caracter >= '0' && caracter <= '9')
                {
                    countNumbers++;
                    continue;
                }

                if (caracter >= 'a' && caracter <= 'z')
                {
                    countMinorLetters++;
                    continue;
                }

                if (((32 < caracter) && (caracter < 48)) ||
                    ((57 < caracter) && (caracter < 65)) ||
                    ((90 < caracter) && (caracter < 97)) ||
                    ((122 < caracter) && (caracter < 127)))
                {
                    countPontuation++;
                }
            }
        }

        printf("Quantidade de caracteres: %d\n", countCharacter);
        printf("Quantidade de pontuacao: %d\n", countPontuation);
        printf("Quantidade de numeros: %d\n", countNumbers);
        printf("Quantidade de letras minusculas: %d\n", countMinorLetters);
        printf("===================================\n");
    }

    {
        /*
        Exercicio 13
        Leia uma string com palavras separadas por espaço e imprima cada palavra em uma linha.
        */
        printf("Exercicio 13\n");
        char string[] = "palavras separadas por espaco";
        char space = ' ';
        char end = '\0';
        char eachChar = 0;
        char substring[sizeof(string)];

        for (int indexString = 0, indexSubstring = 0; (indexString < sizeof(string)); indexString++)
        {

            eachChar = string[indexString];

            int isSpace = (eachChar == space) || (eachChar == end) ? 1 : 0;

            switch (isSpace)
            {
            case 0:
                substring[indexSubstring++] = string[indexString];
                // printf("Montando = %s\n", substring);
                break;

            case 1:
                substring[indexSubstring] = '\0';
                printf("Palavra encontrada = %s\n", substring);
                indexSubstring = 0;
                substring[0] = '\0';
                break;

            default:
                printf("Condição inválida");
                break;
            }
        }
        printf("===================================\n");
    }

    {
        /*
        Exercicio 14
        Leia nome, endereço, telefone e idade e monte uma frase com essas informações.
        */
        printf("Exercicio 14\n");

        // char name[50];
        // char address[100];
        // char phone[20];
        // int age;

        // printf("Type ur name: ");
        // fgets(name, sizeof(name), stdin);
        // name[strcspn(name, "\n")] = '\0';

        // printf("Type ur address: ");
        // fgets(address, sizeof(address), stdin);
        // address[strcspn(address, "\n")] = '\0';

        // printf("Type ur phone: ");
        // fgets(phone, sizeof(phone), stdin);
        // phone[strcspn(phone, "\n")] = '\0';

        // printf("Type ur age: ");
        // scanf("%d", &age);

        // printf("\nMy name is %s, live in %s, my phone is %s and I am %d years old.\n", name, address, phone, age);
        printf("===================================\n");
    }

    {
        /*
        Exercicio 15
        Crie uma função que retorne 1 para 'SIM' e 0 para 'NAO'.
        */
        printf("Exercicio 15\n");
        char sim[3] = "SIM";
        printf("Esta tudo bem: %d\n", isOkay(sim));
        char nao[3] = "NAO";
        printf("Nao esta tudo bem: %d\n", isOkay(nao));
        char lol[3] = "lol";
        printf("Tanto faz: %d\n", isOkay(lol));
        printf("===================================\n");
    }
    return 0;
}