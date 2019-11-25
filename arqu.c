//Praticando Arquivos 
/*
Para ler e escrever em arquivos txt:
fscanf() - Le
fprintf() -Salva no arquivo

Para ler e escrever em arquivos binarios:
fread() - Le
fwrite() - Salva no arquivo 
fgets() - Le um fluxo para string, para em nova linha  
char *fgets(char *string, int value, FILE *stream)
string − This is a pointer to the array of char.

value − The number of characters to be read.

stream − This is a pointer to a file object.

*/
#include <stdio.h>
//Usando Fgets 

/*void main(){

char t[100];//Criei um vetor Char que ira receber os valores de fgets
FILE *ar=fopen("arq.txt","r");//Cria um ponteiro que ira apontar para o arquivo
for(int i=0;i<2;i++){//Diz quantas linha irá ler
fgets(t,30,ar);//Ira ler 30 caracters por vez do arquivo e colocar em t
//printf("%s\n",t);
}
for(int i=0;i<2;i++){
//fgets(t,30,ar);
printf("%s\n",t);
}
fclose(ar);


}*/

//////////////////////////////////////////////////////////


//Usando fscanf

/*void main()
{
int A,B,C;
FILE *a=fopen("ar.txt","r");

fscanf(a, "%d %d %d",&A,&B,&C);
printf("%d %d %d\n",A,B,C);

fclose(a);

}*/

// Usando fprintf

void main(){
int a=12;
FILE * b= fopen("tets.txt","w");

fprintf(b,"%d",a);

}