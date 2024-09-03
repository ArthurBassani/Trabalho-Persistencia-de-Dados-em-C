#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "UsoGeral.h"
#include "source/Persistencia.h"


int main(void){
    setlocale(LC_ALL,"Portuguese");

    int crtl = 0;
    int op;

    do
    {
        //verificaUser();

        do //MENU GERAL
        {

            system("cls");
            printf("Escolha op��o\n");


            printf("1- Cliente\n");
            printf("2- Produto\n");
            printf("3- Venda\n");
            printf("4- Realizar logout\n");

            do //VERIFICA OP��ES DO MENU
            {
                printf("->");
                scanf("%d",&op);
                printf("\n");
                fflush(stdin);
                if(op < 1 || op > 4) printf("Op��o Inv�lida\t|\tInforme novamente\n");
            }
            while(op < 1 || op > 4);

//------------------------------------------SWITCH-------------------------------------------------------------------------------------------//

            switch(op)
            {
            case 1:

                crtl = menuCliente();

                break;
            case 2:

                crtl = menuProduto();

                break;
            case 3:

                crtl = menuVenda();

                break;
            case 4:
                printf("Saindo do sistema...\n");
                crtl = 2;
                break;
            }
        }
        while(crtl <= 1); //MENU GERAL
        fflush(stdin);
    }
    while(crtl == 2); //LOGOUT

}
void verificaUser()
{
    char user[30];
    int senha,op;
    do  //VERIFICA��O USU�RIO
    {
        printf("Informe Usu�rio: ");
        fgets(user,sizeof(user),stdin);
        user[strcspn(user,"\n")] = '\0';
        setbuf(stdin,NULL);
        if(strcmp(user,"admin") != 0)
        {
            printf("Usu�rio inv�lido\n");
        }
    }
    while(strcmp(user,"admin") != 0);
    do //VERIFICA��O SENHA
    {
        printf("Informe Senha: ");
        scanf("%d",&senha);
        setbuf(stdin,NULL);
        if(senha != 123)
        {
            printf("Senha inv�lida\n");
        }
    }
    while(senha != 123);
}
int menuProduto()
{
    int op, crtl = 1;
    int codigo;
    dProduto* produto;
    do
    {
        do
        {
            printf("1- Cadastrar produto\n");
            printf("2- Visualizar produtos\n");
            printf("3- Atualizar produto\n");
            printf("4- Deletar produto\n");
            printf("5- Voltar ao Menu\n");
            printf("6- Realizar logout\n");
            printf("->");
            scanf("%d",&op);
            fflush(stdin);
            printf("\n");
            if(op < 1 || op > 6) printf("Op��o Inv�lida\t|\tInforme novamente\n");
        }
        while(op < 1 || op > 6);

        switch(op)
        {
        case 1: //CADASTRAR
            do
            {

                leProduto();

                do
                {
                    printf("1 - Cadastrar novamente\n");
                    printf("2 - Voltar ao menu\n");
                    printf("3 - Realizar logout\n");
                    printf("->");
                    scanf("%d",&op);
                    fflush(stdin);
                    printf("\n");
                    if(op < 1 || op > 3) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                }
                while(op < 1 || op > 3);

            }
            while(op == 1);
            if(op == 2)
            {
                return  1;
            }
            else if (op == 3)
            {
                return 2;
            }

            break;
        case 2: //VIZUALIZAR
            do //MENU VIZUALIZAR
            {
                printf("1 - Vizualizar todos os produtos cadastrados\n");
                printf("2 - Vizualizar produto espec�fico\n");
                printf("3 - Voltar ao menu\n");
                printf("4 - Realizar logout\n");
                printf("->");
                scanf("%d",&op);
                printf("\n");
                fflush(stdin);
                if(op < 1 || op > 4) printf("Op��o Inv�lida\t|\tInforme novamente\n");
            }
            while(op < 1 || op > 4);

            if(op == 1) //IMPRIMIR TODOS OS PRODUTOS
            {
                pDLista pListaProdutos = queryAll(open(TB_PRODUTOS,sizeof(dProduto)));
                if(pListaProdutos != NULL)
                {
                    imprimirLista(pListaProdutos,imprimeProdutos);
                    printf("\n");
                }
                else
                {
                    printf("Lista de Produtos n�o encontrada no banco de dados\n");
                }
            }
            else if(op == 2) //VIZUALIZAR PRODUTO ESPECIFICO
            {

                do  //CONTINUAR BUSCANDO PRODUTOS
                {

                    do  //VERIFICA OP��O ESCOLHIDA
                    {
                        printf("1 - Buscar por c�digo\n");
                        printf("2 - Buscar por nome\n->");
                        scanf("%d",&op);
                        fflush(stdin);
                        printf("\n");
                        if(op < 1 || op > 2) printf("Op��o inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 1 || op > 2); //VERIFICA OP��O ESCOLHIDA

                    if(op == 1)
                    {
                        printf("Informe c�digo para busca:\n");
                        printf("->");
                        scanf("%d",&codigo);
                        printf("\n");
                        fflush(stdin);


                        produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),comparaCodProduto);

                        if(produto == NULL)
                        {
                            printf("Produto n�o encontrado\n");
                        }
                        else
                        {
                            printf("\n");
                            imprimeProdutos(produto);
                            printf("\n");
                        }

                    }
                    else if(op == 2)
                    {

                        char nomeBuscaProd[30];

                        printf("Informe nome para busca\n->");
                        fgets(nomeBuscaProd,sizeof(nomeBuscaProd),stdin);
                        nomeBuscaProd[strcspn(nomeBuscaProd,"\n")] = '\0';
                        printf("\n");
                        fflush(stdin);

                        produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaChar(nomeBuscaProd),comparaDescProd);

                        if(produto == NULL)
                        {
                            printf("Produto n�o encontrado\n");
                        }
                        else
                        {
                            printf("Produto Encontrado:\n");
                            imprimeProdutos(produto);

                        }
                    }
                    printf("Continuar buscando produto? (0 - N�o | 1 - Sim)\n");
                    printf("->");
                    scanf("%d",&op);
                    fflush(stdin);
                    printf("\n");
                }
                while(op == 1);  //CONTINUAR BUSCANDO PRODUTOS
            }
            else if(op == 3)
            {
                return 1;
            }
            else if(op == 4)
            {
                return 2;
            }


            break;
        case 3: //ATUALIZAR
            do
            {
                printf("1 - Atualizar Nome/Descri��o\n");
                printf("2 - Atualizar Pre�o\n");
                printf("3 - Atualizar Estoque\n");
                printf("4 - Atualizar Tudo\n");
                printf("5 - Voltar ao Menu\n");
                printf("6 - Realizar Logout\n");
                printf("->");
                scanf("%d",&op);
                printf("\n");
                fflush(stdin);

                if(op < 1 || op > 6) printf("Op��o Inv�lida\t|\tInforme novamente\n");
            }
            while(op < 1 || op > 6);

            switch(op)
            {

            case 1:

                printf("Informe c�digo do produto a ser atualizado\n");
                printf("->");
                scanf("%d",&codigo);
                printf("\n");
                fflush(stdin);

                produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),comparaCodProduto);

                if(produto != NULL)
                {

                    printf("Produto encontrado\n");
                    imprimeProdutos(produto);


                    printf("Informe novo nome/descri��o do produto\n");
                    printf("->");
                    fgets(produto->descricao,sizeof(produto->descricao),stdin);
                    produto->descricao[strcspn(produto->descricao,"\n")] = '\0';
                    fflush(stdin);
                    printf("\n");


                    do
                    {
                        printf("Confirmar atualiza��o? (0 - N�o | 1 - Sim)\n");
                        printf("->");
                        scanf("%d",&op);
                        printf("\n");
                        fflush(stdin);
                        if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 0 || op > 1);

                    if(op == 1)
                    {
                        update(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),produto,comparaCodProduto);
                        printf("Nome/Descri��o atualizados\n");
                    }
                    else
                    {
                        printf("Opera��o cancelada\n");
                    }

                }
                else
                {
                    printf("Produto n�o encontrado no banco de dados (menuProduto/switch 3 / switch 1)\n");
                }

                break;
            case 2:

                printf("Informe c�digo do produto a ser atualizado\n");
                printf("->");
                scanf("%d",&codigo);
                printf("\n");
                fflush(stdin);

                produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),comparaCodProduto);

                if(produto != NULL)
                {

                    printf("Produto encontrado\n");
                    imprimeProdutos(produto);

                    do
                    {
                        printf("Informe novo pre�o\n");
                        printf("->");
                        scanf("%f",&produto->preco);
                        printf("\n");
                        fflush(stdin);
                        if(produto->preco < 0) printf("Imposs�vel atribuir pre�o negativo\t|\tInforme novamente\n");
                    }
                    while(produto->preco < 0);

                    do
                    {
                        printf("Confirmar atualiza��o? (0 - N�o | 1 - Sim)\n");
                        printf("->");
                        scanf("%d",&op);
                        printf("\n");
                        fflush(stdin);
                        if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 0 || op > 1);

                    if(op == 1)
                    {
                        update(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),produto,comparaCodProduto);
                        printf("Pre�o atualizado\n");
                    }
                    else
                    {
                        printf("Opera��o cancelada\n");
                    }

                }
                else
                {
                    printf("Produto n�o encontrado no banco de dados (menuProduto/switch 3 / switch 2)\n");
                }


                break;
            case 3:

                printf("Informe c�digo do produto a ser atualizado\n");
                printf("->");
                scanf("%d",&codigo);
                printf("\n");
                fflush(stdin);

                produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),comparaCodProduto);

                if(produto != NULL)
                {

                    printf("Produto encontrado\n");
                    imprimeProdutos(produto);

                    do
                    {
                        printf("Informe nova quantidade em estoque\n");
                        printf("->");
                        scanf("%d",&produto->quantidadeEstoque);
                        printf("\n");
                        fflush(stdin);
                        if(produto->quantidadeEstoque < 0) printf("Imposs�vel cadastrar estoque negativo\t|\tInforme novamente\n");
                    }
                    while(produto->quantidadeEstoque < 0);

                    do
                    {
                        printf("Confirmar atualiza��o? (0 - N�o | 1 - Sim)\n");
                        printf("->");
                        scanf("%d",&op);
                        printf("\n");
                        fflush(stdin);
                        if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 0 || op > 1);

                    if(op == 1)
                    {
                        update(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),produto,comparaCodProduto);
                        printf("Estoque atualizado\n");
                    }
                    else
                    {
                        printf("Opera��o cancelada\n");
                    }

                }
                else
                {
                    printf("Produto n�o encontrado no banco de dados (menuProduto/switch 3 / switch 3)\n");
                }


                break;
            case 4:
                int opc = 0;
                dProduto* produtoAtt = alocaProduto();
                dProduto* produtoAnt;
                do
                {
                    printf("Informe c�digo do produto a ser atualizado\n");
                    printf("->");
                    scanf("%d",&codigo);
                    fflush(stdin);
                    printf("\n");

                    produtoAnt = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),comparaCodProduto);
                    if(produtoAnt != NULL)
                    {
                        printf("Produto a ser atualizado: \n");
                        imprimeProdutos(produtoAnt);
                        printf("\n");

                        produtoAtt->codProd = codigo;

                        printf("Informe nova descri��o/nome:\n");
                        printf("->");
                        fgets(produtoAtt->descricao,sizeof(produtoAtt->descricao),stdin);
                        produtoAtt->descricao[strcspn(produtoAtt->descricao,"\n")] = '\0';
                        fflush(stdin);
                        printf("\n");

                        printf("Infome novo pre�o do produto:\n");
                        printf("->");
                        scanf("%f",&produtoAtt->preco);
                        fflush(stdin);
                        printf("\n");

                        printf("Informe nova quantidade em estoque:\n");
                        printf("->");
                        scanf("%d",&produtoAtt->quantidadeEstoque);
                        fflush(stdin);
                        printf("\n");

                        printf("Novos dados do produto:\n");
                        imprimeProdutos(produtoAtt);

                        printf("Confirmar atualiza��o do produto? (0 - N�o | 1 - Sim):\n");
                        printf("->");
                        scanf("%d",&opc);
                        fflush(stdin);
                        printf("\n");
                        if(opc == 1)
                        {
                            update(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),produtoAtt,comparaCodProduto);
                            printf("Produto atualizado com sucesso\n");
                        }
                    }
                    else
                    {
                        printf("Produto n�o encontrado no banco de dados\n");

                    }

                    printf("Continuar atualizando produtos? (0 - N�o | 1 - Sim):\n");
                    printf("->");
                    scanf("%d",&opc);
                    fflush(stdin);
                    printf("\n");

                }
                while(opc == 1);



                break;
            case 5:
                return 1;
                break;
            case 6:
                return 2;
                break;
            }


            break;
        case 4: //DELETAR
            printf("Informe c�digo do produto a ser deletado:\n");
            printf("->");
            scanf("%d",&codigo);
            fflush(stdin);

            produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),comparaCodProduto);
            if(produto != NULL)
            {
                printf("Produto encontrado:\n");
                imprimeProdutos(produto);

                do
                {
                    printf("Deletar Produto? (0 - N�o | 1 - Sim)\n");
                    printf("Obs: Essa informa��o n�o poder� ser recuperada e provavelmente deixar� falhas no banco de dados\n");
                    printf("->");
                    scanf("%d",&op);
                    printf("\n");
                    fflush(stdin);
                    if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                }
                while(op < 0 || op > 1);

                if(op == 1)
                {
                    deletee(open(TB_PRODUTOS,sizeof(dProduto)),TB_PRODUTOS,alocaInt(codigo),comparaCodProduto);
                    printf("Produto deletado com sucesso\n");
                }
                else if(op == 0)
                {
                    printf("Opera��o cancelada\n");
                }


            }
            else
            {
                printf("Produto n�o encontrado no banco de dados (menuProduto/switch 3 / switch 1)\n");
            }

            break;
        case 5:
            return 1; //VOLTAR MENU
            break;
        case 6:
            return 2; //REALIZAR LOGOUT
            break;
        }
    }
    while(crtl == 1);
    return 1;
}


