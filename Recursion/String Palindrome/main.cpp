#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define ld long double
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>

bool f(int i, string s)
{	
	if(i >= s.length() / 2) 
	{
		return true;
	}

	if(s[i] != s[s.length() - i - 1]) return false;

	return f(i + 1, s);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s = "neveroddoreven";
	bool res = f(0, s);	

	if(!res){
		cout << "Not palindrome" << endl;
	}else{
		cout << "Palindrome" << endl;
	}
}
