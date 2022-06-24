#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

//---------------------------------------------
// Função imprime estoque.

void imprimeEstoque(Estoque cadastraEstoque)
{
    printf("\n\n-------Estoque------\n\n");
    printf("CNPJ: %s\n", cadastraEstoque.cnpj);
    printf("Produto: %d\n", cadastraEstoque.codigoProduto);
    printf("Quantidade: %d\n", cadastraEstoque.quantidade);
}

//----------------------------------------------------------
// Função para cadastrar os dados de um estoque.
Estoque cadastraEstoque()
{

    Estoque cadastraEstoque;

    printf("Digite o CNPJ: ");
    gets(cadastraEstoque.cnpj);

    printf("Digite o código do Produto: ");
    scanf("%d", &cadastraEstoque.codigoProduto);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &cadastraEstoque.quantidade);

    fflush(stdin);

    return (cadastraEstoque);
}
//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo txt.
void salvarEstoquesTXT(Estoque *estoques, int i_estoques)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_ESTOQUES, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo estoques.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_estoques; n++)
    {
        fprintf(fp, "%s|%d|%d\n",
                estoques[n].cnpj,
                estoques[n].codigoProduto,
                estoques[n].quantidade);
    }

    fclose(fp);
}
//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarEstoquesTxt(Estoque *estoques)
{
    FILE *fp;
    char buffer[1024];
    int i_estoques = 0;

    if ((fp = fopen(ARQUIVO_ESTOQUES, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo estoques.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        strcpy((*(estoques + i_estoques)).cnpj, strtok(buffer, "|"));
        (*(estoques + i_estoques)).codigoProduto = atoi(strtok(NULL, "|"));
        (*(estoques + i_estoques)).quantidade = atoi(strtok(NULL, "|"));

        i_estoques++;
    }

    fclose(fp);

    return (i_estoques);
}
