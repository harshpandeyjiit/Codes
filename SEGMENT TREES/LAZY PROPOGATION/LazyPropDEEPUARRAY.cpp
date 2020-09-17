/*#          #  # # # # #  # # # # #  # # # # #  #          #
  #          #  #       #  #       #  #          #          #
  # # # # # ##  # # # # #  ## # # #   # # # # #  # # # # # ##
  #          #  #       #  #    #             #  #          #
  #          #  #       #  #      #   # # # # #  #          #*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define mkp make_pair
#define pb push_back
#define ff first
#define ss second
#define debug1(a) cout<<a<<endl;
#define wdebug2(a,b) cout<<a<<' '<<b<<endl;
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

void build(int tre[],int lazy[],int arr[],int v,int tl,int tr)
{
	if(tl>tr)return;
	if(tl==tr)
	{
		tre[v]=arr[tl];
		return ;
	}
	int mid=tl+(tr-tl)/2;
	build(tre, lazy,arr,v*2+1,tl,mid);
	build(tre, lazy,arr,2*v+2,mid+1,tr);
	tre[v]=min(tre[v*2+1],tre[v*2+2]);
}

void query(int tre[],int lazy[],int v,int tl, int tr)
{
    if(lazy[v]!=0)
    {
        tre[v]=tre[v]-lazy[v];
        if(tl!=tr)
        {
            lazy[v*2+1]+=lazy[v];
            lazy[2*v+2]+=lazy[v];
        }
        lazy[v]=0;
    }
	if(tl==tr)
	{
		cout<<tre[v]<<" ";
		return ;
	}
    int mid=(tl+tr)/2;
	query(tre, lazy, 2*v+1,tl,mid);
    query(tre, lazy, 2*v+2,mid+1,tr);
}

void update(int tre[],int lazy[],int v, int tl, int tr,int val)
{
    if(lazy[v]!=0)
    {
		tre[v]=tre[v]-lazy[v];
        if(tl!=tr)
        {
            lazy[2*v+1]+=lazy[v];
            lazy[2*v+2]+=lazy[v];
        }
        lazy[v]=0;
    }
    if(tl>tr)return;
    if(tre[v]>val)
    {
        tre[v]=tre[v]-1;
        if(tl!=tr)
        {
            lazy[2*v+1]+=1;
            lazy[2*v+2]+=1;
        }
        return;
    }
	if(tl==tr)return;
    int mid=(tl+tr)/2;
    update(tre, lazy,v*2+1,tl,mid,val);
    update(tre, lazy,v*2+2,mid+1,tr,val);
    tre[v]=min(tre[v*2+1],tre[2*v+2]);
}

int32_t main()
{
    fastio
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n;
		int tre[4*n+1]={0};
		int lazy[4*n+1]={0};
        int arr[n];
        rep(i,n)cin>>arr[i];
        build(tre, lazy, arr,0,0,n-1);
        cin>>q;
        rep(i,q)
        {
				int x;
				cin>>x;
                update(tre, lazy, 0,0,n-1,x);
        }
		query(tre, lazy,0,0,n-1);
    }
    return 0;
}
