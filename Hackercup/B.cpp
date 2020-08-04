/*------------------------------------------HARSH_JIIT------------------------------------------------*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/*----------------------------------------------------------------------------------------------------*/
#define int             long long
#define mkp             make_pair
#define pb              push_back
#define ff              first
#define ss              second
#define Endl            endl
#define rep(i,n)        for(int i=0;i<n;i++)
#define repr(i,a,b)     for(int i=a;i<b;i++)
#define repre(i,a,b)    for(int i=a;i<=b;i++)
#define dep(i,n)        for(int i=n;i>=0;i--)
#define depr(i,n,d)     for(int i=n;i>d;i--)
#define depre(i,n,d)    for(int i=n;i>=d;i--)
#define pi              pair<int,int>
#define pii             pair<int,pi>
#define mp              map<int,int>
#define ump             unordered_map<int,int>
#define st              set<int>
#define ust             unordered_set<int>
#define mst             multiset<int>
#define pq              priority_queue
#define mpq             priority_queue<int,vector<int>,greater<int>>
#define allv(vec)       vec.begin(),vec.end()
#define alla(arr,n)     arr,arr+n
#define iofile          freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fastio          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tcase           int test_case;cin>>test_case; while(test_case--)
#define out(vec)        for(auto it:vec){cout<<it<<" ";}cout<<Endl;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
/*----------------------------------------------------------------------------------------------------*/
bool isPrime(int n);
int pow(int a,int b);
int gcd(int a, int b);
int modinv(int a, int m);
int pow(int a,int b,int mod);
int gcdExtended(int a, int b, int *x, int *y);
/*----------------------------------------------------------------------------------------------------*/
#define MAXN 100005
#define MOD 1000000007
/*---------------------------------------------MAIN---------------------------------------------------*/
int cnt=1;
int dfs(int a, int n)
{
	if(a%n==0)
    return cnt;
    cnt++;
    return dfs((a*10+7)%n,n);
}

int32_t main()
{
    fastio
    //tcase
    {
        int n;
		cin>>n;
		if(n%2==0 || n%5==0)cout<<-1<<endl;
		else
		{
			cout<<dfs(7,n);
		}
    }
    return 0;
}

/*--------------------------------------END OF MAIN FUNCTION------------------------------------------*/
int gcd(int a, int b){return b ? gcd (b, a % b) : a;}
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int modinv(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    int res = (x%m + m) % m;
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
