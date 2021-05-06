#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 1000

int count = 0;

int partition(int a[max], int low, int high){
 
    int i,j,pivot,temp;
    pivot = a[low];
    i = low+1;
    j = high;
    while(1){
       
        while(i<high && a[i] <= pivot){
            i++;
            count++;
        }
        while( j> low && a[j] > pivot ){
            j--;
            count++;
        }
        count++;
        if(i<j){
           
            temp = a[i];
            a[i] = a[j];
            a[j]= temp;
        }
        else{

            temp = a[low];
            a[low]= a[j];
            a[j]= temp;
            return j;
        }
    }
}

void quicksort(int a[], int low, int high)
{
    int position;
    if(low<high)
    {
        position = partition(a,low,high);
        quicksort(a,low,position-1);
        quicksort(a,position+1, high);
    }
}
int main(){
    int size,i,j;
    int a[max],b[max],c[max];
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for(i=0; i<size; i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,size-1);
    printf("Sorted array is\n");
    for(i=0; i<size; i++){
        printf("%d ",a[i]);
    }
    printf("Count is %d\n", count);
    
    printf(" \nAnalysis of Running Time of QUICK SORT");
    printf("\nSize      Ascending   Descending  Random Case ");
    for(i=4; i<=2048; i*=2){
        printf("\n%5d",i);
        for(j=0; j<i; j++)
            a[j] = j;
        for(j=0; j<i; j++)
            b[j] = i-j;
        for(j=0; j<i; j++)
            c[j] = rand();
        count = 0;
        quicksort(a,0,i-1);
        printf("%10d",count);
        count = 0;
        quicksort(b,0,i-1);
        printf("%10d",count);
        count = 0;
        quicksort(c,0,i-1);
        printf("%10d",count);
    }

    return 0;
}