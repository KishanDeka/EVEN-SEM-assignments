#include<iostream>
using namespace std;

int count=0;      //create a variable count
int pos=0;        //create a variable pos
void push(float* list);      //
void pop(float* list);
void show(float* list);

int main(){
	float* list;	
	cout<<"NUMber of data to push:"<<endl;
	int num;
	cin>>num;
	for(int i =0; i<num; i++){
		push(list);
	}
	cout<<"new stack"<<endl;
	show(list);
	cout<<"Number of data you want to pop"<<endl;
	cin>>num;
	for(int i= 0; i<num; i++){
		pop(list);
	}
	cout<<"new stack"<<endl;
	show(list);
	
	return 0;
}
void push(float* list){
	cout<<"Data"<<count<<":";
	float data;
	cin>>data;
	list[count]=data;
	count++;
	cout<<"pushed"<<endl;
}
void pop(float* list){
	pos++;
	cout<<"pooped"<<endl;
	
}

void show(float* list){
	if(count==0){
		cout<<"There is nothing to show";
	}
	else{
		float* temp=list;
		for(int i=pos; i<count; i++){
			cout<<temp[i]<<"->";
		}
	}
	cout<<endl;
}
