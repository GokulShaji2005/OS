#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j]) {
                int temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
            }
}

int main() {
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d",&n);

    int requests[n];
    printf("Enter disk requests:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&requests[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    int up[n], down[n], up_count=0, down_count=0;

  
    for(int i=0;i<n;i++) {
        if(requests[i] >= head) up[up_count++] = requests[i];
        else down[down_count++] = requests[i];
    }

    sort(up, up_count);     
    sort(down, down_count); 

    int total_seek = 0;
    int current = head;

    printf("Seek sequence: %d ", current);

    // Move up
    for(int i=0;i<up_count;i++) {
        total_seek += abs(up[i]-current);
        current = up[i];
        printf("%d ",current);
    }

    
    for(int i=down_count-1;i>=0;i--) {
        total_seek += abs(down[i]-current);
        current = down[i];
        printf("%d ",current);
    }

    printf("\nTotal seek time: %d\n", total_seek);

    return 0;
}
