#include "mylib.h"

//Dichiaro le struttire statiche valide solo in mylib.c
static struct Terra* percorso = NULL;

static struct Terra* ultima_terra = NULL;

extern struct Oberon oberon;


//Dichiaro le funzioni da richiamare nei sotto menu'

	//Funzioni del sottomenù crea_percorso()
	static struct Terra *ins_terra(struct Terra* p);
	static struct Terra *del_terra(struct Terra* p);
	static void stampa_percorso(struct Terra* p);
	static struct Terra *chiudi_percorso(struct Terra* p);

	//Funzioni del sottomenù muovi_Oberon()
	static struct Oberon *avanza(struct Oberon* l);
	static struct Oberon *prendi_tesoro(struct Oberon* l);
	static struct Oberon *usa_pozione(struct Oberon* l);
	static struct Oberon *combatti(struct Oberon* l);
	static struct Terra *distruggi_terra(struct Terra* p, struct Oberon* l);


//Funzione sub_main per la creazione del percorso
void crea_percorso()
{// crea_percorso() - OPEN
	
	//Variabili utilizzate nella scelta del sub menu
	static int nScelta_sub;
	static char sScelta_sub[1];
	
	
	for ( ; ; )
	{	
		if (checkExit!=0){
			return;
		}
		
		
		printf("\n--------------FUNZIONE CREA PERCORSO--------------");
		printf("\n      Cosa vuoi fare?\n\n");
		printf("1 - Inserire terreno\n");
		printf("2 - Cancellare terreno\n");
		printf("3 - Mostra terreno\n");
		printf("4 - Chiudi percorso\n");
		printf("\n  > la tua scelta ");
		
		scanf("%s", &sScelta_sub);
		nScelta_sub=atoi(sScelta_sub);
		
		switch (nScelta_sub) {
			case 1:
				system("clear");
				percorso=ins_terra(percorso);
				break;
				
			case 2:
				system("clear");
				ultima_terra=del_terra(ultima_terra);
				break;
		
			case 3:
				system("clear");
				stampa_percorso(percorso);
				break;
		
			case 4:
				system("clear");
				ultima_terra=chiudi_percorso(ultima_terra);
				break;
		
			default:
				system("clear");
				printf("\a********ERRORE********\n");
				printf("Inserire un numero compreso tra 1 e 4!\n\n");
				printf("\n - Premi ENTER per continuare -");
				while(getchar()!='\n');
				getchar();
				break;
			}
		}
	}

	
//Funzione sub_main per l'utilizzo di Oberon
void muovi_Oberon()
{// muovi_Oberon() - OPEN
	
	//Variabili utilizzate nella scelta del sub menu
	static int nScelta_sub;
	static char sScelta_sub[1];
	
	
	for ( ; ; )
	{
		printf("\n--------------FUNZIONE DI MOVIMENTO OBERON--------------");
		printf("\nCosa vuoi fare?\n\n");
		printf("1 - Avanzare\n");
		printf("2 - Prendere il tesoro\n");
		printf("3 - Usare una pozione\n");
		printf("4 - Combattere\n");
		printf("5 - Distruggere un terreno\n");
		scanf("%s", &sScelta_sub);
		nScelta_sub=atoi(sScelta_sub);
	
		switch (nScelta_sub) {
			case 1:
				system("clear");
				//Oberon=avanza(Oberon);
				break;
			case 2:
				system("clear");
				//Oberon=prendi_tesoro(Oberon);
				break;
		
			case 3:
				system("clear");
				//Oberon=usa_pozione(Oberon);
				break;
		
			case 4:
				system("clear");
				//Oberon=combatti(Oberon);
				break;
			
			case 5:
				system("clear");
				//percorso=distruggi_terra(percorso, oberon);
				break;
		
			default:
				system("clear");
				printf("\a********ERRORE********\n");
				printf("Inserire un numero compreso tra 1 e 4!\n\n");
				printf("\n - Premi ENTER per continuare -");
				while(getchar()!='\n');
				getchar();
				break;
		}
	}
}


//Funzione sub_main per terminare il gioco liberando la memoria utilizzata e uscendo
void termina_gioco()
{// termina_gioco() - OPEN
	system("clear");
	printf("--------------------------");
	printf("\n          Termino!");
	printf("\n--------------------------");
	exit(0);
}


//----------------------------------FUNZIONI SOTTOMENU'----------------------------------

//-------------FUNZIONI SU TERRA-------------

//Funzione di inserimento terra
struct Terra *ins_terra(struct Terra* p)
{// *ins_terra() - OPEN
	
	//Inizializzo il random
	time_t t;
	srand((unsigned) time(&t));
	
	short tesoro;
	struct Terra *terra_successiva;
	
