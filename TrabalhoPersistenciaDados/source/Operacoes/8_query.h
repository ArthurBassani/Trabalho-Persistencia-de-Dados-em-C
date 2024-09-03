#ifndef QUERY_H
#define QUERY_H

pDLista queryBy (pDFile arq,FuncaoPredicado pred){
   if (arq->arquivo == NULL){
       printf("Arquivo não foi aberto!(querryBy)\n");
       return NULL;
   }

    pDLista pLista = criarLista();

    if (pLista == NULL){
       printf("Erro ao criar lista(querryBy)\n");
       return NULL;
    }

   rewind(arq->arquivo);
   int result;

   do{
      void *dados = malloc(arq->tamanhoRegistro);
      result = fread (dados, arq->tamanhoRegistro, 1, arq->arquivo);
      if(pred(dados) == 0){
        incluirInfo(pLista, dados);
      }
   }while(result != 0);
    close(arq);
    if(pLista->quantidade <= 0){return NULL;}
    else                       {return pLista;}
}

#endif

