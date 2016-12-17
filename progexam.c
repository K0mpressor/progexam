#include "mylib.h"

void main() {
	int scelta;
	char conferma;
	while (1) {
		printf("PROGEXAM - MENU PRINCIPALE\n\n1 - Crea percorso\n2 - Muovi Oberon\n3 - Termina gioco\n\n");
		scanf("%d", &scelta);
		switch (scelta) {
		case 1:
			system("cls");
			creaPercorso();
			system("cls");
			break;
		case 2:
			system("cls");
			printf("Muovi Oberon\n");
			break;
		case 3:
			//ToDo: implementare funzione termina_gioco
			system("cls");
			printf("Sei sicuro di uscire? (y/n)\n");
			scanf(" %c", &conferma);
			do {
				switch (conferma) {
				case 'y':
					terminaGioco();
					break;
				case 'n':
					break;
				default:
					illegalChoice();
					break;
				}
			} while (conferma == 'y' || conferma == 'n');
			break;
		default:
			illegalChoice();
			break;
		}
	}
}
