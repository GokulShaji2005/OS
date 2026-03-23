#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, total_seek = 0, min_distance, distance;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    int visited[n]; 

    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        visited[i] = 0; 
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek sequence: %d ", head);

    for (i = 0; i < n; i++) {
        min_distance = 1000000; 
        int index = -1;

        
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                distance = abs(head - requests[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;          
        total_seek += min_distance;   
        head = requests[index];      
        printf("%d ", head);
    }

    printf("\nTotal seek time: %d\n", total_seek);
    return 0;
}
