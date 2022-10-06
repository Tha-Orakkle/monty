#include "monty.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag = 0, i, words = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			words++;
		}
	}

	return (words);
}

/**
 * split_into_words - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **split_into_words(char *str)
{
	char **splited_words, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	splited_words = (char **) malloc(sizeof(char *) * (words + 1));
	if (splited_words == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				splited_words[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	splited_words[k] = NULL;

	return (splited_words);
}
