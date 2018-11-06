#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(void){
    /* Kapitel 14 A1 
    Ausgabewert: (nil)
    
    A2: 
    Ausgabe des gdb:
    (gdb) run
    Starting program: /home/sa851tie/BeSys_HW/K14/null 
    (nil)
    [Inferior 1 (process 18477) exited normally]
    (gdb) 

    A3:
    valgrind Ausgabe:
    ==19556== Command: ./null
    ==19556== 
    (nil)
    ==19556== 
    ==19556== HEAP SUMMARY:
    ==19556==     in use at exit: 0 bytes in 0 blocks
    ==19556==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
    ==19556== 
    ==19556== All heap blocks were freed -- no leaks are possible
    ==19556== 
    ==19556== For counts of detected and suppressed errors, rerun with: -v
    ==19556== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

    Interpretation:
    -Ausgabe des Pointers
    -alles durchgelaufen
    -einmal Speicher allokiert und einmal freigegeben,
    Allokation für einen Integer (1.024 Bytes)
    Anmerkung: Der Speicher wurde nicht von uns befreit! Garbage Collector?
    -keine Fehler gefunden
    */
    int * intP;
    intP = NULL;
    printf("%p\n", (void *)intP);


    /*
    A4:
    Normal laufen lassen: geht, keine weiteren Infos
    gdb: keine Probleme werden angezeigt
    valgrind: liefert einen Speicherfehler zurueck, 40 Bytes werden verloren
    Anmerkung: Compiler prüft nur ob ein Programm durchlauft,
    Speicherfehler werden nicht erkannt
    */
   intP = (int*) malloc(10 * sizeof(int));
    return 0;
}