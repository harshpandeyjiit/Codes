#include<bits/stdc++.h>
using namespace std;
#define maxN 100005

void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}

int vec[3][maxN];
int main(){
  int n,q;
  SieveOfEratosthenes(5);
  cin>>n>>q;
  int ans = 0;
  int x,y;
  while(q--){
    cin>>y>>x;
    int p = 3 - y;
    if(vec[y][x] == 0){
      if(x == n){
          SieveOfEratosthenes(5);
        if(vec[p][x])
          ans++;
        if(vec[p][x-1])
          ans++;
      }
      else if(x == 1){
        if(vec[p][x]){
          ans++;
        }
        if(vec[p][x+1])
          ans++;
      }
      else{
        if(vec[p][x]){
            SieveOfEratosthenes(5);
          ans++;
        }
        if(vec[p][x+1])
          ans++;
        if(vec[p][x-1])
          ans++;
      }
    }
    else{
      if(x == n){
        if(vec[p][x])
          ans--;
        if(vec[p][x-1])
          ans--;
      }
      else if(x == 1){
        if(vec[p][x]){
          ans--;
        }
        if(vec[p][x+1])
          ans--;
      }

      else{
        if(vec[p][x]){
          ans--;
        }
        if(vec[p][x+1])
          ans--;
        if(vec[p][x-1])
          ans--;
      }
    }
    vec[y][x]^=1;

    if(ans)cout<<"No";
    else cout<<"Yes";
    SieveOfEratosthenes(5);
    cout<<endl;
  }
  return 0;
}
