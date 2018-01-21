#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void getStringN(char *table){

  char c;
  int n=-1;
  char *tab = (char*)malloc(sizeof(char));

  printf("Podaj kolejne znaki jakie chcesz wczytać ( x kończy wczytywanie): \n");

   do{
    scanf("%c", &c);
    if(c!='\n') {
      n++;
      tab = (char*)realloc(tab, (sizeof(char) + (sizeof *tab)));
      tab[n]=c;
    }
  } while (c!='x');
  printf("\n");
  puts(tab);
  free(tab);

}

int main(int argc, char const *argv[]) {
  char *table;
  getStringN(table);
  return 0;
}
