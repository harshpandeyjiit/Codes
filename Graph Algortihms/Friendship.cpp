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
#define iofile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ump unordered_map<int,int>
#define st set<int>
#define clr0(arr) memset(arr,0,sizeof(arr));
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

const int maxn=100009;
vector<int>adj[maxn];
int visited[maxn];
int par[maxn];
int ct=1;
int disc[maxn];
int low[maxn];
vector<pi >bridges;
int dist[maxn];
map<pair<int,int>,int> mp;
void dfs(int u,int p)
{
    visited[u]=1;
    par[u]=p;
    disc[u]=low[u]=ct++;
    for(auto v:adj[u])
    {
        if(visited[v]==0)
        {
            par[v]=u;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])
            {
                mp[{u,v}]=1;
                mp[{v,u}]=1;
            }
        }
        else if(par[u]!=v)low[u]=min(low[u],disc[v]);
    }
}

void dfs2(int u,int d)
{
    visited[u]=1;
    dist[u]=d;
    for(auto v:adj[u])
    {
        if(visited[v])continue;
        int a=0;
        if(mp.find({u,v})!=mp.end() || mp.find({v,u})!=mp.end())a++;
        dfs2(v,d+a);
    }
}
int32_t main()
{
  fastio
  int n,m;
  cin>>n>>m;
  repre(i,1,m)
  {
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
  }
  dfs(n,0);
  clr0(visited);
  dfs2(n,0);
  int q;
  cin>>q;
  while(q--){
      int u;
      cin>>u;
      if(dist[u]==0 || u==n){cout<<"impossible\n";}
      else cout<<dist[u]<<'\n';
  }
  return 0;
}
