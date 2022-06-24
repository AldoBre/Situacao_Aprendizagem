#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"
//---------------------------------------------
// Função imprime loja.

void listalojas(Loja novaloja)
{
    printf("\n\n-----LISTA DE LOJAS-----\n");
    printf("CNPJ: %s \n", novaloja.cnpj);
    printf("Nome: %s \n", novaloja.nome);
    printf("Segmento: %s \n", novaloja.segmento);
}

//----------------------------------------------------------
// Função para cadastrar os dados de uma loja.
Loja novaloja()
{

    Loja novaloja;

       printf("\n-----------------------------\n"
           "Cadastro de loja\n");
    printf("CNPJ: ");
    gets(novaloja.cnpj);

    printf("Nome: ");
    gets(novaloja.nome);

    printf("Segmento: ");
    gets(novaloja.segmento);
    fflush(stdin);

    return (novaloja);
}
//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo txt.
void salvarLojasTXT(Loja *lojas, int i_lojas)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_LOJAS, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo lojas.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_lojas; n++)
    {
        fprintf(fp, "%s|%s|%s\n",
                lojas[n].cnpj,
                lojas[n].nome,
                lojas[n].segmento);
    }

    fclose(fp);
}
//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarLojasTxt(Loja *lojas)
{
    FILE *fp;
    char buffer[1024];
    int i_lojas = 0;

    if ((fp = fopen(ARQUIVO_LOJAS, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo lojas.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        strcpy((*(lojas + i_lojas)).cnpj, strtok(buffer, "|"));
        strcpy((*(lojas + i_lojas)).nome, strtok(NULL, "|"));
        strcpy((*(lojas + i_lojas)).segmento, strtok(NULL, "|"));

        i_lojas++;
    }

    fclose(fp);

    return (i_lojas);
}