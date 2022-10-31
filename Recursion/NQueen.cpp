#include <bits/stdc++.h>
#define int long long
#define ln "\n"
#define spc " "
#define gcd(a,b) __gcd(a,b)
#define arrin(a,n)  for(int i=0;i<n;i++) cin>>a[i]
#define arrout(a,n) for(int i=0;i<n;i++) cout<<a[i]<<spc
#define loop(i,a,b)  for(int i=a;i<=b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
int n;

bool isSafe(int row,int col,vector<vector <int>> &vec,vector<int> &rowHash,
vector<int> &first,vector<int> &last)
{
  if(vec[row][col]==1 || rowHash[row]==1||first[n+1+row-col]==1 ||last[row+col]==1)
  return false;
  else
  return true;
}

bool n_queen(int row,int col,vector<vector <int>> &vec,vector<int> &rowHash,
vector<int> &first,vector<int> &last)
{
  if(col==n)
  {
    loop(i,0,n-1)
    {
      loop(j,0,n-1)
      cout<<vec[i][j]<<spc;
      cout<<ln;
    }
    return true;
  }

  loop(row,0,n-1)
  {
    if(isSafe(row ,col,vec,rowHash,first,last))
    {
      vec[row][col]=1;
      rowHash[row]=1;
      first[n+1+row-col]=1;
      last[row+col]=1;
      if(n_queen(row,col+1,vec,rowHash,first,last)==true)
      {
        return true;
      }
      vec[row][col]=0;
      rowHash[row]=0;
      first[n+1+row-col]=0;
      last[row+col]=0;
    }
  }
  return false;
}

int32_t main()
{
  ios::sync_with_stdio(0);  cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
    cin>>n;
    vector<vector <int>> vec(n,vector<int> (n,0));
    vector<int> rowHash(n,0);
    vector<int> first(2*n-2,0);
    vector<int> last(2*n-2,0);
    n_queen(0,0,vec,rowHash,first,last);

  }
  return 0;
}
