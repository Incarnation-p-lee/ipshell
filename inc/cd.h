#ifndef COMMAND_CD_H
#define COMMAND_CD_H

extern char *cargv[ARG_MAX];
extern void pwd();
extern char *builtin_cmd[];

void
cd(void);

#endif
  
