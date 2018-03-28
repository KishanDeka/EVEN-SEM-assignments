#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node *parent,*left,*right;
	node(){
		parent=left=right=NULL;
	}
};

class btree{
	node *root;
	int number=0;
public:
	btree()
	{
		root=NULL;
	}

void insert(int d)
{
	node* t=new node;
	t->data=d;
	if(root==NULL)
	{
		root=t;
	}
	else
	{
		node *next;
		node* prev;
		next=prev=root;
		while(next!=NULL)
		{
			if(d> next->data)
			{
				next=next->right;
			}
			else if(d<next->data)
			{
				next=next->left;
			}
			else
			{
				cout<<"This value is already present"<<endl;
				break;
			}
			if(next!=NULL)
			{
				prev=next;
			}
		}
		t->parent=prev;
		if(d>prev->data)
		{
			prev->right=t;
		}
		else if(d<prev->data)
		{
			prev->left=t;
		}
	}
	number++;
}

 void  show_A(node* temp)
 {
	if (root==NULL)
	{
		cout<<"Tree has not grown from seed"<<endl;
	}
	if(number==1)
	{
		cout<<"this tree has just born the value of it's root is :"<<root->data<<endl;
	}

	else{
		if(temp==NULL)
		{
			return;
		}
		else
		{
			show_A(temp->left);
			cout<<temp->data<<",";
			show_A(temp->right);
		}
	}
}

void show()
{
    cout<<"These are your data in tree : \n ";
	show_A(root);
}

node* search_t(int key)
{
	node* temp=root;
	while(temp!=NULL){
		if(key>temp->data)
		{
			temp=temp->right;
		}
		else if(key<temp->data)
		{
			temp=temp->left;
		}
		else
        {
			return temp;
			break;
		}
	}
	if(temp==NULL)
	{
		return temp;
	}
}

void delete_t(int key)
{
    node *temp;
    temp = search_t(key);
    if (temp!=NULL)
    {
        if (temp->right == NULL && temp->left==NULL)
        {
            if(temp == (temp->parent)->left)
            {
                (temp->parent)->left = NULL;
            }
            else
            {
                (temp->parent)->right = NULL;
            }
            temp->parent = NULL;
        }
        else if (temp->right == NULL || temp->left==NULL)
        {
            node *pos1, *pos2;
            if (temp->right == NULL)
            {
                pos1 = temp->parent;
                pos2 = temp->left;
                temp->left = NULL;
            }
            else
            {
                pos1 = temp->parent;
                pos2 = temp->right;
                temp->right = NULL;
            }
            if (pos1->left == temp)
            {
                pos1->left = pos2;
            }
            else
            {
                pos1->right = pos2;
            }
            pos2->parent = pos1;
            temp->parent = NULL;
        }
        else
        {
            node *pos = temp->right;
            while(pos->left != NULL)
            {
                pos = pos->left;
            }
            node *right = pos->right;
            if(pos->right!=NULL)
            {
                (pos->right)->parent = pos->parent;
                (pos->parent)->left = pos->right;
            }
            else
            {
                (pos->parent)->left = NULL;
            }
            temp->data = pos->data;
            pos->parent = NULL;
            pos->right = NULL;
        }
        cout<<" Data "<<key<<" is deleted \n ";
    }
    else
    {
        cout<<"\n No data in tree. \n ";
    }
}

void show_range(int skey, int lkey, node *temp)
{
    if (root==NULL)
	{
		cout<<"Tree is empty."<<endl;
	}

	else{
		if(temp==NULL)
		{
			return;
		}
		else
		{
			show_range(skey,lkey,temp->left);
			if (temp->data >= skey && temp->data <= lkey)
			{   cout<<temp->data<<","; }
			show_range(skey,lkey,temp->right);
		}
	}

}

void show_r(int skey,int lkey)
{
    cout<<"Elements in "<<"("<<skey<<","<<lkey<<")"<<" range : \n ";
    show_range(skey,lkey, root);
}
};

int main()
{
    btree bt;
    cout<<" How many elements do  you want to enter?"<<endl;
     	int num=0;
    	cin>>num;
	    for(int i =0; i<num;i++)
	    {
	    	cout<<"Data"<<i+1<<": ";
	     	int d;
	    	cin>>d;
	    	bt.insert(d);
	    	if(i==num)
	    	{
		     	break;
            }
	    }
    bt.show();
    cout<<"\n Enter the two number between which you want to display : \n";
    int skey, lkey;
    cout<<"small key :";
    cin>>skey;
    cout<<"large key :";
    cin>>lkey;
    bt.show_r(skey,lkey);
return 0;
}
