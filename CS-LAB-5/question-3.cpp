#include <iostream>
#include <stdlib.h>     /*for 'rand'*/
#include <ctime>        /*for time*/

using namespace std;

void bsort_A(int size)    /*defining a new function called*/
{
    double arr[size];     /*create an array*/
    for (int i=0; i<size; i++)    /*'for loop' to take input of elements*/
    {
        arr[i]=rand()%11000;         /*input for data*/
    }
    clock_t begin_t = clock();
    for (int i=0; i<size; i++)   /*'for loop' for sorting*/
    {
        for (int j=0;j<size-1; j++)   /*loop to swap elements*/
        {
            if (arr[j]>arr[j+1])    //condition to swap
            {
                double temp=0;    //make new variable
                temp = arr[j];
                arr[j]= arr[j+1];  /*swap the elements*/
                arr[j+1] = temp;
            }
        }
    }
    clock_t end_t = clock();
    double eltime = double(end_t-begin_t)/CLOCKS_PER_SEC;
    cout<<"\n Time required for bubble sorting by array of size "<<size<<" is : "<<eltime<<" seconds ";
}

class node     /*creating a class for node*/
{
public :
    double data;   /*creates data part*/
    node *next;    /*creates pointer part*/
};

class bsort_ll    /*class for linked list using bubble*/
{
    node *head;      /*create a 'head' node*/
    node *tail;      /*create a 'tail' node*/
public :
    bsort_ll()     /*constructor*/
    {
        head = NULL;     /*makes head null*/
        tail = NULL;     /*makes tail null*/
    }

    void input(int num)     /*function to take input*/
    {
        for (int i=0; i<num; i++)     /*'for loop' to take input*/
        {
            double data;
            data = rand()%11000;           /*input of data*/
            node *temp = new node; /*create a new node type object called 'temp'*/
            temp->data = data;   /*data input is inserted in data part of temp*/
            if (head == NULL)   /*condition for empty list*/
            {
                head=temp;   /*make 'head' and 'temp' same*/
                tail=temp;   /*make 'tail' and 'temp' same*/
                temp->next = NULL;  //points 'next' of temp to null
            }
            else    /*condition for nonempty list*/
            {
                tail->next = temp;  /*points 'next' of tail to temp*/
                temp->next = NULL;  /*points 'next' pointer of temp to null*/
                tail=temp;   /*make 'temp' and 'tail' same*/
            }
        }
    }
    void sort_ll()    /*function for sorting*/
    {
        node *pos;    /*make a new pointer*/
        pos = head;   /*pos become same as head*/
        while (pos->next != NULL)    /*while loop for sorting*/
        {
            node *post;      /*make a new node pointer*/
            post = head;     /*make post same as head*/
            while (post->next != NULL)   /*while loop for sorting*/
            {
              if (post->data > (post->next)->data)   /*condition for swapping*/
              {  /*swap the two elements*/
                  double temp;
                  temp = post->data;
                  post->data = (post->next)->data;
                  (post->next)->data = temp;
              }
              post = post->next;   /*post goes to next node*/
            }
            pos = pos->next;       /*pos goes to next node*/
        }
    }
};

void bsort_LL(int size)
{
    bsort_ll bll;
    bll.input(size);
    clock_t begin_t = clock();
    bll.sort_ll();
    clock_t end_t = clock();
    double eltime = double(end_t-begin_t)/CLOCKS_PER_SEC;
    cout<<"\n Time required for bubble sorting by array of size "<<size<<" is : "<<eltime<<" seconds ";
}

void swap(int *a, int *b)   /*function to swap two elements*/
{
    int t = *a;      /*create a new variable*/
    *a = *b;         /*'a' becomes equal to 'b'*/
    *b = t;          /*'b' becomes equal to 't'*/
}
int partition (int arr[],int low, int high)
{
    int pivot = arr[high];    /*pivot*/
    int i = (low - 1);  /*creates a new variable*/
    /*implement for loop*/
    for (int j = low; j <= high- 1; j++)
    {
        /*If current element is smaller than or
          equal to pivot*/
        if (arr[j] <= pivot)
        {
            i++;      /*increase index of smaller element by one unit*/
            swap(&arr[i], &arr[j]);   /*swap arr[i] and arr[j]*/
        }
    }
    swap(&arr[i + 1], &arr[high]);   /*swap function*/
    return (i + 1);       /*return the index of pivot*/
}
void qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        /*pivot is partitioning index, arr[p] is now
          at right place*/
        int indx = partition(arr, low, high);

        /*Separately sort elements before*/
        /*partition and after partition*/
        qsort(arr, low, indx - 1);
        qsort(arr, indx + 1, high);
    }
}

