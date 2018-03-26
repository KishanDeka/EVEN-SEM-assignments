#include <iostream>

using namespace std;

class node
{
public:
    double data;
    node *left;
    node *right;
};

class btree
{
    node *root=new node;
public:
    btree()
    {
        root = NULL;
    }

    void insert_t(double data)
    {
        while (root!=NULL)
        {
            if(data<=root->data)
            {
                root=root->left;
                cout<<"added left\n";
                insert_t(data);
            }
            else
            {
                root=root->right;
                cout<<"added right\n";
                insert_t(data);
            }
        }
        root->data=data;
        cout<<"data added\n";
    }

};

int main()
{
    btree bt;
    int num;
    cout<<"Enter how many data you have : ";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        double data;
        cout<<"data = ";
        cin>>data;
        bt.insert_t(data);
    }
return 0;
}
