#include<iostream>
#include<iostream>
using namespace std;

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
	
	return 0;
}
