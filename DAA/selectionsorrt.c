#include<stdio.h>
#include<stdlib.h>

int count;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++){
          count++;
          if (arr[j] < arr[min_idx])
            min_idx = j;
        }
  
        
        swap(&arr[min_idx], &arr[i]);
    }
}

 int main(){

    int a[5000], b[5000], c[5000], i, j, n;
printf(" \nCorrectness Proof");



    printf(" \nAnalysis of Running Time of MERGE SORT");
    printf("\nSize      BestCase   WorstCase   RandomCase");
    
for(i=16; i<2048; i*=2){
        printf("\n%5d",i);
        for(j=0; j<i; j++)
            a[j] = j;
        for(j=0; j<i; j++)
            b[j] = j-i;
        for(j=0; j<i; j++)
            c[j] = rand();
        count = 0;
      
  selectionSort(a,i-1);
        printf("%10d",count);
        count = 0;
       
 selectionSort(b,i-1);
        printf("%10d",count);
        count = 0;
       
 selectionSort(c,i-1);
        printf("%10d",count);
    
}
printf("\n");
    return 0;
}