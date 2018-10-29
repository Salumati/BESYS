/* Ruft fork() auf und ruft eine form von exec()
 * um ein anderes programm (/bin/ls) laufen zu lassen.
 * kannst du alle varianten von exec() aufrufen?
 * Wieso denkst du gibt es soviele Varianten dieses einen Aufrufs?
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0){
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("fork3");
        myargs[1] = strdup("ws");
        myargs[2] = NULL;
        if(-1 == execvp(myargs[0], myargs)) {
            printf("fehler bei exec\n");
        }
        printf("this shouldn't print out");
    } else {
        int rc_wait = wait(NULL);
        printf("hello, I am parent fo %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;


    /*execl();
    execle();
    execlp();
    execv();
    execvp();
    execvpe(); */
}