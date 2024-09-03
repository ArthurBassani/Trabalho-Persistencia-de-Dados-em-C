#ifndef STRUCT_FILE_H
#define STRUCT_FILE_H

/* --------------------------
   Tipos de dados
   -------------------------- */
struct dFile{
  FILE* arquivo;         // nome do arquivo em disco
  int   tamanhoRegistro; // qtde bytes do tipo de dado (struct)
};
struct data{
    int dia;
    int mes;
    int ano;
};

struct reg_cliente{
        unsigned long long cpf;
        char nome[30];
        float limiteCredito;
        float creditoAtual;
        int status;
};

typedef struct reg_cliente dCliente;

struct reg_prod{
    int codProd;
    int quantidadeEstoque;
    char descricao[30];
    float preco;
};

typedef struct reg_prod dProduto;

struct reg_prod_venda{
    int codProd;
    int codVenda;
    int quantidade;
};

typedef struct reg_prod_venda dProdVenda;

struct reg_venda{
    int numero;
    int status;
    struct data Data;
    unsigned long long cpf;
    float PrecoVenda;
};

typedef struct reg_venda dVenda;
#endif
