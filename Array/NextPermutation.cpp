#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& v,int n)
{
	if(n<=1)
	return ;
	int i,j;
	for( i=n-2;i>=0;i--)
	{
		if(v[i]<v[i+1])
		break;
	}
	if(i<0)
	reverse(v.begin(),v.end());
	else
	{
	for(j=n-1;j>i;j--)
	{
		if(v[j]>v[i])
			break;
	}
	swap(v[i],v[j]);
	reverse(v.begin()+i+1,v.end());
    }
}

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	nextPermutation(v,n);
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	return 0;
}
