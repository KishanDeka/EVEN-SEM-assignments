#include<iostream>
using namespace std;

class node              /*defining class node*/
{
public :                /*make usable outside the class*/
    double data;        /* creates a double type variable*/
    node *next;         /*node type pointer*/
};

class binarys_ll              /*creating class for linked list*/
{
public :                    /*makes usable outside the class*/
    node *head;             /*creates head of ll*/
    node *tail;             /*creates tail of ll*/
    binarys_ll()              /*constructor for ll*/
    {
        head = NULL;        /*makes head NULL*/
        tail = NULL;        /*makes tail NULL*/
    }
    void insert_ll(int data)
    {
        node *temp = new node; /*create a new node type object called 'temp'*/
        temp->data = data;     /*data input is inserted in data part of temp*/
        if (head == NULL)      /*condition for empty list*/
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
    void display_ll()
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
        cout<<"NULL \n";
        }
    }

    int bsearch_ll(double num, int left, int right)   /*function for binary search*/
    {
        int mid=(left+right)/2;       /*defining a new variable*/
        if (head->data<=num && tail->data>=num)   /*condition for the number in the list*/
        {
            node *pos=head;            /*create a node type variable*/
            for(int i=0; i<mid; i++)   /*for loop to get to mid index*/
            {
                pos=pos->next;
            }
            while(pos->data != num)       /*if the number is not at middle*/
            {

               if (pos->data < num)       /*condition when number is in right of mid*/
               {
                   left = mid+1;          /*mid+1 becomes new left*/
               }
               else                       /*condition when number is in left of mid*/
               {
                   right = mid-1;         /*mid-1 becomes new right*/
               }
               mid = (left+right)/2;      /*'mid' value for while loop*/
               pos=head;                  /*create a node type variable*/
               for(int i=0; i<mid; i++)   /*for loop to get to mid index*/
               {
                   pos=pos->next;
               }
            }
            return mid;                    /*return mid value when number is found*/
        }
        else { return -1; }                /*not found*/
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

int main()
{
    binarys_ll bsll;
    int size;
    cout << " Enter the number of data you want to enter : ";
    cin >> size;                 /*input for size*/
    cout<<" Enter your data : \n";
    for (int i=0; i<size; i++)   /*'for loop' to take input of elements*/
    {
         double data;      /*creating new variable*/
         cout<<" data "<<i+1<<" : ";
         cin>>data;        /*input for data*/
         bsll.insert_ll(data);   /*calling insert function*/
    }
    cout<<" Your data : \n ";
    bsll.display_ll();       /*displaying the data entered*/
    bsll.sort_ll();          /*calling sorting function*/
    cout<<" Sorted data : \n ";
    bsll.display_ll();       /*displaying sorted data*/
    cout<<" Enter the number you want to search : ";
    double key;              /*creates a new variable for key*/
    cin>>key;                /*input for key*/
    int indx;                /*new variable*/
    indx = bsll.bsearch_ll(key,0,size-1);    /*calling binary search function*/
    if (indx != -1)
    {  /*displaying the index of entered number*/
        cout<<" Index of the number in sorted list is : "<<indx;
    }
    else {cout<<" Not found in the list.";}    /*when number is not in list*/
return 0;
}
