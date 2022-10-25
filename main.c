#include <stdio.h>
#include <locale.h>

char nome[100];
int idade;
char endereco[100];

int main()
{
    cadastrarPaciente();
    return 0;
}

void cadastrarPaciente(){
    //setlocale (LC_ALL, "");
    printf("Digite o nome do/a paciente: ");
    gets(nome);
    //getchar();

    printf("Digite a idade do/a paciente: ");
    scanf("%d[^\n]",&idade);
    getchar();

    printf("Digite o endereço do/a paciente: ");
    gets(endereco);
    //getchar();

    //scanf("%s %d %s", nome, idade, endereco);

    printf("\n\nPaciente: %s\nIdade: %d\nEndereço: %s", nome, idade, endereco);


    getchar();
}
