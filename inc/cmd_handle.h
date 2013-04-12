#ifndef COMMAND_HANDLE_H
#define COMMAND_HANDLE_H

void
  eval(char *,char **);
static int
  parse_cmd(char *,char **);
static int
  builtin(char **);


typedef void (*BLTin)(void);

extern char *cargv[ARG_MAX];
extern void pwd();
extern void exitsh();
extern void cd();


char *builtin_cmd[] = {
  "quit",
  "exit",
  "pwd",
  "cd",
};

static BLTin builtin_function[] = {
  exitsh,
  exitsh,
  pwd, 
  cd,
};

#endif

