#include <stdio.h>
#include <strings.h>

struct pessoa{
   int      cpf;
   char     nome[30];
   int      idade;
};

void main(){

FILE *arq;
int  result, op=1;

struct pessoa p;

arq = fopen("Pessoas.dat", "ab+");

if (arq == NULL)
{
    printf("Problemas na abertura do arquivo\n");
    return;
}

fseek (arq, 0, SEEK_END);

int end = ftell(arq);
//printf("Fim : %d", end);

while (op != 0) {

  scanf("%d", &p.cpf);
  fflush(stdin);

  fgets(p.nome, 30, stdin);
  fflush(stdin);

  scanf("%d", &p.idade);
  fflush(stdin);

  result = fwrite(&p, sizeof(struct pessoa), 1, arq);

  printf("Quer cadastrar outra pessoa? (0 - Não, 1 - Sim) = ");
  scanf("%d", &op);
  fflush(stdin);
}

rewind(arq);

do{
  result = fread (&p, sizeof(struct pessoa), 1, arq);
  //printf("%d \n", result);
  if (result != 0)
      printf("CPF: %d - Nome: %s - Idade: %d\n", p.cpf,p.nome,p.idade);
  getch();
} while(result!=0);

fclose(arq);



}
