#include "lab4.h"

//Luis Olivar lao294

// Execute a command with optional wait
int runcommand(char** cline, int where)
{
    char* path;
    pid_t pid;
    int status;

    switch(pid = fork())
    {
        case -1:
            perror(SHELL_NAME);
            return (-1);
        case 0:
            //bug 4 where SIGINT is Ctrl+C
            if(where == BACKGROUND)
            {
                signal(SIGINT,handler);
            }
            //bug 2 and 3
            if((strcmp(cline[0], "cd") == 0) || (strcmp(cline[0],"exit") == 0))
            {
                exit(0);
            }
            else
            {
                execvp(*cline,cline);
                //we should never get to this code, sice execve does not return
                perror(*cline);
                exit(1);
            }
            break;
        default:
            break;
    }

    // Code for parent
    // If background process print pid and exit program is running in the background
    if(where == BACKGROUND)
    {
        printf("[Process id %d]\n",pid);
        return 0;
    }
    //bug 3
    if(strcmp(cline[0],"exit") == 0)
    {
        exit(0);
    }
    //bug 2
    else if(strcmp(cline[0],"cd") == 0)
    {
        if(cline[1]!= NULL)
        {
            chdir(cline[1]);
        }
        else
        {
            path = getenv("HOME");
            chdir(path);
        }
    }

    //Code for child
    //bug fix 5
    // Wait until process pid exits
    if(where == FOREGROUND)
    {
        if (waitpid(pid,&status,0) == -1) 
        {
            return -1;
        } 
        else 
        {
            return status;
        }
    }
}
