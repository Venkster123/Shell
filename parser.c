#include "resources.h"

// Get the flags fro mthe input line
struct ARGS *flags(char *line)
{
	struct ARGS *flags = malloc(sizeof(struct ARGS));
	char *word = malloc(sizeof(char) * LINE_BUF_SIZE);
	flags->args = malloc(sizeof(char) * LINE_BUF_SIZE);
	char *begin = word;
	int letters = 0;
	flags->argc = 0;

	char **start = flags->args;

	if (line == NULL) {
		free(flags);
		return NULL;
	}

	while (*line) {
		if (isspace(*line) && letters > 0) {
			*word = '\0';
			letters = 0;
			(*flags->args) = begin;
			word = malloc(sizeof(char) * LINE_BUF_SIZE);
			begin = word;
			(flags->args)++;
			flags->argc++;
		} else {
			*(word++) = *line;
			letters++;
		}

		line++;
	}

	if (letters > 0) {
		*word = '\0';
		letters = 0;
		(*flags->args) = begin;
		flags->argc++;
	}

	flags->args = start;

	return flags;
}

// Parse the given input and do the actions
struct DIR *parser(struct DIR *root, struct DIR *curr, char *input)
{
	struct ARGS *tokens = flags(input);
	char **args = tokens->args;
	int argc = tokens->argc;

	struct DIR *dir;

	if (argc == 0)
		return NULL;

	char *cmd = args[0];

	if (strcmp(args[0], "exit") == 0) {
		exit(0);
	} else if (strcmp(args[0], "mkdir") == 0) {
		if (argc > 1)
			mkdir(curr, NULL, args[1]);
		else
			printf("mkdir: missing operand\n");
	} else if (strcmp(args[0], "touch") == 0) {
		if (argc > 1)
			touch(curr, args[1]);
		else
			printf("touch: missing file operand\n");
	} else if (strcmp(args[0], "ls") == 0) {
		list_directory(curr);
	} else if (strcmp(args[0], "cd") == 0) {
		if (argc == 2) {
			dir = cd(curr, args[1]);
			if (dir == NULL)
				return NULL;
			return dir;
		} else if (argc == 1) {
			return root;
		} else {
			printf("cd: too many arguments\n");
		}
	} else if (strcmp(args[0], "pwd") == 0) {
		printf("%s\n", curr->path);
	} else {
		printf("%s: command not found\n", args[0]);
	}

	return NULL;
}