#ifndef CREATE_H
#define CREATE_H

void createe (pDFile arq, void* dados){

    if (arq->arquivo == NULL){
        printf("Arquivo não foi aberto!");
        return;
    }

    // posiciona o ponteiro do arquivo no final do arquivo
    printf("Posicionando....");
    fseek (arq->arquivo, 0, SEEK_END);
    printf("Gravando....");
    int result = fwrite(dados, arq->tamanhoRegistro, 1, arq->arquivo);
    printf("Resultado da gravação: %d\n", result);
    printf("\n");
}


#endif
