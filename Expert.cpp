/*------------------------------------------HARSH_JIIT------------------------------------------------*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/*----------------------------------------------------------------------------------------------------*/

#define int long long
#define mkp make_pair
#define pb push_back
#define ff first
#define ss second
#define Endl endl
#define dbg(a) cout<<a<<endl;
#define dbg2(a,b) cout<<a<<' '<<b<<endl;
#define dbg3(a,b,c) cout<<a<' '<<b<<' '<<c<<endl;
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,a,b)for(int i=a;i<b;i++)
#define repre(i,a,b)for(int i=a;i<=b;i++)
#define dep(i,n) for(int i=n;i>=0;i--)
#define depr(i,n,d) for(int i=n;i>d;i--)
#define depre(i,n,d) for(int i=n;i>=d;i--)
#define pi pair<int,int>
#define pii pair<int,pi>
#define mp map<int,int>
#define ump unordered_map<int,int>
#define st set<int>
#define ust unordered_set<int>
#define mst multiset<int>
#define pq priority_queue
#define mpq priority_queue<int,vector<int>,greater<int>>
#define getarr(n) int arr[n];rep(i,n)cin>>arr[i];
#define allv(vec) vec.begin(),vec.end()
#define alla(arr,n) arr,arr+n
#define iofile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tcase int test_case;cin>>test_case; while(test_case--)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
#define MOD 100000007
#define MAXN 100005

/*----------------------------------------------------------------------------------------------------*/
int gcd(int a, int b);
int ncr(int n, int r);
int npr(int n, int r);
bool isPrime(int n);
int pow(int a,int b);
int pow(int a,int b,int mod);
/*----------------------------------------------------------------------------------------------------*/

/*---------------------------------------------MAIN---------------------------------------------------*/

int32_t main()
{
    fastio
    tcase
    {
        int a,b,q;
        cin>>a>>b>>q;
        if(a>b)
        swap(a,b);
        int lcm=(a*b)/__gcd(a,b);
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            if(y<b)
            cout<<"0"<<" ";
            else if(b<y and x<b)
            cout<<y-b+1<<" ";
            else
            {
                if(y<lcm)
                cout<<y-x+1<<" ";
                else if(lcm<=x)
                {
                    int m=y/lcm,n=x/lcm,ans=0;
                    int val=m-n;
                    ans=b*val;
                    if(lcm*m+b>=200)
                    ans-=(b-y%lcm);
                    if(x-lcm<=b)ans+=(x-lcm);
                    cout<<y-x+1-ans<<" ";
                }
                else
                {
                    int m=y/lcm,n=x/lcm,ans=0;
                    int val=m-n;
                    ans=b*val;
                    if(lcm*m+b>=200)ans-=(b-y%lcm);
                    cout<<y-x+1-ans<<" ";
                }
            }
        }
    }
    return 0;
}

/*--------------------------------------END OF MAIN FUNCTION------------------------------------------*/
int gcd(int a, int b)
{
    return b ? gcd (b, a % b) : a;
}
int ncr(int n, int r)
{
    int res=1;
    for(int i=n;i>n-r;i--)res*=i;
    repr(i,2,r)res/=i;
    return res;
}
int npr(int n, int r)
{
    int res=1;
    rep(i,r)res*=(n-i);
    return res;
}
bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    int p=sqrt(n);
    for(int i=5;i<=p;i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
int pow(int a,int b)
{
    int res=1;
    while (b > 0)
    {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int pow(int a,int b,int mod)
{
    a%=mod;
    int res=1;
    while (b > 0)
    {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
