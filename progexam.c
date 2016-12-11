#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
	int scelta;
	do
	{
		printf("PROGEXAM - MENU PRINCIPALE\n\n");
		printf("1 - Crea percorso\n");
		printf("2 - Muovi Oberon\n");
		printf("3 - Termina gioco\n\n");
		scanf("%d", &scelta);
		switch (scelta) {
		case 1:
			system("clear");
			printf("Crea percorso\n");
      //ToDo: implementare funzione crea_percorso
			pause();
			break;
		case 2:
			system("clear");
			printf("Muovi Oberon\n");
       //ToDo: implementare funzione muovi_Oberon
			pause();
			break;
		case 3:
			 //ToDo: implementare funzione termina_gioco
			break;
		default:
			system("clear");
			printf("ERRORE\n");
			printf("Inserire un numero compreso tra 1 e 3!\n");
			pause();
			system("clear");
			break;
		}
	} while (scelta <1 || scelta >3);
}
