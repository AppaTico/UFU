typedef struct deque * Deque;

Deque cria_deque ();

int deque_vazio (Deque);
int deque_cheio (Deque);

int inserir_início (Deque, int*);
int inserir_final (Deque, int*);

int remover_início (Deque, int*);
int remover_final (Deque, int*);

int esvazia_deque (Deque);
int apaga_deque (Deque*);