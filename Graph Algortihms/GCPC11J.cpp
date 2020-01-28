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
int t,n,x,y,ans,node;
vector <int> v[100005];
bool visited[100005];

void dfs(int x,int pos)
{
	visited[x]=true;
	if(pos>ans)
	{
		ans=pos;
		node=x;
	}
	for(int i=0;i<v[x].size();i++)
	{
		if(!visited[v[x][i]])
			dfs(v[x][i],pos+1);
	}
}

int32_t main()
{
    fastio
	cin>>t;
	while(t--)
	{
		node=0;
		ans=0;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<100005;i++)
			v[i].clear();
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		dfs(0,0);
		ans=0;
		memset(visited,false,sizeof(visited));
		dfs(node,0);
		if(ans%2)cout<<ans/2+1<<"\n";
		else cout<<ans/2<<"\n";
	}
}
