#ifndef INCLUIR_INFO_H
#define INCLUIR_INFO_H

void incluirInfo(pDLista pd, void *info){

    if(pd == NULL){
        //CASO A LISTA NÃO EXISTA
        printf("Lista não existe\n");
        return;
    }
    //CRIA NOVO NOH
    pNoh pNovo = malloc(sizeof(Noh));
    pNovo->info = info;
    pNovo->prox = NULL;
    //VERIFICA SE SERA O PRIMEIRO NOH DA LISTA
    if(pd->primeiro == NULL && pd->ultimo == NULL){
        pd->primeiro = pNovo;
        pd->ultimo = pNovo;
    }else{
        //ATRIBUI O NOVO ELEMENTO COMO ULTIMO NA LISTA
        pd->ultimo->prox = pNovo;
        pd->ultimo = pNovo;
    }
    //SOMA 1 NO TAMANHO DA LISTA
    (pd->quantidade)++;

}

#endif
