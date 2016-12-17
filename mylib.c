#include "mylib.h"

//Definizione variabili globali (in mylib.c)
static struct sTerra *percorso = NULL;

static struct sTerra *ultimaTerra = NULL;

static sOberon myOberon;

//Prototipi funzioni creaPercorso
static void insTerra();
static void cancTerra();
static void stampaPercorso();
static void chiudiPercorso();

//Prototipi funzioni creaPercorso
static void avanza();
static void prendiTesoro();
static void usaPozione();
static void combatti();
static void distruggiTerra();

// Definizione funzione creaPercorso
void creaPercorso() {
	int sc;
	printf("Benvenuti nella funzione crea percorso!\n\n0 - Inserisci terra\n1 - Cancella terra\n2 - Stampa percorso\n3 - Chiudi percorso\n");
	scanf("%d", &sc);
	if (sc == 1) {
		insTerra();
	}
	
}

// Definizione funzione muoviOberon
void muoviOberon() {

}

// Definizione funzione terminaGioco
void terminaGioco() {
	exit(0);
}

// Definizione funzione illegalChoice
void illegalChoice() {
	system("cls");
	printf("ERRORE FATALE\n");
	printf("Valore non consentito!\n");
	system("pause");
	system("cls");
}

static void insTerra() {
	printf("Test");
	system("pause");
}
