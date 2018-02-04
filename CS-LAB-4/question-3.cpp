#include <iostream>
#include <string.h>
using namespace std;

int top, front;    //create variable top and front


class issue           //create a class for issue
{
 public:             //make it usable outside the class
 char name[30];      //character variable for name of person 
 long int phone;        //variable for phone no
 char descr[100];        //variable for description
 issue* link;           //pointer 
 issue(){link=NULL;};    //constructor
};

class StkPal         //class for new stack
{ 
 public:             //make it usable outside of class
 char NM[30];         //new character type variable
 void push(char a)         //push function
 {
 top++;
 NM[top] = a;
 }
 void pop()            //pop function
 {
 top--;
 }
}stack;

class CustomerService        //class for customer service
{
 public:                   //make it usable outside of class
 issue* head;
 issue* tail;
 CustomerService()
 {
 head=NULL;
 tail=NULL;
 }
 int chckPalindrome(char nm[30]);
 void addIssue(char nm[30], long int p, char descr[]);
 void dsplyIssue();
};

/*Checking Palindrome Using Array STACK*/
int CustomerService::chkPalindrome(char nm[30])
{
 top=-1;
 front=0;
 char b;
 for (int i = 0;nm[i] != '\0';i++)
 {
 b = nm[i];
 stack.push(b);
 }
 for (int i = 0;i < (signed)(strlen(nm) / 2);i++)
 {
 if (stack.NM[top] == stack.NM[front])
 {
 stack.pop();
 front++;
 }
 else
 {
 return 0;
 }
 }
 int x=front;
 front = 0;
 top = -1;
 if ((signed)(strlen(nm) / 2)==x)
 { return 1;}
 return -1;
}


void CustomerService::addIssue(char nm[],long int p, char des[])
{
 issue* temp=new issue;
 temp->ph=p;
 strcpy(temp->name,nm);
 strcpy(temp->descr,des);
 if(head==NULL)
 {
 head=temp;
 tail=temp;
 return;
 
 }
 if(chckPalindrome(nm)==1)
 {
 temp->link=head;
 head=temp;
 
 }
 else
 {
 tail->link=temp;
 tail=temp;
 
 }
};
 
 

void CustomerService::dsplyIssue()
{
 issue* iss;
 iss=head;
 if(iss==NULL)
 {
 cout<<"There is no registration done"<<endl;
 }
 else
 {
 cout<<"\nNAME \t \t PHONE \t \t\t Description \n";
 while(iss!=NULL)
 {
 cout<<"\n"<<iss->name<<" \t \t "<<iss->ph<<" \t \t "<<iss->descr;
 iss=iss->link;
 }
 }
 cout<<"\n \n \n";
}

int main()
{
 CustomerService CS;
 CS.dsplyIssue();
 CS.addIssue("Sgh",9876543289,"something is wrong");
 CS.dsplyIssue();
 CS.addIssue("ISSI",9905432893,"Code Testing");
 CS.dsplyIssue();
 CS.addIssue("ISS",9876847584,"PALINDROME STACK");
 CS.dsplyIssue();
 CS.addIssue("PRBLM",9876543289,"STACK PALINDROME");
 CS.dsplyIssue();
 CS.addIssue("PRORP",9876003289,"CODE SUCCESFUL");
 CS.dsplyIssue()();
 CS.addIssue("PROB",7319103289,"SUCCESSFUL CODE");
 CS.dsplyIssue()();
 CS.addIssue("TICKET",8093103289,"PDSL 2");
 CS.dsplyIssue()();
 CS.addIssue("TICIT",9099803289,"2 PDSL");
 CS.dsplyIssue()();
 CS.addIssue("TIIT",9009876546,"LAST ONE");
 CS.dsplyIssue()();
 CS.addIssue("ENDNE",7890678987,"ONE LAST");
 CS.dsplyIssue()();
 return 0; 
}

