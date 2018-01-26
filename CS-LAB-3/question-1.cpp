
#include <iostream>

using namespace std;

class node
{
  public:
    int data;
    node *next;
    node *prev;
};
class d_ll
{
    node *head;
    node *tail;

    public :
    d_ll()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_dll(int data);
    void insert_at(int pos, int data);
    void delete_dll();
    void delete_at(int pos);
    void display();
    int count_dll();
};

void menu()
{ cout<<"\n \n This is the list of thing you can do using this programme."<<endl;
  cout<<" (a) create a linked list."<<endl;
  cout<<" (b) add data at the end of the linked list."<<endl;
  cout<<" (c) insert a data at any position. "<<endl;
  cout<<" (d) delete the linked list. "<<endl;
  cout<<" (e) delete data of a specific position."<<endl;
  cout<<" (f) display the elements of linked list."<<endl;
  cout<<" (g) count the number of elements in the list."<<endl;
  cout<<" Press 'x' and hit 'enter' to exit."<<endl;
  cout<<" Choose the option what you want to do : \n -> ";
}

int main ()
{
  char ch;
  d_ll dll;

  while ( ch != 'x')
     {
        menu();
        cin >> ch;
        if (ch=='a')
        {
          cout<<"\n Linked list is created."<<endl;
        }
        else if (ch=='b')
        {  char chr;
           do
            {
                int data;
                cout<<"\n Enter your data : ";
                cin>>data;
                dll.insert_dll(data);
                cout<<"\n Data added. \n ";
                cout<<" \n If you want to add more data press 'y' and hit 'Enter' \n Press any key and hit 'Enter' to exit this function \n ";
                cin >> chr;
            }
            while (chr == 'y');
        }
        else if (ch == 'c')
        {
           int post, data;
           int num;
           num = dll.count_dll(); //calling the count_l() function to check the number element in the list
           cout<<"\n Enter the position where you want to insert a data : ";
           cin>>post;
           if (0 < post && post < num+1) //condition for nonempty linked list
           {
              cout<<"\n Enter the new data : ";
              cin >> data;
              dll.insert_at(post, data); //calling the insert_at() function
           }
           else { cout<<" Invalid position. \n ";} //condition when position entered is not valid for the linked list

        }
        else if (ch == 'd')
        {
            dll.delete_dll();
        }
        else if (ch=='e')
        {
             int post;
             int num;
             num = dll.count_dll();  //calling the count_l() function to check the number element in the list
             cout <<"\n Enter the position of data you want to delete : ";
             cin >> post;
             if (0 < post && post <= num)  //condition for nonempty linked list
             {
                dll.delete_at(post);  //calling the delete_at() function
             }
             else {cout<<"Invalid position.";}  //condition when position entered is not valid for the linked list
        }
        else if (ch=='f')
        {
           cout<<"\n These are your data :"<<endl;
           dll.display();
        }
        else if (ch == 'g')
        {  int num;
           num = dll.count_dll();
           cout<<"\n There is ";
           cout<<num;
           cout<<" elements in your linked list. \n ";
        }
        else
        {
             cout<<"\n You have entered an invalid key try again.";  //when one enter a invalid character
        }

     cout <<"\n  Thank you for using this programme.";
     cout <<"\n  If you want to continue press any key and hit 'enter'.";  //run the while loop again
     cout <<"\n  If you want to exit press 'x' and hit 'enter'. \n -> ";   //break the while loop
     cin >> ch;
     }
return 0;
}

void d_ll :: insert_dll(int data)
{
   node *temp=new node;
   temp->data=data;
   temp->next=NULL;
   temp->prev=NULL;
   if (head==NULL)
   {
       head=temp;
       tail=temp;
   }
   else
   {
       temp->prev=tail;
       tail->next=temp;
       temp->next=NULL;
       tail=tail->next;
       cout<<"added"<<endl;
   }
}

void d_ll :: insert_at(int post, int data)
{
   node *pos;
   node *temp=new node;
   temp->data = data;
   temp->next=NULL;
   temp->prev = NULL;
   pos = head;
   for (int i=2; i<post; i++)
   {
      pos = pos->next;
   }
   if (pos->next == NULL)
   {
      pos->next = temp;
      temp->prev = pos;
      temp->next = NULL;
   }
   else
   {
      temp->prev = pos;
      temp->next = pos->next;
      pos->next = temp;
   }
}

void d_ll :: delete_dll()
{
   if (head != NULL)
   {
     while (head->next != NULL)
     {
        node *pos;
        pos = head;
        while (pos->next != NULL)
        {
           pos = pos->next;
        }
        pos = pos->prev;
        delete pos->next;
        pos->next = NULL;
     }
     head = NULL;
     cout<<"\n Your linked list is deleted.\n ";
   }
   else { cout<<"\n There is no element to delete \n "; }
}

void d_ll :: delete_at(int post)
{
   node *pos;
   pos = head;
   for (int i=2; i<post; i++)
   {
      pos = pos->next;
   }
   node *del;
   del = pos->next;
   pos->next = del->next;
   node *nex;
   nex = del->next;
   nex->prev = pos;
   delete del;
}

void d_ll :: display()
{
    node *pos;
    pos=head;
    if (head==NULL)
    {
        cout<<"your list is empty.";
    }
    else
    {
       while (pos != NULL)
      {
         cout<<pos->data<<" -> ";
         pos=pos->next;
      }
        cout<<"NULL \n ";

    }
}

int d_ll :: count_dll()
{
    node *pos;  //create a new node type pointer called 'pos'
    pos = head;  //makes the address of 'pos' and 'head' same
    int i=2;
    if (head == NULL)   //when number of element in the list is zero
    {
        return 0;
    }

    else if (pos->next == NULL) //when number of element in the list is one
    {
        return 1;
    }

    else
    {
        while (pos->next != tail)
        {
            pos = pos->next;
            i++;
        }
        return i; //return the number of element present
    }
}
