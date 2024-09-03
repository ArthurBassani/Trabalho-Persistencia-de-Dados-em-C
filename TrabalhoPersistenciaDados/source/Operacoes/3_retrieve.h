#ifndef RETRIEVE_H
#define RETRIEVE_H

void* retrieve  (pDFile arq, void* chave, FuncaoComparacao pfc){
    int resultado = 0;
    void* dados = malloc(arq->tamanhoRegistro);
    rewind(arq->arquivo);
    do{
        resultado = fread(dados, arq->tamanhoRegistro,1,arq->arquivo);
        if(pfc(dados,chave) == 0){
            close(arq);
            return dados;
        }
    }while(resultado != 0);
    close(arq);
    return NULL;
}


#endif
