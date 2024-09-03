#ifndef DELETE_H
#define DELETE_H

void deletee(pDFile arq,char nomeArq[30], void* chave, FuncaoComparacao pfc){
    if(arq->arquivo == NULL){
        printf("Erro ao abrir arquivo (delete)\n");
        return;
    }
    FILE* arqTemp = fopen("Temp.xyz","wb+");
    rewind(arq->arquivo);
    int resultado = 0;
    void* dados = malloc(arq->tamanhoRegistro);
    do{
        resultado = fread(dados,arq->tamanhoRegistro,1,arq->arquivo);
        if(pfc(dados,chave) != 0){
            fwrite(dados,arq->tamanhoRegistro,1,arqTemp);
        }
    }while(resultado != 0);

    close(arq);
    fclose(arqTemp);

    if (remove(nomeArq) == 0 && rename("Temp.xyz",nomeArq) == 0){
        printf("Cadastro deletado com sucesso\n");
    }else{
        printf("Erro ao deletar cadastro(delete)\n");
        return;
    }
}

#endif
