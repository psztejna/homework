#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ciagbinarny(int n)
  {
   static char *tb;
   if(n<0)
     {
      n=-n;
      tb=(char*)malloc(n+1);
      memset(tb,'0',n);
      tb[n]=0;
      ciagbinarny(n);
      free(tb);
     }
   else if(n--)
     {
      for(tb[n]='0';tb[n]<='1';++tb[n]) ciagbinarny(n);
     }
   else printf("%s\n",tb);
  }

int main()
  {
   int n;
   for(;;)
     {
      printf("Podaj dlugosc ciagu binarnego: ");
      n=0;
      scanf("%d",&n);
      if(n<=0) break;
      printf("Ciagi binarne dla n=%d\n",n);
      ciagbinarny(-n);
     }
   return 0;
  }