	if(percorso==NULL){
		
		//Alloco memoria di dimensione struct Terra a percorso
		percorso = (struct Terra *)malloc(sizeof(struct Terra));
		
		//Al membro terra_successiva dello struct percorso assegno il valore di p
		percorso->terra_successiva = p;
		do{
			system("clear");
			printf("Che tipo di terra vuoi?\n\n");
			printf("\n1 - deserto\n2 - foresta\n3 - Palude\n4 - villaggio\n5 - Pianura ");
			printf("\n > inserire scelta: ");
			scanf ("%u", &(percorso->terra_successiva->tipo_terra)); 	//terra_successiva->tipo_terra senza int %u   // da prof : &((int)(p->tipo_terra)))
		}while((p->tipo_terra)<1 || (p->tipo_terra)>5);
			
		ultima_terra=p;
		
		p->terra_successiva=NULL;
		return(0);
	}
	else{
		
		//Al membro terra_successiva di ultima_terra alloco memoria di dimensione struct Terra
		ultima_terra->terra_successiva=(struct Terra *)malloc(sizeof(struct Terra));
		
		//Ad ultima terra ora assegno il membro terra_successiva di ultima_terra
		ultima_terra=ultima_terra->terra_successiva;
		
		
		p = (struct Terra *)malloc(sizeof(struct Terra)); //NOT SURE - (non necessario?)
			
		//p->terra_successiva = NULL;              NOT SURE
		
		//A terra_successiva imposto il puntatore p per poter lavorare con la prossima Terra	
		terra_successiva=p;
		
		//        NOT AS b4
			ultima_terra=p;
		
		printf("\n\nChe tipo di terra vuoi?");
		printf("\n1 - deserto\n2 - foresta\n3 - Palude\n4 - villaggio\n5 - Pianura");
		printf("\n > inserire scelta: ");
		scanf ("%u", &((p->terra_successiva->tipo_terra))); //terra_successiva->tipo_terra senza int %u  // da prof : &((int)etc...
			
			
		printf("\n\n\nChe tipo di mostro vuoi?");
		printf("\n1 - nessuno\n2 - scheletro\n3 - lupo\n4 - orco\n5 - drago");
		printf("\n > inserire scelta: ");
		scanf ("%u", &((p->terra_successiva->tipo_mostro))); //terra_successiva->tipo_mostro senza int %u   // da prof : &((int)etc...
		
		//ultima_terra=p;
	}
	return(terra_successiva);
}

//Funzione di cancellazione del terreno creato
struct Terra *del_terra(struct Terra* p)
{// *del_terra() - OPEN

	printf("\n test del_terra funzionante");
	return(0);
}

//Funzione di stampa del percorso
void stampa_percorso(struct Terra* p)
{// stampa_percorso() - OPEN
	
	int contaTerra=1;
	p=percorso;
	
	//Stampa "nessuna Terra"
	if (p == NULL){

		system("clear"); // PULISCE LO SCHERMO
		
		printf("Stampo il percorso");
		printf ("\n\n ---Nessun terreno presente---\n");
		
		printf("\n - Premi ENTER per continuare -");
		while(getchar()!='\n');
		getchar();
	}
	//Stampa Terre dalla prima in poi
	while(p!=NULL){
		printf("\n\n  Terra nr. %d ha :", contaTerra);
		//printf("\n Tipo terra > %d", (int)p->tipo_terra);
		//printf("\n Tipo mostro > %d", (int)p->tipo_mostro);
		//printf("\n Tesoro = %d", (int)p->tesoro);
		
		p=p->terra_successiva;
		
		contaTerra++;
		
		printf("\n - Premi ENTER per continuare -");
		while(getchar()!='\n');
		getchar();
	}
}

//Funzione chiusura del percorso
struct Terra *chiudi_percorso(struct Terra* p)
{// *chiudi_percorso() - OPEN
	
	printf("\n test chiudi_percorso funzionante\n\n");
	checkExit=1;
	return(0);
}


//-------------FUNZIONI SU OBERON-------------

//Funzione di avanzamento di Oberon
struct Oberon *avanza(struct Oberon* l)
{// *avanza() - OPEN
	printf("\n test avanza funzionante");
}

//Funzione della prendita del tesoro
struct Oberon *prendi_tesoro(struct Oberon* l)
{// *prendi_tesoro() - OPEN
	printf("\n test prendi_tesoro funzionante");
}

//Funzione usa pozione su Oberon
struct Oberon *usa_pozione(struct Oberon* l)
{// *usa_pozione() - OPEN
	printf("\n test usa_pozione funzionante");
}

//Funzione del combattimento
struct Oberon *combatti(struct Oberon* l)
{// *combatti() - OPEN
	printf("\n test combatti funzionante");
}

//Funzione di distruzione terra
struct Terra *distruggi_terra(struct Terra* p, struct Oberon* l)
{// *distruggi_terra() - OPEN
	printf("\n test ditruggi_terra funzionante");
}
