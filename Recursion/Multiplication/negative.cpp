#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define ld long double
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>

ll multiply(int a, int b){
	if(b < 0) return -multiply(a, -b);
	if(b == 0 ) return 0;

	return a + multiply(a, b - 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	ll n = 1000;
	ll m = -1000;

	ll result = multiply(n, m);
	cout << result << endl;
}
