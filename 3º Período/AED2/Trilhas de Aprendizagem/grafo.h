
struct grafo 
{
   int NumVert; 
   int NumArco; 
   struct noVert *vertices; 
};
typedef struct grafo *Grafo;

struct noVert 
{ 
   vertice vert;
   struct noVert *prox;
   struct noAdj *ladj; 
};

struct noAdj 
{ 
   vertice vert;
   int peso; 
   struct noAdj *prox; 
};

struct visitaTempo
{
  vertice vert;
  int tempoDescoberta;
  int tempoFinalizacao;
};

struct vertice
{
    char nome[100];
    char tipo[100];
    char acao[100];
};
typedef struct vertice vertice;


/* A lista de adjacência de um vértice v é composta por nós. Cada nó da  corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. */

Grafo criarGrafo(int nVert);
void inserirArco(Grafo G, int v1, int v2);
void inserirNovoVertice(Grafo G, int nv);
int grauVertice(Grafo G, int v);
void imprimirListaAdj(Grafo G);
void imprimirListaAdjRec(struct noVert *nv);

void BuscaEmLargura(Grafo G, int v);
void BuscaEmProfundidade (Grafo G, int v);
void PercursoProfundidadeTempo (Grafo G, int v);

int vertices_iguais(vertice* v1, vertice* v2);