int menuCliente()
{
    int op, crtl = 1;
    pDFile arq = NULL;
    unsigned long long codigo;
    dCliente* cliente;
    do
    {
        do
        {
            printf("1- Cadastrar cliente\n");
            printf("2- Visualizar clientes\n");
            printf("3- Atualizar cliente\n");
            printf("4- Deletar cliente\n");
            printf("5- Pagar valores em cr�dito\n");
            printf("6- Voltar ao Menu\n");
            printf("7- Realizar logout\n");
            printf("->");
            scanf("%d",&op);
            printf("\n");
            fflush(stdin);
            if(op < 1 || op > 7) printf("Op��o Inv�lida\t|\tInforme novamente\n");
        }
        while(op < 1 || op > 7);

        switch(op)
        {
        case 1: //CADASTRAR
            do
            {

                leCliente();

                do
                {
                    printf("1 - Cadastrar novamente\n");
                    printf("2 - Voltar ao menu\n");
                    printf("3 - Realizar logout\n");
                    printf("->");
                    scanf("%d",&op);
                    fflush(stdin);
                    printf("\n");
                    if(op < 1 || op > 3) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                }
                while(op < 1 || op > 3);

            }
            while(op == 1);
            if(op == 2)
            {
                return  1;
            }
            else if (op == 3)
            {
                return 2;
            }

            break;
        case 2: //VIZUALIZAR
            do //MENU VIZUALIZAR
            {
                printf("1 - Visualizar todos os clientes cadastrados\n");
                printf("2 - Visualizar cliente espec�fico\n");
                printf("3 - Voltar ao menu\n");
                printf("4 - Realizar logout\n");
                printf("->");
                scanf("%d",&op);
                printf("\n");
                fflush(stdin);
                if(op < 1 || op > 4) printf("Op��o Inv�lida\t|\tInforme novamente\n");
            }
            while(op < 1 || op > 4);

            if(op == 1) //IMPRIMIR TODOS OS CLIENTES
            {
                pDLista pListaClientes = queryAll(open(TB_CLIENTE,sizeof(dCliente)));
                if(pListaClientes != NULL)
                {
                    printf("Lista de Clientes atuais:\n");
                    imprimirLista(pListaClientes,imprimeCliente);
                    printf("\n");
                }
                else
                {
                    printf("Clientes n�o encontrados no banco de dados\n");
                    printf("\n");
                }
            }
            else if(op == 2) //VIZUALIZAR CLIENTE ESPECIFICO
            {

                do  //CONTINUAR BUSCANDO CLIENTE
                {

                    do  //VERIFICA OP��O ESCOLHIDA
                    {
                        printf("1 - Buscar por cpf\n");
                        printf("2 - Buscar por nome\n->");
                        scanf("%d",&op);
                        fflush(stdin);
                        printf("\n");
                        if(op < 1 || op > 2) printf("Op��o inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 1 || op > 2); //VERIFICA OP��O ESCOLHIDA

                    if(op == 1)
                    {

                        printf("Informe cpf para busca: \n");
                        printf("->");
                        scanf("%llu",&codigo);
                        printf("\n");
                        fflush(stdin);

                        cliente = retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(codigo),comparaCliente);

                        if(cliente == NULL)
                        {
                            printf("Cliente n�o encontrado\n");
                        }
                        else
                        {
                            printf("Cliente encontrado:\n");
                            imprimeCliente(cliente);
                            printf("\n");
                        }

                    }
                    else if(op == 2)
                    {

                        char nomeBuscaCliente[30];

                        printf("Informe nome para busca\n->");
                        fgets(nomeBuscaCliente,sizeof(nomeBuscaCliente),stdin);
                        nomeBuscaCliente[strcspn(nomeBuscaCliente,"\n")] = '\0';
                        printf("\n");
                        fflush(stdin);

                        cliente = (dCliente*) retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaChar(nomeBuscaCliente),comparaNomeCliente);

                        if(cliente == NULL)
                        {
                            printf("Cliente n�o encontrado\n");
                        }
                        else
                        {
                            printf("Cliente Encontrado:\n");
                            imprimeCliente(cliente);
                        }
                    }
                    printf("Continuar buscando clientes? (0 - N�o | 1 - Sim)\n");
                    printf("->");
                    scanf("%d",&op);
                    fflush(stdin);
                    printf("\n");
                }
                while(op == 1);  //CONTINUAR BUSCANDO CLIENTE
            }
            else if(op == 3)
            {
                return 1;
            }
            else if(op == 4)
            {
                return 2;
            }


            break;
        case 3: //ATUALIZAR
            do
            {
                printf("1 - Atualizar Nome\n");
                printf("2 - Atualizar Limite de Cr�dito\n");
                printf("3 - Atualizar Status\n");
                printf("4 - Voltar ao Menu\n");
                printf("5 - Realizar Logout\n");
                printf("->");
                scanf("%d",&op);
                printf("\n");
                fflush(stdin);
                if(op < 1 || op > 6) printf("Op��o Inv�lida\t|\tInforme novamente\n");
            }
            while(op < 1 || op > 6);

            switch(op)
            {

            case 1:

                printf("Informe cpf do cliente a ser atualizado\n");
                printf("->");
                scanf("%llu",&codigo);
                printf("\n");
                fflush(stdin);

                cliente = (dCliente*) retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(codigo),comparaCliente);

                if(cliente != NULL)
                {

                    printf("Cliente encontrado:\n");
                    imprimeCliente(cliente);


                    printf("Informe novo nome:\n");
                    printf("->");
                    fgets(cliente->nome,sizeof(cliente->nome),stdin);
                    cliente->nome[strcspn(cliente->nome,"\n")] = '\0';
                    fflush(stdin);
                    printf("\n");
                    do
                    {
                        printf("Confirmar atualiza��o? (0 - N�o | 1 - Sim)\n");
                        printf("->");
                        scanf("%d",&op);
                        printf("\n");
                        fflush(stdin);
                        if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 0 || op > 1);
                    if(op == 1)
                    {
                        arq = open(TB_CLIENTE,sizeof(dCliente));
                        update(arq,alocaLLU(codigo),cliente,comparaCliente);
                        close(arq);
                        printf("Nome atualizado\n");
                    }
                    else
                    {
                        printf("Opera��o cancelada\n");
                    }

                }
                else
                {
                    printf("Cliente n�o encontrado no banco de dados (menuCLiente/switch 3 / switch 1)\n");
                }

                break;
            case 2:

                printf("Informe cpf do cliente a ser atualizado:\n");
                printf("->");
                scanf("%llu",&codigo);
                printf("\n");
                fflush(stdin);

                cliente = (dCliente*) retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(codigo),comparaCliente);

                if(cliente!= NULL)
                {

                    printf("Cliente encontrado:\n");
                    imprimeCliente(cliente);

                    do
                    {
                        printf("Informe novo limite de cr�dito:\n");
                        printf("->");
                        scanf("%f",&cliente->limiteCredito);
                        printf("\n");
                        fflush(stdin);
                        if(cliente->limiteCredito < 0) printf("Imposs�vel atribuir limite de cr�dito negativo\t|\tInforme novamente\n");
                    }
                    while(cliente->limiteCredito < 0);

                    do
                    {
                        printf("Confirmar atualiza��o? (0 - N�o | 1 - Sim)\n");
                        printf("->");
                        scanf("%d",&op);
                        printf("\n");
                        fflush(stdin);
                        if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 0 || op > 1);

                    if(op == 1)
                    {
                        arq = open(TB_CLIENTE,sizeof(dCliente));
                        update(arq,alocaLLU(codigo),cliente,comparaCliente);
                        close(arq);
                        printf("Limite de cr�dito atualizado\n");
                    }
                    else
                    {
                        printf("Opera��o cancelada\n");
                    }

                }
                else
                {
                    printf("Cliente n�o encontrado no banco de dados (menuCliente/switch 3 / switch 2)\n");
                }


                break;
            case 3:

                printf("Informe cpf do cliente a ser atualizado:\n");
                printf("->");
                scanf("%llu",&codigo);
                printf("\n");
                fflush(stdin);

                cliente = (dCliente*) retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(codigo),comparaCliente);

                if(cliente != NULL)
                {

                    printf("Cliente encontrado\n");
                    imprimeCliente(cliente);

                    if(cliente->status == QUITADO)
                    {
                        do
                        {
                            printf("DESATIVAR cliente?(0 - N�o | 1 - Sim):\n");
                            printf("->");
                            scanf("%d",&op);
                            fflush(stdin);
                            printf("\n");
                            if (op < 0 || op > 1)printf("Op��o Inv�lida\t|\tInforme novamente\n");
                        }
                        while(op < 0 || op > 1);
                        if(op == 1)
                        {
                            cliente->status = DESATIVADO;
                            arq = open(TB_CLIENTE,sizeof(dCliente));
                            update(arq,alocaLLU(codigo),cliente,comparaCliente);
                            close(arq);
                        }
                        else
                        {
                            printf("Opera��o cancelada\n");
                        }
                    }
                    else if(cliente->status == DESATIVADO)
                    {
                        if(cliente->creditoAtual > 0)
                        {
                            printf("Cliente encontra com d�vidas\n");
                            printf("Para reativar conta, primeiro deve pagar o que est� em atraso\n");
                        }
                        else
                        {
                            do
                        {
                            printf("REATIVAR cliente?(0 - N�o | 1 - Sim):\n");
                            printf("->");
                            scanf("%d",&op);
                            fflush(stdin);
                            printf("\n");
                            if (op < 0 || op > 1)printf("Op��o Inv�lida\t|\tInforme novamente\n");
                        }
                        while(op < 0 || op > 1);
                        if(op == 1)
                        {
                            cliente->status = QUITADO;
                            arq = open(TB_CLIENTE,sizeof(dCliente));
                            update(arq,alocaLLU(codigo),cliente,comparaCliente);
                            close(arq);
                            printf("Cliente reativado com sucesso\n");
                        }
                        else
                        {
                            printf("Opera��o cancelada\n");
                        }
                        }
                    }
                    else
                    {
                        printf("N�o � poss�vel alterar o status atual do cliente\n");
                    }
                }
                else
                {
                    printf("Cliente n�o encontrado no banco de dados (menuCliente/switch 3 / switch 3)\n");
                }


                break;
            case 4:
                return 1;
                break;
            case 5:
                return 2;
                break;
            }


            break;
        case 4: //DELETAR
            printf("Informe cpf do cliente a ser deletado:\n");
            printf("->");
            scanf("%llu",&codigo);
            fflush(stdin);

            cliente = (dCliente*) retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(codigo),comparaCliente);
            if(cliente != NULL)
            {
                printf("Cliente encontrado:\n");
                imprimeCliente(cliente);

                do
                {
                    printf("Deletar Cliente? (0 - N�o | 1 - Sim)\n");
                    printf("Obs: Essa informa��o n�o poder� ser recuperada e provavelmente deixar� falhas no banco de dados\n");
                    printf("->");
                    scanf("%d",&op);
                    printf("\n");
                    fflush(stdin);
                    if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                }
                while(op < 0 || op > 1);

                if(op == 1)
                {
                    arq = open(TB_CLIENTE,sizeof(dCliente));
                    deletee(arq,TB_CLIENTE,alocaLLU(codigo),comparaCliente);
                    close(arq);
                    printf("Cliente deletado com sucesso\n");
                }
                else if(op == 0)
                {
                    printf("Opera��o cancelada\n");
                }


            }
            else
            {
                printf("Cliente n�o encontrado no banco de dados (menuCliente/switch 4)\n");
            }
            break;
        case 5:
                printf("Informe cpf do cliente a pagar\n");
                printf("->");
                scanf("%llu",&codigo);
                printf("\n");
                fflush(stdin);

                cliente = (dCliente*) retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(codigo),comparaCliente);

                if(cliente != NULL)
                {
                    printf("Cliente encontrado:\n");
                    imprimeCliente(cliente);


                    float valor;
                    printf("Informe valor em haver a ser pago:\n");
                    printf("->");
                    scanf("%f",&valor);
                    fflush(stdin);
                    printf("\n");
                    do
                    {
                        printf("Confirmar atualiza��o do cr�dito atual? (0 - N�o | 1 - Sim)\n");
                        printf("->");
                        scanf("%d",&op);
                        printf("\n");
                        fflush(stdin);
                        if (op < 0 || op > 1) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                    }
                    while(op < 0 || op > 1);
                    if(op == 1)
                    {
                        cliente->creditoAtual += valor;
                        if(cliente->creditoAtual == cliente->limiteCredito){

                            printf("Status do cliente atualizado para QUITADO\n");
                            cliente->status = QUITADO;

                        }else if(cliente->creditoAtual > cliente->limiteCredito){
                            cliente->creditoAtual = cliente->limiteCredito;
                            printf("Status do cliente atualizado para QUITADO\n");
                            cliente->status = QUITADO;

                        }else if(cliente->creditoAtual < cliente->limiteCredito){
                            printf("Cliente ainda se encontra devendo %.2f\n",cliente->limiteCredito - cliente->creditoAtual);
                            cliente->status = DEVENDO;

                        }
                        arq = open(TB_CLIENTE,sizeof(dCliente));
                        update(arq,alocaLLU(codigo),cliente,comparaCliente);
                        close(arq);
                        printf("Cr�dito atualizado\n");
                    }
                    else
                    {
                        printf("Opera��o cancelada\n");
                    }

                }
                else
                {
                    printf("Cliente n�o encontrado no banco de dados (menuCLiente/switch 5)\n");
                }

            break;
        case 6:
            return 1; //VOLTAR MENU
            break;
        case 7:
            return 2; //REALIZAR LOGOUT
            break;
        }
    }
    while(crtl == 1);
    return 1;

}

