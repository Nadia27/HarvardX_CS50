#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int shift(char c); // Prototype declaration (Function)

int main(int argc, string argv[])
{
    string k = argv[1];   // keyword alphabetical string
    int k_char_index = 0; // keyword character index counter

    if (argc != 2) // If user does not enter keyword
    {
        printf("./vigenere keyword\n");
        return 1;
    }

    if (argc == 2) // If user enters keyword
    {
        for (int i = 0; i < strlen(k); i++)
        {
            if (isalpha(k[i])) // If keyword is entirely alpha
            {
                int key = shift(argv[1][i]); // call shift function to get shift values
            }
            else // If k contains any character besides alpha or more than one arugument
            {
                printf("./vigenere keyword\n");
                return 1;
            }
        }

        // Ask user for message to encipher
        string plain_text = get_string("Enter a message to cipher: ");
        printf("ciphertext: ");

        for (int j = 0; j < strlen(plain_text); j++)
        {
            // Number index of plain_text character in alphabet
            int alpha_index = plain_text[j] - 'A';
            int lower_alpha_index = plain_text[j] - 'a';

            int value_of_shift = shift(argv[1][k_char_index]); // value of shift

            // Number index of ciphered character
            int ciph = (alpha_index + value_of_shift) % 26;
            int lower_ciph = (lower_alpha_index + value_of_shift) % 26;

            // Convert ciphered index back ascii code
            int upper_encrypted_letter = 65 + ciph;
            int lower_encrypted_letter = 97 + lower_ciph;

            if (isalpha(plain_text[j]))
            {
                if (isupper(plain_text[j]))
                {
                    if (plain_text[j] >= 'A' && plain_text[j] <= 'Z')
                    {
                        printf("%c", upper_encrypted_letter);
                    }
                }
                if (islower(plain_text[j]))
                {
                    if (plain_text[j] >= 'a' && plain_text[j] <= 'z')
                    {
                        printf("%c", lower_encrypted_letter);
                    }
                }
            }
            else
            {
                printf("%c", plain_text[j]); // if plaintext[j] !alpha do not modify
            }

            // If plain_text[j] is alpha go to next index in string k
            if (isalpha(plain_text[j]))
            {
                k_char_index++;
            }

            // If b gets to length of string k reset counter to index 0
            if (k_char_index == strlen(argv[1]))
            {
                k_char_index = 0;
            }
        }
        printf("\n");
    }
}

int shift(char c)
{
    int shift_value;
    c = tolower(c);
    shift_value = c - 'a';
    return shift_value;
}
