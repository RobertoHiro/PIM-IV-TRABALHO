#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

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
    int idade;
    char email;
    ObjData dataDoDiagnostico;
    int comorbidade;
} Paciente;

Paciente paciente;
char isComorbidade[];

char* registrosDeDiagnostico = "cadastro_de_diagnostico.txt";
char* registrosDePacienciaComComorbidade = "pacientes_com_comorbidade.txt";

struct tm* diaHoje;

void cadastrarPaciente(){
    setlocale (LC_ALL, "");

    printf("Digite o nome do/a paciente: ");
    scanf("%s[^\n]",&paciente.nome);
    getchar();

    printf("Digite o CPF do/a paciente: ");
    scanf("%d[^\n]",&paciente.cpf);
    getchar();

    printf("Digite o endereco do/a paciente \n");

    printf("Digite a rua do/a paciente: ");
    gets(&paciente.endereco.rua);

    printf("Digite o numero da rua do/a paciente: ");
    scanf("%d[^\n]",&paciente.endereco.numero);
    getchar();

    printf("Digite o bairro do/a paciente: ");
    gets(&paciente.endereco.bairro);

    printf("Digite a cidade do/a paciente: ");
    gets(&paciente.endereco.cidade);

    printf("Digite o estado do/a paciente: ");
    gets(&paciente.endereco.estado);

    printf("Digite o CEP do/a paciente: ");
    scanf("%d",&paciente.endereco.CEP);
    getchar();

    printf("Digite a data de nacimento(dia/mes/ano) do/a paciente: ");
    scanf("%d/%d/%d", &paciente.dataDeNacimento.dia, &paciente.dataDeNacimento.mes, &paciente.dataDeNacimento.ano);
    getchar();

    printf("Digite o e-mail do/a paciente: ");
    gets(&paciente.email);

    printf("Digite se o/a paciente tem comorbidade(S/N): ");
    scanf("%s", &isComorbidade);
    if(isComorbidade[0] == "S" || isComorbidade[0] == "s"){
        paciente.comorbidade = 1;
    }
    else{
        paciente.comorbidade = 0;
    }

    feedback();
}

void feedback(){
    age(paciente.dataDoDiagnostico.dia,
         paciente.dataDoDiagnostico.mes,
         paciente.dataDoDiagnostico.ano,
         paciente.dataDeNacimento.dia,
         paciente.dataDeNacimento.mes,
         paciente.dataDeNacimento.ano);
    printf("\nIdade do/a paciente eh: %d"),paciente.idade;
    salvarRegistro();
}

void salvarDadoComorbidade(){
    FILE *fptr;
    if(access(registrosDePacienciaComComorbidade, F_OK) == 0){
        fptr = fopen(registrosDePacienciaComComorbidade, "a");
    }else{
        fptr = fopen(registrosDePacienciaComComorbidade, "w+");
    }
    printf("\narquivo");
    printf("\nCEP%d", paciente.endereco.CEP);
    printf("\nIdade%d", paciente.idade);
    printf("\narquivo");
    fputs("CEP: ", fptr);
    fputs(paciente.endereco.CEP, fptr);
    fputs(" Idade: ", fptr);
    fputs(paciente.idade, fptr);
    fputs("\n", fptr);
    fclose(fptr);
    printf("\nregistro comorbidade salvo");
}

void salvarRegistro(){
    FILE *file;

    if(access(registrosDeDiagnostico, F_OK) == 0){
        file = fopen(registrosDeDiagnostico, "a");
    }else{
        file = fopen(registrosDeDiagnostico, "w+");
    }

    fputs("Nome: ", file);
    fputs(paciente.nome, file);
    fputs(" CPF: ", file);
    fputs(paciente.cpf, file);
    fputs(" Telefone: ", file);
    fputs(paciente.telefone, file);
    fputs(" Rua: ", file);
    fputs(paciente.endereco.rua, file);
    fputs(" Número: ", file);
    fputs(paciente.endereco.numero, file);
    fputs(" Bairro: ", file);
    fputs(paciente.endereco.bairro, file);
    fputs(" Cidade: ", file);
    fputs(paciente.endereco.cidade, file);
    fputs(" Estado: ", file);
    fputs(paciente.endereco.estado, file);
    fputs(" CEP: ", file);
    fputs(paciente.endereco.CEP, file);
    fputs("\n", file);
    fclose(file);
    printf("\nregistro salvo");

    printf("\n%d",paciente.comorbidade);

    if(paciente.comorbidade == 1){
        salvarDadoComorbidade();
    }else if(paciente.idade > 65){
        salvarDadoComorbidade();
    }
}

void age(int present_date, int present_month, int present_year, int birth_date, int birth_month, int birth_year) {
   int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if (birth_date > present_date) {
      present_date = present_date + month[birth_month - 1];
      present_month = present_month - 1;
   }
   if (birth_month > present_month) {
      present_year = present_year - 1;
      present_month = present_month + 12;
   }
   int final_date = present_date - birth_date;
   int final_month = present_month - birth_month;
   int final_year = present_year - birth_year;
   //printf("Present Age Years: %d Months: %d Days: %d", final_year, final_month, final_date);
   paciente.idade = final_year;
}

void main(){
    SYSTEMTIME t;
    GetLocalTime(&t);
    printf("Data do diagnostico: %d/%d/%d\n", t.wDay, t.wMonth, t.wYear);
    paciente.dataDoDiagnostico.dia= t.wDay;
    paciente.dataDoDiagnostico.mes= t.wMonth;
    paciente.dataDoDiagnostico.ano= t.wYear;
    cadastrarPaciente();
}