int  menuVenda()
{
    int op, crtl = 1, sw,codigo;
    float valor;
    unsigned long long cpf;
    dCliente* cliente;
    dProduto* produto;
    dProdVenda* prodVenda;
    dVenda* venda;
    pDLista pListaVenda;
    pDLista pListaProdVenda;
    do
    {
        printf("1- Realizar Venda\n");
        printf("2- Visualizar Vendas\n");
        printf("3- Atualizar Venda\n");
        printf("4- Deletar Venda\n");
        printf("5- Voltar ao Menu\n");
        printf("6- Realizar logout\n");
        printf("->");
        scanf("%d",&op);
        printf("\n");
        fflush(stdin);
        if(op < 1 || op > 6) printf("Op��o Inv�lida\t|\tInforme novamente\n");
    }
    while(op < 1 || op > 6);

    switch(op)
    {
    case 1:
        do
        {
            leVenda();
            printf("\n");
            printf("Continuar vendendo: (0- N�o | 1 - Sim)\n");
            printf("->");
            scanf("%d",&sw);
            fflush(stdin);
            printf("\n");

        }
        while(sw == 1);
        break;
    case 2:

        do
        {
            printf("1- Vizualizar todas as vendas\n");
            printf("2- Vizualizar venda espec�fica\n");
            printf("->");
            scanf("%d",&sw);
            fflush(stdin);
            printf("\n");
            if(sw < 1 || sw > 2) printf("Op��o Inv�lida\t|\tInforme novamente\n");
        }
        while(sw < 1 || sw > 2);

        if(sw == 1)
        {
            pListaVenda = queryAll(open(TB_VENDA,sizeof(dVenda)));
            if(pListaVenda != NULL)
            {
                printf("Vendas cadastradas no banco de dados:\n");
                imprimirLista(pListaVenda,imprimeVenda);
                printf("\n");
            }
            else
            {
                printf("Nenhuma venda encontrada no banco de dados\n");
            }
            system("pause");
            printf("\n");
        }
        else if(sw == 2)
        {
            do
            {
                printf("1- Buscar por c�digo da venda\n");
                printf("2- Filtrar vendas\n");
                printf("->");
                scanf("%d",&sw);
                fflush(stdin);
                printf("\n");
                if(sw < 1 || sw > 2) printf("Op��o Inv�lida\t|\tInforme novamente\n");
            }
            while(sw < 1 || sw > 2);

            if(sw == 1)
            {
                printf("Informe n�mero da venda:\n");
                printf("->");
                scanf("%d",&codigo);
                printf("\n");
                fflush(stdin);
                venda = (dVenda*)retrieve(open(TB_VENDA,sizeof(dVenda)),alocaInt(codigo),comparaNumVenda);
                imprimeVenda(venda);
                printf("\n");
                system("pause");
            }
            else
            {
                do
                {
                    printf("Filtrar por:\n");
                    printf("1- Cpf Cliente\n");
                    printf("2- C�digo produto\n");
                    printf("3- Valor maior que (>)\n");
                    printf("4- Valor menor que (<)\n");
                    printf("->");
                    scanf("%d",&op);
                    fflush(stdin);
                    printf("\n");
                    if(op < 1 || op > 4) printf("Op��o Inv�lida\t|\tInforme novamente\n");
                }
                while(op < 1 || op > 4);

                switch(op)
                {
                case 1:
                    printf("Informe CPF do cliente:\n");
                    printf("->");
                    scanf("%llu",&cpf);
                    printf("\n");
                    fflush(stdin);
                    cliente = (dCliente*)retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(cpf),comparaCliente);
                    if (cliente != NULL)
                    {
                        printf("Cliente: \n");
                        imprimeCliente(cliente);
                        printf("\n");
                        openFiltro(alocaLLU(cpf),sizeof(unsigned long long));
                        pListaVenda = queryBy(open(TB_VENDA,sizeof(dVenda)),filtraCPF);
                        if(pListaVenda == NULL)
                        {
                            printf("Cliente n�o possui vendas em seu nome (menuVenda/ switch 3/ switch 1)\n");
                        }
                        else
                        {
                            printf("Vendas: \n");
                            imprimirLista(pListaVenda,imprimeVenda);
                            printf("\n");
                        }
                    }
                    else
                    {
                        printf("Cliente n�o encontrado no banco de dados (menuVenda/ switch 3/ switch 1)\n");
                    }

                    break;
                case 2:
                    printf("Informe c�digo do produto:\n");
                    printf("->");
                    scanf("%d",&codigo);
                    printf("\n");
                    fflush(stdin);
                    produto = (dProduto*)retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(codigo),comparaCodProduto);
                    if (produto != NULL)
                    {

                        printf("Produto: \n");
                        imprimeProdutos(produto);
                        printf("\n");

                        openFiltro(alocaInt(codigo),sizeof(int));
                        pListaProdVenda = queryBy(open(TB_PRODUTO_VENDA,sizeof(dProdVenda)),comparaCodProdVenda);

                        if(pListaProdVenda != NULL)
                        {

                            pNoh pAux = pListaProdVenda->primeiro;
                            pListaVenda = criarLista();


                            while(pAux != NULL)
                            {
                                prodVenda = (dProdVenda*) pAux->info;
                                venda = (dVenda*) retrieve(open(TB_VENDA,sizeof(dVenda)),alocaInt(prodVenda->codVenda),comparaNumVenda);
                                if(venda != NULL)
                                {
                                    incluirInfo(pListaVenda,venda);
                                }
                                pAux = pAux->prox;
                            }

                            if(pListaVenda->primeiro == NULL)
                            {
                                printf("N�o h� vendas com esse produto no banco de dados (menuVenda/ switch 3/ switch 2)\n");
                            }
                            else
                            {
                                printf("Vendas: \n");
                                imprimirLista(pListaVenda,imprimeVenda);
                                printf("\n");
                            }

                        }
                        else
                        {
                            printf("N�o h� vendas com esse produto (menuVenda/ switch 3/ switch 2)\n");
                        }
                    }
                    else
                    {
                        printf("Produto n�o encontrado no banco de dados (menuVenda/ switch 3/ switch 2)\n");
                    }

                    break;
                case 3:
                    printf("Informe valor para filtrar:\n");
                    printf("->");
                    scanf("%f",&valor);
                    printf("\n");
                    fflush(stdin);

                    openFiltro(alocaFloat(valor),sizeof(float));
                    pListaVenda = queryBy(open(TB_VENDA,sizeof(dVenda)),filtraMaiorQue);

                    if(pListaVenda == NULL)
                    {
                        printf("N�o h� vendas com valor total maior que %.2f (menuVenda/ switch 3/ switch 3)\n",valor);
                    }
                    else
                    {
                        printf("Vendas: \n");
                        imprimirLista(pListaVenda,imprimeVenda);
                        printf("\n");
                    }
                    break;


                case 4:
                    printf("Informe valor para filtrar:\n");
                    printf("->");
                    scanf("%f",&valor);
                    printf("\n");
                    fflush(stdin);

                    openFiltro(alocaFloat(valor),sizeof(float));
                    pListaVenda = queryBy(open(TB_VENDA,sizeof(dVenda)),filtraMenorQue);

                    if(pListaVenda == NULL)
                    {
                        printf("N�o h� vendas com valor total menor que %.2f (menuVenda/ switch 3/ switch 3)\n",valor);
                    }
                    else
                    {
                        printf("Vendas: \n");
                        imprimirLista(pListaVenda,imprimeVenda);
                        printf("\n");
                    }
                    break;
                }
            }
        }
        system("pause");
        break;
    case 3:
            printf("Informe n�mero da venda: \n");
            printf("->");
            scanf("%d",&codigo);
            fflush(stdin);
            printf("\n");
            venda = (dVenda*)retrieve(open(TB_VENDA,sizeof(dVenda)),alocaInt(codigo),comparaNumVenda);
            if(venda != NULL){
                printf("Venda: \n");
                imprimeVenda(venda);
                do{
                printf("1 - Atualizar cliente respons�vel\n");
                printf("2 - Atualizar data da venda\n");
                printf("3 - Voltar ao menu\n");
                printf("->");
                scanf("%d",&op);
                fflush(stdin);
                printf("\n");
                if(op < 1 || op > 3)printf("Op��o Inv�lida\t|\tInforme novamente\n");
                }while(op < 1 || op > 3);

                if(op == 1){
                    printf("Informe cpf do novo cliente respons�vel:\n");
                    printf("->");
                    scanf("%llu",&venda->cpf);
                    fflush(stdin);
                    printf("\n");
                }else
                if(op == 2){
                    printf("Infome nova data: (dd mm yyyy)\n");
                    printf("->");
                    scanf("%d %d %d",&venda->Data.dia,&venda->Data.mes,&venda->Data.ano);
                    fflush(stdin);
                    printf("\n");
                }else
                if (op == 3){
                    return 1;
                }
                printf("Novos dados da venda: \n");
                imprimeVenda(venda);
                printf("\n");
                printf("Confirmar atualiza��o?(0 - N�o | 1 - Sim)\n");
                printf("->");
                scanf("%d",&op);
                if(op == 1){
                    update(open(TB_VENDA,sizeof(dVenda)),alocaInt(venda->numero),venda,comparaNumVenda);
                    printf("Venda atualizada com sucesso\n");
                }else{
                    printf("Opera��o cancelada\n");
                }



            }else{
                printf("Venda n�o encontrada no banco de dados(menuVenda / switch 3)\n");
            }
        break;
    case 4:
        printf("Informe n�mero da venda: \n");
            printf("->");
            scanf("%d",&codigo);
            fflush(stdin);
            printf("\n");
            venda = (dVenda*)retrieve(open(TB_VENDA,sizeof(dVenda)),alocaInt(codigo),comparaNumVenda);
            if(venda != NULL){
                printf("Venda: \n");
                imprimeVenda(venda);
                printf("Deseja realmente deletar a venda?(0 - N�o | 1 - Sim)\n");
                printf("->");
                scanf("%d",&op);
                fflush(stdin);
                if(op == 1){
                    deletee(open(TB_VENDA,sizeof(dVenda)),TB_VENDA,alocaInt(venda->numero),comparaNumVenda);
                    printf("Venda deletada com sucesso\n");
                }else{
                    printf("Opera��o cancelada\n");
                }



            }else{
                printf("Venda n�o encontrada no banco de dados(menuVenda / switch 3)\n");
            }

        break;
    case 5:
        return 1;
        break;
    case 6:
        return 2;
    break;

    }
    return 1;

}

