 //Harsh Bamotra AC-1216
//Program to sort an array using bucket sort

#include <iostream>   
using namespace std;  
  
int Max(int a[], int n) 
    {  
	  int max = a[0];  
	  for(int i = 1 ; i < n ; i++)  
	    if(a[i] > max)  
	      max = a[i];  
	  return max;  
    }  

void BucketSort(int a[], int n)  
    {  
  	int max = Max(a, n); 
  	int bucket[max] , i;  
  	for(int i = 0 ; i <= max ; i++)  
  		{  
    			bucket[i] = 0;  
  		}  
  	for(int i = 0 ; i < n ; i++)  
  		{  
    			bucket[a[i]]++;  
  		}  
  	for(int i = 0 , j = 0 ; i <= max ; i++)  
  		{  
    			while (bucket[i] > 0)  
    				{  
      					a[j++] = i;  
      					bucket[i]--;  
    				}  
  		}  
     }  

int main()  
    {  
	int n;
	cout << "Enter the number of elements ::";
	cin >> n;
	
	int arr[n];
	
	cout << "Enter the array elements ::" << endl;
	for(int i=0 ; i<n ; i++)
		cin >> arr[i];
	
	cout << "**********************************************" << endl;

	cout << "The array you entered ::";
	for(int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	BucketSort(arr , n);	

	cout << endl << "The array after sorting ::";
	for(int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << endl<< "**********************************************" << endl;

  	return 0;
    }  