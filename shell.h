#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define END_OF_FILE -2
#define EXIT -3
extern char **environ;

/**
 * struct listnode - new struct type defining a linked listnode.
 * @dir: The directory path.
 * @next: pointer to another struct listnode
 */
typedef struct listnode
{
	char *dir;
	struct listnode *next;
} listnodeType;

/**
 * struct bltnode - New struct type defining bltnode commands.
 * @name: Name of the bltnode command.
 * @f: Function pointer to the bltnode command's function.
 */
typedef struct bltnode
{
	char *name;
	int (*f)(char **argv, char **ourfront);
} bltnodeType;

/**
 * struct alsNode - New struct defining aliases.
 * @name: Name of the alias.
 * @value: Value of the alias.
 * @next: The pointer to another struct alsNode.
 */
typedef struct alsNode
{
	char *name;
	char *value;
	struct alsNode *next;
} alstype;

/* gb link... list */
alstype *aliases;

/* Main Helpers */
/*+copy getline functioof*/
ssize_t fn_get_ln(char **ptrline, size_t *n, FILE *strm);
/*+copy ofrealloc function*/
void *fn_reset_sz(void *ourptr, unsigned int sizeOld, unsigned int sizeNew);
/*+ copy of strtok function*/
char **parse_funct(char *ourline, char *ourdelim);
/*get+location function*/
char *locate_funct(char *ourcmd);
/*get+path+dir function*/
lisType *direct_path(char *ourpath);
/*execute function needed*/
int func_exc(char **amgt, char **ourfront);
/*free the linked list*/
void func_freeList(lisType *head);
/*copy of itoa function*/
char *_itoa(int num);

/* Builtin Helpers */
char **envir_fn_cp(void);
void fn_to_free_envir(void);
char **fn_to_get_envir(const char *var);

/* Builtins */
int (*get_builtin(char *command))(char **amgt, char **ourfront);
int exit_shell(char **amgt, char **ourfront);
int envir_shell(char **amgt, char __attribute__((__unused__)) **ourfront);
int set_envir_shell(char **amgt, char __attribute__((__unused__)) **ourfront);
int unsetEnvShell(char **amgt, char __attribute__((__unused__)) **ourfront);
int change_fileDir(char **amgt, char __attribute__((__unused__)) **ourfront);
int set_shellVar(char **amgt, char __attribute__((__unused__)) **ourfront);
int helper_shell(char **amgt, char __attribute__((__unused__)) **ourfront);

/* Input Helpers */
void line_handler(char **ourline, ssize_t read);
void replace_var(char **ourline, int *exeRet);
char *arguments_get(char *ourline, int *exeRet);
int arguments_call(char **amgt, char **ourfront, int *exeRet);
int arg_runner(char **amgt, char **ourfront, int *exeRet);
int arg_handler(int *exeRet);
int argum_checker(char **amgt);
void fn_to_free_arg(char **amgt, char **ourfront);
char **alias_replacement(char **amgt);

/* String functions */
int stringLen(const char *s);
char *string_concat(char *ourDesti, const char *oursource);
char *str_n_concat(char *ourDesti, const char *oursource, size_t n);
char *copy_string(char *ourDesti, const char *oursource);
char *char_string(char *s, char c);
int copy_of_spn(char *s, char *accept);
int compare_string(char *string1, char *string2);
int ncmp_string(const char *string1, const char *string2, size_t n);

/* Error Handling */
int func_createErr(char **amgt, int err);
char *func_envErr(char **amgt);
char *errNum_1(char **amgt);
char *exitErr_num2(char **amgt);
char *changeDErr_num2(char **amgt);
char *syntxErr_num2(char **amgt);
char *errNum_126(char **amgt);
char *errNum_127(char **amgt);

/* Linkedlist Helpers */
alstype *add_alias_end(alstype **head, char *name, char *value);
void func_free_alsList(alstype *head);
lisType *add_node_end(lisType **head, char *dir);
void func_freeList(lisType *head);

void allHelper(void);
void alsHelper(void);
void chdirHelper(void);
void extHelper(void);
void hpHelper(void);
void envirHelper(void);
void setEnvirHelper(void);
void unSetEnvirHelper(void);
void hstorHelper(void);

int prFileCmd(char *file_path, int *exeRet);
#endif
