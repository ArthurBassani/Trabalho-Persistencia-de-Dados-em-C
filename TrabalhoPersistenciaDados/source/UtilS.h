


/* aloca memoria para um inteiro e armazena o valor naquele espaco */
int* alocaInt(int n){
   int * pi = (int *) malloc(sizeof(int));
   *pi = n;
   return pi;
}
