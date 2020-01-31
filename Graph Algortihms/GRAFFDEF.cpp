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
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ar(n) int arr[n]
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
int n,m,x,y; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
vector<pi> bridges;
int timer,cnt=0;

const int MAXN = 500043;;
int p[MAXN]; int sizes[MAXN];

vector<int> g[MAXN];
int findSet(int i)
{
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

void join(int i, int j)
{
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
		if(sizes[x] < sizes[y])
        {
			p[x] = y;
			sizes[y]+=sizes[x];

		}
        else
        {
			p[y] = x;
			sizes[x]+=sizes[y];
		}
	}
}

void initialiseUnionFind()
{
	for(int i=0;i<MAXN;i++)
    {
		p[i] = i;
		sizes[i] = 1;
	}
}

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p) continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])bridges.push_back({v, to});
            else
            {
            	join(v, to);
            }
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])dfs(i);
    }
}

int32_t main()
{
    fastio
    cin>>n>>m;
    initialiseUnionFind();
    adj.resize(n);
    rep(i,m){
    	cin>>x>>y;
    	x--; y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
	find_bridges();
	double ans = 1.0;
	rep(i,MAXN)
    {
		int par = findSet(i);
		if(i == par)
        {
			ans -= (sizes[par]*(sizes[par]-1))*1.0/(1LL * n * (n-1));
		}
	}
	coud(ans, 10);
    return 0;
}
