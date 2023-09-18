#include "shell.h"

void envHelper(void);
void setEnvHelper(void);
void unSetEnvHelper(void);
void hstorHelper(void);

/**
 * envHelper - this function display info.
 */
void envHelper(void)
{
	char *ourmsg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, ourmsg, stringLen(ourmsg));
}

/**
 * setEnvHelper - this function display and set info.
 */
void setEnvHelper(void)
{
	char *ourmsg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, ourmsg, stringLen(ourmsg));
	ourmsg = "envir var, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, ourmsg, stringLen(ourmsg));
	ourmsg = "\tUpon fail, prints a message to stderror.\n";
	write(STDOUT_FILENO, ourmsg, stringLen(ourmsg));
}

/**
 * unSetEnvHelper - this function unset envirenment
 */
void unSetEnvHelper(void)
{
	char *ourmsg = "unsetenv: unset envirenment [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, ourmsg, stringLen(ourmsg));
	ourmsg = "env var.\n\n\tUpon fail, prints a ";
	write(STDOUT_FILENO, ourmsg, stringLen(ourmsg));
	ourmsg = "message to stderr.\n";
	write(STDOUT_FILENO, ourmsg, stringLen(ourmsg));
}
