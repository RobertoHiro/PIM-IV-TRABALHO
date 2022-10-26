#include <stdio.h>
#include <locale.h>

typedef struct
{
   char rua[100];
   int numero;
   char bairro[100];
   char cidade[100];
   char estado[100];
   int CEP;
} Endereco;

typedef struct
{
    char nome[100];
    int idade;
    int cpf;
    int telefone;
    Endereco endereco;

} Paciente;

Paciente paciente;

void cadastrarPaciente(){
    setlocale (LC_ALL, "");

    printf("Digite o nome do/a paciente: ");
    gets(paciente.nome);

    printf("Digite o CPF do/a paciente: ");
    scanf("%i[^\n]",&paciente.cpf);
    getchar();

    printf("Digite a idade do/a paciente: ");
    scanf("%i[^\n]",&paciente.idade);
    getchar();

    printf("Digite o endereço do/a paciente \n");

    printf("Digite a rua do/a paciente: ");
    gets(paciente.endereco.rua);

    printf("Digite o número da rua do/a paciente: ");
    scanf("%i[^\n]",&paciente.endereco.numero);

    printf("Digite o bairro do/a paciente: ");
    gets(paciente.endereco.bairro);

    printf("Digite a cidade do/a paciente: ");
    gets(paciente.endereco.cidade);

    printf("Digite o estado do/a paciente: ");
    gets(paciente.endereco.estado);

    printf("Digite o CEP do/a paciente: ");
    scanf("%i[^\n]",&paciente.endereco.CEP);
    getchar();
    
    feedback();
}

void feedback(){
    printf("\n\nPaciente cadastrado\nNome: %s\nCPF: %s\nTelefone: %i\nRua: %s\nNúmero: %i\nBairro: %s\nCidade: %s\nEstado: %s\nCEP: %i", 
    paciente.nome, 
    paciente.cpf, 
    paciente.telefone, 
    paciente.endereco.rua, 
    paciente.endereco.numero, 
    paciente.endereco.bairro, 
    paciente.endereco.cidade, 
    paciente.endereco.estado, 
    paciente.endereco.CEP);

    getchar();
}

int main()
{
    cadastrarPaciente();
    return 0;
}