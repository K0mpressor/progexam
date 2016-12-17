#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum tipoTerra {
	deserto = 1,
	foresta,
	palude,
	villaggio,
	pianura
} eTipoTerra;

typedef enum tipoMostro {
	nessuno = 1,
	scheletro,
	lupo,
	orco,
	drago
} eTipoMostro;

typedef struct oberon {
	unsigned short borsaOro;
	unsigned short puntiFerita;
	unsigned short incantesimi;
	unsigned short pozioneGuaritrice;
} sOberon;

typedef struct terra {
	eTipoTerra tipoTerra;
	eTipoMostro tipoMostro;
	unsigned short tesoro;
	/*sTerra *terraSuccessiva;*/
} sTerra;

void creaPercorso();

void muoviOberon();

void terminaGioco();

void illegalChoice();
