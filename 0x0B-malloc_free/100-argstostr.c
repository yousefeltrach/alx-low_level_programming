#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program into a single string.
 *
 * @ac: Number of arguments.
 * @av: Array of arguments.
 *
 * Return: A pointer to the concatenated string of arguments.
 */
char *argstostr(int ac, char **av)
{
    int i, j, len = 0;
    char *str;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* Calculate the total length of all arguments */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
            len++;
        len++; /* Add 1 to account for the space after each argument */
    }
    len++; /* Add 1 for the null terminator */

    /* Allocate memory for the concatenated string */
    str = malloc(sizeof(char) * len);
    if (str == NULL)
        return (NULL);

    /* Concatenate the arguments into the string */
    len = 0;
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
        {
            str[len] = av[i][j];
            len++;
        }
        str[len] = ' '; /* Add a space after each argument */
        len++;
    }
    str[len] = '\0'; /* Add the null terminator */

    return (str);
}
