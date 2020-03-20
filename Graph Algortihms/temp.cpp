#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define mkp make_pair
#define pb push_back
#define ff first
#define ss second
#define debug1(a) cout<<a<<endl;
#define debug2(a,b) cout<<a<<' '<<b<<endl;
#define debug3(a,b,c) cout<<a<' '<<b<<' '<<c<<endl;
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,a,b)for(int i=a;i<b;i++)
#define repre(i,a,b)for(int i=a;i<=b;i++)
#define pi pair<int,int>
#define pii pair<int,pi>
#define mp map<int,int>
#define iofile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ump unordered_map<int,int>
#define st set<int>
#define ust unordered_set<int>
#define mst multiset<int>
#define pq priority_queue
#define mpq priority_queue<int,vector<int>,greater<int> >
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define sumofdigits(sum,num) int sum = 0; while (n != 0) { sum = sum + n % 10; n = n/10; }
#define int2str(str,n) n=boost::lexical_cast<int>(str);
#define float2str(str,n) n=boost::lexical_cast<float>(str);
using namespace __gnu_pbds;
using namespace std;
#define Endl endl
#define ar(n) int arr[n]
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
int gcd(int a, int b){return b ? gcd (b, a % b) : a;}
int mpower(int x,int y,int p);
const int maxn=1000009;
int arr[maxn];
const int maxm=10000009;
int prime[maxm];
int n;
map<int,int>max_map;
const int mod=1e9+7;

void sieve()
{
  prime[0]=1;
  prime[1]=1;
  for(int i=2;i*i<=10000000;i++)
  {
    if(prime[i]==0)
    {
      prime[i]=i;
      for(int j=i*i;j<=10000000;j+=i)
      {
        if(prime[j]==0)prime[j]=i;
      }
    }
  }
  for(int i=1000;i<=10000000;i++)
  {
    if(prime[i]==0)prime[i]=i;
  }
}

int lcmMod()
{
    for (int i = 1; i <= n; i++)
    {
        int num = arr[i];
        map<int, int> temp;
        while (num > 1)
        {
            int factor = prime[num];
            temp[factor]++;
            num /= factor;
        }
        for (auto it : temp)max_map[it.ff] = max(max_map[it.ff], it.ss);
    }
    int ans = 1;
    for (auto it : max_map)ans = ((ans%mod) * (mpower(it.ff, it.ss,mod)%mod)) % mod;
    return ans%mod;
}

int32_t main()
{
  fastio
  sieve();
  cin>>n;
  repre(i,1,n)cin>>arr[i];
  int k;
  cin>>k;
  int lcm=lcmMod();
  int ans=((lcm%mod)*(k%mod))%mod;
  cout<<ans%mod<<'\n';
  return 0;
}

int mpower(int x, int y, int p)
{
int res = 1;
x = x % p;
while(y > 0){
    if(y & 1) res = (res*x) % p;
      y = y>>1;
      x = (x*x) % p;
    }
    return res;
}
