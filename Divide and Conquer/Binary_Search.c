#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int iterativeBinarySearch(int arr[],int s,int key)
{
    int low=0;
    int high=s-1;
    while(low<=high)
     {
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key)low=mid+1;
        else high=mid-1;
     }
     return -1;
}

int recursiveBinarySearch(int arr[],int low,int high, int key)
{
    if (low>high) return -1; //base case

    int mid=(low+high)/2;
    if (arr[mid]==key) 
    return mid;
    else if (arr[mid]>key)
     return recursiveBinarySearch(arr,low,mid-1,key);
     else 
      return recursiveBinarySearch(arr,mid+1,high,key);
}


int main()
{
   
    int arr[MAX];
    int target;
    int n;  //n is the size of the array
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter array elements in sorted order: ");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search:");
    scanf("%d",&target);
     while (1)
    {
     printf("---LIST OF OPTIONS---\n");
    printf("1. Ierative Binary Search\n");
    printf("2. Recursive Binary Search\n");
    printf("3. Exit\n");
    
     int choice;
     printf("Select choice: ");
     scanf("%d", &choice);
     switch(choice)
     {
        case 1:
        {
           int bin=iterativeBinarySearch(arr,n,target);
           if (bin==-1)
            printf("Element not found in the array\n");
           else
           { printf("Element found at index %d\n",bin);
            break;
           }
        }
        case 2:
        {
           int bin=recursiveBinarySearch(arr,0,n-1,target);
           if (bin==-1)
            {printf("Element not found in the array\n");}
           else
            {printf("Element found at index %d\n",bin);
            break;
            }
        }
        case 3:
        {
            exit(0);
        }
         default:
         {
            printf("Invalid choice\n");
         }
    }
}
    return 0;

}