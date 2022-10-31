#include <bits/stdc++.h>
using namespace std;
/*
	thisis thefastest non-probabilistic programe to check primality;
	Time complexity :: O(n/3)
*/
long long fast_exp(int n,int p)
{
	if(p<0) return -1;
	long long ans=1;
	while(p>0)
	{
		if(p&1){
			ans=ans*n;
		}
		ans=(ans*ans);
		p=p>>1;
	}
  	 return ans;
}

int main()
{
	/*

 NOTE::ans should fit within long long int
	*/
	int num =11,power=40;
	long long ans= fast_exp(num,power);
	cout<<num<< "^"<<power<<"::"<<ans<<endl;	
	return 0;
}