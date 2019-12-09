//Fazer um programa que pede os dados da file dados.txt usando struct

#include <stdio.h>

struct pessoa{
char nome[20];
int idade;
float altura;
float peso;
char cor_Fav[20];
};

void pegaDados(FILE *F,struct pessoa *p){
while(fgets(p->nome,1,F)!=0){
    fgets(p->nome,1,F);
}
fscanf(F,"%d",&p->idade);
fscanf(F,"%f",&p->altura);
fscanf(F,"%f",&p->peso);
fgets(p->cor_Fav,7, F);
}

void imprimeDados(struct pessoa *p){
printf("%s\n",p->nome);
printf("%d\n",p->idade);
printf("%f\n",p->altura);
printf("%f\n",p->peso);
printf("%s\n",p->cor_Fav);
}

void main(){

struct pessoa a;
FILE *Ar=fopen("dados.txt", "r");

pegaDados(Ar,&a);
imprimeDados(&a);


}