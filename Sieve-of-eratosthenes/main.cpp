#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n)
{
    bool prime[n + 1];

    for (int i = 2; i <= n; i++)
    {
        prime[i] = true;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    sieveOfEratosthenes(30);
}
