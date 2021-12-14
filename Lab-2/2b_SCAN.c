#include<stdio.h>
#include<stdlib.h>

void scan(int Ar[20], int n, int start);
void sort(int Ar[20], int n);

int main() {
    int diskQueue[20], n, start, i;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for(i=1;i<=n;i++) {                                     /* head element to be read */ 
        scanf("%d",&diskQueue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &start);                                
    diskQueue[0] = start;                                    /* injecting to the first position */
    ++n;
    sort(diskQueue, n);                                     /* total of n+1 elements */    
    scan(diskQueue, n, start);

    return 0;
}

void scan(int Ar[20], int n, int start) {
    int i, pos, diff, seekTime=0, current;
    // position of the disk to start seeking 
    for(i=0;i<n;i++) {                                      
        if(Ar[i]==start) {
            pos=i;
            break;
        }
    }
    // start seeking to the right
    printf("\nMovement of Cylinders\n");
    for(i=pos;i<n-1;i++) {
        diff = abs(Ar[i+1] - Ar[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", Ar[i], Ar[i+1], diff);
    }
    current=i;
                                             /* last element position */
    //moving to end location
    printf("Move from %d to 199 with seek time %d\n", Ar[i], (199-Ar[i]));
    seekTime+=199-Ar[i];
    Ar[i]= 199;
    // start seeking to the left
    for(i=pos-1;i>=0;i--) {
        diff = abs(Ar[current] - Ar[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d\n", Ar[current], Ar[i], diff);
        current=i;
    }
    printf("\nTotal Seek Time: %d", seekTime);
    // average of entered elements(n-1) excluding head
    printf("\n");
}

void sort(int Ar[20], int n) {
    int i, j, tmp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1-i;j++) {
            if(Ar[j]>Ar[j+1]) {
                tmp = Ar[j];
                Ar[j] = Ar[j+1];
                Ar[j+1] = tmp;
            }
        }
    }
}

/* OUTPUT
Enter the size of Queue: 7
Enter the Queue: 82 170 43 140 24 16 190
Enter the initial head position: 50

Movement of Cylinders
Move from 50 to 82 with seek time 32
Move from 82 to 140 with seek time 58
Move from 140 to 170 with seek time 30
Move from 170 to 190 with seek time 20
Move from 190 to 199 with seek time 9
Move from 199 to 43 with seek time 156
Move from 43 to 24 with seek time 19
Move from 24 to 16 with seek time 8

Total Seek Time: 332
    
*/
