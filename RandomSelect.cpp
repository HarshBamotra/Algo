 //Harsh Bamotra AC-1216
//Program to implement rondomized select

#include <iostream>
#include <time.h>
using namespace std;


template <class T>
int partition(T arr[] , int p , int r)
    {
	T x = arr[r];
	int i = p-1;

	for(int j=p ; j<r ; j++)
		{
			if(arr[j]<=x)
				{
					i++;
					swap(arr[i] , arr[j]);
				}
		}
	swap(arr[i+1] , arr[r]);
	return (i+1);
    }

template <class T>
randomize_partition(T arr[] , int p , int r)
    {
	srand(time(NULL));
	int i = (int) p+(rand()%(r-p+1));
	swap(arr[r] , arr[i]);
	return partition(arr , p , r);
    }

template <class T>
T randomize_select(T arr[], int p , int r, int i)
    {
	if(p==r)
		return arr[p];
	
	int q = randomize_partition(arr , p , r);
	int k = q-p+1;

	if(i == k)
		return arr[q];
	else if(i < k)
		return randomize_select(arr, p, q-1, i);
	return randomize_select(arr, p, q-1, i);
    }

int main()
    {
	int n , i;
	cout << "Enter the number of terms ::";
	cin >> n;

	int arr[n];
	cout << "Enter the array elements ::" << endl;
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];

	cout << "*******************************************" << endl;
	cout << "Enter the rank ::";
	cin >> i;

	cout << "The " << i << "th rank element ::" << randomize_select<int>(arr , 0 , n-1 , i) << endl;
	cout << "*******************************************" << endl;
	return 0;
    }