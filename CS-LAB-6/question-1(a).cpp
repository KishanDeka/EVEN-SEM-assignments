#include <iostream>

using namespace std;

int bsearch(int arr[], int num, int left, int right)
{
    int mid = (left+right)/2;          /*create a variable for middle position*/
    if (arr[left]<=num && arr[right]>=num)
    {
        while(arr[mid] != num)         /*if the number is not at middle*/
        {

           if (arr[mid] < num)         /*condition when number is in right of mid*/
           {
               left = mid+1;           /*mid+1 becomes new left*/ 
           }
           else                        /*condition when number is in left of mid*/
           {
               right = mid-1;          /*mid-1 becomes new right*/
           }
           mid = (left+right)/2;       /*'mid' value for while loop*/
        }
        return mid;                    /*return mid value when num found*/
    }
    else { return -1; }                /*not found*/
}

int main()
{
        int arr[]={ 12,36,3,91,42,17,13,40,27,19,24,10,111,362,-93,-4162,1928,152,90,243 } ;
        int size = sizeof(arr)/sizeof(arr[0]);
        /* buuble sorting */
        for (int i=0; i<size; i++)        /*'for loop' for sorting*/
        {
            for (int j=0;j<size-1; j++)   /*loop to swap elements*/
            {
                 if (arr[j]>arr[j+1])     /*condition to swap*/
                 {
                     double temp=0;       /*make new variable*/
                     temp = arr[j];
                     arr[j]= arr[j+1];    /*swap the elements*/
                     arr[j+1] = temp;
                 }
            }
        }
        cout<<" Enter which number you want to find : ";
        int key;     /* create a new variable */
        cin >> key;
        cout <<" Found at : "<<bsearch(arr, key, 0, size-1);
}
