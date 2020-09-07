// Takes a command line arguement <key> and creates a ciphertext by rotating all letters in a
// plain text string by that many positions in the alphabet

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Per specifications, argc must be 2 or we will return an error message and the value
    // 1 to main
    if (argc == 2)
    {
        // Set our key and prompt the user for their plaintext message to be converted to
       // ciphertext
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");

        // Establish our alphabetical index by creating two strings.  Since strings are
       // actually just arrays of characters...
       // This will be the same as creating an array where A and a are at index 0, B and b at
       // 1, C and c at 2, etc.
        string upper_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string lower_alpha = "abcdefghijklmnopqrstuvwxyz";

        // Count the length of our plaintext string. Create an empty character array of the
        // same lenth to hold our ciphertext
        int plaintext_length = strlen(plaintext);
        char ciphertext[plaintext_length];

        // Convert plaintext to ciphertext using our alphabetical index while preserving case
        for (int i = 0; i < plaintext_length; i++)
        {
            int ascii_to_alpha = 0;
            if (isupper(plaintext[i]))
            {
                ascii_to_alpha = ((int) plaintext[i] - 65 + key) % 26;
                ciphertext[i] = upper_alpha[ascii_to_alpha];
            }
            else if (islower(plaintext[i]))
            {
                ascii_to_alpha = ((int) plaintext[i] - 97 + key) % 26;
                ciphertext[i] = lower_alpha[ascii_to_alpha];
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }

        // Display the ciphertext to the user
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        printf("Error: incorrect command line format.  Try again using exactly one command line arguement.\n");
        return 1;
    }
}