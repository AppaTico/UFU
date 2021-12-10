typedef struct pilha * Pilha;

Pilha cria_pilha ();

int pilha_vazia (Pilha);
int pilha_cheia (Pilha);

int push (Pilha, int);
int pop (Pilha, int *);

int le_topo (Pilha, int *);

int esvazia_pilha (Pilha);
int libera_pilha (Pilha *);