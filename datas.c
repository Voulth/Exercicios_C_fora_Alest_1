#include <stdio.h>

struct data {
  int dia, mes, ano;
};

struct niver {
  struct data data;
  char nome[10];
};

void pegadata( FILE * f, struct data * d ) {
  char c;
  fscanf( f, "%d%c%d%c%d", &d->dia, &c, &d->mes, &c, &d->ano );
}

void peganiver( FILE * f, struct niver * d ) {
  pegadata( f, &d->data );
  fscanf( f, " " );
  fgets( d->nome, 10, f );
}

void fprintdata( FILE * f, struct data * d ) {
  fprintf( f, "%d/%d/%d", d->dia, d->mes, d->ano );
}

void fprintniver( FILE * f, struct niver * d ) {
  fprintdata( f, &d->data );
  fprintf( f, " %s", d->nome );
}

// 1 -> data existe
// 0 -> data nao existe
int existedata( struct data * d ) {
  if ( d->dia <= 0 || d->dia > 31 ) return 0;
  if ( d->mes <= 0 || d->mes > 12 ) return 0;
  if ( d->ano < 0 ) return 0;
  return 1;
}

const int Max = 100;

void main() {
  struct niver niver[Max];
  FILE *arq = fopen( "datas", "r" );

  if ( arq == NULL )
    printf( "Nao consegui abrir arquivo\n" );
  else {
    int i = 0;
    while ( i < Max )
      peganiver( arq, &niver[i++] );
    fclose( arq );
    FILE *arqbom = fopen( "datasok", "w" );
    FILE *arqmau = fopen( "datasnaook", "w" );
    if ( arqbom == NULL ) printf( "Nao consegui abrir arquivo arqbom\n" );
    if ( arqmau == NULL ) printf( "Nao consegui abrir arquivo arqmau\n" );
    i = 0;
    while ( i < Max )
      if ( existedata( &niver[i].data ) == 1 )
        fprintniver( arqbom, &niver[i++] );
      else
        fprintniver( arqmau, &niver[i++] );
    fclose( arqbom );
    fclose( arqmau );
  }
}
