#include "shell.h"

char **env_fn_cp(void);
void fn_to_free_env(void);
char **fn_to_get_env(const char *var);

/**
 * env_fn_cp - Function create copy of env.
 * Return: return NULL or double
 */
char **env_fn_cp(void)
{
	char **new_environ;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(stringLen(environ[index]) + 1);

		if (!new_environ[index])
		{
			for (index--; index >= 0; index--)
				free(new_environ[index]);
			free(new_environ);
			return (NULL);
		}
		copy_string(new_environ[index], environ[index]);
	}
	new_environ[index] = NULL;

	return (new_environ);
}

/**
 * fn_to_free_env - this function to free env.
 */
void fn_to_free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}

/**
 * fn_to_get_env - this function gets env var.
 * @var: name of env var.
 * Return: null or double poiter.
 */
char **fn_to_get_env(const char *var)
{
	int index, len;

	len = stringLen(var);
	for (index = 0; environ[index]; index++)
	{
		if (ncmp_string(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
