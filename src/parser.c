#include "system.h"

struct args *flags(char *line)
{
	struct args *flags = malloc(sizeof(struct args));
	char *word = malloc(sizeof(char) * LINE_BUF_SIZE);
	flags->flags = malloc(sizeof(char) * LINE_BUF_SIZE);
	char *begin = word;
	int letters = 0;
	flags->argc = 0;

	char **start = flags->flags;
	
	if (line == NULL) {
		free(flags);
		return NULL;
	}

	while (*line) {
		if (isspace(*line) && letters > 0) {
			*word = '\0';
			letters = 0;
			
			(*flags->flags) = begin;
			
			word = malloc(sizeof(char) * LINE_BUF_SIZE);
			begin = word;
			(flags->flags)++;
			flags->argc++;
		} else  {
			*(word++) = *line;
			letters++;
		}

		line++;
	}

	if (letters > 0) {
		*word = '\0';
		letters = 0;
		(*flags->flags) = begin;
		flags->argc++;
	}

	flags->flags = start;

	return flags;
}

struct item *parser(char *input)
{
	wprintw(window, "Parsed\n");

	return NULL;
}
