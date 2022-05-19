#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

struct vaccineRegister {
	int id;
	char name[26];
	char cpf[15];
	char vaccine[15];
	char date[11];
	long int lotNumber;
};

struct vaccineRegister peopleList[10];
int v = 0;
char cpfForSearch[14] = { "NULL" };

void peopleListInitialization(void) {
	for (int i = 0; i < 10; i++) {
		peopleList[i].id = 0;
		strncpy(peopleList[i].name, "NULL", 4);
		strncpy(peopleList[i].cpf, "XXX.XXX.XXX-XX", 14);
		strncpy(peopleList[i].vaccine, "NULL", 4);
		strncpy(peopleList[i].date, "NULL", 4);
		peopleList[i].lotNumber = 0;
	};
	//printf(" \nA inicialização foi feita com sucesso!");
};

void registerVaccine(void) { //	CADASTRO
	bool x;

	x = true;
	while (x) {
		//	ID
		peopleList[v].id = v;

		//	NOME
		printf("Digite o nome:\n");
		scanf(" %s", peopleList[v].name);
		fflush(stdin);

		//	CPF
		printf("Digite o CPF:\n");
		scanf(" %s", peopleList[v].cpf);
		fflush(stdin);

		//	VACINA
		printf("Digite a vacina utilizada:\n");
		scanf(" %s", peopleList[v].vaccine);
		fflush(stdin);

		//	DATA
		printf("Digite a data de aplicação:\n");
		scanf(" %s", peopleList[v].date);
		fflush(stdin);

		//	NÚMERO DE LOTE
		printf("Digite o número de lote:\n");
		scanf(" %ld", &peopleList[v].lotNumber);
		fflush(stdin);

		v += 1;
		x = false;
	}
	//printf(" %d", v);
}

void listVaccinedPeople(void) {
	for (int i = 0; i < 10; i++) {
		printf(" \n Código: %d", peopleList[i].id);
		printf(" \n Nome: %s", peopleList[i].name);
		printf(" \n CPF: %s", peopleList[i].cpf);
		printf(" \n Vacina aplicada: %s", peopleList[i].vaccine);
		printf(" \n Data de aplicação: %s", peopleList[i].date);
		printf(" \n Número de lote: %ld", peopleList[i].lotNumber);
		printf(" \n ===============================================");
	};
};

void cpfSearch(char arry[15]) {
	for (int i = 0; i < 10; i++) {
		int teste = strcmp(peopleList[i].cpf, arry);
		if (teste == 0) {
			printf(" \n Código: %d", peopleList[i].id);
			printf(" \n Nome: %s", peopleList[i].name);
			printf(" \n CPF: %s", peopleList[i].cpf);
			printf(" \n Vacina aplicada: %s", peopleList[i].vaccine);
			printf(" \n Data de aplicação: %s", peopleList[i].date);
			printf(" \n Número de lote: %ld", peopleList[i].lotNumber);
			printf(" \n ===============================================");
		}
		else {
			printf(" \n CPF não encontrado.");
		};
	};
};

void mainMenu(void) {
	bool goon = 1;
	while (goon) {
		int menuOption = 0;
		printf("\n1 - Cadastrar vacina\n");
		printf("2 - Listar aplicações\n");
		printf("3 - Consulta por CPF\n");
		printf("4 - Sair\n");
		scanf(" %d", &menuOption);

		switch (menuOption) {
		case 1:
			registerVaccine();
			break;
		case 2:
			listVaccinedPeople();
			break;
		case 3:
			printf("Insira o CPF para consulta: ");
			scanf(" %s", cpfForSearch);
			cpfSearch(cpfForSearch);
			break;
		case 4:
			goon = 0;
			break;
		default:
			printf("Escolha inválida.");
			break;
		}
	};
};

int main() {

	setlocale(LC_ALL, "Portuguese");

	peopleListInitialization();
	mainMenu();

	return 0;
}