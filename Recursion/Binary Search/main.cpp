#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define ld long double
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>


int binarySearch(int *arr,int low, int high, int key){
	if(low > high){
		return -1;
	}

	int mid = (low + high) / 2;

	if(arr[mid] == key){
		return mid;
	}

	if(arr[mid] < key){
		return binarySearch(arr, mid + 1, high, key);
	}

	return binarySearch(arr, low,  mid - 1,  key);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	int arr[] = {1,2,3,4,5,6,7};
	int low = 0;
	int size = sizeof(arr)/ sizeof(arr[0]);

	int high = size - 1;
	int key = 6;

	int result = binarySearch(arr, low, high, key);
	cout << result << endl;	
}


/*
	Ascending 

	if (arr[mid] < key)
    	return binarySearch(arr, mid + 1, high);
	else
    	return binarySearch(arr, low, mid - 1);


    Descending
    
    if (arr[mid] < key)
    	return binarySearch(arr, low, mid - 1);
	else
    	return binarySearch(arr, mid + 1, high);


*/
