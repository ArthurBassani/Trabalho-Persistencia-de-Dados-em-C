#ifndef PERSISTALL_H
#define PERSISTALL_H

void persistAll(pDFile arq, pDLista pLista){
    if(arq->arquivo == NULL){
        printf("Erro ao abrir o arquivo (persistAll)\n");
    }
    if(pLista == NULL){
        printf("Erro ao abrir lista (persistAll)\n");
    }
    pNoh Aux = pLista->primeiro;
    while(Aux != NULL){
        createe(arq,Aux->info);
        Aux = Aux->prox;
    }
    printf("Lista Cadastrada No Banco\n");
    close(arq);
}

#endif
