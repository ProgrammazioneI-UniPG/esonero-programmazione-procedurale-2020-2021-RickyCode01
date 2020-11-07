// esonero programmazione 1 2020 Riccardo Manoni
#include<stdio.h>
#include<time.h> //per utilizzare funzione time
#include<stdlib.h> // per utilizzare funzione randomica
#include<string.h> // per utilizzare memset

#define MAX 128 //dimensione massima per bufferoverflow
char buff[MAX]; // array testo -> buffer caratteri
char key[MAX]; // array int -> chiave generata

char keygen(){
  time_t t;
  srand((unsigned) time(&t));
  int i;
  for(i=0; i<(sizeof(key)); i++){
    key[i] = (rand()%128)+32;
    printf("%c", key[i]);
  }
}

char *start() {
  printf("%s","\t --Algoritmo codifica standard RC4-- \n");
  printf("%s","\t Inserisci il testo da cifrare:\n");
  printf("\t");
  fgets(buff, MAX, stdin);

  printf("%s","\t 1. Inserire chiave personale \n");
  printf("%s","\t 2. Generare chiave casuale \n");
  printf("%s","--> Come si vuole procedere? ");

  int scelta;

  scanf("%d", &scelta);
  switch(scelta){
      case 1:
        printf("%s", "inserire chiave(MAX 128 caratteri): ");
        while((scelta=getchar())!='\n' && scelta !=EOF ); // aspetta che il buffer sia vuoto
        fgets(key, MAX, stdin);
        //printf("%ld", strlen(key) );
        while(strlen(key) < strlen(buff)){
          printf("la lunghezza deve essere maggiore di: %ld\n", sizeof(key));
          memset(key, 0, MAX); //svuoto il buffer
          fgets(key, MAX, stdin);
        }
        break;
      case 2:
        keygen();
        break;
  }
}

int main(){

  start();
  //printf("%s\n",key); --> perchè mi stampa i carrateri di input da fgets
  return 0;
}
