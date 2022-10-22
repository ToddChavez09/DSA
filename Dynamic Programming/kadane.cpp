#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
typedef long long ll;
using namespace std;

ll kadane (vector<ll> nums){
  ll max_current=nums[0];
  ll max_total=nums[0];
  for(int i=0; i<nums.size(); i++){
    max_current=max(nums[i], max_current+nums[i]);
    
    if(max_current>max_total)
      max_total=max_current;
  }
  return max_total;
}

int main(){

  int n;
  cin>>n;
  int x;
  vector<ll> nums;
  while(n--){
    cin>>x;
    nums.push_back(x);
  }

  cout<<kadane(nums)<<endl;
}
