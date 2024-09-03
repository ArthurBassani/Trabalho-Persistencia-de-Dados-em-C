#ifndef QUERYALL_H
#define QUERYALL_H

pDLista queryAll(pDFile arq){

   if (arq->arquivo == NULL){
       printf("Arquivo não foi aberto!");
       return NULL;
   }

   pDLista lista = criarLista();

   rewind(arq->arquivo);
   int result;

   do{
      void *dados = malloc(arq->tamanhoRegistro);
      result = fread (dados, arq->tamanhoRegistro, 1, arq->arquivo);
      if (result == 0)
        continue;
      //pfi(dados);
      incluirInfo(lista, dados);
   } while(result!=0);
   if(lista->quantidade > 0){
        close(arq);
        return lista;
   }else{
        return NULL;
   }
}

#endif
