/**********************************************************
 *  SENAI - SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL
 *  Unidade Curricular: Lógica de programação
 *  Situação de aprendizagem
 *  Professor: Lucas Antunes
 *  Alunos: Aldo Bressan
 *  Luzerna, 26/05/2022
 **********************************************************/

//---------------------------------------------
// Bibliotecas.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "produto.h"
#include "cliente.h"
#include "loja.h"
#include "estoque.h"

#define MAX_VETOR 100

//---------------------------------------------
// Variáveis globais.
Cliente clientes[MAX_VETOR];
Produto produtos[MAX_VETOR];
Loja lojas[MAX_VETOR];
Estoque estoques[MAX_VETOR];
int i_clientes = 0; // Variável de índice do vetor.
int i_produto = 0;
int i_lojas = 0;
int i_estoques = 0;
int aux, aux1, k;
char aux3[MAX_VETOR], seguir;

//----------------------------------------------------------
// Função main.
int main()
{
    SetConsoleOutputCP((UINT)65001);

    i_clientes = carregarClientesTxt(clientes);
    i_produto = carregarProdutosTxt(produtos);
    i_lojas = carregarLojasTxt(lojas);
    i_estoques = carregarEstoquesTxt(estoques);

    while (1)
    {
        printf("\n\n\n"
               "======================================\n"
               "|      Bem vindo ao E-Commerce!      |\n"
               "|   Selecione uma das Opções a baixo |\n"
               "|                                    |\n"
               "| 1 - Área do lojista                |\n"
               "| 2 - Area do Cliente                |\n"
               "| 3 - Consulta de Estoque            |\n"
               "|[ESC] - Sair                        |\n"
               "======================================\n");

        switch (getch())
        {

        case '1':
            system("cls");
            printf("\n\n\n"
                   "======================================\n"
                   "|          Área do lojista           |\n\n"
                   "|   Selecine uma das opções a baixo: |\n\n"
                   "| 1 - Cadastro de Loja               |\n"
                   "| 2 - Lista de lojas                 |\n"
                   "| 3 - Cadastro de Produto            |\n"
                   "| 4 - Lista de Produtos              |\n"
                   "| 5 - Cadastrar Estoque              |\n"
                   "| 6 - Lista de Estoque               |\n"
                   "|[BACKSPACE] - Voltar ao menu        |\n"
                   "======================================\n");

            switch (getch())
            {

            case '1':
                if (i_lojas < MAX_VETOR)
                {
                    system("cls");
                    printf("\n\n\n"
                           "======================================\n"
                           "|         Cadastro de Loja           |\n"
                           "======================================\n");
                    lojas[i_lojas++] = novaloja();
                }
                else
                {
                    printf("\n [!] - Número máximo de cadastros atingidos!\n\n");
                }

                printf("\n [!] - Loja Cadastrada com sucesso!\n\n");
                system("Pause");
                system("cls");
                break;

            case '2':
                system("cls");
                printf("\n\n\n"
                       "======================================\n"
                       "|          Lista de lojas            |\n"
                       "======================================\n");
                for (int n = 0; n < i_lojas; n++)
                {
                    listalojas(lojas[n]);
                }
                system("pause");
                system("cls");
                break;

            case '3':
                if (i_produto < MAX_VETOR)
                {
                    system("cls");
                    printf("\n\n\n"
                           "======================================\n"
                           "|         Cadastro de Produtos       |\n"
                           "======================================\n");
                    produtos[i_produto++] = cadastraProduto();
                }
                else
                {
                    printf("\n [!] - Número máximo de cadastros atingidos!\n\n");
                }
                printf("\n [!] - Produto Cadastrado com sucesso!\n\n");
                system("Pause");
                system("cls");
                break;

            case '4':
                system("cls");
                printf("\n\n\n"
                       "======================================\n"
                       "|          Lista de Produtos         |\n"
                       "======================================\n");
                for (int n = 0; n < i_produto; n++)
                {
                    imprimeProduto(produtos[n]);
                }
                system("pause");
                break;

            case '5':
                system("cls");

                if (i_estoques < MAX_VETOR)
                {
                    system("cls");
                    printf("\n\n\n"
                           "======================================\n"
                           "|          Cadastro de Estoque        |\n"
                           "======================================\n");
                    estoques[i_estoques++] = cadastraEstoque();
                }
                else
                {
                    printf("\n [!] - Número máximo de cadastros atingidos!\n\n");
                }

                break;

            case '6':
                printf("\n\n\n"
                       "======================================\n"
                       "|          Lista de Estoque          |\n"
                       "======================================\n");
                for (int n = 0; n < i_estoques; n++)
                {
                    imprimeEstoque(estoques[n]);
                }
                break;

            case 8:
                system("cls");
                main();
                break;

            default:
                system("cls");
                printf("\n [!] - Opção Inválida!\n\n");
                break;
            }
            break;

        case '2':
            system("cls");
            printf("\n\n\n"
                   "======================================\n"
                   "|          Área do Cliente           |\n\n"
                   "|   Selecine uma das opções a baixo: |\n\n"
                   "| 1 - Cadastro Cliente               |\n"
                   "| 2 - Lista de Clintes               |\n"
                   "| 3 - Busca de Cliente por CPF       |\n"
                   "| 4 - Lista de Produtos por Preço    |\n"
                   "|[BACKSPACE] - Voltar ao menu        |\n"
                   "======================================\n");
            switch (getch())
            {

            case '1':
                if (i_clientes < MAX_VETOR)
                {
                    system("cls");
                    printf("\n\n\n"
                           "======================================\n"
                           "|         Cadastro de Cliente        |\n"
                           "======================================\n");
                    clientes[i_clientes++] = cadastraCliente();
                }
                else
                {
                    printf("\n [!] - Número máximo de cadastros atingidos!\n\n");
                }

                printf("\n [!] - Cliente cadastrado com sucesso!\n\n");
                system("Pause");
                system("cls");
                break;

            case '2':
                system("cls");
                printf("\n\n\n"
                       "======================================\n"
                       "|           Lista de Clientes        |\n"
                       "======================================\n");
                for (int n = 0; n < i_clientes; n++)
                {
                    imprimeCliente(clientes[n]);
                }
                system("pause");
                break;

            case '3':
                printf("\n\n\n"
                       "======================================\n"
                       "|      Busca de Cliente por CPF      |\n"
                       "======================================\n");
                buscaClienteCPF(i_clientes, clientes);
               
            break;

                /*printf("\nDigite o CPF: ");
                fflush(stdin);
                gets(cpfs);

                for (i = 0; i < i_clientes; i++)
                {
                    if (strcmp(cpfs, clientes[i].cpf) == 0)
                    {
                        posicao = i;
                        system("cls");
                        printf(" [!] - Cliente encontrado!\n\n");

                        printf("\n-----------------------------\n"
                               "Informações do Cliente: \n"
                               "\nCPF: %s\n"
                               "\nNome: %s\n"
                               "\nSaldo: %.2f\n",
                               clientes[posicao].cpf,
                               clientes[posicao].nome,
                               clientes[posicao].saldo);

                        goto fimbusca;
                    }
                }

                printf("\n CPF não encontrado!");*/
            
              

            case '4':
                system("cls");
                //-------------------------------------------------------
                //-----------------Bubblesort

                printf("======================================\n"
                       "|     Lista de Produtos por Preço    |\n"
                       "======================================\n");
                for (int i = 1; i < i_produto; i++)
                {
                    for (int n = 0; n < i_produto - 1; n++)
                    {
                        if (produtos[n].valor > produtos[n + 1].valor)
                        {
                            aux = produtos[n].valor;
                            aux1 = produtos[n].codigoProduto;
                            strcpy(aux3, produtos[n].descricao);

                            produtos[n].valor = produtos[n + 1].valor;
                            produtos[n].codigoProduto = produtos[n + 1].codigoProduto;
                            strcpy(produtos[n].descricao, produtos[n + 1].descricao);

                            produtos[n + 1].valor = aux;
                            produtos[n + 1].codigoProduto = aux1;
                            strcpy(produtos[n + 1].descricao, aux3);
                        }
                    }
                }
                for (int n = 0; n < i_produto; n++)
                {
                    printf("%d   %s  %f\n\n",
                           produtos[n].codigoProduto,
                           produtos[n].descricao,
                           produtos[n].valor);
                }
                system("pause");
                break;

            case 8:
                main();
                system("cls");
                break;

            default:
                printf("\n [!] - Opção Invalida, tente novamente! \n\n");
                system("pause");
            }
            break;
        case '3':
            system("cls");
            printf("\n\n\n"
                   "======================================\n"
                   "|          Lista de Estoque          |\n"
                   "======================================\n");
            for (int n = 0; n < i_estoques; n++)
            {
                imprimeEstoque(estoques[n]);
            }
            system("pause");
            system("cls");
            break;
            system("cls");
        case 27:
            salvarClientesTXT(clientes, i_clientes);
            salvarProdutoTXT(produtos, i_produto);
            salvarLojasTXT(lojas, i_lojas);
            salvarEstoquesTXT(estoques, i_estoques);
            return (0);
        }
    }
    return (0);
}
