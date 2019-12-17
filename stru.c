//Fazer um programa que pede os dados da file dados.txt usando struct

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//Inclui as funções relacionadas as strings 

struct pessoa{
char nome[20];
int idade;
float altura;
float peso;
char cor_Fav[20];
};
//Links Uteis 
//https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
//https://stackoverflow.com/questions/15326729/check-if-a-character-is-a-space
//https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm


/*Explicação de como o fgets para em C: https://stackoverflow.com/questions/1555731/how-to-take-whitespace-in-input-in-c*/

//Arrumar funções pegaNome e pegaCor para parar quando encontrarem um espaço em branco pararem. Erro esta apontando um valor de ponteiro 
void pegaNome(FILE *F,struct pessoa *p){
fgets(p->nome,20,F);// fgets pega até um new line, melhor usar ele para pegar strings em sequencias de novas linhas do que palavras até o espaço, também é muito boa para evitar o overflow
}



void pegaCor(FILE *F,struct pessoa *p){
fgets(p->cor_Fav,20,F);// fgets pega até um new line, melhor usar ele para pegar strings em sequencias de novas linhas do que palavras até o espaço, também é muito boa para evitar o overflow
}

void pegaDados(FILE *F,struct pessoa *p){
fscanf(F,"%s",p->nome);
fscanf(F,"%d",&p->idade);
fscanf(F,"%f",&p->altura);
fscanf(F,"%f",&p->peso);
fscanf(F,"%s",p->cor_Fav);
}

void imprimeDados(struct pessoa *p){
printf("%s\n",p->nome);
printf("%d\n",p->idade);
printf("%f\n",p->altura);
printf("%f\n",p->peso);
printf("%s\n",p->cor_Fav);
}

int main(){

struct pessoa a;
if(fopen("dados.txt","r")==NULL){
    printf("Erro na leitura\n");
    return -1;
    }
FILE *Ar=fopen("dados.txt", "r");


pegaDados(Ar,&a);
imprimeDados(&a);


}