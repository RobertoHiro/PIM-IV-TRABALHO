#include <stdio.h>
#include <locale.h>

typedef struct{
   char rua[100];
   int numero;
   char bairro[100];
   char cidade[100];
   char estado[100];
   int CEP;
} Endereco;

typedef struct{
    int dia;
    int mes;
    int ano;
} ObjData;

typedef struct{
    char nome[100];
    int cpf;
    int telefone;
    Endereco endereco;
    ObjData dataDeNacimento;
    char email;
    ObjData dataDoDiagnostico;
    bool comorbidade;
} Paciente;

Paciente paciente;
char isComorbidade;

void cadastrarPaciente(){
    setlocale (LC_ALL, "");

    printf("Digite o nome do/a paciente: ");
    gets(paciente.nome);

    printf("Digite o CPF do/a paciente: ");
    scanf("%i[^\n]",&paciente.cpf);
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

    printf("Digite a data de nacimento(dia/mes/ano) do/a paciente: ");
    scanf("%d/%d/%d", paciente.dataDeNacimento.dia, paciente.dataDeNacimento.mes, paciente.dataDeNacimento.ano);
    getchar();

    printf("Digite o e-mail do/a paciente: ");
    gets(paciente.email);

    printf("Digite a data do diagnóstico(dia/mes/ano): ");
    scanf("%d/%d/%d", paciente.dataDoDiagnostico.dia, paciente.dataDoDiagnostico.mes, paciente.dataDoDiagnostico.ano);
    getchar();

    printf("Digite se o/a paciente tem comorbidade(S/N): ");
    scanf("%s", isComorbidade);
    if(toUpper(isComorbidade) == "S"){
        paciente.comorbidade == true;
    }
    else{
        paciente.comorbidade == false;
    }
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

void salvarRegistro(){

}

int main(){
    cadastrarPaciente();
    return 0;
}