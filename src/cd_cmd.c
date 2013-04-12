/*
* Author:   Incarnation.p Lee 
* Date:     2013/Apr/6
* FOR:      cd command to change directory
*/

void
  cd()
{
  if(strcmp(builtin_cmd[CD], cargv[0]))
  {
    fprintf(stdout,"call cd command in a unknown context.\n");
	return;
  }
  
  if(NULL == cargv[1])
  {
    chdir("/home");
    fprintf(stdout,"Switched to /home..\n");
  }
  else
  {
    if(!chdir(cargv[1]))
	{
      fprintf(stdout,"Switched to ");
      fflush(stdout);
      pwd();
    }
	else
	  fprintf(stdout,"unknown directory:%s\n",cargv[0]);
  }
 
  return;
}
