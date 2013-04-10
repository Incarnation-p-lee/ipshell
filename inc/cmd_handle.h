#ifndef COMMAND_HANDLE_H
#define COMMAND_HANDLE_H


void
  eval(char *,char **);
static int
  parse_cmd(char *,char **);
static int
  builtin(char **);


typedef void (*BLTin)(void);


/* builtin command marco */
#define QUIT     0
#define EXIT     1
#define PWD      2


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

