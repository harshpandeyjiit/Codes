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
#define Endl endl
#define ar(n) int arr[n]
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index

const int maxn=300009;
vector<int>adj[maxn];
int par[maxn];
int low[maxn];
int disc[maxn];
int visited[maxn];
int n,m,w;
int arr[maxn];
int ans;
int flag;
int s;
int ct=1;
int dfs(int v,int p,int root)
{
    disc[v]=low[v]=ct++;
    visited[v]=1;
    int child=0;
    int sum=arr[v];
    par[v]=p;
    int pre=0;
    int pre2=1;
    int art=0;
    for(auto u:adj[v])
    {
        if(visited[u]==0)
        {
            child++;
            par[u]=v;
            int sumChild=dfs(u,v,root);
            low[v]=min(low[v],low[u]);
            sum+=sumChild;
             if(v!=root && low[u]>=disc[v])
            {
                art=1;
                flag=1;
                int m2=sumChild;
                pre2+=m2;
                pre=pre^m2;
            }
        }
        else if(par[v]!=u)low[v]=min(low[v],disc[u]);
    }
    if(art)
    {
        int rem=s-pre2-arr[v];
        pre=pre^rem;
        ans=max(ans,pre);
    }
    return sum;
}
int32_t main()
{
      fastio
      cin>>n>>m;
      repre(i,1,n){cin>>arr[i];s+=arr[i];}
      repre(i,1,m)
      {
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
      }
      repre(i,1,n){
          if(visited[i]==0)dfs(i,0,i);
      }
      if(flag==0)ans=-1;
      cout<<ans<<endl;
      return 0;
}
