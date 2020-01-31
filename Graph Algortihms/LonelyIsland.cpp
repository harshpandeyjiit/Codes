
/*#          #  # # # # #  # # # # #  # # # # #  #          #
  #          #  #       #  #       #  #          #          #
  # # # # # ##  # # # # #  ## # # #   # # # # #  # # # # # ##
  #          #  #       #  #    #             #  #          #
  #          #  #       #  #      #   # # # # #  #          #*/
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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
// using namespace __gnu_pbds;
using namespace std;
#define Endl endl
#define ar(n) int arr[n]
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
vector<int>v[200005],ans;
queue<int>t;
#define eps 1e-9
int n,m,r,in[200005];
double val[200005],out[200005];
void topological_sort()
{
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			t.push(i);
		}
	}
	while(!t.empty())
	{
		int u=t.front();
		t.pop();
		ans.push_back(u);
		for(auto i:v[u])
		{
			in[i]-=1;
			val[i]+=val[u]/out[u];
			if(in[i]==0)
			{
				t.push(i);
			}
		}
	}
}
int32_t main()
{
	cin>>n>>m>>r;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		out[x]+=1.0;
		in[y]++;
	}
	val[r]=1;
	topological_sort();
	assert(ans.size()==n);
	double maxx=0;
	for(int i=1;i<=n;i++)
		if(!out[i])
			maxx=max(maxx,val[i]);
	for(int i=1;i<=n;i++)
	{
		if(!out[i] && fabs(val[i]-maxx)<=eps)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}
