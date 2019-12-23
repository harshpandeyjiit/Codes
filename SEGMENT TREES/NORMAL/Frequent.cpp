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
const int N=100005;
int arr[N];
struct segment
{
	int pv,sv,pc,sc,ans;
	void merge(segment a, segment b)
	{
	   pv=a.pv;
       pc=a.pc;
       sv=b.sv;
       sc=b.sc;
       if(a.pv == b.pv)
       pc=a.pc+b.pc;
       if(a.sv == b.sv)
       sc=a.sc+b.sc;
       ans=max(a.ans,b.ans);
       if(a.sv == b.pv)
       {
           ans=max(ans,a.sc+b.pc);
       }
	}
}seg[4*N];

void build(int low, int high, int node)
{
	if(low>high)return ;

	    if(low == high)
	    {
	        seg[node].pv=seg[node].sv=arr[low];
	        seg[node].pc = seg[node].sc=1;
	        seg[node].ans=1;
	        return;
	    }
	    int mid = low+high>>1;
	    build(low,mid,2*node+1);
	    build(mid+1,high,2*node+2);
	    seg[node].merge(seg[2*node+1],seg[2*node+2]);
}

segment query(int low,int high,int lq,int hq,int node)
{
    segment anss;
    anss.pc=anss.sc=anss.pv=anss.sv=anss.ans=0;
    if(low>high || high<lq || low>hq)
    return anss;
    if(lq<=low && high<=hq)     return seg[node];     int mid=low+high>>1;
    anss.merge(query(low,mid,lq,hq,2*node+1),query(mid+1,high,lq,hq,2*node+2));
    return anss;
}

int32_t main()
{
    fastio
    int t=1;
    while(t--)
    {
        int n,q;
		cin>>n;
		while(n)
		{
			cin>>q;
			rep(i,n)cin>>arr[i];
			build(0,n-1,0);
			int x,y;
			while(q--)
			{
				cin>>x>>y;
				segment yy=query(0,n-1,x-1,y-1,0);
				cout<<yy.ans<<endl;
			}
			cin>>n;
		}
    }
    return 0;
}
