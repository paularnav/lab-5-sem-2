#include<iostream>
#include<iostream>
using namespace std;
// declare the class for node
class Node{ public:
	int data;
	Node*next;
};
//class declaration for LinkedList
class LinkedList{
public:
    Node *head;
    Node *tail;
    int n;//initialization size of LinkedList

//setting the initial size of the LinkedList
    LinkedList(){
    head=NULL;
    tail=NULL;
    n=0;
}
//inserting node in the end
    void Insert(int x){
        Node *temp=new Node;
        temp->data=x;
        ++n;
        //checking if the LinkedList is empty
        if (head==NULL){
            head=temp;
            tail=temp;

        }
        else{

            tail->next=temp;
            tail=temp;

        }
         tail->next=head;
    }
};
//declare class for sorting array and linked list
class bubbleshort
{
 public:
// declare the function for sort the array
int* arrsort(int* p,int size){
for(int i=0; i<size; i++){
		for(int j=0; j<size-i-1;j++){
			if(p[j]>p[j+1]){
				float a =p[j];
				p[j]=p[j+1];
				p[j+1]=a;
			}
		}
	}
	return p;
}
// declare the function for sorting the linked list
Node* sorting ( Node*head)
{
  Node * temphead = head;
  Node * tempnode = NULL;
int counter = 0;
while (temphead)
{
temphead = temphead->next;
counter++;
}
for (int i=0; i<counter; i++)
{
for (int j=0; j<counter-i; j++)
{
if (temphead->data > temphead->next->data)
{
tempnode = temphead;
temphead = temphead->next;
temphead->next = tempnode;
}
}
}
return temphead;
}

};
int main()
{

	int n, i, arr[50], j;bubbleshort b;
	cout<<"Enter total number of elements :";
	cin>>n;
	cout<<"Enter "<<n<<" numbers :";
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Elements sorted successfully..!!\n";
	int *temp=b.arrsort(arr,n);
	cout<<"Sorted list in ascending order :\n";
	for(i=0; i<n; i++)
	{
		cout<<*(temp+i)<<" ";
	}
	LinkedList l;
	l.Insert(9);
	l.Insert(8);
	l.Insert(7);
	l.Insert(6);
	cout<<"For linked list \n";
	Node*lsort;
	lsort=b.sorting (l.head);
	while(lsort!=NULL){ cout<<lsort->data<<endl;
	}
	return 0;
}
