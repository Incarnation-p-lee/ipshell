#ifndef COMMAND_PWD_H
#define COMMAND_PWD_H

#define FILENAME_LEN_MAX 255
#define PATH_LEN_MAX     65535

void 
  pwd();
static unsigned long
  getinode(char *);
static void
  pwd_nested(unsigned long);
static void
  getfilename(unsigned long,char *);

#endif
  
