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
#define MAXN 100005
vector<int> adjlist[MAXN];
bool visited[MAXN];
vector<int> tin,low;
int timer=0,ans=0;

void dfs(int v,int p=-1)
{
    visited[v]=true;
    tin[v]=low[v]=timer++;
    int child=0;
    for(auto to: adjlist[v])
    {
        if(to==p)continue;
        if(visited[to])
        {
            low[v]=min(low[v],tin[to]);
        }
        else
        {
            dfs(to,v);
            low[v]=min(low[to],low[v]);
            if(low[to]>=tin[v] && p!=-1)ans++;
            ++child;
        }
    }
    if(p==-1 && child>1)ans++;
}

int32_t main()
{
    fastio
    int tcase=1;
    //cin>>tcase;
    while(1)
    {
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0)return 0;
        else
        {
            ans=0;
            timer=0;
            tin.assign(n,-1);
            low.assign(n,-1);
            memset(visited,false,sizeof(visited));
            rep(i,n)adjlist[i].clear();
            int a,b;
            while(m--)
            {
                cin>>a>>b;
                --a,--b;
                adjlist[a].push_back(b);
                adjlist[b].push_back(a);
            }
            rep(i,n)if(!visited[i])dfs(i);
            cout<<ans<<endl;
        }
    }
    return 0;
}
