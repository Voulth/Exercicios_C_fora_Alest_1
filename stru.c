//Fazer um programa que pede os dados da file dados.txt usando struct

#include <stdio.h>
#include <stdlib.h>

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

//Arrumar funções pegaNome e pegaCor para parar quando encontrarem um espaço em branco 
void pegaNome(FILE *F,struct pessoa *p){
int i=0;
while(p->nome[i] != ' '){
fgets(p->nome,1,F);
i++;
}
}


void pegaCor(FILE *F,struct pessoa *p){
fgets(p->cor_Fav,sizeof p->cor_Fav,F);

}

void pegaDados(FILE *F,struct pessoa *p){

pegaNome(F,p);
fscanf(F,"%d",&p->idade);
fscanf(F,"%f",&p->altura);
fscanf(F,"%f",&p->peso);
pegaCor(F,p);
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