#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//program odwraca kolejnosc liter w napisie

char * pal(char s[], char k[], int x, int y)
{
    if (y >= 0) {
        k[y] = s[x];
        return pal(s, k, x+1, y-1);
    }
    else {
        k[x] = 0;
        return k;
    }
}

int main()
{
    char nap[] = {"przykladowy tekst"}, po[20];
    int i, j=0;

    i = strlen(nap);

    pal(nap, po, j, i-1);

    puts(po);

    return 0;
}
