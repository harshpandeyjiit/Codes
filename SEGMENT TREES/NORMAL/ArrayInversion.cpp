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
void update(int t[], int v, int l, int r, int val)
{
	if(l==val && r==val)
	{
		t[v]=1;
		return ;
	}
	if(val<l || val>r)return ;
	int mid =(l+r)/2;
	update(t,2*v+1,l, mid,val);
	update(t,v*2+2,mid+1,r,val);
	t[v]=t[2*v+1]+t[2*v+2];
}

int query(int t[],int v,int tl, int tr, int l, int r)
{
	if(l<=tl && r>=tr)return t[v];
	if(r<tl || tr<l)return 0;

	int mid=(tl+tr)/2;

	return query(t,2*v+1,tl,mid,l,r)+query(t,2*v+2,mid+1,tr,l,r);
}

int32_t main()
{
    fastio
    int tc=1;
    //cin>>tc;
    while(1)
    {
        int n;
		cin>>n;
		if(n==0)return 0;
		int arr[n];
		rep(i,n)cin>>arr[i];
		int mx=*max_element(arr,arr+n);
		int t[mx*6];
		memset(t,0,sizeof(t));
		int ans=0;
		rep(i,n)
		{
			ans+=query(t,0,0,mx,arr[i]+1,mx);
			update(t,0,0,mx,arr[i]);
		}
		cout<<ans<<endl;
    }
    return 0;
}