int comparaNumVenda(void* dados, void* chave)
{
    dVenda* venda = (dVenda*) dados;
    if(venda->numero == *(int*)chave)
    {
        return 0;
    }
    return 1;
}
int comparaCodProdVenda(void* dados)
{
    pDFile arq = open(FILTROS,sizeof(int));
    if(arq->arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo (comparaCodProdVenda)\n");
        return;
    }
    rewind(arq->arquivo);
    int* codigo;
    fread(codigo,sizeof(int),1,arq->arquivo);
    close(arq);
    dProdVenda* prodVenda = (dProdVenda*) dados;
    if(prodVenda->codProd == *codigo)
    {
        return 0;
    }
    return 1;
}
int comparaCodVendaProd(void* dados)
{
    pDFile arq = open(FILTROS,sizeof(int));
    if(arq->arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo (comparaCodProdVenda)\n");
        return;
    }
    rewind(arq->arquivo);
    int* codigo = malloc(sizeof(int));
    fread(codigo,sizeof(int),1,arq->arquivo);
    close(arq);
    dProdVenda* prodVenda = (dProdVenda*) dados;
    if(prodVenda->codVenda == *codigo)
    {
        return 0;
    }
    return 1;
}

int filtraCPF(void* dados)
{
    pDFile arq = open(FILTROS,sizeof(unsigned long long));
    if(arq->arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo (filtraCPF)\n");
        return;
    }
    rewind(arq->arquivo);
    unsigned long long* cpf;
    fread(cpf,sizeof(unsigned long long),1,arq->arquivo);
    close(arq);
    dVenda* venda = (dVenda*) dados;
    if(venda->cpf == *cpf)
    {
        return 0;
    }
    return 1;
}
int filtraMaiorQue(void* dados)
{
    pDFile arq = open(FILTROS,sizeof(float));
    if(arq->arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo (maiorQue)\n");
        return;
    }
    rewind(arq->arquivo);
    float* valorComp;
    fread(valorComp,sizeof(float),1,arq->arquivo);
    close(arq);
    dVenda* venda = (dVenda*) dados;
    if(venda->PrecoVenda >= *valorComp)
    {
        return 0;
    }
    return 1;
}
int filtraMenorQue(void* dados)
{
    pDFile arq = open(FILTROS,sizeof(float));
    if(arq->arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo (maiorQue)\n");
        return;
    }
    rewind(arq->arquivo);
    float* valorComp;
    fread(valorComp,sizeof(float),1,arq->arquivo);
    close(arq);
    dVenda* venda = (dVenda*) dados;
    if(venda->PrecoVenda <= *valorComp)
    {
        return 0;
    }
    return 1;
}

