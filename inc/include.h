/*
* include all the reference standard header files.
*/
#ifndef SHINCLUDE_H
#define SHINCLUDE_H 

/* C standard including */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#ifdef __linux__
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#endif

#endif
