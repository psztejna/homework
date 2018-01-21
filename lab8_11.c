
#include <stdio.h>
#include <string.h>

int OnEnd(char *string, char *text){
  int h, t = strlen(text), n = strlen(string);
  int str = t-n;

  for(h = t-1; h-str >= 0; h--){
	   printf("%c %c %c", text[h], string[h-str], '\n');

	    if(text[h] != string[h-str])

    	return -1;


int main(){

  char *text = "tekst sprawdzajacy dzialanie funkcji";
  char *string = "nie funkcji";

  printf("%d\n",OnEnd(string,text));
return 0;
}