void openFiltro(void* dados,int tam)
{
    FILE* arq = fopen(FILTROS,"wb+");
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo (openFiltro)\n");
        return;
    }
    fwrite(dados,tam,1,arq);
    fclose(arq);
}
void leVenda()
{
    pDLista pListaProdutos = criarLista(); //CRIA UMA LISTA DOS PRODUTOS QUE V�O SER VENDIDOS
    dVenda* venda = alocaVenda();
    dCliente* cliente;
    dProduto* produto;
    dProdVenda* prodVenda = alocaProdVenda();
    float valorTotal = 0;
    char conf = 'N';
    int op = 0,forma, ctrl = 0, codProd;

    do
    {

        venda->status = QUITADO;

        printf("Informe cpf do cliente: ");
        scanf("%llu",&venda->cpf);
        cliente = (dCliente*)retrieve(open(TB_CLIENTE,sizeof(dCliente)),&venda->cpf,comparaCliente);

        if(cliente == NULL)
        {
            printf("Cliente n�o existente no banco de dados\n");
        }
        else
        {
            printf("Clinte: %s\n",cliente->nome);
        }
        if(cliente->status == DESATIVADO || cliente->status == EM_ATRASO)
        {
            printf("Cliente desativado | Reative para poder gerar vendas\n");
            op = 0;
        }
        else
        {
            printf("Continuar venda?(0 - N�o/1 - Sim): \n");
            printf("->");
            scanf("%d",&op);
            fflush(stdin);
        }
        if(op == 0) return;

        printf("Informe data (dd mm aaaa): ");
        scanf("%d %d %d",&venda->Data.dia,&venda->Data.mes,&venda->Data.ano);
        fflush(stdin);

        venda->numero = geraCodVend(); //GERA C�DIGO AUTOMATICO DA VENDA

        do  //CONTINUAR ADICIONANDO PRODUTOS
        {

            do  //CONFIRMA VENDA DO PRODUTO X
            {

                prodVenda->codVenda = venda->numero;

                printf("Informe codigo do produto: "); //PEDE CODIGO DO PRODUTO PARA BUSCA
                scanf("%d",&prodVenda->codProd);
                fflush(stdin);

                printf("\n");
                produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(prodVenda->codProd),comparaCodProduto); //PEGA OS DADOS DO PRODUTO
                imprimeProdutos(produto);

                do  //VERIFICA SE A QUANTIDADE SE TEM EM ESTOQUE A QUANTIDADE SUFICIENTE PARA VENDA
                {

                    printf("Informe quantidade do produto: ");
                    scanf("%d",&prodVenda->quantidade);
                    fflush(stdin);

                    if(prodVenda->quantidade > produto->quantidadeEstoque)
                    {
                        printf("Saldo insuficiente em estoque\n");
                        printf("Informe nova quantidade\n");
                    }
                }
                while(prodVenda->quantidade > produto->quantidadeEstoque);  //VERIFICA SE A QUANTIDADE SE TEM EM ESTOQUE A QUANTIDADE SUFICIENTE PARA VENDA

                printf("Confirmar adi��o do produto: %s | (S/N)\n",produto->descricao);
                scanf("%c",&conf);
                fflush(stdin);

                if(conf == 's' || conf == 'S')
                {
                    valorTotal += (produto->preco * prodVenda->quantidade); //CALCULA O VALOR DA VENDA
                    incluirInfo(pListaProdutos,prodVenda); //INCLUI O PRODUTO ESCOLHIDO NA LISTA DE PRODUTOS_VENDA
                }
            }
            while(conf == 'n' || conf == 'N');  //CONFIRMA VENDA DO PRODUTO X

            printf("Valor Parcial: %.2f\n",valorTotal);

            printf("Adicionar mais algum produto? (0-N�o,1-Sim): ");
            scanf("%d",&op);
            fflush(stdin);

        }
        while(op == 1);  //CONTINUAR ADICIONANDO PRODUTOS

        do  //VFRIFICA SE FORMA DE PAGAMENTO � V�LIDA
        {
            printf("Valor Total: %.2f\n",valorTotal);
            printf("Escolha forma de pagamento\t");
            printf("(1 - � vista \t||\t 2- � prazo)\n");
            scanf("%d",&forma);
            fflush(stdin);

            if(forma == 2)
            {
                if( cliente->creditoAtual >= valorTotal)
                {
                    ctrl = 1;
                    printf("Limite suficiente\n");
                    venda->status = DEVENDO;
                }
                else
                {
                    printf("Limite de cr�dito insuficiente\n");
                    printf("Informe outra forma de pagamento ou exclua a venda\n");
                    ctrl = 0;
                }
            }else{
                ctrl = 1;
            }
        }
        while(ctrl == 0); //VFRIFICA SE FORMA DE PAGAMENTO � V�LIDA

        printf("Finalizar Venda? S/N\n");
        scanf("%c",&conf);
        fflush(stdin);
        if(conf == 'S' || conf == 's')
        {
            if(forma == 2)
            {
                printf("Limite de cr�dito atualizado\n");
                cliente->creditoAtual -= valorTotal; //DESCONTA O VALOR DA VENDA DO CR�DITO DO CLIENTE
                cliente->status = DEVENDO; //ATUALIZA O STATUS DO CLIENTE PARA DEVENDO
                update(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(cliente->cpf),cliente,comparaCliente);
            }
            venda->PrecoVenda = valorTotal;
            pDFile arq = open(TB_VENDA,sizeof(dVenda));
            createe(arq,venda); //CADASTRA A VENDA NO BANCO DE DADOS
            close(arq);
            persistAll(open(TB_PRODUTO_VENDA,sizeof(dProdVenda)),pListaProdutos); //CADASTRA TODOS OS PRODUTO_VENDAS NA TABELA RELACIONAL
            printf("Venda realizada com sucesso\n");
            atualizaEstoque(pListaProdutos); //ATUALIZA O ESTOQUE DOS PRODUTOS VENDIDOS
            imprimeVenda(venda);
        }
        else
        {
            printf("Venda Cancelada\n");
            retornaCodVenda();
        }

        printf("Deseja continuar cadastrando? (0-N�o,1-Sim)\n");
        scanf("%d",&op);
        fflush(stdin);

        valorTotal = 0;
    }
    while(op == 1);  //VERIFICA SE DESEJA REALIZAR OUTRA VENDA

}


