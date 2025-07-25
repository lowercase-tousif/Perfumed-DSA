#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define ld long double
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>

ll power(ll a, ll n){
	if(n <= 0){
		return 1;
	}

	return a * power(a, n-1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	ll a = 100000;
	ll n = 3;

	cout << power(a, n) << endl;	
}
