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
#define MAX  10005

bool visited[MAX] , ans ;
vector <int> graph[MAX] ;

void DFS (int)  ;

int32_t main ()
{
	int  m , n ,  v1 , v2 , i , j ;
	cin>>n>>m;
	ans = true ;
	for (i =1 ; i<=m; i++)
	{
		cin>>v1>>v2;
		graph[v1].push_back (v2) ;
		graph[v2].push_back (v1) ;
	}
	if (n!=m+1)ans = false ;
	for (i =1 ; i <= n ; i++)visited[i]  = false ;
	visited[1] = true ;
	DFS(1) ;
	for(i=1;i<=n;i++)
    {
        if(visited[i]==false)ans=false;
    }
	if (ans)printf ("YES\n") ;
	else printf ("NO\n") ;
    return 0 ;
}

void DFS (int x)
{
	int i , c ;
	c=0;
	for(i=0;i<graph[x].size();i++)
    {
        if(visited[graph[x][i]]==true)c++;
    }
	if(c>1)ans=false;
	for (i = 0 ; i<graph[x].size() ; i++)
	{
		if (visited[graph[x][i]] == false)
		{
			visited[graph[x][i]] = true ;
			DFS (graph[x][i]) ;
		}
	}
}
