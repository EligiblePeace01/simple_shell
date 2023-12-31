#include "shell.h"

int lenght_tok(char *ourstring, char *ourdlm);
int tok_cnt(char *ourstring, char *ourdlm);
char **parse_funct(char *ourline, char *ourdelim);

/**
 * lenght_tok - function locates the delim
 * @ourstring: A string must be searched.
 * @ourdlm: delim charac.
 * Return: return the delim.
 */
int lenght_tok(char *ourstring, char *ourdlm)
{
	int indx = 0, len = 0;

	while (*(ourstring + indx) && *(ourstring + indx) != *ourdlm)
	{
		len++;
		indx++;
	}

	return (len);
}

/**
 * tok_cnt -  function count the num of delim .
 * @ourstring: string must be searched.
 * @ourdlm: ourdlm char.
 * Return: return the num of  the words.
 */
int tok_cnt(char *ourstring, char *ourdlm)
{
	int indx, tkns = 0, len = 0;

	for (indx = 0; *(ourstring + indx); indx++)
		len++;

	for (indx = 0; indx < len; indx++)
	{
		if (*(ourstring + indx) != *ourdlm)
		{
			tkns++;
			indx += lenght_tok(ourstring + indx, ourdlm);
		}
	}

	return (tkns);
}

/**
 * parse_funct -  function parse our string.
 * @ourline: the string must be tokenised.
 * @ourdelim: our delimeter.
 * Return: tokenised word.
 */
char **parse_funct(char *ourline, char *ourdelim)
{
	char **ptr;
	int indx = 0, tkns, t, letters, l;

	tkns = tok_cnt(ourline, ourdelim);
	if (tkns == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tkns + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tkns; t++)
	{
		while (ourline[indx] == *ourdelim)
			indx++;

		letters = lenght_tok(ourline + indx, ourdelim);

		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (indx -= 1; indx >= 0; indx--)
				free(ptr[indx]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = ourline[indx];
			indx++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
