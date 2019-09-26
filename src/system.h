#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum headers {FILE_H = 0xf, DIR_H = 0xe};

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