void qsort_A(int size)
{
    int arr[size];       /*create an array*/
    for (int i=0; i<size; i++)    /*'for loop' to take input of elements*/
    {
        arr[i]=rand()%11000;      /*random input for data*/
    }
    clock_t begin_t = clock();
    qsort(arr, 0, size-1);        /*calling quicksort function*/
    clock_t end_t = clock();
    double eltime = double(end_t-begin_t)/CLOCKS_PER_SEC;
    cout<<"\n Time required for bubble sorting by array of size "<<size<<" is : "<<eltime<<" seconds ";
}

void swap_ll(node *one, node *two)    /*function to swap data of two nodes*/
{
    double t = one->data;          /*create a new variable*/
    one->data = two->data;         /*'a' becomes equal to 'b'*/
    two->data = t;                 /*'b' becomes equal to 't'*/
}

class quick_ll              /*creating class for linked list*/
{
    node *head;             /*creates head of ll*/
    node *tail;             /*creates tail of ll*/
public :                    /*makes usable outside the class*/
    quick_ll()              /*constructor for ll*/
    {
        head = NULL;        /*makes head NULL*/
        tail = NULL;        /*makes tail NULL*/
    }
    void insert_qll(int data)
    {
        node *temp = new node;  /*create a new node type object called 'temp'*/
        temp->data = data;      /*data input is inserted in data part of temp*/
        if (head == NULL)       /*condition for empty list*/
        {
            head=temp;          /*make 'head' and 'temp' same*/
            tail=temp;          /*make 'tail' and 'temp' same*/
            temp->next = NULL;  /*points 'next' of temp to null*/
        }
        else    /*condition for nonempty list*/
        {
           tail->next = temp;  /*points 'next' of tail to temp*/
           temp->next = NULL;  /*points 'next' pointer of temp to null*/
           tail=temp;          /*make 'temp' and 'tail' same*/
        }
    }

    int partition_qll(int low, int high)
    {
        node *temp;
        temp = head;
        for(int i=0; i<high; i++)
        {
            temp = temp->next;
        }
        double pivot = temp->data;    /* pivot */
        int i = low - 1;         /*creates a new variable */
        /* implement for loop */
        for (int j = low; j <= high-1; j++)      /*for loop*/
        {
            node *pos = head;         /*creating a new node type variable*/
            for (int k=0; k<j; k++)
            {
                pos = pos->next;
            }
            /* If current element is smaller than or
              equal to pivot */
            if (pos->data <= pivot)
            {
                i++;      /* increase index of smaller element by one unit */
                node *pos_i = head;
                for (int k=0; k<i; k++)
                {
                    pos_i = pos_i->next;
                }
                node *pos_j = head;
                for (int k=0; k<j; k++)
                {
                    pos_j = pos_j->next;
                }
                swap_ll(pos_i, pos_j);   /*swap  the data*/
            }
        }
    node *pos_i = head;            /*create a new node type variable*/
    for (int k=0; k<i+1; k++)
    {
        pos_i = pos_i->next;
    }
    node *pos_j = head;
    for (int k=0; k<high; k++)
    {
        pos_j = pos_j->next;
    }
    swap_ll(pos_i, pos_j);        /*swap the data*/
    return (i + 1);            /*return the index of pivot*/
}

    void sort_qll(int low, int high)
    {
        if (low < high)
        {
            /* pivot is partitioning index, arr[p] is now
               at right place */
            int indx = partition_qll(low, high);
            /* Separately sort elements before */
            /* partition and after partition */
            sort_qll(low, indx - 1);
            sort_qll(indx + 1, high);
        }
    }
};

void qsort_LL(int size)
{
    quick_ll qll;
    for (int i=0; i<size; i++)    /*'for loop' to take input of elements*/
    {
         int data;             /*creating new variable*/
         data = rand()%11000;     /*input for data*/
         qll.insert_qll(data);    /*calling insert function*/
    }
    clock_t begin_t = clock();
    qll.sort_qll(0,size-1);
    clock_t end_t = clock();
    double eltime = double(end_t-begin_t)/CLOCKS_PER_SEC;
    cout<<"\n Time required for bubble sorting by array of size "<<size<<" is : "<<eltime<<" seconds ";
}

int main()
{
    int array[] = {100, 1000, 2500, 5000, 8000, 10000};   /*array for the table of data*/
    for(int i=0; i<6; i++)      /*for loop*/
    {
       int n = array[i];        /*create a new variable*/
       cout<<" For "<<array[i]<<" data : ";
       bsort_A(n);        /*calling bubble sorting by array function*/
       bsort_LL(n);       /*calling bubble sorting by linked list function*/
       qsort_A(n);        /*calling quick sorting by array function*/
       qsort_LL(n);       /*calling quick sorting by linked list function*/
       cout<<"\n  \n  \n";
    }
return 0;
}

