#ifndef EXTERNAL_D_H
#define EXTERNAL_D_H

extern void
  eval(char *,char **);
extern void
  pwd(void);
extern void
  exitsh(void);
extern void
  cd(void);

extern char command[CMD_MAX];
extern char *cargv[ARG_MAX];

#endif
