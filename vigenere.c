/**
* pset 2
* vigenere.c
* Evan Million <million.evan@gmail.com>
**/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) 
{
    // Checks if command-line argument is empty or if any 
    // character is not an alphabetic character. 
    if (argc != 2)
    {
        printf("Please enter a string as the key.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Please provide only letters for the key.\n");
            return 1;
        }
    }
    // Gets user input
    string input = GetString();
    string k = argv[1];
    // For loop iterates over each character in user's input
    // and checks to see if upper or lower case and then 
    // shifts the character up by each letter in the key 
    // provided by the user. Then prints shifted character excluding
    // special characters.
    for (int i = 0, j = 0, n = strlen(input), m = strlen(k); i < n; i++) 
    {
        if (input[i] >= 32 && input[i] <= 64)
        {
            printf("%c", input[i]);
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            printf("%c", ((((input[i] - 'A') + (toupper(k[j % m]) - 'A')) % 26) + 'A'));
            j++;
        }
        else if (input[i] >= 97 && input[i] <= 122)
        {
            printf("%c", ((((input[i] - 'a') + (toupper(k[j % m]) - 'A')) % 26) + 'a'));
            j++;
        }
    }
    printf("\n");
    return 0;
}
