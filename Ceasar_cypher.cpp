#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int shiftr(char ch)
{
    if (ch == 'z')
        return 'a';
    if (ch == 'Z')
        return 'A';
    ch++;
    return ch;
}
int shiftl(char ch)
{
    if (ch == 'a')
        return 'z';
    if (ch == 'A')
        return 'Z';
    ch--;
    return ch;
}
int unravel(char ch, int n)
{
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            ch = shiftr(ch);
        }
    }
    if (n < 0)
    {
        for (int i = n; i < 0; i++)
        {
            ch = shiftl(ch);
        }
    }
    return ch;
}
int main()
{
    clrscr();
    int k = 1;
    char str[100];
    int strl = strlen(str);
    int n;
    while (k == 1)
    {
        printf("Type something: \n");
        fflush(stdin);
        gets(str);
        printf("Type the transitory value: \n");
        scanf("%d", &n);
        char a;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = unravel(str[i], n);
            }
            if (str[i] >= 'A' && str[i] <= 'A')
            {
                str[i] = unravel(str[i], n);
            }
        }
        printf("The message:\n%s\n", str);
        printf("Co muon tiep tuc khong?\n(Yes = 1 / No = 0): \n");
        scanf("%d", &k);
        if (k == 0)
        {
            printf("Bye.");
        }
    }
    return 0;
}
