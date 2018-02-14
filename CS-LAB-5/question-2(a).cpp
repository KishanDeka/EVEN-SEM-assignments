#include<iostream>
using namespace std;

void swap(int *a, int *b)   /* function to swap two elements */
{
    int t = *a;        /* create a new variable */
    *a = *b;        /* 'a' becomes equal to 'b' */
    *b = t;        /* 'b' becomes equal to 't' */
}

int partition (int arr[],int low, int high)
{
    int pivot = arr[high];    /* pivot */
    int i = (low - 1);  /*creates a new variable */
    /* implement for loop */
    for (int j = low; j <= high- 1; j++)
    {
        /* If current element is smaller than or
           equal to pivot */
        if (arr[j] <= pivot)
        {
            i++;      /* increase index of smaller element by one unit */
            swap(&arr[i], &arr[j]);   /*swap arr[i] and arr[j]*/
        }
    }
    swap(&arr[i + 1], &arr[high]);   /* swap function */
    return (i + 1);       /*return the index of pivot*/
}

void qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pivot is partitioning index, arr[p] is now
           at right place */
        int indx = partition(arr, low, high);

        /* Separately sort elements before */
        /* partition and after partition */
        qsort(arr, low, indx - 1);
        qsort(arr, indx + 1, high);
    }
}

/* Function to print an array */
void show(int arr[], int size)
{
    int i;      /* create a integer type variable */
    for (i=0; i < size; i++)   /* for loop */
    { cout << arr[i]<<"    "; }
}

/* Driver program to test above functions */
int main()
{
    int size;
    cout << " Enter the size of array : ";
    cin >> size;         /*input for size*/
    int arr[size];       /*create an array*/
    cout <<" Enter the elements of the array : "<<endl;
    for (int i=0; i<size; i++)    /*'for loop' to take input of elements*/
    {
        cout<<" data "<<i+1<<" : ";
        cin>>arr[i];       /*input for data*/
    }
    show(arr, size);
    qsort(arr, 0, size-1);    /* calling quicksort function */
    cout<<"\n Sorted Array : \n";
    show(arr,size);
return 0;
}
