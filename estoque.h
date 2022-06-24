#ifndef ESTOQUE_H
#define ESTOQUE_H

//----------------------------------------------------------
// Definição do arquivo de persistência dos dados.
#define ARQUIVO_ESTOQUES "./db/estoques.txt"

//----------------------------------------------------------
// Estrutura de dados estoque.
typedef struct
{
    char cnpj[100];
    int codigoProduto;
    int quantidade;

} Estoque;

//----------------------------------------------------------
// Estrutura de dados estoque
Estoque cadastraEstoque();
void salvarEstoquesTXT(Estoque *estoques, int i_estoques);
void imprimeEstoque(Estoque cadastraEstoque);
int carregarEstoquesTxt(Estoque *estoques);
#endif