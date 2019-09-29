#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ncurses.h>
#include <panel.h>

// Re-used constants
enum header_t {FILE_H = 0x0, DIR_H = 0x1};
enum system_t {NORMAL = 0x0, QUIT = 0x1};

// Data structures
struct date {
    __uint8_t year;
    __uint8_t month;
    __uint8_t day;
    __uint8_t hour;
    __uint8_t min;
    __uint8_t sec;
};

struct item {
    size_t size;
    char *name;
    char *path;
    char *contents;
    __uint8_t header;
    __uint8_t pstatus;
    struct date created;
    struct date modded;
    struct list *items;
    struct item *parent;
};

struct list {
    struct item *curr;
    struct list *next;
};

// System status variables
extern __uint8_t status;

// Functions
extern struct list *init(struct item *);
extern struct list *append(struct list *, struct list *);
