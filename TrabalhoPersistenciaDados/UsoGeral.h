#ifndef USO_GERAL_H
#define USO_GERAL_H
#define Vermelho "\033[31m"
#define Verde "\033[32m"
#define Amarelo "\033[33m"
#define Azul "\033[34m"
#define Magenta "\033[35m"
#define Ciano "\033[36m"
#define Branco "\033[37m"
#define Reset "\033[0m"
#include <string.h>
//DEFINE AS FUN��ES//
//-------------------------------------------------------------------------//
void* alocaFloat(float num);
//-------------------------------------------------------------------------//
void* alocaChar(char* aux);
//-------------------------------------------------------------------------//
void imprimeChar(void* vetor[],int tam);
//-------------------------------------------------------------------------//
void imprimeFloat(void* vetor[],int tam);
//-------------------------------------------------------------------------//
void imprimeInt(void* vetor[],int tam);
//-------------------------------------------------------------------------//
int comparaFloat(void *info1,void *info2);
//-------------------------------------------------------------------------//
int comparaInt(void *info1,void *info2);
//-------------------------------------------------------------------------//
void imprimePontInt(void* num);
//-------------------------------------------------------------------------//
void imprimePontFloat(void* num);
//-------------------------------------------------------------------------//
void imprimePontChar(void* num);
//-------------------------------------------------------------------------//
void* alocaInt(int num);
//-------------------------------------------------------------------------//
void* alocaLLU(unsigned long long num);
//-------------------------------------------------------------------------//
void* alocaInt(int num){
    void* pNum = (int*)malloc(sizeof(int));
    *(int*)pNum = num;
    return pNum;
}
//-------------------------------------------------------------------------//
void* alocaFloat(float num){
    void* pNum = (float*)malloc(sizeof(float));
    *(float*)pNum = num;
    return pNum;
}
//-------------------------------------------------------------------------//
void* alocaLLU(unsigned long long num){
    void* pNum = (unsigned long long*) malloc(sizeof(unsigned long long));
    *(unsigned long long*)pNum = num;
    return pNum;
}
//-------------------------------------------------------------------------//
void* alocaChar(char* aux){
    void *Ac;
    Ac = (char*)malloc(sizeof(aux));
    strcpy(Ac,aux);
    return Ac;
}
//-------------------------------------------------------------------------//
void imprimeChar(void* vetor[],int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("Vetor[%d] = %s\n",i,(char*)vetor[i]);
	}
}
//-------------------------------------------------------------------------//
void imprimeVetorIntFloat(void* vetor[],int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("Vetor[%d] = %.2f\n",i,*(float*)vetor[i]);
	}
}
//-------------------------------------------------------------------------//
void imprimeVetorInt(void* vetor[],int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("Vetor[%d] = %d\n",i,*(int*)vetor[i]);
	}
}
//-------------------------------------------------------------------------//
int comparaFloat(void* info1,void *info2){
   return *(float*)info1 - *(float*)info2;
}
//-------------------------------------------------------------------------//
int comparaInt(void* info1,void *info2){
   return *(int*)info1 - *(int*)info2;
}
//-------------------------------------------------------------------------//
int comparaChar(void* info1,void* info2){
    return strcmp(info1,info2);
}
//-------------------------------------------------------------------------//
void imprimePontInt(void* num){
    if(num == NULL){
        printf("Conte�do inexistente\n");
    }else{
        printf("Lista: %d\n",*(int*)num);
    }
}
void imprimePontFloat(void* num){
    if(num == NULL){
        printf("Conte�do inexistente\n");
    }else{
        printf("Lista: %2.f\n",*(float*)num);
    }
}
void imprimePontChar(void* num){
    if(num == NULL){
        printf("Conte�do inexistente\n");
    }else{
        printf("Lista: %s\n",(char*)num);
    }
}

#endif // USO_GERAL_H

