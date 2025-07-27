#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define ld long double
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>

int first_occur(int *arr, int n, int key){
	
	if(n == 0)
		return -1;

	if(arr[0] == key)
		return 0;

	int i = first_occur(arr+1, n-1, key);

	if(i == -1)
		return -1;

	return i + 1;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	int arr[] = {1,2,4,5,6,7};
	int size = sizeof(arr)/ sizeof(arr[0]);
	int key = 7;

	cout << first_occur(arr, size, key) << endl;	
}
