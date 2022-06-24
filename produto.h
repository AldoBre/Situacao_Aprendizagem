#ifndef PRODUTO_H
#define PRODUTO_H

//----------------------------------------------------------
// Definição do arquivo de persistência dos dados.
#define ARQUIVO_PRODUTOS "./db/produtos.txt"

//----------------------------------------------------------
// Estrutura de dados cliente.
typedef struct
{
    int codigoProduto;
    char descricao[100];
    float valor;
} Produto;

//----------------------------------------------------------
// Estrutura de dados cliente.
void imprimeProduto(Produto produto);
Produto cadastraProduto();
int carregarProdutosTxt(Produto *produto);
void salvarProdutoTXT(Produto *produto, int i_produtos);

#endif
