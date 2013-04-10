/*
* Author:   Incarnation.p Lee 
* Date:     2013/Apr/5
* FOR:      module for handling input command line and 
*           workflow
*/

void
  eval(char *cmdline,char **envp)
{
  char buf[CMD_MAX];
  int bg,status;
  pid_t cpid;

  memcpy(buf,cmdline,CMD_MAX);
  bg = parse_cmd(buf,cargv);		/* return 0 if this is a background command */

  if(CMD_NULL == bg)
    return;

  if(!builtin(cargv))    /* return 0, not a builtin command */
  {
    if(cpid = fork(),0 == cpid)  /* if child return */
      if(execve(cargv[0],cargv,envp) < 0)
      {
        fprintf(stderr,"command <%s> not found,plz check the name.\n",cargv[0]);
        exit(0);
      }
      
    if(bg)
    {
      if(waitpid(cpid,&status,0) < 0)
        fprintf(stdout,"waitpid() error.\n"); 
    }
    else
        fprintf(stdout,"[%d] @%s",cpid,cmdline); 
  }

  return;
}

static int
  parse_cmd(char *cmdline,char ** argv)
{
  int i = 0;
  int argc = 0;

  while(' ' == cmdline[i])   
    i++;
  
  if('\n' == cmdline[i])
    return CMD_NULL;

  cmdline[strlen(cmdline) - 1] = ' ';

  while('\0' != cmdline[i])
  {
    if(' '==cmdline[i])
    {
      i++;
      continue;
    }

    if(ARG_MAX < argc)
    {
      fprintf(stdout,"reach MAX arguments counts.\n");
      break;
    }

    argv[argc++] = &cmdline[i];
    while(i++, ' ' != cmdline[i] && '\0' != cmdline[i])
      ;
    cmdline[i++] = '\0';
  }/* while('\n' != cmdline[i]) [end] */

  argv[argc] = NULL;
  if(0 == argc)
    return 1;

  if('&' == *argv[argc - 1])
  {
    argv[argc - 1] = NULL;
    return 0;
  }

  return 1;
}

static int
  builtin(char **argv)
{
  int i = -1, len;

  len = sizeof(builtin_function)/sizeof(builtin_function[0]);
  
  while(i++, i < len)
  {
    if(!strcmp(argv[0],builtin_cmd[i]))
    {
      (*builtin_function[i])(); 
      return 1;
    }
  }

  return 0;
}

