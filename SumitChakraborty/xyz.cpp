#include<stdio.h>
#include <stdlib.h> 
#include<time.h> 
void bubbleSort(int arr[],int n);
//void swap(int *xp, int *yp); 
int main()
{
	int i,j;
	char plot[51][51];
	for(i=0;i<51;i++)
	{
		for(j=0;j<51;j++)
		{
			plot[i][j]=' ';
		}
	}
	clock_t t;
	double a[10];
	for(i=0;i<10;i++)
	{
		int arr[i*1000];
		for(j=0;j<i*1000;j++)
		{
			arr[j]=rand();
		}
		t = clock(); 
		bubbleSort(arr, i*1000);
		t = clock() - t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC;
		a[i]=time_taken;
		printf("%f\n",a[i]);
		
		int x=(i*1000)/200;
		int y=((int)(time_taken*1000))/20;
		//printf("%d %d ",y,x);
		plot[x][y]='.';
		
		
	}
	printf("\n");
	for(i=50;i>=0;i--)
	{
		for(j=0;j<51;j++)
		{
			printf("%c",plot[j][i]);
		}
		printf("\n");
	}
	
}

/*void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} */
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j,t; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
            {
            	t=arr[j];
            	arr[j]=arr[j+1];
            	arr[j+1]=t;
			} 
} 
