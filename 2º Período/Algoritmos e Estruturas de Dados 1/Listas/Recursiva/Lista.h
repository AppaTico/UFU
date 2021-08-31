typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista);
int insere_ord (Lista *, int);
int remove_ord (Lista *, int);
int apaga_lista (Lista *);
int esvazia_lista (Lista *);
int get_elem_pos (Lista, int pos, int *var);
