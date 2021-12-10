#define max_c 10
typedef struct deque * Deque;

struct deque
{
    struct no * ini;
    struct no * fim;
};

struct no
{
    char string[max_c];
    struct no * prox, * ant;
};

Deque cria_deque ();

int deque_vazio (Deque);
int deque_cheio (Deque);

int inserir_inicio (Deque, char[max_c]);
int inserir_final (Deque, char[max_c]);

int remover_inicio (Deque, char*[max_c]);
int remover_final (Deque, char*[max_c]);

int esvazia_deque (Deque);
int apaga_deque (Deque*);