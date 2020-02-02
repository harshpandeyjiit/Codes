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

vector<int>v[MAXN];
bool vis[MAXN];
int n,num[MAXN],parent[MAXN],low[MAXN];
stack<int> st;
set<pair<int,int> >ans;
set<pair<int,int> >::iterator it;
void dfs(int u)
{
	static int time=1;
	int children=0;
	vis[u]=1;
	num[u]=low[u]=time++;
	for(int i=0;i<v[u].size();i++)
	{
		int curr=v[u][i];
		if(!vis[curr])
		{
			children++;
			parent[curr]=u;
			dfs(curr);
			low[u]=min(low[u],low[curr]);
			if(low[curr]>num[u]){ans.insert(make_pair(u,curr));ans.insert(make_pair(curr,u));}
		}
		else if(curr!=parent[u])
			low[u]=min(low[u],num[curr]);
	}
}
int32_t main()
{
	int n,m,q;
	cin>>n>>m;
	int i,a[MAXN],b[MAXN];
	rep(i,m)
	{
		cin>>a[i]>>b[i];
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	repre(i,1,n)
    {
        if(!vis[i])dfs(i);
    }
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
        --x;
		if(ans.find(make_pair(a[x],b[x]))!=ans.end())printf("Unhappy\n");
		else printf("Happy\n");
	}
	return 0;
}
