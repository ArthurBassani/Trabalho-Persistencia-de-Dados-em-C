#include <stdio.h>
#include <strings.h>
#include "Persistencia.h"
#include "Cap3/Lista.h"
#include "Utils.h"

struct pessoa{
   int      cpf;
   char     nome[30];
   int      idade;
};

void imprimePessoa(void *info){
   struct pessoa *p = (struct pessoa *) info;
   printf("CPF: %d - Nome: %s - Idade: %d\n", p->cpf, p->nome, p->idade);
}

void* alocaPessoa(){
   return malloc(sizeof(struct pessoa));
}

int comparaPessoaChave(void* info, void* chave){
    struct pessoa *p = (struct pessoa *) info;
    int* key = (int *) chave;
    return *key - p->cpf;
 }

void main(){

  struct pessoa p;

  pDFile arqPessoa;

  arqPessoa = open("Pessoa.dat", sizeof(struct pessoa));
  int op = 1;
  while (op != 0) {

    scanf("%d", &p.cpf);
    fflush(stdin);

    fgets(p.nome, 30, stdin);
    fflush(stdin);

    scanf("%d", &p.idade);
    fflush(stdin);

    createe(arqPessoa, &p);
    //update(arqPessoa, alocaInt(456), &p, comparaPessoaChave, alocaPessoa);

    printf("Quer cadastrar outra pessoa? (0 - Não, 1 - Sim) = ");
    scanf("%d", &op);
    fflush(stdin);
  }

  pDLista listaPessoas = queryAll(arqPessoa, alocaPessoa);

  int i;
  for(i=1; i <= listaPessoas->quantidade; i++){
    struct pessoa* pp = (struct pessoa*) buscarInfoPos(listaPessoas, i);
    imprimePessoa(pp);
  }

  close(arqPessoa);


}
