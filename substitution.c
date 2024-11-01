#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool check_key(string key);

int main(int argc, string argv[])
{
    //makes sure the user inputs a single command line argument.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //checks if the users key passes all the conditions
    if (!check_key(argv[1]))
    {
        printf("key is not valid!\n");
        return 1;
    }

    string key = argv[1]; //stores the value of the user key
    string ptext = get_string("Plaintext: ");
    printf("ciphertext: ");

    //loops through the key and returns the cipher text.
    for (int i = 'A'; i <= 'Z'; i++)
    {
        key[i - 'A'] = toupper(key[i - 'A']) - i;
    }

    for (int i = 0, len = strlen(ptext); i < len; i++)
    {
        if (isalpha(ptext[i]))
        {
            ptext[i] = (ptext[i]) + key[ptext[i] - (isupper(ptext[i]) ? 'A' : 'a')];
        }
        printf("%c", ptext[i]);
    }
    printf("\n");

    return 0;
}

//checks if the user input matches all the conditions.
bool check_key(string key)
{
    int freq[26] = { 0 };
    int n = strlen(key);

    if (n != 26)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        //checks if the user key contains non alphabetical characters.
        if (!isalpha(key[i]))
        {
            return false;
        }
        // checks for the frequency of a character in the key.
        int index = toupper(key[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }
    return true;
}