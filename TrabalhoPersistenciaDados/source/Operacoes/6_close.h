#ifndef CLOSE_H
#define CLOSE_H

void close(pDFile arq){

    fclose(arq->arquivo);

}

#endif
