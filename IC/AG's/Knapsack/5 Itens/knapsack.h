#define tamanho_genoma 5 //quantos bits possuem um genoma
#define tamanho_pop 6 //quantos genomas possuem uma geracao
#define tamanho_mochila 5 //quantos itens usaremos no problema
#define limite_peso 3000 //peso maximo permitido na mochila
#define limite_fitness 740 //valor da resposta conhecida para o problema proposto
#define probabilidade 0.5 //probabilidade usada para definir as mutacoes
#define limite_geracoes 100 //limite de geracoes que sera gerado pelo programa

//struct dos itens que preenchem a mochila
struct it
{
    char nome[50];
    int peso;
    int valor;
};
typedef struct it item;