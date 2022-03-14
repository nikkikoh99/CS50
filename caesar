// code allows you to create a basic cipher

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ALPHABET[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z'};

int isNumber(string x);
string ciphertext(string text, int k);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (isNumber(argv[1]))
        {
            printf("Success!\n");
            int k = atoi(argv[1]);
            printf("%i\n", k);
            string text = get_string("plaintext: ");
            //print the word ciphertext & the ciphertext
            printf("ciphertext: ");
            string cipher = ciphertext(text, k);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int isNumber(string x)
{
    for (int i = 0, n = strlen(x); i< n; i++)
    {
        if (isdigit(x[i]) == 0)
              return 0;
    }
    return 1;
}

string ciphertext(string text, int k)
{
    for (int i = 0, l = strlen(text); i<l; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {


            char p = text[i];
            int index = ((int) p - 97 + k) % 26;
            char newletter = ALPHABET[index];
            printf("%c", newletter);
           // ciphertext = strcat(ciphertext, newletter);

            //append newletter into ciphertext
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            char pi = text[i];
            int index = ((int) pi - 65 + k) % 26;
            char addletter = toupper(ALPHABET[index]);
            printf("%c", addletter);
            //append newletter into ciphertext
        }
        else
        {
            printf("%c", text[i]);
            //append text[i] into ciphertext
        }
    }
printf("\n");
return 0;
}
