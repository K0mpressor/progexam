typedef struct oberon {
  unsigned short borsa_oro;
  unsigned short punti_ferita;
  unsigned short incantesimi;
  unsigned short pozione_guaritrice; 
} sOberon;

typedef struct terra {
  enum tipo_terra {deserto, foresta, palude, villaggio, pianura} eTipo_terra;
  enum tipo_mostro {nessuno, scheletro, lupo, orco, drago} eTipo_mostro;
  unsigned short tesoro;
  terra *terra_successiva;
} sTerra;

void crea_percorso();

