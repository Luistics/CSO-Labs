#include "lab4.h"

//Luis Olivar lao294

int main()
{
    //run the shell until EOF (keyboard Ctrl+D) is detected
    while (userinput( ) != EOF)
    {
        process();
    }
    return 0;
}

//Bug 1: In process.c, line 11 read "int narg;" which was not initialized, resulting in the arguments from the first command being saved and never overwritten. By initializing the variable to 0 on each call to process, the correct number of arguments is stored in the variable.

//Bug 2: On lines 24-27 in runcommand.c, I added a default exit if the cd command is used during a child process. Then on lines 53-64 I added logic that checks if the first argument inputted is "cd" using the strcmp function. If it is, then it changes the difrecory to the second arguemnt if it is not null using the chdir function. If it is null, then the getenv function is used to return the default address, and then the directory is changed to that default address. As for the ".." command, it worked by default without me having to do anything.

//Bug 3: On lines 24-27 in runcommand.c there is a condition for if the first argument is "exit" as well as "cd" for exiting the child process, where it would enter the parent process to complete the exit. In addition, I added another if statement on lines 48-51 which takes care of the exit if the first argument was "exit".

//Bug 4: Since CTRL+C is a signal by default, namely SIGINT, I had to add a handler function to catch this signal when it is inputted by the user. At the bottom of process.c, I added the handler function which is just an empty declaration. On line 14 of procces.c I added the signal call for SIGINT. Then in runcommand.c, in the switch statement, I added logic that would allow the CTRL+C command to be inputed during a child process which would just exit from that procces but not from the terminal entirely. 

//Bug 5: For this bug I simply changed line 69 in runcommand.c to where == FOREGROUND to allow the wait to happen during the parent process, otherwise returning -1 if the child process had terminated but was not reaped.