void atualizaEstoque(pDLista pLista)
{
    if(pLista == NULL)
    {
        printf("Lista inexistente (atualizaEstoque)\n");
        return;
    }
    pNoh pAux = pLista->primeiro;
    dProduto* produto;
    dProdVenda* prodVenda;
    while(pAux != NULL)
    {
        prodVenda = (dProdVenda*) pAux->info;

        produto = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(prodVenda->codProd),comparaCodProduto);
        produto->quantidadeEstoque -= prodVenda->quantidade;
        update(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(produto->codProd),produto,comparaCodProduto);

        pAux = pAux->prox;
    }
    free(pLista);
}

void imprimeProdVenda(dProdVenda* prodVenda){
    printf("Venda: %d\tCodProduto: %d\tQuantidade: %d\n",prodVenda->codVenda,prodVenda->codProd,prodVenda->quantidade);
}

void leProduto()
{
    dProduto* produto = alocaProduto();
    dProduto* produto_ao = alocaProduto();
    char conf = 'N';
    int op = 0;
        do  //VERIFICA SE J� EXISTE MESMA DESCRI��O PARA PRODUTO X
        {

            printf("Informe descri��o do produto: ");
            fgets(produto->descricao,sizeof(produto->descricao),stdin);
            produto->descricao[strcspn(produto->descricao,"\n")] = '\0';
            fflush(stdin);

            produto_ao = (dProduto*) retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaChar(produto->descricao),comparaDescProd);
            if(produto_ao != NULL)
            {
                printf("Produto com mesma descri��o existente\n");
                printf("Cadastre novamente o produto com mais informa��es\n");
                op = 1;
            }
            else
            {
                op = 0;
            }

        }
        while(op == 1);  //VERIFICA SE J� EXISTE MESMA DESCRI��O PARA PRODUTO X


        printf("Informe pre�o do produto: ");
        scanf("%f",&produto->preco);
        fflush(stdin);

        printf("Informe quantidade em estoque do produto: ");
        scanf("%d",&produto->quantidadeEstoque);
        fflush(stdin);

        printf("Confirmar cadastramento? S/N\n");
        scanf("%c",&conf);
        fflush(stdin);

        if(conf == 'S' || conf == 's')
        {
            produto->codProd = geraCodProd();
            pDFile arq = open(TB_PRODUTOS,sizeof(dProduto));
            createe(arq,produto);
            close(arq);
        }
        else
        {
            printf("Produto n�o cadastrado\n");
        }

        printf("Deseja continuar cadastrando? (0-N�o,1-Sim)\n");
        scanf("%d",&op);
        fflush(stdin);
}


