#include<stdio.h>
#include<stdlib.h>

int count;

void merge(int a[], int l, int m, int h)
{
  
   int i=l, j=m+1, k=l, c[10000];
   
   while(i<=m && j<=h)
   {
     count++;
     if(a[i]<a[j])
        c[k++]=a[i++];
     else
        c[k++]=a[j++];
   }
   
   while(i<=m)
     c[k++]=a[i++];
   
   while(j<=h)
     c[k++]=a[j++];
   
   for(i=l;i<=h;i++)
     a[i]=c[i];
}

void mergesort(int a[], int l, int h)
{
  int m;
  
  if(l<h)
  {
    m=(l+h)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,h);
    merge(a,l,m,h);
  }
}

 int main(){

    int a[5000], b[5000], c[5000], i, j, n;
printf(" \nCorrectness Proof");

    printf("\nEnter the size: ");
scanf("%d",&n);

    printf("\nEnter the array elements : ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

mergesort(a,0,n-1);

    printf("\nArray after merge sort: ");
    for(i=0; i<n; i++)
        printf("%d\t",a[i]);

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
      
  mergesort(a,0,i-1);
        printf("%10d",count);
        count = 0;
       
 mergesort(b,0,i-1);
        printf("%10d",count);
        count = 0;
       
 mergesort(c,0,i-1);
        printf("%10d",count);
    
}
printf("\n");
    return 0;
}