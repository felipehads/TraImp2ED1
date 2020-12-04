#include "atleta.h"
#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SLList * camp = NULL;

typedef struct _atleta_{
    char iniciaisNome[30];
    int idade;
    float altura;
    float TempoMin;
} Atleta;


void criarCampeonato(){
    if(camp == NULL){
        camp = SllCreate();
        printf("Campeonato criado!");
    } else {
        printf("Campeonato ja criado");
    }
}


Atleta * criarAtleta(char iniciaisNome[], int idade, float altura, float TempoMin){
    Atleta * atleta;
    atleta = (Atleta *)malloc(sizeof(Atleta));
    if (atleta != NULL){
        strcpy(atleta->iniciaisNome, iniciaisNome);
        atleta->idade = idade;
        atleta->altura = altura;
        atleta->TempoMin = TempoMin;

        return atleta;
    }
    return NULL;
}

int cmpAtleta(void * atleta1, void * atleta2){
    if (atleta1 != NULL && atleta2 != NULL){
        char * iniciasNome1 = ((Atleta*)atleta1)->iniciaisNome;
        int idade1 = ((Atleta*)atleta1)->idade;
        float altura1 = ((Atleta*)atleta1)->altura;
        float TempoMin1 = ((Atleta*)atleta1)->TempoMin;

        char * iniciasNome2 = ((Atleta*)atleta2)->iniciaisNome;
        int idade2 = ((Atleta*)atleta2)->idade;
        float altura2 = ((Atleta*)atleta2)->altura;
        float TempoMin2 = ((Atleta*)atleta2)->TempoMin;

        if( strcmp(iniciasNome1,iniciasNome2) == 0 && idade1 == idade2 && altura1 == altura2 && TempoMin1 == TempoMin2){
            return TRUE;
        }
    }
    return FALSE;
}


void inserirAtleta(){
    int result = FALSE;
    if (camp == NULL){
        printf("Crie um campeonato primeiro!\n");
        return NULL;
    }
        char iniciasNome[30];
        int idade;
        float altura, TempoMin;
        Atleta * atleta;

        printf("Digite as informacoes do Atleta a ser inserido!\n");
        printf("Iniciais do nome:");
        scanf("%s", &iniciasNome);

        printf("Idade:\n");
        scanf("%d", &idade);

        printf("Altura:\n");
        scanf("%f", &altura);

        printf("Menor Tempo:\n");
        scanf("%f", &TempoMin);

        atleta = criarAtleta(iniciasNome, idade, altura, TempoMin);

        result = SllInsert(camp, atleta);

        if (result == TRUE){
            printf("Atleta inserido na competicao!\n\n");
        }
}


void removerAtleta(){
    void * result = NULL;
    if (camp == NULL){
        printf("Crie um campeonato primeiro!\n");
        return NULL;
    } else if (SllGetFirst(camp) == NULL){
        printf("Insira um atleta na competicao antes!\n");
        return NULL;
    }
        char iniciaisNome[30];
        int idade;
        float altura, TempoMin;
        Atleta * atleta;

        printf("Digite as informacoes do Atleta a ser removido!\n");
        printf("Iniciais do nome:\n");
        scanf("%s", &iniciaisNome);

        printf("Idade:\n");
        scanf("%d", &idade);

        printf("Altura:\n");
        scanf("%f", &altura);

        printf("Menor Tempo:\n");
        scanf("%f", &TempoMin);

        atleta = criarAtleta(iniciaisNome, idade, altura, TempoMin);

        result = SllRemoveSpec(camp, atleta, cmpAtleta);

        if(result != NULL){
            printf("Atleta removido da competicao!\n\n");
        } else {
            printf("Atleta nao encontrado!\n\n");
        }
}


void consultarAtleta(){
    void * result = NULL;
    if (camp == NULL){
        printf("Crie um campeonato primeiro!\n");
        return NULL;
    } else if (SllGetFirst(camp) == NULL){
        printf("Insira um atleta na competicao antes!\n");
        return NULL;
    }
        char iniciaisNome[30];
        int idade;
        float altura, TempoMin;
        Atleta * atleta;

        printf("Digite as informacoes do Atleta a ser consultado!\n");
        printf("Iniciais do nome:\n");
        scanf("%s", &iniciaisNome);

        printf("Idade:\n");
        scanf("%d", &idade);

        printf("Altura:\n");
        scanf("%f", &altura);

        printf("Menor Tempo:\n");
        scanf("%f", &TempoMin);

        atleta = criarAtleta(iniciaisNome,idade,altura,TempoMin);
        result = SllQuery(camp, atleta, cmpAtleta);

        if (result == NULL){
            printf("\n\nATLETA NAO ENCONTRADO!!\n\n");
        } else {
            printf("\n\nATLETA ENCONTRADO E INSCRITO!!\n\n");
            printf("INICIAS DO NOME:%s\n", retornaNome(atleta));
            printf("IDADE:%d\n", retornaIdade(atleta));
            printf("ALTURA:%f\n", retornaAltura(atleta));
            printf("TEMPO MINIMO:%f\n", retornaTempoMin(atleta));
        }
}

void destruirCampeonato(){
    int result = FALSE;
    if (camp == NULL){
        printf("Nao ha campeonato para ser destruido!\n");
        return NULL;
    }
    if (SllGetFirst(camp) != NULL){
        printf("Primeiro retire todos os atletas do campeonato!\n");
    } else {
        printf("O campeonato sera destruido!!\n\n");
        SllDestroy(camp);
        camp = NULL;
        printf("Campeonato destruido!!!\n");
    }
}

void listarAtletas(){
    Atleta * atleta;
    if (camp != NULL){
        atleta = SllGetFirst(camp);
        while (atleta != NULL){
            printf("INICIAIS DO NOME: %s\n", retornaNome(atleta));
            printf("IDADE: %d\n", retornaIdade(atleta));
            printf("ALTURA: %f\n", retornaAltura(atleta));
            printf("TEMPO MINMO: %f\n\n", retornaTempoMin(atleta));

            atleta = SllGetNext(camp);
        }
    }else if (camp == NULL){
        printf("Nao existe campeonato!\n");
    } else if (SllGetFirst(camp) == NULL){
        printf("Insira alguem no campeonato primeiro!\n");
    }
}

char * retornaNome(Atleta * atleta){
    if (atleta != NULL){
        return atleta->iniciaisNome;
    }
    return NULL;
};

int retornaIdade(Atleta * atleta){
    if(atleta != NULL){
        return atleta->idade;
    }
    return -1;
};

float retornaAltura(Atleta * atleta){
    if(atleta != NULL){
        return atleta->altura;
    }
    return -1;
};

float retornaTempoMin(Atleta * atleta){
    if(atleta != NULL){
        return atleta->TempoMin;
    }
    return -1;
};
