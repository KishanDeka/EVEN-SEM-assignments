#include <iostream>
using namespace std;

class node //create a node class
{
  public :
    double data;  //data part of a node
    node *next;   //pointer to next node
};
class stack_ll   //create a stack class
{
    node *top;   //create a node name top
  public :
    stack_ll()  //constructor
    {
        top = NULL;   //makes top NULL
    }
    void push(double data)     //function to push a data
    {
        node *temp=new node;   //create node named 'temp'
        temp->data = data;     //store data in temp
        temp->next = NULL;     //makes temp point to NULL
        if (top!=NULL)         //conition when stack is non empty
        {
        temp->next = top;  //next pointer of temp points to top
        }
        top = temp;   //makes temp the top
        cout<<"The data is successfully pushed. \n ";
    }
    void pop()     //function to delete the top element
    {
        node *pos;   //crates a pointer of node type
        pos = top;   //makes pos and top same
        if (top != NULL)    //condition for nonempty stack
        {
            pos = pos->next;   //pos points to next node
            cout<<" The top element is "<<top->data<<endl;
            delete top;     //delete the top node
            top = pos;      //makes top same as pos
            cout<<"This data is deleted. \n";
        }
        else {cout<<"The stack is empty. \n ";}
    }
    void show()
    {
        node *pos;    //create a position pointer of node type
        pos = top;    //makes top same as top
        if (top != NULL)   //condition for nonempty stack
        {   cout<<"These are your data : "<<endl;
            while (pos != NULL)   /*while loop till pos reach last element*/
            {
                cout<<" "<<pos->data<<endl;  //prints data
                pos = pos->next;   //pos goes to next node
            }
        }
        else {cout<<" The stack is empty. \n";}
    }
};

int main()
{
   stack_ll s;    //object of stack_ll class
   int choice=0;  //variable choice is defined
   while (choice != 4)   //use while loop
   {
     cout<<"\n1.PUSH  2.POP  3.SHOW  4.EXIT "<<endl;  /*prints menu*/
     cout<<"Enter what you want to do : ";
     cin>>choice;    //input for choice
     switch (choice)   //switch function
     { case 1 :        //first case
         cout<<"Enter the data : ";   //ask for data
         double value;   //defining variable 'value'
         cin>>value;    //takes input for value
         s.push(value);   //calling the 'push' function
         break;         //breaks first case
       case 2 :         //second case
         s.pop();       //calling 'pop' function
         break;         //ends second function
       case 3 :        //third case 
         cout <<"These are your data :"<<endl;
         s.show();     //calling 'show' function
         break;        //ends third function
       default :       //default case
         cout <<"Invalid choice. "<<endl;
         break;    //ends
       cin>>choice;    //again take input for choice
     }
   }
return 0;    //main function ends
}

