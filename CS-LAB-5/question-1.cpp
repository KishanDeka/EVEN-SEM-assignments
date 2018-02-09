#include <iostream>

using namespace std;

class arraybubble     /*create a class for bubble sorting using array*/
{
    int size;       /*creates a integer variable for size of array*/
public :             /*make the functions usable outside of the class also*/
    void insort()     /*defining a new function called*/
    {
        cout << " Enter the size of array : ";   
        cin >> size;     //input for size
        double arr[size];     //create an array
        cout <<" Enter the elements of the array : "<<endl;
        for (int i=0; i<size; i++)    /*'for loop' to take input of elements*/
        {
           cout<<" data "<<i+1<<" : ";    
           cin>>arr[i];         /*input for data*/
        }
        cout<<" This is the array you have entered : "<<endl;
        cout<<" { ";
        for (int i=0; i<size; i++)    /*'for loop' to display the elements of array*/
        {
           cout<<arr[i]<<"   ";     //print i th element 
        }
        cout<<"}"<<endl;
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
        cout<<" This is your array after sorting : "<<endl;
        cout<<" { ";
        for (int k=0; k<size; k++)   /* loop to print the array after sorting*/
        {
           cout<<arr[k]<<"   ";
        }
        cout<<"}";
    }
};

class node     //creating a class for node
{
public :
    double data;   //creates data part
    node *next;    //creates pointer part
};

class ll_bubble    /*class for linked list using bubble*/
{
node *head;      /*create a 'head' node*/
node *tail;      /*create a 'tail' node*/
public :
    ll_bubble()     /*constructor*/
    {
        head = NULL;     //makes head null
        tail = NULL;     //makes tail null
    }

    void input()     /*function to take input*/
    {
        int num;    //makes a new int variable
        cout<<"\n Enter the number of element you want to insert : ";
        cin>>num;     /*input for num*/
        cout<<" Enter your data : "<<endl;
        for (int i=0; i<num; i++)     /*'for loop' to take input*/
        {
            double data;           
            cout<<" data "<<i+1<<" : ";
            cin>>data;           /*input of data*/
            node *temp = new node; //create a new node type object called 'temp'
            temp->data = data;   //data input is inserted in data part of temp
            if (head == NULL)   //condition for empty list
            {
                head=temp;   //make 'head' and 'temp' same
                tail=temp;   //make 'tail' and 'temp' same
                temp->next = NULL;  //points 'next' of temp to null
            }
            else    //condition for nonempty list
            {
                tail->next = temp;  //points 'next' of tail to temp
                temp->next = NULL;  //points 'next' pointer of temp to null
                tail=temp;   //make 'temp' and 'tail' same
            }
        }
    }
    void display_ll()
    {
        node *pos;  //create a new node type pointer called 'pos'
        pos=head;  //makes the address of 'pos' and 'head' same
        while (pos != NULL)
        {
            cout<<pos->data<<" -> ";  //display the elements
            pos=pos->next; //goes to next element
        }
        cout<<"NULL \n";
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

int main()      /*main function*/
{
    arraybubble ab;    /*make an object of arraybubble class*/
    ll_bubble llb;    /*make an object of ll_bubble class*/
    int choice;    //make a new variable
    while (choice != 0)    //while loop for choice
    {   /*prints the menu*/
        cout<<"\n Choose what you want to use for bubble sorting :\n 1. Array     2. Linked list.";
        cout<<"\n Enter '0' to exit."<<endl<<" Choice : ";
        cin>>choice;    //input for choice
        switch (choice)   //switch for choice
        {
          case 1 :
            ab.insort();   //call for insort function
            break;
          case 2 :
            llb.input();    //call for input function
            cout<<" These are your data : \n ";
            llb.display_ll();   //call for display_ll function
            llb.sort_ll();     //call for sort_ll function
            cout<<" These are your data after sorting : \n ";
            llb.display_ll();   //call for display_ll function
            break;
          case 0 :
            break;
          default :
            cout<<" Enter a valid choice. \n ";
            break;
        }
        cout<<"\n Enter any key and hit 'enter' to do again. \n Enter '0' and hit 'enter to exit."<<endl;
        cin>>choice;    /*input for choice again*/
    }
return 0;
}
