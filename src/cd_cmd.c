/*
* Author:   Incarnation.p Lee 
* Date:     2013/Apr/6
* FOR:      cd command to change directory
*/

void
  cd()
{
  if(NULL == cargv[0])
    fprintf(stdout,"call cd command in a unknown context.\n");
  
  if(NULL == cargv[1])
  {
    chdir("/home");
    fprintf(stdout,"Switched to /home..\n");
  }
  else
  {
    chdir(cargv[1]);
    fprintf(stdout,"Switched to ");
    fflush(stdout);
    pwd();
  }
 
  return;
}
