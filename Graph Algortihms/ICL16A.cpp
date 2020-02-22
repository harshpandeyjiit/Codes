/*#          #  # # # # #  # # # # #  # # # # #  #          #
  #          #  #       #  #       #  #          #          #
  # # # # # ##  # # # # #  ## # # #   # # # # #  # # # # # ##
  #          #  #       #  #    #             #  #          #
  #          #  #       #  #      #   # # # # #  #          #*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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

const int INF = (int)1e9 + 7;
char a[2007][27];
int cost[2007][2007];
bool used[2007];
int n;
void dfs(int v, int maxc)
{
	used[v] = true;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i] && cost[v][i] <= maxc)
		{
			dfs(i, maxc);
		}
	}
}

int main()
{
	int m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++)cin>>a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cost[i][j] = max(cost[i][j], abs(a[i][k] - a[j][k]));
			}
		}
	}
	int l = -1, r = 30;
	while (r - l>1)
	{
		int m = (l + r) / 2;
		for (int i = 1; i <= n; i++)
		{
			used[i] = false;
		}
		dfs(1, m);
		bool ok = true;
		for (int i = 1; i <= n; i++)
		{
			if (!used[i]) ok = false;
		}
		if (ok)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	printf("%d\n", r);
}
