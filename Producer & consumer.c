#include <stdio.h>
#include <stdlib.h> 
#define Pf printf
#define Sf scanf

void main() {
    int buffer[10];     // The shared buffer of size 10
    int bufsize;        // Actual buffer size variable
    int in, out;        // Pointers for insertion ('in') and removal ('out')
    int produce;        // Variable to hold the value being produced
    int consume;        // Variable to hold the value being consumed
    int choice;         

    in = 0;
    out = 0;
    choice = 0;
    bufsize = 10;
    
    while (choice != 3) {
        
        Pf("\n1. Producer\n2. Consumer\n3. Exit\n");
        Pf("Enter your choice: ");
        Sf("%d", &choice);

        switch (choice) {
            
            // === Case 1: Producer ===
            case 1: {
                if ((in + 1) % bufsize == out) {
                    Pf("\nBuffer is Full!");
                }
                else {
                    Pf("\nEnter the value: ");
                    Sf("%d", &produce);
                    
                    buffer[in] = produce;
                    in = (in + 1) % bufsize;
                }
                break;
            } // End Case 1 block

            // === Case 2: Consumer ===
            case 2: {
                if (in == out) {
                    Pf("\nBuffer is Empty!");
                }
                else {
                    // Consumption logic
                    consume = buffer[out];
                    Pf("\nThe consumed value is %d\n", consume);
                    
                    out = (out + 1) % bufsize; 
                }
                break;
            } // End Case 2 block

            // === Case 3: Exit ===
            case 3:
                break; 

            // === Default ===
            default:
                Pf("\nInvalid choice!");
                break;
        }
    }
}