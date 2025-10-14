#include <stdio.h>
#include <stdlib.h>
#include <math.h> // for abs()

int tfph;
int philname[20], status[20], howhung, hu[20];
int cho;

void one();
void two();

#define Pf printf
#define Sf scanf

int main() {
    int i;
    
    Pf("\n\nDINING PHILOSOPHER PROBLEM\n");
    
    Pf("Enter the total no. of Philosophers: ");
    Sf("%d", &tfph);

    for (i = 0; i < tfph; i++) {
        philname[i] = i + 1; // P1, P2, P3...
        status[i] = 1;       // 1: All initially waiting/hungry
    }
    
    Pf("\nHow many are hungry: ");
    Sf("%d", &howhung);
    
    if (howhung == tfph) {
        Pf("In All are hungry, Dead lock stage will occur!\n");
    }
    
    for (i = 0; i < howhung; i++) {
        Pf("Enter philosopher %d position: ", i + 1);
        Sf("%d", &hu[i]);
        hu[i] = hu[i] - 1; // Convert 1-based input to 0-based array index
        status[hu[i]] = 1; // Explicitly set status to 1 (Waiting/Hungry)
    }

    do {
        Pf("\n------------------------------------\n");
        Pf("1. One can eat at a time\n");
        Pf("2. Two can eat at a time\n");
        Pf("3. Exit\n");
        Pf("Enter your choice: ");
        Sf("%d", &cho);

        switch (cho) {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                exit(0);
            default:
                Pf("Invalid option!\n");
        }
    } while (cho != 3);

    return 0;
}

void one() {
    int pos, i, x; 
    
    Pf("\nAllow one Philosopher to eat at any hungry time\n");
    
    if (howhung > 0) {
        // Only the first one in the list (i=0) is granted permission.
        i = 0;
        pos = hu[i]; // pos stores the array index of the eating philosopher
        
        // Grant Eat Permission
        Pf("P%d is granted to eat\n", philname[pos]);
        status[pos] = 2; // Set status to Eating
        
        // Loop for Waiting
        for (x = 0; x < howhung; x++) {
            if (hu[x] != pos) {
                 Pf("P%d is waiting\n", philname[hu[x]]);
            }
        }
    } else {
        Pf("No philosophers are hungry right now.\n");
    }
}

void two() {
    int i, j, t, r, x, s = 0; 
    Pf("\nAllow two philosophers to eat at same time\n");
    
    if (howhung < 2) {
        Pf("Need at least two hungry philosophers.\n");
        return;
    }

    // Outer loop for the first hungry philosopher
    for (i = 0; i < howhung; i++) {
        // Inner loop for the second hungry philosopher (j > i)
        for (j = i + 1; j < howhung; j++) {
            
            int ph1_index = hu[i];
            int ph2_index = hu[j];
            
            if ((abs(ph1_index - ph2_index) >= 2) && (abs(ph1_index - ph2_index) != tfph - 1)) {
                
                // Grant Eat Permission for the pair
                Pf("\nIn combination %d and %d:\n", i + 1, j + 1);
                
                t = ph1_index;
                r = ph2_index;
                s++; 

                Pf("P%d and P%d are granted to eat\n", philname[t], philname[r]);
                
                // Check for waiting philosophers
                for (x = 0; x < howhung; x++) {
                    int current_ph_index = hu[x];
                    if (current_ph_index != t && current_ph_index != r) {
                        Pf("P%d is waiting\n", philname[current_ph_index]);
                    }
                }
            }
        }
    }
    Pf("\nEnd of two-at-a-time checks.\n");
}