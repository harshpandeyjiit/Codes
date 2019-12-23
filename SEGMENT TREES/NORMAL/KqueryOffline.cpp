/*#          #  # # # # #  # # # # #  # # # # #  #          #
  #          #  #       #  #       #  #          #          #
  # # # # # ##  # # # # #  ## # # #   # # # # #  # # # # # ##
  #          #  #       #  #    #             #  #          #
  #          #  #       #  #      #   # # # # #  #          #*/
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
const int MAXN=120000;
int n;
vector<int> t[MAXN];
#define INF 0

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = vector<int>(1, a[tl]);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        merge(t[v*2+1].begin(), t[v*2+1].end(), t[v*2+1+1].begin(), t[v*2+1+1].end(),back_inserter(t[v]));
    }
}

int query(int v, int tl, int tr, int l, int r, int x)
{
    if (l > r)
        return INF;
    if (l == tl && r == tr)
    {
        vector<int>::iterator pos = upper_bound(t[v].begin(), t[v].end(), x);
        if(pos!=t[v].end())return t[v].end()-pos;
        return INF;
    }
    int tm = tl + (tr-tl) / 2;
    return query(v*2+1, tl, tm, l, min(r, tm), x)+query(v*2+1+1, tm+1, tr, max(l, tm+1), r, x);
}

int32_t main()
{
    fastio
    int t=1;
    while(t--)
    {
        int n;
        scanf("%lld",&n);
        int arr[n];
        rep(i,n)scanf("%lld",&arr[i]);
        build(arr,0,0,n-1);
        int q;
        scanf("%lld",&q);
        int l[q],r[q],k[q];
        rep(i,q)
        {
            scanf("%lld %lld %lld",&l[i],&r[i],&k[i]);
        }
        rep(i,q)
        {
            printf("%lld\n",query(0,0,n-1,l[i]-1,r[i]-1,k[i]));
        }
    }
    return 0;
}
