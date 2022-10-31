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

string dir="DLRU";
int di[]={1,0,0,-1};
int dj[]={0,-1,1,0};

void rat(string s,int n,int m,int i,int j,vector<vector<int>> &vis)
{
  
  if(i>=n || j>=m ||i<0 ||j<0||vis[i][j]==1)
  return;

  if(i==n-1 && j==m-1)
  { 
    cout<<s<<ln;
    return;
  }
  vis[i][j]=1;
  for(int k=0;k<4;k++)
  {
    s+=dir[k];
    rat(s,n,m,i+di[k],j+dj[k],vis);
    s.pop_back();
  }
  vis[i][j]=0;

}

using namespace std;

int32_t main()
{
  ios::sync_with_stdio(0);  cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int i=0,j=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    string s="";
    rat(s,n,m,i,j,vis);
  }
  return 0;
}

