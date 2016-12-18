#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crea_percorso();

void muovi_Oberon();

void termina_gioco();

typedef enum tipo_terra{
	deserto=1, 
	foresta,
	palude, 
	villaggio, 
	pianura
} eTipo_terra;

typedef enum tipo_mostro{
	nessuno=1, 
	scheletro, 
	lupo, 
	orco, 
	drago
} eTipo_mostro;

struct sOberon{
	short borsa_oro;
	short punti_ferita;
	short incantesimi;
	short pozione_guaritrice;
};

struct sTerra{
	eTipo_terra tipo_terra;
	eTipo_mostro tipo_mostro;
	short tesoro;
	struct sTerra* terra_successiva;
};

//Variabile globale che esce dal menu crea_percorso e ritorna a progexam
short int checkExit;
