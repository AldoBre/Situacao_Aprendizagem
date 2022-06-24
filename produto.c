#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

//----------------------------------------------------------
//
void imprimeProduto(Produto produto)
{
    printf("\n-----------------------------\n"
           "Informações do produto: \n"
           "\nCódigo: %d\n"
           "\nDescrição: %s\n"
           "\nValor: %.2f\n",
           produto.codigoProduto,
           produto.descricao,
           produto.valor);
}

//----------------------------------------------------------
//
Produto cadastraProduto()
{
    Produto cadastro;

    printf("\nInforme o código do produto: ");
    scanf("%d", &cadastro.codigoProduto);
    fflush(stdin);

    printf("\nInforme a descrição do produto: ");
    gets(cadastro.descricao);

    printf("\nInforme o valor do produto (R$): ");
    scanf("%f", &cadastro.valor);
    fflush(stdin);

    return cadastro;
}
//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo txt.
void salvarProdutoTXT(Produto *produto, int i_produtos)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_PRODUTOS, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_produtos; n++)
    {
        fprintf(fp, "%d|%s|%f\n",
                produto[n].codigoProduto,
                produto[n].descricao,
                produto[n].valor);
    }

    fclose(fp);
}

//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarProdutosTxt(Produto *produto)
{
    FILE *fp;
    char buffer[1024];
    int i_produto = 0;

    if ((fp = fopen(ARQUIVO_PRODUTOS, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        (*(produto + i_produto)).codigoProduto = atoi(strtok(buffer, "|"));
        strcpy((*(produto + i_produto)).descricao, strtok(NULL, "|"));
        (*(produto + i_produto)).valor = atof(strtok(NULL, "|"));

        i_produto++;
    }

    fclose(fp);

    return (i_produto);
}