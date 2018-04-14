#include <iostream>

using namespace std;

int num=0;
int A[100];
void swap_A(int i, int p)
{
    int k;
    k=A[i];
    A[i] = A[p];
    A[p] = k;
}

void insert_A(int key)
{
    int i = num;
    if (num == 0)
    {
        A[i]=key;
    }
    else
    {
        A[i]=key;
        while(i!=0)
        {
           int p = (i-1)/2;
           if(A[i]>A[p])
           {
               swap_A(i,p);
               i=p;
           }
           else
           {
               i=p;
           }
        }
    }
    num++;
}

void remove_A()
{
    A[0] = A[num];
    A[num] = 0;
    num--;
    int i=0;
    while (i!=num)
    {
        int j=0;
        if(A[2*i+1]<A[2*i+2])
        {
            j=2*i+2;
        }
        else if(A[2*i+1]>=A[2*i+2])
        {
            j=2*i+1;
        }
        if(A[i]<A[j])
        {
            swap_A(i,j);
        }

        i=j;
    }

}

void show()
{
    cout<<"\n These are your data : ";
    for(int i=0;i<num;i++)
    {
       cout<<"\n "<<A[i];
    }
}

int main()
{
   int key;
   int n;
   cout<<" How many data you want to input : ";
   cin>>n;
   cout<<" Enter the data : "<<endl;;
   for(int k=0;k<n;k++)
   {
       cout<<" Data : ";
       cin>>key;
       insert_A(key);
   }
   show();
   remove_A();
   show();

return 0;
}
