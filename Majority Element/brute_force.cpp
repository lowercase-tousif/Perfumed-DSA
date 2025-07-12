#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


int majority_brute_force(int *arr, int n){
    
    int c = 0;
    
    for(int i = 0; i < n; i++){\
        c = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                c++;
            }
        }
        
        if(c > n / 2){
            return arr[i];
        }
    }
    
    return -1;
}

int main()
{
    // Majority Element
    
    // Brute Force Approach
    int arr[] ={2,2,3,3,1,2,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << majority_brute_force(arr, size) << endl;
    return 0;
}
