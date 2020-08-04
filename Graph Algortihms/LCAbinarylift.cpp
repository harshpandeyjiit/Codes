/*----------------------------------HARSH_JIIT--------------------------------------------------------*/

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
#define MAXN 1005
vector<int> adjlist[MAXN];
int tin[MAXN]={0},tout[MAXN]={0};
int up[1005][1005];
int timer=0;
int L;
/*---------------------------------------------------------------------------------------------------*/
int gcd(int a, int b);
int ncr(int n, int r);
int npr(int n, int r);
bool isPrime(int n);
int binexp(int a,int b);
int modbinexp(int a,int b,int mod);
bool is_parent(int u, int v)
{
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}
void dfs(int v,int p)
{
    tin[v]=++timer;
    up[v][0]=p;
    for(int i=1;i<=L;i++)
        up[v][i]=up[up[v][i-1]][i-1];
    for(auto u: adjlist[v])
    {
        if(u!=p)dfs(u,v);
    }
    tout[v]=++timer;
}

int lca(int u,int v)
{
    if(is_parent(u,v))return u;
    else if(is_parent(v,u))return v;
    for(int i=L;i>=0;--i)
    {
        if(!is_parent(up[u][i],v))
        {
            cout<<up[u][i]<<"*";
            u=up[u][i];
        }
    }
    return up[u][0];
}
/*---------------------------------------------MAIN---------------------------------------------------*/

int32_t main()
{
    fastio
    int tt;
    cin>>tt;
    repre(t,1,tt)
    {
        timer=0;
        rep(i,MAXN)adjlist[i].clear();
        int n;
        cin>>n;
        int m=n;
        L=ceil(log2(n));
        rep(i,m)
        {
            int count;
            cin>>count;
            while(count--)
            {
                int b;
                cin>>b;
                --b;
                adjlist[i].pb(b);
                adjlist[b].pb(i);
            }
        }
        dfs(0,0);
        cout<<"Case "<<t<<":"<<endl;
        int q;
        cin>>q;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            --a,--b;
            cout<<lca(a,b)+1<<endl;
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
int binpow(int a,int b)
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
int modbinexp(int a,int b,int mod)
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
