#include <stdio.h>
#include <stdlib.h>
#define CONT_PROD "ContProd.xyz"
#define CONT_VEND "ContVend.xyz"
#define TB_CLIENTE "Clientes.xyz"
#define TB_PRODUTOS "Produtos.xyz"
#define TB_VENDA "Vendas.xyz"
#define TB_PRODUTO_VENDA "Produto_Venda.xyz"
#define FILTROS "Filtros.xyz"
#define QUITADO 0
#define DEVENDO 1
#define EM_ATRASO 2
#define DESATIVADO 3

#include "Cap3/Lista.h"

#include "Operacoes/0_structs.h"

#include "TAD_Persistencia.h"

#include "Operacoes/1_open.h"

#include "Operacoes/2_create.h"

#include "Operacoes/3_retrieve.h"

#include "Operacoes/4_update.h"

#include "Operacoes/5_delete.h"

#include "Operacoes/6_close.h"

#include "Operacoes/7_queryAll.h"

#include "Operacoes/8_query.h"

#include "Operacoes/9_persistAll.h"


