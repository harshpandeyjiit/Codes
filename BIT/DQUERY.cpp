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
const int MAX = 300005;
const int MAX1 = 1e6 + 5;
int BIT[MAX], p[MAX1], ans[MAX], a[MAX];
pair <int, pair<int, int> > pr[MAX];

void update(int idx, int val)
{
    while(idx < MAX)
    {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

int read(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int32_t main()
{
    int n, q, x;
    scanf("%lld", &n);
    for(int i = 1;i <= n;++i)
        scanf("%lld", &a[i]);
    scanf("%lld", &q);
    for(int i = 0;i < q;++i)
    {
        scanf("%lld %lld", &pr[i].second.first, &pr[i].first);
        pr[i].second.second = i;
    }
    sort(pr, pr + q);
    memset(p, -1, sizeof(p));
    memset(BIT, 0, sizeof(BIT));
    x = 0;
    for(int i = 1;i <= n;++i)
    {
        if(p[a[i]] != -1)update(p[a[i]], -1);
        p[a[i]] = i;
        update(i, 1);
        //rep(i,n)cout<<BIT[i+1]<<" ";
        //cout<<endl;
        while(x < q and pr[x].first == i)
        {
            //cout<<read(pr[x].first)<<" "<<read(pr[x].second.first-1)<<endl;
            ans[pr[x].second.second] = read(pr[x].first) - read(pr[x].second.first-1);
            x++;
        }
    }
    for(int i = 0;i < q;++i)
        printf("%lld\n", ans[i]);
    return 0;
}
