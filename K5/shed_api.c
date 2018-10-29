/* Ein programm, dass den Befehl fork() aufruft */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int x = 1;
    printf("Hallo, x ist: %d\n ich bin (pid:%d)\n ", x, (int) getpid());
    int fc = fork();/*startet ein neues Programm, 
                        mit eigenen Speicherbereich, 
                        welches alle befehle nach fork ausfuehrt 
                        und alle Variablen von vor for uebernimmt
                        */
    x++;

    if(fc < 0) {
        printf("fork() wurde nicht ausgeführt\n");
    } else if (fc == 0) {
        printf("hello, i am child (pid:%d)\n Mein x ist: %d\n", (int) getpid(), x);
    } else {
        printf("hello, I am parent of %d (pid:%d)\n Mein x ist: %d\n", fc, (int) getpid(), x );
    }
    /* sowohl parent als auch child haben am ende einen x-Wert von 2,
       denn ihre speicher sind unabhängig voneinander
       */

    return 0; 
}
