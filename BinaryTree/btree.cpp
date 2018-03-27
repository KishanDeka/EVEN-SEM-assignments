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
	btree(){
		root=NULL;
	}
	void insert(int );
	void show();
	void show_A(node* temp);
	void del(int );
 	int search(int );
};

int main(){
	cout<<"this is a program to grow tree and then maintain it"<<endl;
	cout<<"We will provide necessary nutrients to it , but you have to command to grow it."<<endl;
	cout<<"buying seed..\nDone."<<endl;
	btree t;
	cout<<"this tree needs values to make it branches and leaves, Please provide values when asked"<<endl;
	cout<<"We are showing you the tree"<<endl;
	t.show();
	cout<<"Enter one value to make the tree born"<<endl;
	int data;
	cin>>data;
	t.insert(data);
	t.show();
	cout<<"\n\n\n How much values  you want to enter?"<<endl;
	int num=0;
	cin>>num;
	for(int i =0; i<num;i++){
		cout<<"Data"<<i+1<<": ";
		int d;
		cin>>d;
		t.insert(d);
		if(i==num){
			break;
		}
	}
	cout<<"tree is grown, check it by pressing any key and enter"<<endl;
	cin>>num;
	t.show();
	cout<<"Enter a value to search in the tree"<<endl;
	int key;
	cin>>key;
	t.search(key);
	return 0;
}
void btree::insert(int d){
	node* t=new node;
	t->data=d;
	if(root==NULL){
		root=t;
	}
	else {
		node *next;
		node* prev;
		next=prev=root;
		while(next!=NULL){
			if(d> next->data){
				next=next->right;
			}
			else if(d<next->data){
				next=next->left;
			}
			else {
				cout<<"This value is already present"<<endl;
				break;
			}
			if(next!=NULL){
				prev=next;
			}
		}
		t->parent=prev;
		if(d>prev->data){
			prev->right=t;
		}
		else if(d<prev->data){
			prev->left=t;
		}
	}
	number++;
}
void  btree::show_A(node* temp){
	if (root==NULL){
		cout<<"Tree has not grown from seed"<<endl;
	}
	if(number==1){
		cout<<"this tree has just born the value of it's root is :"<<endl;
	}

	else{
		if(temp==NULL){
			return;
		}
		else{
			show_A(temp->left);
			cout<<temp->data<<",";
			show_A(temp->right);
		}
	}
}
void btree::show(){
	show_A(root);
}
int btree::search(int key){
	node* temp=root;
	while(temp!=NULL){
		if(key>temp->data){
			temp=temp->right;
		}
		else if(key<temp->data){
			temp=temp->left;
		}
		else {
			cout<<"This data exists in the tree"<<endl;
			break;
		}
	}
	if(temp==NULL){
		cout<<"Value is not present in tree"<<endl;
	}
}
