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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
const int mod=1000000007;

int cost[100005] , parent[100005];
int find1( int a )
{
	if( a!=parent[a])
	{
		parent[a]=find1(parent[a]);
	}
	return parent[a];
}

void union1( int a , int b , int rank[])
{
	int pa , pb;
	pa=find1(a);
	pb=find1(b);
	if( pa==pb )
	{
		return;
	}
	if( rank[pa] > rank[pb] )
	{
		parent[pb]=pa;
	}
	else
	{
		parent[pa]=pb;
		if( rank[pa]==rank[pb] )
		{
			rank[pb]++;
		}
	}

}

void find2( int x )
{
	int root_parent;
	root_parent=find1(x);
   	if( (cost[x]<cost[root_parent] && cost[x]>=0) || (cost[root_parent]<0 && cost[x]>=0))
   	{
   		cost[root_parent]=cost[x];
   	}
}

int32_t main()
{
    fastio
    int t=1;
    //cin>>t;
    while(t--)
    {
		int n , m , a , b, min=100005 , sum=0 , count=0 , j=1;
		cin>>n>>m;
		int rank[100005];
		bool vis[n+1];
		for( int i=1 ; i<=n ; i++)
		{
			rank[i]=0;
			parent[i]=i;
			vis[i]=false;
		}
		for( int i=1 ; i<=m ; i++)
		{
			cin>>a>>b;
			union1(a,b,rank);
		}
		for( int i=1 ; i<=n ; i++)
		{
			cin>>cost[i];
		}
		for( int i=1 ; i<=n ; i++)
		{
			find2(i);
		}

		for( int i=1 ; i<=n ; i++)
		{
			if(vis[parent[i]] == false)
			{
				if( cost[parent[i]]<0 )
				{
					j=0;
				}
			   sum+=cost[parent[i]];
			   vis[parent[i]]=true;
			   if(cost[parent[i]]<min )
			   {
			   	min=cost[parent[i]];
			   }
			   count++;
			}
		}
		if(count!=1)
		{
			if(j==0)
			{
				cout<<"-1\n";
			}
			else
			{
				count=(count-2)*min;
			   cout<<sum+count<<"\n";
			}
		}
		else
		{
			cout<<"0\n";
		}

		return 0;
	}
}
