#include <iostream>

// Selection sort
void selectionSort(int *arr, int n)
{
    int i, j, minIndex;

    for (i = 0; i < n - 1; ++i)
    {
        minIndex = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i) // We found a new min. element
        {
            std::swap(arr[minIndex], arr[i]);
        }
    }
}

// Bubble sort
void bubbleSort(int *arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; ++i)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 5, 2, -15, 20, 51, -20, 3, 1, 6};

    unsigned arrSize = sizeof(arr) / sizeof(arr[0]);

    // Sort
    // selectionSort(arr, arrSize);
    bubbleSort(arr, arrSize);

    printArray(arr, arrSize);

    return 0;
}