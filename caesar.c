// Encrypts messages using Caesar's cipher
// Nadia Abby
// Problem Set 2
#include <cs50.h>
#include <ctype.h> // allows usage of isalpha()
#include <stdio.h>
#include <stdlib.h> // allows usage of atoi()
#include <string.h> // allows usage of strlen()

int main(int argc, string argv[])
{
    int key;

    // Accept an argument at the command line

    if (argc == 2)
    {
        // Convert string to number
        key = atoi(argv[1]);
        printf("%i\n", key);
    }
    else
    {
        printf("Please provide only one input!\n");
        return 1;
    }

    // Ask user for message to encipher
    string plain_text = get_string("Enter a message to cipher: ");
    printf("ciphertext: ");

    // Loop through user message by letter index
    for (int i = 0, plain_text_len = strlen(plain_text); i < plain_text_len; i++)
    {

        // Number index of plain_text character in alphabet
        int alpha_index = plain_text[i] - 'A';
        int lower_alpha_index = plain_text[i] - 'a';

        // Number index of ciphered character in alphabet
        int ciph = (alpha_index + key) % 26;
        int lower_ciph = (lower_alpha_index + key) % 26;

        // Convert ciphered index back ascii to code
        int j = 65 + ciph;
        int k = 97 + lower_ciph;

        // Verify user input is alpha 
        if (isalpha(plain_text[i]))
        {
            // If character index is uppercase preserve case
            if (isupper(plain_text[i]))
            {
                // If character index is between A-Z convert to ciphered character 
                if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
                {
                    printf("%c", j);
                }
            }
            // If character is lowercase preserve case
            if (islower(plain_text[i]))
            {
                // If character is between a-z convert to ciphered character
                if (plain_text[i] >= 'a' && plain_text[i] <= 'z')
                {
                    printf("%c", k);
                }
            }
        }
        //If character is non-alpha there is no need to convert 
        else
        {
            printf("%c", plain_text[i]);
        }
    }

    printf("\n");
}