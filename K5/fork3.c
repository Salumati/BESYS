/* das Programm soll Fork aufrufen,
* Das Elternprogramm gibt "Goodbeye", das Kind "Hello" aus.
* geht das auch ohne wait?
* Antwort: Wait ist noetig, denn der fork() aufruf ist unspezifisch.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int rz = fork();
    if(rz < 0){
        fprintf(stderr, "fork() failed\n");
        return 1;
    } else if (rz == 0) {
        printf("Hello! \n");
    } else {
        int rc_wait = wait(NULL);
        printf("Goodbeye!\n");
    }
    return 0;

} 
/* Notiz: mit waitpid() sollte sich ein spezifischer Ablauf mehrer kinder regeln lassen */