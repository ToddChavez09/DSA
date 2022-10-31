#include <bits/stdc++.h>
using namespace std;

//Auxilary space : O(n/2)
//Time complexity : O(n/2)

bool palindrome(string s,int i,int n)
{
   
    if(i==n/2)
    return true;

    if(s[i]==s[n-i-1])
    {
      return palindrome(s,i+1,n);
    }
    else{
      return false;
    }
}

using namespace std;

int main()
{
  
    string s;
    cin>>s;
    int size=s.size();
    int i=0;
    if(palindrome(s,i,size))
    cout<<"YES"<<endl ;
    else
    cout<<"NO"<<endl ;
  
  return 0;
}
