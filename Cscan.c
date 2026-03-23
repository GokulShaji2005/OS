#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, disk_size;
    
    printf("Enter number of requests: ");
    scanf("%d", &n);
    
    int requests[n];
    
    printf("Enter disk requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    printf("Enter disk size (max cylinder number): ");
    scanf("%d", &disk_size);
    

    int up[n], down[n]; 
    int up_count = 0, down_count = 0;
    
    for (i = 0; i < n; i++) {
        if (requests[i] >= head)
            up[up_count++] = requests[i];
        else
            down[down_count++] = requests[i];
    }
    
  
    for (i = 0; i < up_count-1; i++)
        for (int j = i+1; j < up_count; j++)
            if (up[i] > up[j]) {
                int temp = up[i]; up[i] = up[j]; up[j] = temp;
            }
    
    for (i = 0; i < down_count-1; i++)
        for (int j = i+1; j < down_count; j++)
            if (down[i] > down[j]) {
                int temp = down[i]; down[i] = down[j]; down[j] = temp;
            }
    
    int total_seek = 0;
    int current = head;
    
    printf("Seek sequence: %d ", current);
    
   
    for (i = 0; i < up_count; i++) {
        total_seek += abs(up[i] - current);
        current = up[i];
        printf("%d ", current);
    }
    
 
    if (current != disk_size - 1) {
        total_seek += abs((disk_size - 1) - current);
        current = disk_size - 1;
        printf("%d ", current);
    }
    
   
    total_seek += abs(current - 0);
    current = 0;
    printf("%d ", current);
    
   
    for (i = 0; i < down_count; i++) {
        total_seek += abs(down[i] - current);
        current = down[i];
        printf("%d ", current);
    }
    
    printf("\nTotal seek time: %d\n", total_seek);
    
    return 0;
}
