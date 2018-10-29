/*C-Programm, dass ein Dokument öffnet
und anschliessend nach dem Aufruf des fork() Befehls
als child parallel ausgefuehrt wird */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
    size_t openFile = open("./text.txt", O_WRONLY);
    if(openFile < 0) {
        return 1;
    }
    fork();
    
    write(openFile, "12345 ", 5);
    
    if(close(openFile) < 0) {
        return 1;
    }
    return 0;
}
