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
const int MAXN=1000000;
int n,t[MAXN];

int iszero(int a)
{
	if(a==0)return 1;
	else return 0;
}

void build(int arr[],int v,int tl,int tr)
{
	if(tl==tr)
	{
		t[v]=iszero(arr[tl]);
	}
	else
	{
		int mid=tl+(tr-tl)/2;
		build(arr,v*2+1,tl,mid);
		build(arr,2*v+2,mid+1,tr);
		t[v]=t[v*2+1]+t[v*2+2];
	}
}

int count_zero(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
	{
        return t[v];
    }
    int tm = tl+ (tr-tl)/2;
    return count_zero(v*2+1, tl, tm, l, min(r, tm))+ count_zero(v*2+2, tm+1, tr, max(l, tm+1), r);
}

int32_t main()
{
    fastio
    int test_case=1;
	cin>>test_case;
    while(test_case--)
    {
        int n;
		cin>>n;
		int arr[n];
		rep(i,n)cin>>arr[i];
		build(arr,0,0,n-1);
		int q;
		cin>>q;
		rep(i,q)
		{
			int a,b;
			cin>>a>>b;
			cout<<count_zero(0,0,n-1,a-1,b-1)<<endl;
		}
    }
    return 0;
}
