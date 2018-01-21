#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 5

void getString(char *wsk){
    char tab[TAB_SIZE];
    char podaj_znak;
      int i=0;
    printf("Podaj %d znakow, a kazdy zatwierdz ENTER \n", TAB_SIZE);

    while ( i < TAB_SIZE ){
        podaj_znak = getchar();

        if( podaj_znak != '\n' ) {
            tab[i] = podaj_znak;
            *(wsk+i) = tab[i];
            ++i;
        }
    }

    puts("Podales:\n");

    for (i=0; i<TAB_SIZE; ++i)
        printf("%c ", *(wsk+i));
        puts("\n");
}

int main(int argc, char const *argv[]) {
  char *table = malloc(sizeof(char)*5);
  getString(table);
  free(table);
  return 0;
}
