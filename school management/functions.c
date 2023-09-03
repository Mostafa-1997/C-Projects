#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* arr,int size)
{
    int i,k,j=size-1,temp,max=0x80000000;
    for (i=0; i<size; i++)
    {
        max=0;
        for(k=0; k<=j; k++)
        {
            if (arr[k]>arr[max])
            {
                max=k;
            }
        }
        temp=arr[max];
        arr[max]=arr[j];
        arr[j]=temp;
        j--;
    }
}

void array_print(int*arr,int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int Choices (int min, int max)
{
    int num;
    scanf("%d",&num);
    fflush(stdin);
    if (num>max || num<min)
    {
        printf("Invalid Choice\n");
    }
    while (num>max || num<min)
    {
        scanf("%d",&num);
        fflush(stdin);
        if (num>max || num<min)
        {
            printf("Invalid Choice\n");
        }
    }
    return num;
}
