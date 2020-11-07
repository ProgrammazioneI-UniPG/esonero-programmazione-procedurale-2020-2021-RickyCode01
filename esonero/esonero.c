/* esonero programmazione 1 2020/2021 Riccardo Manoni */
#include<stdio.h>
#include<time.h>                  //per utilizzare funzione time
#include<stdlib.h>                // per utilizzare funzione randomica
#include<string.h>                // per utilizzare memset

#define MAX 128                   //dimensione massima per bufferoverflow
char buff[MAX];                   // array testo -> buffer caratteri
char key[MAX];                    // array int -> chiave generata
char C[MAX];                      // array chiave cifrata


int ASCII(int num){               //funzione per togliere caratteri speciali
  if(num <= 32){
    num = num + 32;
  }
  return num;
}

void keygen(){
  time_t t;
  srand((unsigned) time(&t));
  int i;
  printf("la chiave generata è: ");
  for(i=1; i<strlen(buff); i++){
    int n_rand = rand()%128;
    n_rand = ASCII(n_rand);
    // if(n_rand <= 32){             //elimino i valori superiori a 32
    //   n_rand = n_rand + 32;
    //   key[i] = n_rand;
    // }else{
    //   key[i] = n_rand;
    // }
    key[i] = n_rand;
    printf("%c", key[i]);
  }
  printf("\n");
}


void start() {
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
        while((scelta=getchar())!='\n' && scelta !=EOF );                         // aspetta che il buffer sia vuoto
        fgets(key, MAX, stdin);
        //printf("%ld", strlen(key) );
        while(strlen(key) < strlen(buff)){
          printf("la lunghezza deve essere maggiore o uguale di: %ld\n", sizeof(key));
          memset(key, 0, MAX);                                                    //svuoto il buffer
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
  printf("%s","chiave cifrata: ");

  int i;
  int xor;
  for(i=1 ;i<strlen(buff); i++){
    xor = buff[i] ^ key[i];
    xor = ASCII(xor);
    C[i] = xor;
    printf("%c", C[i]);
  }

  return 0;
}
