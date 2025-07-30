#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define ld long double
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>

void f(int i, int *arr, int n){
	if(i >= n / 2){
		return;
	}

	swap(arr[i], arr[n-i-1]);
	f(i + 1, arr, n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int arr[] = {7,8,9,1,2,3,4,5};
	int size = sizeof(arr)/ sizeof(arr[0]);

	f(0, arr, size);

	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}	
	cout << endl;
}
