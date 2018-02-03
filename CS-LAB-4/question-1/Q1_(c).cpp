#include <iostream>
using namespace std;
int ar[10];     //define an array of size 10
int top = -1;    //create a variable called top and assign value -1
void push(int num);    //create push function
void pop();            //create pop function
void display();        //create display function
void push(int num)     //defining push function
{
  if(top == 10)       //condition for full stack
  {
   cout<<"\n   Stack is full or overflow! \n";
  }
  else
  {
     top++;         //top's value increase by one
     ar[top] = num;    //store the element in num 
  }
}
void pop()      //defining pop function
{
  if(top == -1)     //condition for empty stack
  {
      cout<<"\n Stack is Empty or underflow! \n";
  }
  else
  {
      top--;     //top's value decreases by one value
      cout<<"Deleted number is : ";
      cout<<ar[top];     //print top th element of arr
  }
}
void display()      //defining display function
{
   int top=9;          //creating top variable
   if(top == -1)      
   {
      cout<<"Array is Empty or underflow.\n";
   }

   else
   {
      cout<<"\n Array is : ";
      while(top!=-1)      //while loop
      {
          cout<<"    "<<ar[top];    //prints the top th element
          top--;
      }
   }
}

int main()     //main function
{
   char ch;       //creating character type variable
   do             //do while loop
   {
       cout<<"\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit : \n";    //prints menu
       cin>>ch;               //input for ch
       switch(ch)            //use switch
       {
           case '1' : cout<<"Enter a value : ";    //first case
                      int num;                     //create variable num 
                      cin>>num;                    //input for num
                      push(num);                   //calling push function
                      break;
           case '2' : pop();                       //second case && calling pop function
                      break;
           case '3' : display();                   //third case & calling display function
                      break;
       }
   }
   while(ch!='4');                                //breaking condition
   return 0;
}
