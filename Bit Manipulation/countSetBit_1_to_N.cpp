//Count total set bits in all numbers from 1 to n
#include <bits/stdc++.h>
using namespace std;
#define     mod             (int)(1e9 + 7)

int power(int x, int y)
{
    int ans = 1;
    if (x == 0) return 0;
 
    while (y > 0)
    {
        if (y & 1)
            ans = (ans*x)%mod;
             
        y = y>>1; // y = y/2
        x = (x*x)%mod;
    }
    return ans%mod;
}

// Function which counts set bits from 0 to n
int countSetBits(int n)
{
    int i = 0;

    // ans store sum of set bits from 0 to n  
    int ans = 0; 

    // while n greater than equal to 2^i
    while ((1 << i) <= n) {

        int num=power(2,i+1);
        int temp=power(2,i);

        if((n+1)% num==0)
        {    
            ans+=temp*((n+1)/num);
        }
        else{
            int m=(n+1)% num;
            ans+=temp*((n+1)/num);
            if(m>temp)
            ans+=m-temp;
        }
        // increment the position
        i++;
    }

    return ans;
}

// Main Function
int main()
{
    int n ;
    cin>>n;
    cout << countSetBits(n) << endl;
    return 0;
}
