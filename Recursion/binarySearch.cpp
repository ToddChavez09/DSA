#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9 + 7)
#define ln "\n"
#define spc " "
#define gcd(a,b) __gcd(a,b)
#define arrin(a,n)  for(int i=0;i<n;i++) cin>>a[i]
#define arrout(a,n) for(int i=0;i<n;i++) cout<<a[i]<<spc
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
#define yes cout<<"YES"<<endl 
#define no cout<<"NO"<<endl 
using namespace std;

bool binary(int arr[],int start,int end,int find)
{
    int mid =(start+end)/2;
    if(arr[mid]==find)
    return true;

    if(start==end)
    return false;

    if(arr[mid]>find)
    {
      end=mid-1;
      bool call=binary(arr,start,end,find);
      return call;
    }
    else{
      start=mid+1;
      bool call=binary(arr,start,end,find);
      return call;
    }
}

using namespace std;

int32_t main()
{
  ios::sync_with_stdio(0);  cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
    int n,find;
    cin>>n>>find;
    int arr[n];
    loop(i,0,n-1)
    cin>>arr[i];
    sort(arr,arr+n);
    int i=0;
    if(binary(arr,i,n-1,find))
    yes;
    else
    no;
  }
  return 0;
}
