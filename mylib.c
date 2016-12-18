#include "mylib.h"

//						
//						

//Dichiaro le struttire statiche valide solo in mylib.c
static struct sTerra* percorso = NULL;

static struct sTerra* ultima_terra = NULL;

static struct sOberon oberon;   // NOTSURE "extern" dovrebbe essere static 


//Dichiaro le funzioni da richiamare nei sotto menu'

	//Funzioni del sottomenù crea_percorso()
	static struct sTerra *ins_terra(struct sTerra* p);
	static struct sTerra *del_terra(struct sTerra* p);
	static void stampa_percorso(struct sTerra* p);
	static void chiudi_percorso();

	//Funzioni del sottomenù muovi_Oberon()
	static struct sOberon *avanza(struct sOberon* l);
	static struct sOberon *prendi_tesoro(struct sOberon* l);
	static struct sOberon *usa_pozione(struct sOberon* l);
	static struct sOberon *combatti(struct sOberon* l);
	static struct sTerra *distruggi_terra(struct sTerra* p, struct sOberon* l);
	
	
//Dichiaro un pointer che registri l'ultima posizine inserita
struct sTerra *ptr=NULL;
	


//Funzione sub_main per la creazione del percorso
void crea_percorso()
{// crea_percorso() - OPEN
	
	//Variabili utilizzate nella scelta del sub menu
	static int nScelta_sub;
	static char sScelta_sub[1];
	
	
	for ( ; ; )
	{	
		//Controllo del programma nel caso sia stata utilizzata la fun chiudi_percorso e uscire se accaduto
		if (checkExit!=0){
			return;
		}
		
		printf("\n			PROGEXAM - SUBMENU CREA PERCORSO\n\n");
		printf("\n      Cosa vuoi fare?\n\n");
		printf(" 1 - Inserire terreno\n");
		printf(" 2 - Cancellare terreno\n");
		printf(" 3 - Mostra terreno\n");
		printf(" 4 - Chiudi percorso\n");
		
		// CHECK
		if (percorso==NULL){
			printf("\n\nvuota");
		}
		else{
			printf("\n\npiena");
		}
		printf("\n%x", &percorso);
		printf("\n%p", percorso);
		//CHECK
		
		printf("\n  > la tua scelta ");
		scanf("%s", &sScelta_sub);
		
		//Coneversione del valore string sScelta_sub in int nScelta_sub per controllare che l'utente abbia utilizzato valori validi
			nScelta_sub=atoi(sScelta_sub);
		
		switch (nScelta_sub) {
			case 1:
				system("clear");
				ptr=ins_terra(ptr);
				break;
				
			case 2:
				system("clear");
				ptr=del_terra(ptr);
				break;
		
			case 3:
				system("clear");
				stampa_percorso(percorso);
				break;
		
			case 4:
				system("clear");
				chiudi_percorso();
				break;
		
			default:
				system("clear");
				printf("\a********ERRORE********\n");
				printf("Inserire un numero compreso tra 1 e 4!\n\n");
				printf("\n - Premi ENTER per continuare -");
				while(getchar()!='\n'){
					getchar();
				}
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
	
	if (percorso==NULL){
		printf("\a\n		********ERRORE********\n");
		printf("    Non hai ancora inserito nessun terreno!");
		printf("\n\n Premi INVIO per ritornare al menu principale...");
		while(getchar()!='\n');
			getchar();
		return;
		
	}
	for ( ; ; )
	{
		printf("\n			PROGEXAM - SUBMENU MOVIMENTO OBERON--------------");
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
				printf("Inserire un numero compreso tra 1 e 5\n\n");
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
struct sTerra *ins_terra(struct sTerra* p)
{// *ins_terra() - OPEN
	
	//Inizializzo il random
	time_t t;
	srand((unsigned) time(&t));
	
	//Definiscoa le variabili temporanee da immettere
	int temp_tipo_terra=0;
	int temp_tipo_mostro=0;
	
	struct sTerra *pun;
	
	//Inserimento valori a p da percorso
	if(percorso==NULL){
			
		//Inserimento terra
		printf("\n Che tipo di terra vuoi?\n");
		printf("\n   1 - Deserto\n   2 - Foresta\n   3 - Palude\n   4 - Villaggio\n   5 - Pianura\n");
		printf("\n > inserire scelta: ");
			
		scanf("%d", &temp_tipo_terra); 										// da prof : &((int)(p->tipo_terra))
		printf("\n Hai inserito %d", temp_tipo_terra);
			
			
		//Inserimento mostri
		printf("\n\n Che tipo di mostro vuoi?\n");
		printf("\n   1 - Nessuno\n   2 - Scheletro\n   3 - Lupo\n   4 - Orco\n   5 - Drago");
		printf("\n > inserire scelta: ");
		
		scanf("%d", &(temp_tipo_mostro)); 										// da prof : &((int)(p->tipo_terra)))
		printf("%d", temp_tipo_mostro);
		 
	}
	else{
		
		//Inserimento terra
		printf("\n Che tipo di terra vuoi?\n");
		printf("\n   1 - Deserto\n   2 - Foresta\n   3 - Palude\n   4 - Villaggio\n   5 - Pianura\n");
		printf("\n > inserire scelta: ");
		
			
		scanf("%d", &(temp_tipo_terra)); 										// da prof : &((int)(p->tipo_terra)))
		printf("%d", temp_tipo_terra);
		
		//Inserimento mostri
		printf("\n\n Che tipo di mostro vuoi?\n");
		printf("\n   1 - Nessuno\n   2 - Scheletro\n   3 - Lupo\n   4 - Orco\n   5 - Drago");
		printf("\n > inserire scelta: ");
		
		scanf("%d", &(temp_tipo_mostro)); 										// da prof : &((int)(p->tipo_terra)))
		printf("%d", temp_tipo_mostro);
	
	}
	
	//Allocazione memoria
	if(percorso==NULL){
		
		//Alloco al puntatore p
		p=(struct sTerra*)malloc(sizeof(struct sTerra));
		
		
		//Imposto che la terra successiva di p non abbia nessun valore
		p->terra_successiva=NULL;
		
		
		//Do a tipo_terra di p il valore della vartiabile temporanea
		p->tipo_terra=temp_tipo_terra;
		
		//Do a tipo_mostro di p il valore della vartiabile temporanea
		p->tipo_mostro=temp_tipo_mostro;
		
		//Imposto tesoro come numero random  
		p->tesoro=rand()%100;
		
		
		//A percorso assegno l'indirizzo dello struct p
		percorso= p;
		
		//Assegno ad ultima terra l'indirizzo di p
		ultima_terra=p;
		
	}
	else{
		
		//Alloco uno spazio 
		p->terra_successiva=(struct sTerra *)malloc(sizeof(struct sTerra));
		
		//Accedo all' elemento nuovo p->terra_successiva tramite il puntatore pun
		pun=p->terra_successiva;
		
		
		//Do a tipo_terra di p il valore della vartiabile temporanea
		pun->tipo_terra=temp_tipo_terra;
		
		//Do a tipo_mostro di p il valore della vartiabile temporanea
		pun->tipo_mostro=temp_tipo_mostro;
		
		//Imposto tesoro come numero random  
		pun->tesoro=rand()%250;
		
		//Imposto che la terra successiva di p non abbia nessun valore
		pun->terra_successiva = NULL;
		
		//Assegno ad ultima terra l'indirizzo di pun
		ultima_terra=pun;
		
	}
	
	return(ultima_terra);
	
}

//Funzione di cancellazione del terreno creato
struct sTerra *del_terra(struct sTerra* p)
{// *del_terra() - OPEN
	
	/* if(ultima_terra==0){
		
		printf("\n Non hai inserito nessun terreno ancora...")
		
	}
	else{
		
		//Libera la memoria dell'ultimo terreno avuto
		free(ptr)
		
		//Imposta che l'ultimo terreno corrisponda 
		ultima_terra=;
		
	}
	*/
	return(ultima_terra); 
	
	
}

//Funzione di stampa del percorso
void stampa_percorso(struct sTerra* p)
{// stampa_percorso() - OPEN
	
	//Inizializzo il contatore delle terre visibile solo in stampa_percorso
	int contaTerra=1;
	
	//Stampa nel caso in cui non sia presente nessuna terra
	if (p == NULL){
		
		system("clear");
		
		printf("Stampo il percorso");
		printf ("\n\n ---Nessun terreno presente---\n");
		
		printf("\n - Premi ENTER per continuare -");
		while(getchar()!='\n');
			getchar();
		
	}
	
	//Stampa delle terre dalla prima in poi
	while(p != NULL){
		
		system("clear");
		
		printf("\n Terra nr. %d ha :", contaTerra);
		printf("\n Tipo terra > %d", p->tipo_terra);
		printf("\n Tipo mostro > %d", p->tipo_mostro);
		printf("\n Tesoro = %d\n\n", p->tesoro);
		
		//Leggo l'elemento successivo
		p=p->terra_successiva;
		
		//Contatore numero terre incrementato di 1
		contaTerra++;
		
		printf("\n - Premi ENTER per continuare -");
		while(getchar()!='\n');
			getchar();
		
	}
	
}

//Funzione chiusura del percorso
void chiudi_percorso()
{// *chiudi_percorso() - OPEN

	checkExit=1;
	
}


//-------------FUNZIONI SU OBERON-------------

//Funzione di avanzamento di Oberon
struct sOberon *avanza(struct sOberon* l)
{// *avanza() - OPEN

	printf("\n test avanza funzionante");
	return(0);
	
}

//Funzione della prendita del tesoro
struct sOberon *prendi_tesoro(struct sOberon* l)
{// *prendi_tesoro() - OPEN

	printf("\n test prendi_tesoro funzionante");
	return(0);
	
}

//Funzione usa pozione su Oberon
struct sOberon *usa_pozione(struct sOberon* l)
{// *usa_pozione() - OPEN

	printf("\n test usa_pozione funzionante");
	return(0);
	
}

//Funzione del combattimento
struct sOberon *combatti(struct sOberon* l)
{// *combatti() - OPEN

	printf("\n test combatti funzionante");
	return(0);
	
}

//Funzione di distruzione terra
struct sTerra *distruggi_terra(struct sTerra* p, struct sOberon* l)
{// *distruggi_terra() - OPEN

	printf("\n test ditruggi_terra funzionante");
	return(0);
	
}
