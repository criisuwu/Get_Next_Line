#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char    *get_next_line(int fd);

#endif