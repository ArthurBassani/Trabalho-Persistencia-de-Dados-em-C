//-------------------------------------------------------------------------------------------------//
/* --------------------------
   Tipos de dados
   -------------------------- */
typedef struct dFile DFile;
typedef DFile*       pDFile;

typedef int   (*FuncaoComparacao)(void *, void *);
typedef void* (*FuncaoAloca)     ();
typedef void  (*FuncaoImpressao) (void *);
typedef int   (*FuncaoPredicado) (void *);

/* --------------------------
   Operações CRUD
   -------------------------- */
pDFile  open      (char[30], int);
void    createe   (pDFile, void*);                          // dados
void*   retrieve  (pDFile, void*, FuncaoComparacao);        // chave
void    update    (pDFile, void*, void*, FuncaoComparacao); // chave e os dados
void    deletee   (pDFile,char[30],void*, FuncaoComparacao);// chave
void    close     (pDFile);

void deleteAll    (char[30]);
pDLista queryAll  (pDFile);
pDLista queryBy   (pDFile, FuncaoPredicado);
void   persistAll (pDFile, pDLista);

//-------------------------------------------------------------------------------------------------//
void* alocaCliente();
void* alocaProduto();
void* alocaVenda();
void* alocaProdVenda();
void imprimeCliente(dCliente*);
void leCliente();
void leProduto();
void imprimeProdutos(dProduto*);
int geraCodProd();
int geraCodVend();
int comparaCodProduto(void* dados, void* chave);
int comparaDescProd(void* dados, void* chave);
int comparaNomeCliente(void* dados, void* chave);
void leVenda();
void retornaCodVenda();
void atualizaEstoque(pDLista pLista);
int menuVenda();
int filtraCPF(void* dados);
int filtraMaiorQue(void* dados);
int filtraMenorQue(void* dados);
int comparaCliente(void* dados,void* chave);
int comparaNumVenda(void* dados, void* chave);
int comparaCodProdVenda(void* dados);
void imprimeVenda(dVenda* venda);
void imprimeProdVenda(dProdVenda* prodVenda);
//-------------------------------------------------------------------------------------------------//




