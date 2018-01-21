#include <stdio.h>
#include <stdlib.h>



void getStringN(char *table, int n){
    table = malloc(sizeof(char)*n);
    char tab[n];
    char podaj_znak;
    int i=0;

    printf("Podaj ile znakow chcesz wprowadzic do tablicy \n");
    scanf("%d", &n);

    printf("Podaj %d znakow, a kazdy zatwierdz ENTER \n", n);

    while ( i < n){
        podaj_znak = getchar();

        if( podaj_znak != '\n' ) {
            tab[i] = podaj_znak;
            *(table+i) = tab[i];
            i++;
        }
    }

    puts("Podales:\n");

    for (i=0; i<n; ++i)
        printf("%c ", *(table+i));
        puts("\n");
}

int main(int argc, char const *argv[]) {
  char *table;
  int n;
  getStringN(table, n);
  free(table);
  return 0;
}
