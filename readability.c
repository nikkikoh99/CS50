#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_letter_count(string text);
int compute_word_count(string text);
int compute_sentence_count(string text);

int main(void)
{
    string text = get_string("Paste text here: ");
    int words = compute_word_count(text);
    float L = compute_letter_count(text) / (words / 100.0);
    float S = compute_sentence_count(text) / (words / 100.0);
    
    //calculate readability formula
    
    float readability = (0.0588 * L) - (0.296 * S) - 15.8;
    
    //Before Grade 1
    
    if (readability < 1)
    {
        
        printf("Before Grade 1\n");
    }
    
    //After Grade 16
    
    else if (readability >= 16)
    {
        
        printf("Grade 16+\n");
        
    }
    else
    {
        
        readability = round(readability);
        printf("Grade %i\n", (int) readability);
        
    }
    
}

//compute number of letters
int compute_letter_count(string text)
{
    
    int letter_count = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            
            letter_count ++;
            
        }
        
    }
    
    return letter_count;
    
}

//compute number of words
int compute_word_count(string text)
{
    
    int word_count = 1;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        
        if (text[i] == ' ')
        {
            
            word_count ++;
            
        }
        
    }
    
    return word_count;
}

//compute number of sentences
int compute_sentence_count(string text)
{
    
    int sentence_count = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        
        if (text[i] == '!' || text[i] == '?')
        {
            
            sentence_count ++;
            
        }
        else if (text[i] == '.' && (text[i + 1] == ' ' || text[i + 1] == '\0'))
        {
            
            sentence_count ++;
            
        }
        
    }
    
    return sentence_count;
}
