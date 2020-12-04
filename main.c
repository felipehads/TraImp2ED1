#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atleta.h"
#include "sll.h"

#define TRUE 1
#define FALSE 0

int main(void){
    int op = 0;


    do {
        printf("\n\t****************************\n");
        printf("\t*********Campeonato*********\n");
        printf("\t***Manipulacao de Atletas***\n");
        printf("\t****************************\n\n");

        printf("\t1 - Criar Campeonato.\n");
        printf("\t2 - Inserir Atleta.\n");
        printf("\t3 - Remover Atleta.\n");
        printf("\t4 - Consultar Atleta.\n");
        printf("\t5 - Listar Atletas.\n");
        printf("\t6 - Destruir campeonato.\n");
        printf("\t7 - Sair.\n");

        printf("Digite a opcao:");
        scanf("%d", &op);


        switch(op){
            case 1:
                criarCampeonato();
                break;
            case 2:
                inserirAtleta();
                break;
            case 3:
                removerAtleta();
                break;
            case 4:
                consultarAtleta();
                break;
            case 5:
                listarAtletas();
                break;
            case 6:
                destruirCampeonato();
                break;
            case 7:
                printf("\n\n\nSAINDO DO PROGRAMA, ATE MAIS! :)\n\n\n");
                break;

            default:
            printf("\n\t******************************\n");
            printf("\tOPCAO INVALIDA!Tente Novamente!");
            printf("\n\t******************************\n");
            break;

        }
    } while (op != 7);




    return 0;

}

