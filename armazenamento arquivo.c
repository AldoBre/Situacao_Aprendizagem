#include <stdio.h>

//---------------------------------------------------------------------------------
// Tamanho máximo do vetor
#define NUM_MAX_SALAS 100

//---------------------------------------------------------------------------------
// Estrutura de salas
typedef struct
{
    int bloco;
    int numero;
    char apelido[30];
    char tipo[50];
    int capacidade;

} Sala;


//---------------------------------------------------------------------------------
// Variáveis de armazenamento global
int posicaoVetorSalas = 0;
Sala salasSENAI[NUM_MAX_SALAS];


//---------------------------------------------------------------------------------
//
void salvarSalasTXT()
{

    FILE *fp;

    if ((fp = fopen("salas.txt", "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo salas.txt\n");
        exit(-1);
    }

    for (int n = 0; n < posicaoVetorSalas; n++)
    {
        fprintf(fp, "%d|%d|%s|%s|%d\n",
                salasSENAI[n].bloco,
                salasSENAI[n].numero,
                salasSENAI[n].apelido,
                salasSENAI[n].tipo,
                salasSENAI[n].capacidade);
    }

    fclose(fp);
}

//---------------------------------------------------------------------------------
//
void carregarSalaTxt()
{
    FILE *fp;
    char buffer[1024];
    char *seek;
    posicaoVetorSalas = 0;

    if ((fp = fopen("salas.txt", "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo salas.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Quebra por pipe.
        seek = strtok(buffer, "|");

        // Adiciona o primeiro parâmetro.
        salasSENAI[posicaoVetorSalas].bloco = atoi(seek);

        // Adiciona os proximos 4 parâmetros.
        for (int n = 0; n < 4; n++)
        {
            seek = strtok(NULL, "|");

            if (seek == NULL)
            {
                printf("*** Erro de formato! ***");
                exit(-3);
            }

            switch (n)
            {

            case 0:
                salasSENAI[posicaoVetorSalas].numero = atoi(seek);
                break;

            case 1:
                strcpy(salasSENAI[posicaoVetorSalas].apelido, seek);
                break;

            case 2:
                strcpy(salasSENAI[posicaoVetorSalas].tipo, seek);
                break;

            case 3:
                salasSENAI[posicaoVetorSalas].capacidade = atoi(seek);
                break;
            }
        }

        posicaoVetorSalas++;
    }

    fclose(fp);
}