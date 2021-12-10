typedef struct fila * Fila;

Fila cria_fila ();
int fila_vazia (Fila);
int insere_fim (Fila, int);
int remove_ini (Fila, int *);