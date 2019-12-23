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

class DisjointSet
{
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;
public:
	void makeSet(vector<int> const &universe)
	{
		for (int i : universe)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int k)
	{
		if (parent[k] != k)
			parent[k] = Find(parent[k]);
        return parent[k];
	}
	void Union(int a, int b)
	{
		int x = Find(a);
		int y = Find(b);
		if (x == y)
		{
			cout<<"Invalid query!";
			return;
		}
		if (parent[x] > parent[y])
			parent[y] = x;
		else if (parent[x] < parent[y])
			parent[x] = y;
		else
		{
			parent[x] = y;
			rank[y]++;
		}
	}
	void printparent(int a)
	{
		cout<<parent[a]<<endl;
	}
};

void printSets(vector<int> const &universe, DisjointSet &ds)
{
	for (int i : universe)
    {
        cout<<ds.Find(i)<<" ";
    }

    /*set<int> myset;
    for (int i : universe)
    {
        myset.insert(fd[ds.Find(i)]);
        //cout<<fd[ds.Find(i)]<<" ";
    }
    int j=1;
    for(auto it=myset.begin();it!=myset.end();it++)j=j*(*it);
    cout<<j<<endl;*/
}

int32_t main()
{
    fastio
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
	    vector<int> universe;
        rep(i,n)
        {
			int temp;
			cin>>temp;
            universe.push_back(temp);
        }
	    DisjointSet ds;
        ds.makeSet(universe);
		int q;
		cin>>q;
		rep(i,q)
		{
			int z;
			cin>>z;
			if(!z)
			{
				int a,b;
				cin>>a>>b;
				ds.Union(a,b);
			}
			else
			{
				int a;
				cin>>a;
				ds.printparent(a);
			}
		}
        //printSets(universe, ds);
    }
    return 0;
}
