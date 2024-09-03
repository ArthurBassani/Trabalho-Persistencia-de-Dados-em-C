#ifndef UPDATE_H
#define UPDATE_H

void update(pDFile arq, void* chave, void* dados, FuncaoComparacao pfc){
    if(arq->arquivo == NULL){
        printf("Erro ao abrir o arquivo (update)\n");
        return;
    }
    int resultado = 0;
    rewind(arq->arquivo);
    void* info = malloc(arq->tamanhoRegistro);
    do{
        resultado = fread(info, arq->tamanhoRegistro,1,arq->arquivo);
        if(pfc(info,chave) == 0){
        fseek(arq->arquivo, -arq->tamanhoRegistro, SEEK_CUR);
        fwrite(dados, arq->tamanhoRegistro, 1, arq->arquivo);
        printf("Cadastro atualizado com sucesso\n");
        return;
        }
    }while(resultado != 0);
}

#endif
