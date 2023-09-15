#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

/* Buffer sizes for reading and writing */

#define READ_BUF_SIZE 1024

#define WRITE_BUF_SIZE 1024

#define BUF_FLUSH -1

/* Constants for command chaining */

#define CMD_NORM	0

#define CMD_OR		1

#define CMD_AND		2

#define CMD_CHAIN	3

/* Constants for convert_number() */

#define CONVERT_LOWERCASE	1

#define CONVERT_UNSIGNED	2

/* History file settings */

#define USE_GETLINE 0

#define USE_STRTOK 0


#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - Singly linked list.
 * @num: The number field.
 * @str: String
 * @next: Pointer points to the next node.
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 * struct passinfo - Container for pseudo-arguments to pass into functions,
 * enabling a consistent prototype for function pointer structs.
 * @arg: A string generated from getline, containing arguments.
 * @argv: An array of strings generated from arg.
 * @path: A string representing the path for the current command.
 * @argc: The count of arguments.
 * @line_count: The count of encountered errors.
 * @err_num: The error code for exit() calls.
 * @linecount_flag: A flag indicating whether to count this line of input.
 * @fname: The filename of the program.
 * @env: A linked list serving as a local copy of the environment variables.
 * @history: A linked list representing the history node.
 * @alias: A linked list containing aliases.
 * @environ: A custom-modified copy of the environment
 *	from the linked list 'env'.
 * @env_changed: A flag indicating whether the environment was changed.
 * @status: The return status of the last executed command.
 * @cmd_buf: Address of a pointer to the cmd_buf, used when chaining commands.
 * @cmd_buf_type: The type of command chaining (CMD_type ||, &&, ;).
 * @readfd: The file descriptor from which to read line input.
 * @histcount: The history line number count.
 */


typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}




/**
 * struct builtin - Represents a builtin command and its associated function.
 * @type: A string describing the builtin command.
 * @func: A function pointer to the implementation of the builtin command.
 */

typedef struct builtin
{
	char *type;/* The name or identifier of the builtin command */

	/* A function pointer to the implementation of the command. */
	int (*func)(info_t *);
} builtin_table;

/* Function prototypes */

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int loophsh(char **);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif/* _SHELL_H */

