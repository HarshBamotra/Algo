 //Harsh Bamota AC-1216
//Program to implement heap sort

#include <iostream>
using namespace std;

template <class T>
class Heap
    {
	private:
	int temp;
	int size;
	T arr[];

	public:
	Heap(int n)
		{
			size=temp=n;
			arr[size];
		}

	void Input()						//utility functions
		{
			for(int i=0 ; i<size ; i++)
				cin >> arr[i];
		}

	void print()
		{
			for(int i=0 ; i<size ; i++)
				cout << arr[i] << " ";
		}

	void heapify(int i)
		{
			int largest;
			int l=2*i+1;
			int r=2*i+2;

			if(l<=temp-1 && arr[l]>=arr[i])
				largest=l;
			else 
				largest=i;
		
			if(r<=temp-1 && arr[r]>=arr[largest])
				largest=r;

			if(largest!=i)
				{
					swap(arr[i] , arr[largest]);
					heapify(largest);
				}
		}

	void HeapSort()
		{
			for(int i=size/2-1 ; i>=0 ; i--)
        			heapify(i);
	    		for(int i=size-1 ; i>0 ; i--) 
				{
	        			swap(arr[0], arr[i]);
					temp--;
       		 			heapify(0);
    				}	
		}

    };

int main()
    {
	int n;
	cout << "Enter the size of array ::";
	cin >> n;

	Heap <int> A(n);

	cout << "Enter the array elements ::";
	A.Input();

	cout << "The array you entered ::";
	A.print();

	A.HeapSort();

	cout << endl << "The array after sorting ::";
	A.print();
	
	return 0;
    }