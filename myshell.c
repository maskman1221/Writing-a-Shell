#include<stdio.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


void command()
{
	char cmd[100];
	char para[100];
	scanf("%s",cmd);
	char c = getchar();
	char *exe_command[100]={};
	char *temp;
	char stop[50]={"exit"};
	if(c==' ')
	{
		scanf("%s",para);
		temp = strtok(para, "\n");	
		exe_command[1] = strdup(para);
	}
    	temp = strtok(cmd, " \n");
	exe_command[0] = strdup(temp);
	
    
	pid_t pid=fork();
	if(pid==-1)
	{
		exit(1);
	}
	else if(pid==0)
	{
		execvp(exe_command[0],exe_command);
	}
	else
	{
		int CD;
		waitpid(pid,&CD,0);
	}

		if(cmd[0]==stop[0]&&cmd[1]==stop[1]&&cmd[2]==stop[2]&&cmd[3]==stop[3])
	{
		exit(0);
	}

}

void get_time()
{
    time_t ctime;
    struct tm *t;
    time(&ctime);
    t=localtime(&ctime);
    printf("%d/%d/%d/ %d:%d:%d#\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
}


void main()
{
	while(1)
	{
		get_time();
        	command();
	}

}
