#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// creates a cipher

int isLetter(string x);
int isDuplicate(string x);
string substitute(string text, string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {

        if (isLetter(argv[1]) && strlen(argv[1]) == 26 && (isDuplicate(argv[1]) == 0))
        {

            string text = get_string("Plaintext: ");
            string key = argv[1];
            printf("ciphertext: ");
            string cipher = substitute(text, key);
            return 0;

        }
        else
        {

            printf("Error: Ensure that key contains 26 letters and a-z once each");
            return 1;

        }

    }
    else
    {

        printf("Error: Enter 2 values on the command line, the program name and the key\n");
        return 1;

    }

}

int isLetter(string x)
{
    int n = strlen(x);

    for (int i = 0; i < n; i++)
    {

        if (isalpha(x[i]) == 0)
        {

            return 0;

        }

    }

    return 1;

}

int isDuplicate(string x)
{

    int n = strlen(x);

    for (int i = 0; i < n-1; i++)
    {

        for (int j = i+1; j < n; j++)
        {

            if (toupper(x[i]) == toupper(x[j]))
            {

                return 1;

            }

        }

    }

    return 0;

}

string substitute(string text, string key)
{
    for (int i = 0, l = strlen(text); i<l; i++)
    {

        if (text[i] >= 'a' && text[i] <= 'z')
        {

            char letter = text[i];
            int index = ((int) letter - 97);
            char newletter = tolower(key[index]);
            printf("%c", newletter);
           // ciphertext = strcat(ciphertext, newletter);

            //append newletter into ciphertext
        }

        else if (text[i] >= 'A' && text[i] <= 'Z')
        {

            char upperletter = text[i];
            int index = ((int) upperletter - 65);
            char newletter = toupper(key[index]);
            printf("%c", newletter);
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
