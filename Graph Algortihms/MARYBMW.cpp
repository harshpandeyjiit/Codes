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
#define MAX 50005
vector< pair<int,pair<int,int> > > v;
int parent[MAX];
int ranks[MAX],n;

void __init__()
{
	for(int i=1;i<=n;i++)
	{
		parent[i] = i;
		ranks[i] =0;
	}
}
int find(int x)
{
	while(x != parent[x])
	{
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void Union(int x1,int y1)
{
	if(ranks[x1] > ranks[y1])
	{
		parent[y1] = x1;
		ranks[x1] = ranks[x1] + ranks[y1];
	}
	else
	{
		parent[x1] = y1;
		ranks[y1] = ranks[y1] + ranks[x1];
	}
}

bool ok()
{
	int x = find(1);
	int y = find(n);
	if(x==y)return true;
	else return false;
}

bool check(int m)
{
	__init__();
	for(int i=0;i<m;i++)
	{
		int x = find(v[i].second.first);
		int y = find(v[i].second.second);
		if(x==y)continue;
		Union(x,y);
		if(ok())
		{
			cout << v[i].first << endl;
			return true;
		}
	}
	return false;
}

int32_t main()
{
    fastio
	int t,m,a,b;
	int c;
	cin>>t;
	while(t--)
	{
		v.clear();
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			v.pb(mkp(c,mkp(a,b)));
		}
		sort(v.rbegin(),v.rend());
		if(!check(m))cout<<"-1"<<endl;
	}
	return 0;
}
