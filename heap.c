#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i ;
    int right = 2 * i + 1;

    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 ; i >= 1; i--)
    {
        heapify(arr, N, i);
    }

    for (int i = N ; i >=1; i--)
    {
        swap(&arr[1], &arr[i]);
        heapify(arr, i, 1);
    }
}

int main(void)
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of array: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("\nSorted array is: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}