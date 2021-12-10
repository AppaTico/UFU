typedef struct no * Fila;

Fila cria_fila ();
int fila_vazia (Fila);

int insere_fim (Fila *, int);
int remove_ini (Fila *, int *);

int esvazia_fila (Fila);
int apaga_fila (Fila *);