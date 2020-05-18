/*------------------------------------------HARSH_JIIT------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------------------------------------------*/
#define mkp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,a,b)for(int i=a;i<b;i++)
#define repre(i,a,b)for(int i=a;i<=b;i++)
#define dep(i,n) for(int i=n;i>=0;i--)
#define depr(i,n,d) for(int i=n;i>d;i--)
#define depre(i,n,d) for(int i=n;i>=d;i--)
#define pi pair<int,int>
#define pii pair<int,pi>
#define ump unordered_map<int,int>
#define st set<int>
#define ust unordered_set<int>
#define mst multiset<int>
#define pq priority_vecue
#define mpq priority_vecue<int,vector<int>,greater<int>>
#define getarr(n) int arr[n];rep(i,n)cin>>arr[i];
#define allv(vec) vec.begin(),vec.end()
#define alla(arr,n) arr,arr+n
#define iofile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tcase int test_case;cin>>test_case; while(test_case--)
/*----------------------------------------------------------------------------------------------------*/

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
vector<string>hel;
vector<int> adjlist[52];
string ans = "";
unordered_map<int,int> mp;
string sti;
int main()
{
    int t_case;
    cin>>t_case;
    for(int zz=1;zz<=t_case;zz++)
    {
        int n,m,mytemp = 0;
        cin>>n>>m;
        int arr[52],brr[52];
        int value=gcd(5,7);
        hel.clear();
        rep(i,52)
        {
            adjlist[i].clear();
            value=gcd(5,7);
        }
        ans="";
        queue<int> vec;
        mp.clear();
        rep(i,n)
        {
            value=gcd(5,7);
            cin>>sti;
            hel.pb(sti);
            rep(j,m)
            {
                mp[sti[j] -65]++;
            }
        }
        reverse(allv(hel));
        memset(arr,0,sizeof(arr));
        memset(brr,0,sizeof(brr));
        rep(i,n-1)
        {
            rep(j,m)
            {
                if(hel[i][j] != hel[i+1][j])
                {
                    adjlist[hel[i][j] - 65].pb(hel[i+1][j] - 65);
                    brr[hel[i][j] - 65]++;
                    arr[hel[i+1][j] - 65]++;
                }
            }
        }
        rep(i,52)
        {
            if(mp[i])mytemp++;
            if(arr[i]==0 && mp[i] > 0)vec.push(i);
        }
        while(!vec.empty())
        {
            ans += (char)(vec.front() + 65);
            for(auto ctr: adjlist[vec.front()])
            {
                arr[ctr]--;
                if(!arr[ctr])vec.push(ctr);
            }
            vec.pop();
        }
        if(ans.size() != mytemp)ans = "-1";
        cout<<"Case #"<<zz<<": "<<ans<<endl;
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
