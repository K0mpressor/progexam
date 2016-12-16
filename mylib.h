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
} Tipo_terra;

typedef enum tipo_mostro{
	nessuno=1, 
	scheletro, 
	lupo, 
	orco, 
	drago
} Tipo_mostro;

typedef struct oberon{
	short borsa_oro;
	short punti_ferita;
	short incantesimi;
	short pozione_guaritrice;
} Oberon;

struct Terra{
	Tipo_terra tipo_terra;
	Tipo_mostro tipo_mostro;
	short tesoro;
	struct Terra* terra_successiva;
};

//Variabile globale che esce dal menu crea_percorso e ritorna a progexam
short int checkExit;