void leCliente()
{
    dCliente* cliente = alocaCliente();
    dCliente* pessoa = alocaCliente();
    char conf = 'N';
    int op = 0,exist;

        do  //VERIFICA SE J� EXISTE CLIENTE CADASTRADO
        {
            printf("Informe cpf:\n");
            printf("->");
            scanf("%llu",&cliente->cpf);
            printf("\n");
            fflush(stdin);

            pessoa = (dCliente*) retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaLLU(cliente->cpf),comparaCliente);
            if(pessoa != NULL)
            {
                printf("Cpf j� existente no banco de dados\n");
                imprimeCliente(pessoa);
                printf("Informe novamente os dados, ou delete cadastro repetido\n");
                exist = 1;
            }
            else
            {
                exist = 0;
            }
            fflush(stdin);

        }
        while(exist == 1);  //VERIFICA SE J� EXISTE CLIENTE CADASTRADO

        printf("Informe nome:\n");
        printf("->");
        fgets(cliente->nome,sizeof(cliente->nome),stdin);
        cliente->nome[strcspn(cliente->nome,"\n")] = '\0';
        printf("\n");
        fflush(stdin);

        printf("Informe limite de cr�dito:\n");
        printf("->");
        scanf("%f",&cliente->limiteCredito);
        printf("\n");
        fflush(stdin);

        printf("Confirmar cadastramento?: S/N.\n");
        printf("->");
        scanf("%c",&conf);
        printf("\n");
        fflush(stdin);

        if(conf == 'S' || conf == 's'){
            cliente->status = QUITADO;
            cliente->creditoAtual = cliente->limiteCredito;
            pDFile arq = open(TB_CLIENTE,sizeof(dCliente));
            createe(arq,cliente);
            close(arq);
        }else{
            printf("Cliente n�o cadastrado\n");
        }
}
void imprimeVenda(dVenda* venda){

    dCliente* cliente = retrieve(open(TB_CLIENTE,sizeof(dCliente)),alocaInt(venda->cpf),comparaCliente);
    dProdVenda* prodVenda;
    dProduto* produto;

    printf("N�mero da venda: %d\n",venda->numero);
    printf("Cliente: %s\t\t",cliente->nome);
    printf("Data da venda: %d/%d/%d\n",venda->Data.dia,venda->Data.mes,venda->Data.ano);
    printf("Produtos: \n");


    openFiltro(alocaInt(venda->numero),sizeof(int));

    pDLista pListaProdVenda = queryBy(open(TB_PRODUTO_VENDA,sizeof(dProdVenda)),comparaCodVendaProd);
    pDLista pListaProdutos = criarLista();
    pNoh pAux = pListaProdVenda->primeiro;
    void* dados;
    while(pAux != NULL){

        prodVenda = (dProdVenda*) pAux->info;
        dados = retrieve(open(TB_PRODUTOS,sizeof(dProduto)),alocaInt(prodVenda->codProd),comparaCodProduto);
        incluirInfo(pListaProdutos,dados);
        pAux = pAux->prox;
    }
    pAux = pListaProdVenda->primeiro;
    pNoh pProd = pListaProdutos->primeiro;

    while(pProd != NULL){
        prodVenda = (dProdVenda*) pAux->info;
        produto = (dProduto*) pProd->info;
        printf("%d un - %s\n",prodVenda->quantidade, produto->descricao);
        pAux = pAux->prox;
        pProd = pProd->prox;
    }
    printf("Valor total da venda: %.2f\n",venda->PrecoVenda);

}
void* alocaCliente(){
    dCliente* cli = (dCliente*)malloc(sizeof(dCliente));
    return cli;
}
void* alocaProduto(){
    dProduto* prod = (dProduto*)malloc(sizeof(dProduto));
    return prod;
}
void* alocaVenda(){
    dVenda* venda = (dVenda*)malloc(sizeof(dVenda));
    return venda;
}
void* alocaProdVenda(){
    dProdVenda* prodVenda = (dProdVenda*)malloc(sizeof(dProdVenda));
    return prodVenda;
}


