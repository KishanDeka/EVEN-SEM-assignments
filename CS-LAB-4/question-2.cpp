#include <iostream>
using namespace std;

class node          //create a node class
{
  public :
    double data;       //data part of a node
    node *next;       //pointer to next node
};
class stack_1      //create a stack class
{
  node *top;       //create a node name top
  public :
    stack_1()      //constructor
    {
        top = NULL;        //makes top NULL
    }
    int isEmpty()               //function to check whether the stack is empty
    {
        if (top == NULL)       //condition for empty stack
        {
            return 1;           //function returns 1
        }
        else {return 0;}        //for non empty stacks function returns 0
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
    double pop()     //function to delete the top element
    {
        node *pos;              //crates a pointer of node type
        pos = top;              //makes pos and top same
        double value;
        value = top->data;
        if (top != NULL)        //condition for nonempty stack
        {
           pos = pos->next;     //pos points to next node
           delete top;          //delete the top node
           top = pos;           //makes top same as pos
           return value;        //returns the deleted value
        }
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

class stack_2   //create a stack class
{
  public :
    node *top;   //create a node name top
    stack_2()  //constructor
    {
        top = NULL;   //makes top NULL
    }
    int isEmpty()         //function to check whether the stack is empty
    {
        if (top == NULL)      //condition for empty stack
        {
            return 1;           //function returns 1
        }
        else {return 0;}       //for non empty stacks function returns 0
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
    double pop()     //function to delete the top element
    {
        node *pos;              //crates a pointer of node type
        pos = top;              //makes pos and top same
        double value;
        value = top->data;
        if (top != NULL)       //condition for nonempty stack
        {
           pos = pos->next;     //pos points to next node
           delete top;          //delete the top node
           top = pos;           //makes top same as pos
           return value;        //returns the deleted value
        }
    }
    void show(node *pos)
    {
        if (top != NULL)   //condition for nonempty stack
        {
            pos = pos->next;      //pos moves to next node
            show(pos);            //recursion
            cout<<" "<<pos->data<<endl;     //print the data stored
        }
    }
};

double pop_q()
{
    stack_1 s1;       //object of stack_1 class
    stack_2 s2;       //object of stack_2 class
    int x=s1.isEmpty();      //calling isEmpty function
    int y=s2.isEmpty();      //calling isEmpty function
    if(y==0)
    {
        while (x != 0)
        {
            double value = s1.pop();
            s2.push(value);
            x=s1.isEmpty();
        }
    }
    return s2.pop();
}

int isEmpty()
{
    stack_1 s1;       //object of stack_1 class
    stack_2 s2;       //object of stack_2 class
    int x=s1.isEmpty();      //calling isEmpty function
    int y=s2.isEmpty();      //calling isEmpty function
    if (x==0 && y==0)        //when both stack is empty
    {
        return 1;           //return 1
    }
    else { return 0;}        //return 0
}

int main()
{
   stack_1 s1;    //object of stack_1 class
   stack_2 s2;    //object of stack_2 class
   int e = isEmpty();
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
         s1.push(value);   //calling the 'push' function
         break;         //breaks first case
       case 2 :          //second case
         if (e==1)       //condition for empty queue
         {
             cout << " Your queue is empty. Nothing to pop.";
         }
         else
         {
             cout << " The last element is "<<pop_q();     //calling pop_q function
         }
         cout << "\n popped successfully.";
         break;         //ends second function
       case 3 :        //third case
         node *pos;
         pos = s2.top;
         cout << "These are your data :"<<endl;
         s1.show();     //calling 'show' function
         s2.show(pos);     //calling 'show' function
         break;        //ends third function
       default :       //default case
         cout <<"Invalid choice. "<<endl;
         break;    //ends
       cin>>choice;    //again take input for choice
     }
   }
return 0;    //main function ends
}

