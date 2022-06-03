/**************************************************************
 * SENAI - SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL
 * Unidade Curricular: Lógica de programação
 * Situação de aprendizagem
 * Professor: Lucas Antunes
 * Aluno: Aldo Bressan
 * Luzerna 26/05/2022
***************************************************************/


//---------------------------------------------
//Bibliotecas.
#include<stdio.h>

//---------------------------------------------
//Estruturas.

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
//Assinatura de funções.


//---------------------------------------------
//Variáveis globais.

Produto produtos[100];
Estoque estoques[100];
Loja loja[100];
Cliente clientes[100];
Carrinho carrinhos[100];
Compra compras[100];



//---------------------------------------------
//Função main.

int main (){

    

    return(0);
}

//---------------------------------------------
//Funções.

