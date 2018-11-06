#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(void){
    
    /*
    A5
    Normaler Ablauf: keine Meldungen
    valgrind: beschwert sich ueber einen "invalid write of size 4"
    Anmerkung: Eigentlich geht das Array nur von 0 - 99,
    daher schreibt data[100] = 0; in den nicht reservierten Speicherbereich.
    Dies ist zwar moeglich, kann jedoch dazu fuehren, dass andere Daten ueberschrieben werden.
    */
    int* data = (int*) malloc(100 * sizeof(int));
    data[100] = 0;
    free(data);
    
    /*
    A6
    Normaler Ablauf: Es wird 0 zurueckgeliefert
    valgrind: beschwert sich ueber einen "invalid read of size 4"
    Anmerkung: Der Zeiger zeigt nach free() nicht mehr auf eine Adresse,
    daher wird nicht der gespeicherte Wert zurueck geliefert.
    valgrind erkennt dies als Fehler.
    */
    data = (int*) malloc(10 * sizeof(int));
    data[0] = 1;
    free(data);

    printf("%d\n", data[0]);
    
    /*
    A7
    Normaler Aufruf: Invalid Pointer
    valgrind: Invalid free() / delete / delete[] / realloc()
    Anmerkung: Wir versuchen Speicher freizugeben der nie reserviert wurde.
    */
   data = (int*) malloc(10 * sizeof(int)); // array
   int *newPointer = data;

   free(newPointer + 10); // passing funny value to free
   free(data);
   /*
   A8
   */
    
    /*
    A9
    */
   return 0;
}