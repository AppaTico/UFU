typedef struct fpa * Fpa;

Fpa cria_fpa ();
int fpa_vazia (Fpa);

int insere_fim (Fpa, int);
int remove_ord (Fpa, int *);

int esvazia_fpa (Fpa);
int apaga_fpa (Fpa *);