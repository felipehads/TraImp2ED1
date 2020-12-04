#ifndef ATLETA_H
#define ATLETA_H

#define TRUE 1
#define FALSE 0


typedef struct _atleta_ Atleta;

void criarCampeonato();
Atleta *criarAtleta(char nome[], int idade, float altura, float TempoMin);
int cmpAtleta(void * atleta1, void * atleta2);
void inserirAtleta();
void removerAtleta();
void consultarAtleta();
void destruirCampeonato();
void listarAtletas();

char * retornaNome(Atleta * atleta);
int retornaIdade(Atleta * atleta);
float retornaAltura(Atleta * atleta);
float retornaTempoMin(Atleta * atleta);



#endif

