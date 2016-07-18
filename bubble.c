/**
*  File: bubble.c
*
*  Desc  :: Sorts an array of chars by ASCII code in order specified by a key.
*           Uses optimized bubble sort algorithm.
*        
*  Input :: order key: accepted values: -a for ascending order,
*                                       -d for descending order;
*
*           array    : accepted values: set of chars separated by spaces;
*
*  Output:: sorted array
*
*  Author:: Artem Pokyntelytsia
*           ##########
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int SetSortDirection(string order_key, char character1,char character2);

int main(int argc, string argv[])
{
    // Checks presence of other arguments
    if (argc == 1)
    {
        printf("* Usage: ./bubble <order> <array>\n");
        printf("*\n");
        printf("*        <order> -a for ascending, -d for descending\n");
        printf("*        <array> array of chars separated by a space\n");
        return -1;
    }
    // Checks for bad order keys
    else if (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-d") != 0)
    {
        printf("* Error: unknown order key\n");
        return -2;
    }
    else
    {
        // Checks for elements with more than one character
        int error_count = 0;
        for (int str_index = 2; str_index < argc; str_index++)
        {
            if (strlen(argv[str_index]) > 1)
            {
                error_count++;
            }
        }
        if (error_count != 0)
        {
            printf("* Error: too many characters in array element\n");
            return -3;
        }
        else
        {
            // The number of pairs of elements
            int elem_pairs = argc - 3;
            // Runs through the array until all the elements have been sorted.
            for (int i = 0; i < elem_pairs; i++)
            {
                int sorted = 0;
                string elem_storage;
                // Compares and permutes the elements
                for (int j = 2; j < argc - 1; j++)
                {
                    if (SetSortDirection(argv[1], argv[j][0], argv[j + 1][0]))
                    {
                        elem_storage = argv[j];
                        argv[j]      = argv[j + 1];
                        argv[j + 1]  = elem_storage;
                    }
                    else
                    {
                        sorted++;
                    }
                }
                // Terminates the loop if the array is already sorted
                if (sorted == elem_pairs)
                {
                    break;
                }
            }
            // Prints sorted array
            for (int str_index = 2; str_index < argc; str_index++)
            {
                printf("%s ", argv[str_index]);
            }
            printf("\n");
            return 0;
        }
    }
}

/**
*  Function Name: SetSortDirection
*
*  Description:
*      Sets the sort direction depending on the order key. Compares two characters
*      using their ASCII codes.
*        
*  Arguments:
*      order_key:
*          type: string;
*          accepted values: "-a" defines ascending order,
*                           "-d" defines descending order;
*          description: the key is used to specify the sort order.
*
*     character1:
*         type: char;
*         accepted values: set of chars separated by spaces;
*         description: one of two characters to be compared.
*
*     character2:
*         type: char;
*         accepted values: set of chars separated by spaces;
*         description: the other character.
*
*  Returns:
*      0 as a negative result of comparison, 1 as a positive result of comparison.
*/
int SetSortDirection(string order_key, char character1, char character2)
{
    if (strcmp(order_key, "-a") == 0)
    {
        return character1 > character2;
    }
    else
    {
        return character1 < character2;
    }
}
