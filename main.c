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
    fgets(&nome,100, stdin);
    //getchar();

    printf("Digite a idade do/a paciente: ");
    scanf("%d[^\n]",&idade);
    getchar();

    printf("Digite o enderešo do/a paciente: ");
    fgets(&endereco, 100, stdin);
    getchar();

    //scanf("%s %d %s", nome, idade, endereco);

    printf("\nPaciente: %sIdade: %d\nEnderešo: %s", nome, idade, endereco);


    getchar();
}
