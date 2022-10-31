#include <bits/stdc++.h>
using namespace std;
/*
	thisis thefastest non-probabilistic programe to check primality;
	Time complexity :: O(n/3)
*/
	bool isPrime(int n)
{

  	 if( n<=1 ) return false;
  	 if( n<=3 ) return true;
  	 if( n%2 == 0 or n % 3 == 0 ) return false;
  	  /*
  	  	for numberes grater than 3 
  	  	consider all numbers as multiple of 6 with remainder
  	  	which can be written as 
  	  	6k + 0   = 6 12 18 24 ....
  	  	6k + 1   = 7 13 19 25  ....
  	  	6k + 2   = 8 14 20 26 ...
  	  	6k + 3   = 9 15 21 27 ....
  	  	6k + 4   = 4 10 16 22 28  ...
  	  	6k + 5     5 11 17 23 29....
  	  	all numberse exept 6k +1 and 6k+1 are multiple of 2 or 3 or both
  	  	so conclusion is prime numbers grater than 3 are either in the form of 6k + 1 or 6k +5   
  	  	6k +5 can also be wriiten as 6k - 1;
  	  	and the code is written on this logic;
  	  */
  	 for (int p = 5 ; p*p <= n; p += 6)
  	 {
  	 	if( n%p == 0 or n % (p+2)==0 ) return false;
  	 }
	return true;
}

int main()
{
	int num;
	cout<<"Enter the number which youwant to check::";
	cin>>num;
	if(isPrime(num))
	{
		cout<<num<<" is a Prime number.";
	}
	else{
		cout<<num<<" is not a Prime number";
	}
	return 0;
}