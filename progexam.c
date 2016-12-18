#include "mylib.h"

int main() { 	
	
	//Utilizzate per l'inserimento di valori char che non sono utilizzati nella scelta 
		char sScelta[1];
		int nScelta;
	
	//Pulisce la schermata la prima volta che viene avviato il programma
		system("clear");
	
	//Ciclo infinito for che richiede ogni volta una scelta dell'utente
	for( ; ; ){
		
		//Variabile utilizzata per il rientro nella funzione crea_percorso nel caso in cui si voglia apportare delle modifiche 
			checkExit=0;
		
		//Stampa del menu principale e scansione della funzione richiesta
		printf("\n\n		 PROGEXAM - MENU PRINCIPALE\n\n");
		printf("   Scegli digitando il numero corrispondente sulla funzione che vuoi utilizzare \n\n");
		printf(" 1 - Crea percorso\n");
		printf(" 2 - Muovi Oberon\n");
		printf(" 3 - Termina gioco\n\n");
		printf (" la tua scelta > ");
		scanf("%s", &sScelta);
		
		//Conversione del valore string "sScelta" in int "nScelta" per controllare che l'utente abbia utilizzato valori validi
			nScelta=atoi(sScelta);
		
		switch (nScelta) {
			case 1:
				system("clear");
				crea_percorso();
				break;
			case 2:
				system("clear");
				muovi_Oberon();
				break;
			case 3:
				system("clear");
				termina_gioco();
				break;
			default:
				system("clear");
				printf("\a\n		********ERRORE********\n");
				printf("	 Inserire un numero compreso tra 1 e 3!\n\n\n");
				printf("\n - Premi ENTER per continuare -");
				while(getchar()!='\n');
					getchar();
				break;
		}
	}
}
