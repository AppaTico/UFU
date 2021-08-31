#ifndef lista
#define lista

typedef struct no * Lista;

struct bebida
{
    char nome[10];
    float preco;
    int volume;
};

typedef struct bebida Bebida;

Lista cria_lista ();
int lista_vazia (Lista lst);
int insere_final (Lista *lst, Bebida bbd);
int remove_ini (Lista *lst, Bebida *bbd);
int get_elem_pos (Lista lst, int indice, Bebida *bbd);
int apaga_lista (Lista *lst);
int esvazia_lista (Lista *lst);

#endif
