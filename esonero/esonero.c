/* esonero programmazione 1 2020/2021 Riccardo Manoni */
#include<stdio.h>
#include<time.h>                  // per utilizzare funzione time
#include<stdlib.h>                // per utilizzare funzione randomica
#include<string.h>                // per utilizzare memset

#define MAX 128                   // dimensione massima per bufferoverflow
char buff[MAX];                   // array testo -> buffer caratteri
char key[MAX];                    // array int -> chiave generata
char C[MAX], D[MAX];              // arrays cifratura


int ASCII(int num){               // funzione per togliere caratteri speciali
  if(num <= 32){
    num = num + 32;
  }
  return num;
}

void keygen(){
  time_t t;
  srand((unsigned) time(&t));
  int i;
  printf("\nla chiave generata è: ");
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
  printf("\n\t--> Algoritmo codifica RC4 <--");
  printf("\n\n");
  printf("Inserisci il testo da cifrare:\n");
  fgets(buff, MAX, stdin);
  printf("-----------------------------\n");
  printf("%s","\t 1. Inserire chiave personale \n");
  printf("%s","\t 2. Generare chiave casuale \n");
  printf("%s","\t 3. Uscire dal programma \n");
  printf("-------> Come si vuole procedere? ");

  int scelta;

  scanf("%d", &scelta);
  printf("-----------------------------");

  switch(scelta){
      case 1:
        printf("\ninserire chiave(MAX 128 caratteri): ");
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
      case 3:
        printf("\n\tGoodbye =)\n");
        exit(1);
  }
}

int main(){

  start();

  printf("stringa cifrata: ");
  int i, xor;
  for(i=0 ;i<strlen(buff); i++){
    xor = buff[i] ^ key[i];
    D[i] = xor ^ key[i];
    xor = ASCII(xor);
    C[i] = xor;
    printf("%c", C[i]);
  }
    printf("\nstringa decifrata: ");
  for(i=0 ;i<strlen(buff); i++){
    printf("%c", D[i]);
  }

  printf("-----------------------------\n");

  return 0;
}
