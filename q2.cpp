#include <iostream>
using namespace std;
const int MAX = 10 ;
class array
{
	private :
 
		int arr[MAX] ;
		int count ;
	public :
 
		array( ) ;
		void add ( int item ) ;
		int getcount( ) ;
		static int split ( int *, int, int ) ;
		void quiksort ( int lower, int upper ) ;
		void display( ) ;
} ;
array :: array( )
{
	count = 0 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
}
void array :: add ( int item )
{
	if ( count < MAX )
	{
		arr[count] = item ;
		count++ ;
	}
	else
		cout << "\nArray is full" << endl ;
}
int array :: getcount( )
{
	return count ;
}
void array :: quiksort ( int lower, int upper )
{
	if ( upper > lower )
	{
		int i = split ( arr, lower, upper ) ;
		quiksort ( lower, i - 1 ) ;
		quiksort ( i + 1, upper ) ;
	}
}
int array :: split ( int *a, int lower, int upper )
{
	int i, p, q, t ;
 
	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;
	while ( q >= p )
	{
		while ( a[p] < i )
			p++ ;
		while ( a[q] > i )
			q-- ;
		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}
	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;
	return q ;
}
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "  " ;
	cout << endl ;
}
// C++ program for Quick Sort on Singly Linled List
using namespace std;
 
// a node of the singly linked list //
class LLNode
{ public:
    int data;
    LLNode *next;
};
 
//utility function to insert a LLNode at the beginning of linked list //
void insertAtBeginning(LLNode**head,int dataToBeInserted)
{
    LLNode*curr=new LLNode;
    //make a new LLNode with this data and next pointing to NULL
    curr->data=dataToBeInserted;
    curr->next=NULL;

    if(*head==NULL) //if list is empty then set the current formed LLNode as head of list
            *head=curr;
        
    else //make the next of the current LLNode point to the present head and make the current LLNode as the new head
        {
            curr->next=*head;
            *head=curr;
        }
        
        //O(1) constant time
}
 
// A utility function to print linked list //
void display(LLNode**head)
{
    LLNode*temp=*head;
    while(temp!=NULL) //till the list ends (NULL marks ending of list)
        {
            if(temp->next!=NULL)
            cout<<temp->data<<" ->";
            else
            cout<<temp->data;
            
            temp=temp->next; //move to next node
        }
        //O(number of nodes)
    cout<<endl;
}
 
// Returns the last node of the list
LLNode *getTail(LLNode *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// Partitions the list taking the last element as the pivot
LLNode *partition(LLNode *head, LLNode *end, LLNode **newHead, LLNode **newEnd)
{
    LLNode *pivot = end;
    LLNode *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur LLNode is greater than pivot
        {
            // Move cur LLNode to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            LLNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot LLNode
    return pivot;
}
 
 
//here the sorting happens exclusive of the end node
LLNode *quickSortRecur(LLNode *head, LLNode *end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    LLNode *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    LLNode *pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the LLNode before the pivot LLNode as NULL
        LLNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last LLNode of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(LLNode **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
 
// Driver program to test above functions
int  main( )
{
	array a ;
	a.add ( 11 ) ;
	a.add ( 2 ) ;
	a.add ( 9 ) ;
	a.add ( 13 ) ;
	a.add ( 57 ) ;
	a.add ( 25 ) ;
	a.add ( 17 ) ;
	a.add ( 1 ) ;
	a.add ( 90 ) ;
	a.add ( 3 ) ;
	cout << "\nQuik sort.\n" ;
	cout << "\nArray before sorting:" << endl ;
	a.display( ) ;
	int c = a.getcount( ) ;
	a.quiksort ( 0, c - 1 ) ;
	cout << "\nArray after quick sorting:" << endl ;
	a.display( ) ;
	
	cout<<endl<<endl;
	LLNode *head = NULL;
    LLNode *tail = NULL;

    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 16);
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 23);
 
    cout << "Linked List before sorting \n";
    display(&head);
 
    quickSort(&head);
 
    cout << "Linked List after sorting \n";
    display(&head);
	return 0;
}
