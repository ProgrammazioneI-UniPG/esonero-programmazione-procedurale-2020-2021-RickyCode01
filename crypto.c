/* esonero programmazione 1 2020/2021 Riccardo Manoni */
#include<stdio.h>
#include<time.h>                  // per utilizzare funzione time
#include<stdlib.h>                // per utilizzare funzione randomica
#include<string.h>                // per utilizzare memset

#define MAX 128                   // dimensione massima per bufferoverflow
char ctext[MAX], key[MAX];        // arrays testo e chiave
char C[MAX], D[MAX];              // arrays cifratura
int flag = 0;                     //flag per continuare il programma

int ASCII(int num){               // funzione per togliere caratteri speciali
  if(num <= 32){
    num = num + 32;
  }
  return num;
}

void keygen(){                    // funzione per generare numeri casuali
  time_t t;
  srand((unsigned) time(&t));
  int i;
  printf("\nla chiave generata è: ");
  for(i=1; i<strlen(ctext); i++){
    int n_rand = rand()%128;
    n_rand = ASCII(n_rand);
    key[i] = n_rand;
    printf("%c", key[i]);
  }
  printf("\n");
}

void personalKey(){
  printf("\ninserire chiave(MAX 128 caratteri): ");
  fgets(key, MAX, stdin);
  fflush(stdin);                                                            //svuoto ctexter
  while(strlen(key) < strlen(ctext)){
    printf("la lunghezza deve essere maggiore o uguale di: %ld\n", sizeof(key));
    memset(key, 0, MAX);                                                    //svuoto l'array
    fgets(key, MAX, stdin);
    fflush(stdin);
  }
}


void menu() {
  printf("########################################\n");
  printf("|    --> Algoritmo codifica RC4 <--    |\n");
  printf("########################################\n");
  printf("Inserisci il testo da cifrare:\n");
  fgets(ctext, MAX, stdin);
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
        while((scelta=getchar())!='\n' && scelta !=EOF);                    // aspetta che il buffer sia vuoto
        personalKey();
        break;
      case 2:
        while((scelta=getchar())!='\n' && scelta !=EOF);
        keygen();
        break;
      case 3:
        printf("\nGoodbye! =)\n");
        exit(1);
  }
}

int main(){

  do{
    menu();
    printf("stringa cifrata: ");
    int i, xor;
    for(i=0 ;i<strlen(ctext); i++){
      xor = ctext[i] ^ key[i];
      D[i] = xor ^ key[i];
      xor = ASCII(xor);
      C[i] = xor;
      printf("%c", C[i]);
      }
    printf("\nstringa decifrata: ");
    for(i=0 ;i<strlen(ctext); i++){
      printf("%c", D[i]);
      }
    printf("-->vuoi continuare?(y/n) ");
    char c;
    while((c=getchar()) != '\n' && c != EOF){
      if(c == 'n' || c == 'N') flag = 1;
    }
  }while(!flag);

  printf("-----------------------------\n");

  return 0;
}
