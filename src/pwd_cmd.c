/*
* Author:   Incarnation.p Lee 
* Date:     2013/Apr/6
* FOR:      pwd command implement for display current directory
*/

void
  pwd()
{
  pid_t pid;
  int status;

  if(pid = fork(), 0 == pid)
  {
    pwd_nested(getinode("."));
    fprintf(stdout,"\n");
    exit(0);
  }
  else
  {
    if(waitpid(pid,&status,0) < 0)    
      fprintf(stdout,"waitpid error.\n");
  }
  return;
}

static void
  pwd_nested(unsigned long inode)
{
  
  char fname[FILENAME_LEN_MAX];
  memset(fname,'\0',FILENAME_LEN_MAX);

  if(inode != getinode(".."))
  {
    getfilename(inode,fname);
    chdir("..");
    inode = getinode(".");
    pwd_nested(inode);
    fprintf(stdout,"%s/",fname);
  }
  else
    fprintf(stdout,"/");
  
  return;
}
  
static unsigned long
  getinode(char *filename)
{
  struct stat info;
  
  if(-1 == stat(filename,&info))
  {
    fprintf(stderr,"stat error.\n");
    return -1;
  }
  
  return info.st_ino;
}

static void
  getfilename(unsigned long inode,char *filename)
{
  DIR *dp;
  struct dirent *entry;

  if(dp = opendir(".."), NULL==dp)    
  {
    fprintf(stdout,".");
    return;
  }
 
  while(entry = readdir(dp), entry != NULL)
  {
    if(inode == entry->d_ino)
    {
      strcpy(filename,entry->d_name);
      closedir(dp);
      return; 
    }
  }

  return;
}
