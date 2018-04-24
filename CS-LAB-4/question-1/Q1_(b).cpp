#include <iostream>

using namespace std;

class node   //create a node class
{
  public :    //makes it usable outside of the class
    double data;   //create a data type variable
    node *next;    //create a node type pointer
};

class queueLL     //create class for queue
{
   node *head;    //create a head node
   node *tail;    //create a tail node
  public :        //makes it usable outside the class
    queueLL()     //constructor
    {
       head = NULL;     //make head NULL
       tail = NULL;     //make tail NULL
    }
    void push(double data);     //mention the functions
    void pop();
    void show();
};

int main()     //main function
{
   queueLL q;     //object of class queue
   int choice=0;    //int type variable and assign value 0
   while (choice != 4)     //while loop until choice=4
   {
     cout<<"\n1.PUSH  2.POP  3.SHOW  4.EXIT "<<endl;    //prints the menu
     cout<<"Enter what you want to do : ";      //ask for input
     cin>>choice;          //takes the input for choice
     switch (choice)        //switch function
     { case 1 :               //first case
         cout<<"Enter the data : ";      //ask for data
         double value;         //double type variable 'value'
         cin>>value;          //takes input for value
         q.push(value);       //calling push function to push the value
         break;               //breaks first case
       case 2 :               //second case
         q.pop();           //calling pop function
         break;            //breaks second function
       case 3 :                //third case
         cout <<"These are your data :"<<endl;
         q.show();            //calling show function
         break;              //breaks third function
       default :              //default case
         cout <<"Invalid choice. "<<endl;
         break;              //breaks
       cin>>choice;            //again takes input for choice
     }
   }
return 0;               //return an integer 0
}

void queueLL :: push(double  value)         //defining push function of queue class
{
    node *temp = new node;                //creates a new node
    temp->data = value;               //store the value in node
    temp->next = NULL;                //next points to NULL
    if(head != NULL)                 //condition for nonempty list
    {
        tail->next = temp;            //tail's next pointer points to temp
    }
    else
    {
       head = temp;               //temp becomes head
    }
    tail = temp;                  //temp becomes tail
    cout <<"Succesfully pushed."<<endl;             //print it
}

void queueLL :: pop()            //defining pop function of queue class
{
   node *pos;                //creates node type pointer
   pos = head;              //pos is same as head
   if (head==NULL)           //condition for empty list
   {
     cout<<"Your queue is empty."<<endl;
   }
   else
   {  
      cout<<"The data at the top is "<<pos->data<<endl;      //prints the top element
      pos = head->next;          //pos points to head's next
      delete head;              //delete head
      head = pos;                //pos becomes head
      cout<<"The first data is deleted. \n ";           //prints
   }
}

void queueLL :: show()              //defining show function of queue class
{
   node *pos;                //creates node type pointer
   pos = head;               //pos is same as head
   if (head == NULL)           //condition for empty list
   {
      cout <<"Your queue is empty. \n ";
   }
   else
   {
      while (pos != NULL)        //while loop until pos becomes null
      {
         cout<<pos->data<<endl;      //prints data
         pos = pos->next;             //pos shifts to next node
      }
   }
}
