/*#          #  # # # # #  # # # # #  # # # # #  #          #
  #          #  #       #  #       #  #          #          #
  # # # # # ##  # # # # #  ## # # #   # # # # #  # # # # # ##
  #          #  #       #  #    #             #  #          #
  #          #  #       #  #      #   # # # # #  #          #*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//#define int long long
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
//#define mp map<int,int>
#define iofile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ump unordered_map<int,int>
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
vector<pair<long long,long long>>v[100001];
map<long long,long long>mp;

void bridges(long long u, bool* visited, long long* parent, long long* low, long long* disc)
{
    visited[u]=true;
    static int time=0;
    disc[u]=low[u]= ++time;
    for(int i=0;i<v[u].size();i++)
    {
        pair<long long,long long>p=v[u][i];
        long long v=p.first;
        if(!visited[v])
        {
            parent[v]=u;
            bridges(v,visited,parent,low,disc);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])
            {
                mp[p.second]=1;
            }
        }
        else if(v!=parent[u])
        low[u]=min(disc[v],low[u]);
    }
}

void solve(long long n, long long m,long long q)
{
    bool* visited=new bool[n];
    long long* parent=new long long[n];
    long long* low=new long long[n];
    long long* disc=new long long[n];
    for(int i=1;i<=n;i++)
    {
        visited[i]=false;
        parent[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bridges(i,visited,parent,low,disc);
        }
    }
}

int main()
{
    long long n,m,q;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(int i=0;i<m;i++)
    {
        long long f,s, id;
        scanf("%lld %lld %lld",&f,&s,&id);
        v[f].push_back({s,id});
        v[s].push_back({f,id});
    }
    solve(n,m,q);
    while(q--)
    {
        long long chk;
        scanf("%lld",&chk);
        if(mp[chk]==1)
        printf("YES\n");
        else printf("no\n");
    }
    return 0;
}
