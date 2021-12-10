typedef struct no * Pilha;

Pilha cria_pilha ();

int pilha_vazia (Pilha);

int push (Pilha *, int);
int pop (Pilha *, int *);

int le_topo (Pilha *, int *);

int libera_pilha (Pilha *);
int esvazia_pilha (Pilha);