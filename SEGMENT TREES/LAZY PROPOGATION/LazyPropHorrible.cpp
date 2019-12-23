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
//*p.find_by_order(v) return value at v
//p.order_of_key(key) return v
const int MAXN=1000002;

int query(int v,int tree[],int lazy[],int tl,int tr,int l,int r)
{
	  if(tl>r || tl>tr || tr<l)return 0;
	  if(lazy[v]!=0)
	  {
	    tree[v]+=(tr-tl+1)*lazy[v];
	    if(tl!=tr)
	    {
	      lazy[2*v+1]+=lazy[v];
	      lazy[2*v+2]+=lazy[v];
	    }
	    lazy[v]=0;
	  }
	  if(tl>=l && tr<=r)return tree[v];
	  int mid=(tl+tr)/2;
	  int left=query(2*v+1,tree,lazy,tl,mid,l,r);
	  int right=query(2*v+2,tree,lazy,mid+1,tr,l,r);
	  return (left+right);
}

void update(int v,int tree[],int lazy[],int tl,int tr,int l,int r,int val)
{
	  if(lazy[v]!=0)
	  {
	    tree[v]+=(tr-tl+1)*lazy[v];
	    if(tl!=tr)
	    {
	      lazy[2*v+1]+=lazy[v];
	      lazy[2*v+2]+=lazy[v];
	    }
	    lazy[v]=0;
	  }
	  if(tl>r || tr<l || tl>tr)return;
	  if(tl>=l && tr<=r)
	  {
	    tree[v]+=(tr-tl+1)*val;
	    if(tl!=tr)
	    {
	      lazy[2*v+1]+=val;
	      lazy[2*v+2]+=val;
	    }
	    return;
	  }
	  int mid=(tl+tr)/2;
	  update(2*v+1,tree,lazy,tl,mid,l,r,val);
	  update(2*v+2,tree,lazy,mid+1,tr,l,r,val);
	  tree[v]=tree[2*v+1]+tree[2*v+2];
}

int32_t main()
{
    fastio
    int test_case=1;
	cin>>test_case;
    while(test_case--)
    {
		int n,q;
		cin>>n>>q;
        int limit=4*n;
        int tree[limit]={0};
        int lazy[limit]={0};
		rep(i,q)
		{
			int a;
            cin>>a;
            if(a==0)
            {
                int b,c,d;
			    cin>>b>>c>>d;
                update(0,tree,lazy,0,n-1,b-1,c-1,d);
            }
            else
            {
                int b,c;
				cin>>b>>c;
                cout<<query(0,tree,lazy,0,n-1,b-1,c-1)<<"\n";
            }
		}
    }
    return 0;
}
