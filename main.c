/**************************************************************
 * SENAI - SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL
 * Unidade Curricular: Lógica de programação
 * Situação de aprendizagem
 * Professor: Lucas Antunes
 * Aluno: Aldo Bressan
 * Luzerna 26/05/2022
 ***************************************************************/

//---------------------------------------------
// Bibliotecas.
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CLIENTES 100

//---------------------------------------------
// Estruturas.

typedef struct
{
    int codigoProduto;
    char descricao[100];
    float valor;

} Produto;

typedef struct
{
    char cnpj[14];
    char nome[50];
    char segmento[200];

} Loja;

typedef struct
{
    Loja loja[100];
    Produto codigoProduto;
    int quantidade;

} Estoque;

typedef struct
{
    char cpf[12];
    char nome[50];
    float saldo;

} Cliente;

typedef struct
{
    char cpf[12];
    int codigoProduto;

} Carrinho;

typedef struct
{
    char cpf[14];
    float total;
    int codigoProdutos[100];
} Compra;

//---------------------------------------------
// Assinatura de funções.
Produto cadastraProduto();
void listaprodutos(Produto cadastraProduto, Loja novaloja);
Loja novaloja();
void listalojas(Loja novaloja);
void imprimecliente(Cliente cadastraCliente);
Cliente cadastraCliente();
Carrinho cadastraCarrinho();
void imprimeCarrinho(Carrinho cadastraCarrinho);
void imprimeCompra(Compra cadastraCompra);
Compra cadastraCompra();
void imprimeEstoque(Estoque cadastraEstoque);
Estoque cadastraEstoque();
//---------------------------------------------
// Variáveis globais.

FILE *fp = NULL;
Produto produtos[100];
Estoque estoques[100];
Loja loja[100];
Cliente clientes[MAX_CLIENTES];
Carrinho carrinhos[100];
Compra compras[100];
int n, contloja = 0, contprodutos = 0, contcliente = 0, contcarrinho = 0, contestoque = 0, posicao;
char opcao, cnpjs[14], seguir;

//---------------------------------------------
// Função main.

int main()
{
    SetConsoleOutputCP((UINT)65001);

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
               "| 4 - Lista de produtos              |\n"
               "|[ESC] - Sair                        |\n"
               "======================================\n");

        switch (getch())
        {
        case '1':

            printf("\n-----Área do lojista-----\n\n");
            printf("Selecine uma das opções a baixo: \n\n"
                   "1 - Cadastro de Loja\n"
                   "2 - Cadastro de Produto\n"
                   "3 - Cadastro de estoque\n"
                   "[ESC] - Voltar ao menu\n");
            switch (getch())
            {
            case '1':
                if (contloja < 100)
                {
                    loja[contloja++] = novaloja();
                    printf("\n [!] - Loja Cadastrada com sucesso!\n\n");
                    system("Pause");
                    system("cls");
                    break;                  
                }
            

            case '2':
                printf("\nDigite seu CNPJ: ");
                fflush(stdin);
                gets(cnpjs);

                int i;
                if (contprodutos < 100)
                {
                    for (i = 0; i < 100; i++)
                    {
                        if (strcmp(cnpjs, loja[i].cnpj) != 0)
                        {
                            i++;
                        }
                        else
                        {
                            strcmp(cnpjs, loja[i].cnpj) == 0;
                            posicao = i;
                            system("cls");
                            printf("\n [!] - CNPJ encontrado!\n\n");
                            while (seguir != 'n')
                            {
                                printf("Olá %s\n", loja[posicao].nome);

                                produtos[contprodutos++] = cadastraProduto();

                                printf("\n\nDeseja continuar?[s/n] ");
                                scanf(" %c", &seguir);
                            }
                        }
                    }
                }
                break;

                break;
            case '3':

                if (contestoque < 100)
                {
                    estoques[contestoque++] = cadastraEstoque();
                    imprimeEstoque(estoques[n]);
                }
                printf("\n [!] Estoque adicionado com sucesso!\n\n");
                system("pause");
                system("cls");
                break;
            case 27:
                system("cls");
                printf("\n [!] - Voltando ao menu...\n\n");
                break;

            default:
                system("cls");
                printf("\n [!] - Opção inválida, tente novamente...\n\n");
                system("pause");
                break;
            }
            break;

        case '2':
            printf("\n-----ESPAÇO DO CLIENTE-----\n");
            printf("Selecione umas das opções a baixo: \n"
                   "                                   \n"
                   "1 - Cadastro de Cliente            \n"
                   "2 - Carrinho                       \n"
                   "3 - compras                        \n"
                   "[ESC] - Voltar ao menu             \n");
            switch (getch())
            {
            case '1':
                if (contcliente < 100)
                {
                    clientes[contcliente++] = cadastraCliente();
                    imprimecliente(clientes[n]);
                    system("pause");
                }
                printf("\n [!] - Cliente cadastrado com sucesso!\n\n");
                system("cls");
                break;

            case '2':
                if (contcarrinho < 100)
                {
                    carrinhos[contcarrinho++] = cadastraCarrinho();
                    imprimeCarrinho(carrinhos[n]);
                }
                printf("\n [!] - Item adicionado com sucesso!\n\n");
                system("cls");
                break;
            case '3':
                // ADICIONAR COMPRAS
                break;
            case 27:
                system("cls");
                printf("\n [!] - Voltando ao menu...\n\n");
                break;

            default:
                system("cls");
                printf("\n [!] - Opção inválida, tente novamente...\n\n");
                system("pause");
                break;
            }
            break;

        case '3':
            imprimeEstoque(estoques[n]);
            break;

        case '4':
            listaprodutos(produtos[n], loja[n]);
            break;

        default:
            printf("\n [!] - Opção inválida, tente novamente...\n\n");

            break;
        }
    }
    return (0);
}
//para adicionar aquivos externos e bibliotecas gcc -0 situacao main.c cliente.c produto.c