int geraCodProd(){
    int aux;

    FILE* arq = fopen(CONT_PROD,"rb+");
    fscanf(arq,"%d",&aux);
    fclose(arq);

    arq = fopen(CONT_PROD,"wb+");
    fprintf(arq, "%d", aux+1);
    fclose(arq);

    return aux;
}
int geraCodVend(){
    int aux;

    FILE* arq = fopen(CONT_VEND,"rb+");
    fscanf(arq,"%d",&aux);
    fclose(arq);

    arq = fopen(CONT_VEND,"wb+");
    fprintf(arq, "%d", aux+1);
    fclose(arq);

    return aux;
}
void deleteAll(char nome[30]){
    FILE* arq = fopen(nome,"wb+");
    if(arq != NULL){
        printf("Cadastros deletados\n");
    }else{
        printf("Erro ao deletar aquivos\n");
    }
    fclose(arq);
    if(strcmp(nome,TB_PRODUTOS) == 0){
        arq = fopen(CONT_PROD,"wb+");
        fprintf(arq,"0");
        fclose(arq);
    }else if(strcmp(nome,TB_VENDA) == 0){
        arq = fopen(CONT_VEND,"wb+");
        fprintf(arq,"0");
        fclose(arq);
    }
}
void imprimeProdutos(dProduto* produto){
    printf("C�digo do produto: %d\n",produto->codProd);
    printf("Descri��o do produto: %s\n",produto->descricao);
    printf("Pre�o do produto: %.2f\n",produto->preco);
    printf("Quantidade dispon�vel do produto: %d\n\n",produto->quantidadeEstoque);

}
void imprimeCliente(dCliente* cliente){
    printf("CPF: %llu\n",cliente->cpf);
    printf("NOME: %s\n",cliente->nome);
    printf("LIMITE DE CR�DITO: %.2f\n",cliente->limiteCredito);
    printf("CR�DITO ATUAL: %.2f\n",cliente->creditoAtual);
    switch(cliente->status){
    case QUITADO:
        printf("STATUS CLIENTE: QUITADO\n\n");
    break;
    case DEVENDO:
        printf("STATUS CLIENTE: DEVENDO\n\n");
    break;
    case EM_ATRASO:
        printf("STATUS CLIENTE: EM ATRASO\n\n");
    break;
    case DESATIVADO:
        printf("STATUS CLIENTE: DESATIVADO\n\n");
    break;
    }

}
int comparaCliente(void* dados,void* chave){
    dCliente* cliente = (dCliente*)dados;
    return cliente->cpf == *(unsigned long long*)chave ? 0 : 1;
}
int comparaDescProd(void* dados, void* chave){
    dProduto* produto = (dProduto*)dados;
    return strcmp(produto->descricao,chave);
}
int comparaNomeCliente(void* dados, void* chave){
    dCliente* cliente = (dCliente*) dados;
    return strcmp(cliente->nome,chave);
}

int comparaCodProduto(void* dados, void* chave){
    dProduto* produto = (dProduto*) dados;
    if(produto->codProd == *((int*)chave))
        return 0;
    else
        return 1;
}

void retornaCodVenda(){
    int aux;
    FILE* arq = fopen(CONT_VEND,"rb+");
    fscanf(arq,"%d",&aux);
    fclose(arq);

    arq = fopen(CONT_VEND,"wb+");
    fprintf(arq, "%d", aux-1);
    fclose(arq);
}



