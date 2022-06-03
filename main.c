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
    int codigoProduto;
    int quantidade;

} Estoque;

typedef struct
{
    char cnpj[14];
    char nome[50];
    char segmento[200];

} Loja;

typedef struct
{
    char cpf[9];
    char nome[50];
    float saldo;

} Cliente;

typedef struct
{
    char cpf[14];
    int codigoProduto;

} Carrinho;

typedef struct
{
    char cpf[14];
    float total;
    Produto produtos[100];
} Compra;

//---------------------------------------------
// Assinatura de funções.
Produto cadastraProduto();
void listaprodutos(Produto cadastraProduto);
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

Produto produtos[100];
Estoque estoques[100];
Loja loja[100];
Cliente clientes[100];
Carrinho carrinhos[100];
Compra compras[100];
int n, contloja = 0, contprodutos = 0, contcliente = 0, contcarrinho = 0, contestoque = 0;
char opcao;

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
                    listalojas(loja[n]);
                }
                printf("\n [!] - Loja Cadastrada com sucesso!\n\n");
                system("Pause");
                system("cls");
                break;

            case '2':
                if (contprodutos < 100)
                {
                    produtos[contprodutos++] = cadastraProduto();
                    listaprodutos(produtos[n]);
                }
                printf("\n [!] Produto cadastrado com sucesso!\n\n");
                system("pause");
                system("cls");
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

        default:
            printf("\n [!] - Opção inválida, tente novamente...\n\n");
    
            break;
        }
    }
    return (0);
}

//---------------------------------------------
// Funções.

//---------------------------------------------
// Função Cadastra Produto

Produto cadastraProduto()
{

    Produto cadastraProduto;

    printf("\n-----CADASTRO DE PRODUTOS-----\n");
    printf("Código do produto: ");
    scanf("%d", &cadastraProduto.codigoProduto);

    printf("Informe a descrição do produto: ");
    fflush(stdin);
    gets(cadastraProduto.descricao);

    printf("Informe o valor do produto: ");
    scanf("%f", &cadastraProduto.valor);

    return (cadastraProduto);
}

//---------------------------------------------
// Função imprime Produto

void listaprodutos(Produto cadastraProduto)
{
    printf("\n\n-----LISTA DE PRODUTOS-----\n");
    printf("Código: %d\n", cadastraProduto.codigoProduto);
    printf("Descrição: %s\n", cadastraProduto.descricao);
    printf("Valor: %.2f\n", cadastraProduto.valor);
}

//---------------------------------------------
// Função cadastra loja.

Loja novaloja()
{
    Loja novaloja;

    printf("\n-----CADASTRO DE LOJA-----\n");
    printf("CNPJ: ");
    gets(novaloja.cnpj);

    printf("Nome: ");
    gets(novaloja.nome);

    printf("Segmento: ");
    gets(novaloja.segmento);

    return (novaloja);
}

//---------------------------------------------
// Função Imprime loja

void listalojas(Loja novaloja)
{
    printf("\n\n-----LISTA DE LOJAS-----\n");
    printf("\t\t Loja Nº %d\n", contloja);
    printf("CNPJ: %s \n", novaloja.cnpj);
    printf("Nome: %s \n", novaloja.nome);
    printf("Segmento: %s \n", novaloja.segmento);
}

//---------------------------------------------
// Função Cadastra cliente.

Cliente cadastraCliente()
{

    Cliente cadastraCliente;

    printf("\n-----CADASTRO DE CLIENTE-----\n");
    printf("\n Nome: ");
    gets(cadastraCliente.nome);

    printf("CPF: ");
    gets(cadastraCliente.cpf);

    printf("Seu Saldo: ");
    scanf("%f", &cadastraCliente.saldo);

    return (cadastraCliente);
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

    Carrinho cadastraCarrinho;

    printf("\n-----Carrinho de Produtos -----\n");
    printf("\n\nDigite seu CPF: ");
    gets(cadastraCarrinho.cpf);

    printf("Digite o código do produto: ");
    scanf("%d", &cadastraCarrinho.codigoProduto);

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

    Compra cadastraCompra;

    printf("\n-----CADASTRA COMPRA-----\n\n");
    printf("Digite o seu CPF: ");
    gets(cadastraCompra.cpf);

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

    Estoque cadastraEstoque;

    printf("\n-----CADASTRA ESTOQUE-----\n\n");
    printf("Digite o CNPJ: ");
    fflush(stdin);
    gets(cadastraEstoque.cnpj);

    printf("Digite o código do Produto: ");
    scanf("%d", &cadastraEstoque.codigoProduto);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &cadastraEstoque.quantidade);

    return (cadastraEstoque);
}
//---------------------------------------------
// Função Imprime Estoque

void imprimeEstoque(Estoque cadastraEstoque)
{
    printf("\n\n-------Estoque------\n\n");
    printf("CNPJ: %s\n", cadastraEstoque.cnpj);
    printf("Produto: %d\n", cadastraEstoque.codigoProduto);
    printf("Quantidade: %d\n", cadastraEstoque.quantidade);
}