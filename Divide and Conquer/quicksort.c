#include <stdio.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    printf ("Enter the size of the array: ");
    int n;  //n is the size of the array
    scanf("%d", &n);    

    int arr[n];
    printf("Enter array elements: ");   
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);

    printf("Sorted Array: ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi-1);

        quicksort(arr, pi+1, high);
    }
}
