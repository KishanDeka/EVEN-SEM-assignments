#include <iostream>

using namespace std;

class arraybubble
{
    int size;
public :
    void insort()
    {
        cout << " Enter the size of array : ";
        cin >> size;
        double arr[size];
        cout <<" Enter the elements of the array : "<<endl;
        for (int i=0; i<size; i++)
        {
           cout<<" data "<<i+1<<" : ";
           cin>>arr[i];
        }
        cout<<" This is the array you have entered : "<<endl;
        cout<<" { ";
        for (int i=0; i<size; i++)
        {
           cout<<arr[i]<<"   ";
        }
        cout<<"}"<<endl;
        for (int i=0; i<size; i++)
        {
            for (int j=0;j<size-1; j++)
            {
                 if (arr[j]>arr[j+1])
                 {
                     double temp=0;
                     temp = arr[j];
                     arr[j]= arr[j+1];
                     arr[j+1] = temp;
                 }
            }
        }
        cout<<" This is your array after sorting : "<<endl;
        cout<<" { ";
        for (int k=0; k<size; k++)
        {
           cout<<arr[k]<<"   ";
        }
        cout<<"}";
    }
};

class node
{
public :
    double data;
    node *next;
};

class ll_bubble
{
node *head;
node *tail;
public :
    ll_bubble()
    {
        head = NULL;
        tail = NULL;
    }

    void input()
    {
        int num;
        cout<<"\n Enter the number of element you want to insert : ";
        cin>>num;
        cout<<" Enter your data : "<<endl;
        for (int i=0; i<num; i++)
        {
            double data;
            cout<<" data "<<i+1<<" : ";
            cin>>data;
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
    void sort_ll()
    {
        node *pos;
        pos = head;
        while (pos->next != NULL)
        {
            node *post;
            post = head;
            while (post->next != NULL)
            {
              if (post->data > (post->next)->data)
              {
                  double temp;
                  temp = post->data;
                  post->data = (post->next)->data;
                  (post->next)->data = temp;
              }
              post = post->next;
            }
            pos = pos->next;
        }
    }
};

int main()
{
    arraybubble ab;
    ll_bubble llb;
    int choice;
    while (choice != 0)
    {
        cout<<"\n Choose what you want to use for bubble sorting :\n 1. Array     2. Linked list.";
        cout<<"\n Enter '0' to exit."<<endl<<" Choice : ";
        cin>>choice;
        switch (choice)
        {
          case 1 :
            ab.insort();
            break;
          case 2 :
            llb.input();
            cout<<" These are your data : \n ";
            llb.display_ll();
            llb.sort_ll();
            cout<<" These are your data after sorting : \n ";
            llb.display_ll();
            break;
          case 0 :
            break;
          default :
            cout<<" Enter a valid choice. \n ";
            break;
        }
        cout<<"\n Enter any key and hit 'enter' to do again. \n Enter '0' and hit 'enter to exit."<<endl;
        cin>>choice;
    }
return 0;
}
