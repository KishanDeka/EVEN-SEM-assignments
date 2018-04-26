#include<iostream>
using namespace std;

class node              /*defining class node*/
{
public :                /*make usable outside the class*/
    double data;        /* creates a double type variable*/
    node *next;         /*node type pointer*/
};

void swap(node *one, node *two)   /* function to swap two elements */
{
    double t = one->data;        /* create a new variable */
    one->data = two->data;           /* 'a' becomes equal to 'b' */
    two->data = t;            /* 'b' becomes equal to 't' */
}

class quick_ll               /*creating class for linked list*/
{
public :                    /*makes usable outside the class*/
    node *head;             /*creates head of ll*/
    node *tail;             /*creates tail of ll*/
    quick_ll()              /*constructor for ll*/
    {
        head = NULL;        /*makes head NULL*/
        tail = NULL;        /*makes tail NULL*/
    }
    void insert_list(int data)
    {
        node *temp = new node; /*create a new node type object called 'temp'*/
        temp->data = data;   /*data input is inserted in data part of temp*/
        if (head == NULL)   /*condition for empty list*/
        {
            head=temp;   /*make 'head' and 'temp' same*/
            tail=temp;   /*make 'tail' and 'temp' same*/
            temp->next = NULL;  /*points 'next' of temp to null*/
        }
        else    /*condition for nonempty list*/
        {
           tail->next = temp;  /*points 'next' of tail to temp*/
           temp->next = NULL;  /*points 'next' pointer of temp to null*/
           tail=temp;   /*make 'temp' and 'tail' same*/
        }
    }
    void display_l()
    {
        node *pos;  /*create a new node type pointer called 'pos'*/
        pos=head;  /*makes the address of 'pos' and 'head' same*/
        if (head==NULL)
        {
            cout<<"your list is empty.";
        }
        else
        {
            while (pos != NULL)
            {
                cout<<pos->data<<" -> ";  /*display the elements*/
                pos=pos->next; /*goes to next element*/
            }
        cout<<"NULL \n ";
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
                swap(pos_i, pos_j);   /*swap  the data*/
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
    swap(pos_i, pos_j);        /*swap the data*/
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

int main()
{
    quick_ll qll;
    int size;
    cout << " Enter the number of data you want to enter : ";
    cin >> size;                 /*input for size*/
    cout<<" Enter your data : \n";
    for (int i=0; i<size; i++)   /*'for loop' to take input of elements*/
    {
         double data;      /*creating new variable*/
         cout<<" data "<<i+1<<" : ";
         cin>>data;        /*input for data*/
         qll.insert_list(data);   /*calling insert function*/
    }
    cout<<" Your data : \n ";
    qll.display_l();
    qll.sort_qll(0,size-1);
    cout<<" Sorted data : \n ";
    qll.display_l();
return 0;
}
