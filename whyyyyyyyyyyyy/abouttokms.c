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
	//printf(" \nA inicializa��o foi feita com sucesso!");
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
		printf("Digite a data de aplica��o:\n");
		scanf(" %s", peopleList[v].date);
		fflush(stdin);

		//	N�MERO DE LOTE
		printf("Digite o n�mero de lote:\n");
		scanf(" %ld", &peopleList[v].lotNumber);
		fflush(stdin);

		v += 1;
		x = false;
	}
	//printf(" %d", v);
}

void listVaccinedPeople(void) {
	for (int i = 0; i < 10; i++) {
		printf(" \n C�digo: %d", peopleList[i].id);
		printf(" \n Nome: %s", peopleList[i].name);
		printf(" \n CPF: %s", peopleList[i].cpf);
		printf(" \n Vacina aplicada: %s", peopleList[i].vaccine);
		printf(" \n Data de aplica��o: %s", peopleList[i].date);
		printf(" \n N�mero de lote: %ld", peopleList[i].lotNumber);
		printf(" \n ===============================================");
	};
};

void cpfSearch(char arry[15]) {
	for (int i = 0; i < 10; i++) {
		int teste = strcmp(peopleList[i].cpf, arry);
		if (teste == 0) {
			printf(" \n C�digo: %d", peopleList[i].id);
			printf(" \n Nome: %s", peopleList[i].name);
			printf(" \n CPF: %s", peopleList[i].cpf);
			printf(" \n Vacina aplicada: %s", peopleList[i].vaccine);
			printf(" \n Data de aplica��o: %s", peopleList[i].date);
			printf(" \n N�mero de lote: %ld", peopleList[i].lotNumber);
			printf(" \n ===============================================");
		}
		else {
			printf(" \n CPF n�o encontrado.");
		};
	};
};

void mainMenu(void) {
	bool goon = 1;
	while (goon) {
		int menuOption = 0;
		printf("\n1 - Cadastrar vacina\n");
		printf("2 - Listar aplica��es\n");
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
			printf("Escolha inv�lida.");
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