//---------------------------------------------
// Funções.

//---------------------------------------------
// Função Cadastra Produto

Produto cadastraProduto()
{
    fp = fopen("Produtos.txt","a+");
    
       if (fp == NULL)
    {
        printf("\n [!] problemas com o arquivo (Produtos.txt) \n\n");
    }

    Produto cadastraProduto;

    printf("\n-----CADASTRO DE PRODUTOS-----\n");
    printf("Informe o Código do produto: ");
    scanf("%d", &cadastraProduto.codigoProduto);

    printf("Informe a descrição do produto: ");
    fflush(stdin);
    gets(cadastraProduto.descricao);

    printf("Informe o valor do produto: ");
    scanf("%f", &cadastraProduto.valor);

    fprintf(fp,"\n----------------------------\n");
    fprintf(fp,"%d ",cadastraProduto.codigoProduto);
    fprintf(fp,"%s ",cadastraProduto.descricao);
    fprintf(fp,"%.2f ",cadastraProduto.valor);
    
    fclose(fp);
    


    return (cadastraProduto);
}

//---------------------------------------------
// Função imprime Produto

void listaprodutos(Produto cadastraProduto, Loja novaloja)
{
    printf("\n\n-----LISTA DE PRODUTOS-----\n");
    //printf("Loja: %s\n", novaloja.nome);
    printf("Código: %d\n", cadastraProduto.codigoProduto);
    printf("Descrição: %s\n", cadastraProduto.descricao);
    printf("Valor: %.2f\n", cadastraProduto.valor);
}

//---------------------------------------------
// Função cadastra loja.

Loja novaloja()
{
    fp = fopen("Lojas.txt", "a+");

    if (fp == NULL)
    {
        printf("\n [!] problemas com o arquivo (Lojas.txt) \n\n");
    }
    Loja novaloja;

    printf("\n-----CADASTRO DE LOJA-----\n");
    printf("CNPJ: ");
    fflush(stdin);
    gets(novaloja.cnpj);

    printf("Nome: ");
    fflush(stdin);
    gets(novaloja.nome);

    printf("Segmento: ");
    fflush(stdin);
    gets(novaloja.segmento);

    fprintf(fp,"\n---------------------------\n");
    fprintf(fp,"%s ",novaloja.cnpj);
    fprintf(fp,"%s ", novaloja.nome);
    fprintf(fp,"%s ", novaloja.segmento);
    
    fclose(fp);

    return (novaloja);
}

//---------------------------------------------
// Função Imprime loja

void listalojas(Loja novaloja)
{
    printf("\n\n-----LISTA DE LOJAS-----\n");
    printf("CNPJ: %s \n", novaloja.cnpj);
    printf("Nome: %s \n", novaloja.nome);
    printf("Segmento: %s \n", novaloja.segmento);
}

//---------------------------------------------
// Função Cadastra cliente.

