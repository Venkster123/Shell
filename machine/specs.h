#ifndef SPECS_H
#define SPECS_H

#define CAPACITY 0x100
#define ALIGN 0x1
#define BUF_SIZE 0x10

// Remove all headers later
#include <stdio.h>

struct header {
	struct {
		struct header *next;
		unsigned int size;
	} item;

	char align[ALIGN];
};

int DRAM = CAPACITY;
struct header *flist = 0;

void boot()
{
	printf("Size of header: %ld\n", sizeof(struct header));
}

#endif
