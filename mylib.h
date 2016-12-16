typedef enum tipoTerra {
  deserto = 1; // Si parte da 0 o da 1... mah..
  foresta;
  palude;
  villaggio;
  pianura;
} eTipoTerra;

typedef struct tipoMostro {
  nessuno = 1;
  scheletro;
  lupo;
  orco;
  drago;
} eTipoMostro

typedef struct oberon {
  unsigned short borsa_oro;
  unsigned short punti_ferita;
  unsigned short incantesimi;
  unsigned short pozione_guaritrice; 
} sOberon;

typedef struct terra {
  eTipoTerra tipoTerra;
  eTipoMostro tipoMostro;
  unsigned short tesoro;
  terra *terra_successiva;
} sTerra;

void crea_percorso();