Cliente cadastraCliente()
{
    fp = fopen("Clientes.txt","a+");
    
       if (fp == NULL)
    {
        printf("\n [!] problemas com o arquivo (Clientes.txt) \n\n");
    }
    Cliente cadastraCliente;

    printf("\n-----CADASTRO DE CLIENTE-----\n");
    printf("\n Nome: ");
    gets(cadastraCliente.nome);

    printf("CPF: ");
    gets(cadastraCliente.cpf);

    printf("Seu Saldo: ");
    scanf("%f", &cadastraCliente.saldo);
    fflush(stdin);

    fprintf(fp,"\n---------------------------\n");
    fprintf(fp,"%s ",cadastraCliente.nome);
    fprintf(fp,"%s ",cadastraCliente.cpf);
    fprintf(fp,"%.2f ",cadastraCliente.saldo);

     fclose(fp);

    return(cadastraCliente);
}
//---------------------------------------------
// Função imprime cliente

void imprimecliente(Cliente cadastraCliente)
{
    printf("\n\n-----LISTA DE CLIENTES-----\n");
    printf("\t\t Cliente Nº:%d\n", contcliente);
    printf("Nome: %s\n", cadastraCliente.nome);
    printf("CPF: %s\n", cadastraCliente.cpf);
    printf("Saldo: %.2f\n", cadastraCliente.saldo);
}

//---------------------------------------------
// Função cadastra Carrinho

Carrinho cadastraCarrinho()
{
    fp = fopen("Carrinho.txt","a+");
    
       if (fp == NULL)
    {
        printf("\n [!] problemas com o arquivo (Carrinho.txt) \n\n");
    }

    Carrinho cadastraCarrinho;

    printf("\n-----Carrinho de Produtos -----\n");
    printf("\n\nDigite seu CPF: ");
    gets(cadastraCarrinho.cpf);

    printf("Digite o código do produto: ");
    scanf("%d", &cadastraCarrinho.codigoProduto);

    fprintf(fp,"\n----------------------------\n");
    fprintf(fp,"%s ",cadastraCarrinho.cpf);
    fprintf(fp,"%d ",cadastraCarrinho.codigoProduto);
    
    fclose(fp);

    return (cadastraCarrinho);
}

//---------------------------------------------
// Função Imprime Carrinho

void imprimeCarrinho(Carrinho cadastraCarrinho)
{

    printf("\n-----CARRINHO-----\n");
    printf("CPF: %s", cadastraCarrinho.cpf);
    printf("Código do Produto: %d", cadastraCarrinho.codigoProduto);
}

//---------------------------------------------
// Função Cadastra Compra

Compra cadastraCompra()
{
    fp = fopen("Compra.txt","a+");
    
    if (fp == NULL)
    {
        printf("\n [!] problemas com o arquivo (Compra.txt) \n\n");
    }
    Compra cadastraCompra;

    printf("\n-----CADASTRA COMPRA-----\n\n");
    printf("Digite o seu CPF: ");
    gets(cadastraCompra.cpf);

    fprintf(fp,"\n----------------------------\n");
    fprintf(fp,"%s ",cadastraCompra.cpf);
  
    
    fclose(fp);
    return (cadastraCompra);
}

//---------------------------------------------
// Função Imprime Compra

void imprimeCompra(Compra cadastraCompra)
{

    printf("\n-----COMPRA-----\n\n");
    printf("CPF: %s\n", cadastraCompra.cpf);
    printf("Produtos: %d\n", cadastraCompra.produtos);
    printf("Total: R$%.2f\n", cadastraCompra.total);
}
//---------------------------------------------
// Função Cadastra Estoque

Estoque cadastraEstoque()
{
    fp = fopen("Estoque.txt","a+");
    
    if (fp == NULL)
    {
        printf("\n [!] problemas com o arquivo (Compra.txt) \n\n");
    }
    Estoque cadastraEstoque;

    printf("\n-----CADASTRA ESTOQUE-----\n\n");
    printf("Digite o CNPJ: ");
    fflush(stdin);
    gets(cadastraEstoque.loja);

    printf("Digite o código do Produto: ");
    scanf("%d", &cadastraEstoque.codigoProduto);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &cadastraEstoque.quantidade);

    fprintf(fp,"\n----------------------------\n");
    fprintf(fp,"%s ",cadastraEstoque.loja);
    fprintf(fp,"%d ",cadastraEstoque.codigoProduto);
    fprintf(fp,"%d ",cadastraEstoque.quantidade);
    
    fclose(fp);
    

    return (cadastraEstoque);
}
//---------------------------------------------
// Função Imprime Estoque

void imprimeEstoque(Estoque cadastraEstoque)
{
    printf("\n\n-------Estoque------\n\n");
    printf("CNPJ: %s\n", cadastraEstoque.loja);
    printf("Produto: %d\n", cadastraEstoque.codigoProduto);
    printf("Quantidade: %d\n", cadastraEstoque.quantidade);
}