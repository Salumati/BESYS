/*
Gruppe 2: Sarah Tiefert, Sebastian Manz.
Sinn des Programms ist es, die Zeitkosten des Systemaufrugs (SystemCall) zu messen.
dies wird mit getTimeOfDay() realisiert
es brauch zwischen 1 und 2 ms
*/

#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>

int main(void){
    struct timeval tv;
    int ms, e = 0, i;
    //struct tm* ptm;
    //char time_string[40];

    //ptm = localtime (&tv.tv_sec);
    //strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
    
    for(i = 0; i <= 10; i++){
        gettimeofday (&tv, NULL);
        ms = tv.tv_usec;
        read(0, NULL, 0);
        gettimeofday (&tv, NULL);
        e = e + (tv.tv_usec - ms);
    }
    printf("Zeit fuer SysCall: %d \n", e/i);

/* ContextSwitch Test*/
    gettimeofday (&tv, NULL);
    ms = tv.tv_usec;
    int f = fork();

    if(f < 0){
        printf("fork failed\n");
    } else if(f == 0){
        gettimeofday (&tv, NULL);
        printf("I am child, ContextSwitch Time = %d\n", tv.tv_usec - ms);
        
    } else {
        int rc_wait = wait(NULL);
    }
    return 0;
}
