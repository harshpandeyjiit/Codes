//This is The Coding Area#include <iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	int t;
	cin>>t;
  vector<int> sol;
	while(t--)
  {
		cin>>n;
    int count_st = 0;
    int count_end = 0;

    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            sol.insert(sol.begin()+count_st, i);
            count_st++;
            if(i != sqrt(n)){
                sol.insert(sol.end()-count_end, n/i);
                count_end++;
            }
        }
    }
		for (int i = 0; i < sol.size(); ++i) cout << sol[i] << " ";
		cout<<endl;
    sol.clear();
	}
	return 0;
}
