/*
* Author:   Incarnation.p Lee 
* Date:     2013/Apr/5
* FOR:      A sample shell
*/
#include "include.h"
#include "defvars.h"
#include "external.h"

int
  main(int argc,char **argv,char **envp)
{
  unsigned int count = 0;

  fprintf(stdout,"Incarnation.p Lee, simple shell..."
    "\nVersion 0.1\n");
  
  while(1)
  {
    memset(command,0,sizeof(command));
    fprintf(stdout,"[%03u]^>",count++);
    fgets(command,CMD_MAX,stdin);
    if(feof(stdin))
      exit(0);
    eval(command,envp);
  }

  return EXIT_SUCCESS;
}


