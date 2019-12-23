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
int ffmin=-1*15009;
struct data{
    int sum, pref, suff, ans;
};
data t[40000000]={0};

data combine(data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(int val)
{
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(ffmin,val);
    return res;
}

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = make_data(a[tl]);
    }
    else
    {
        int tm =tl+(tr-tl) / 2;
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        t[v] = combine(t[v*2+1], t[v*2+2]);
    }
}

data query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return make_data(ffmin-2);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2+1, tl, tm, l, min(r, tm)),
                   query(v*2+2, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
	{
        t[v] = make_data(new_val);
    }
	else
	{
        int tm = tl+ (tr-tl)/ 2;
        if (pos <= tm)update(v*2+1, tl, tm, pos, new_val);
        else update(v*2+2, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2+1],t[v*2+2]);
    }
}

int32_t main()
{
    fastio
    int t=1;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        rep(i,n)cin>>arr[i];
        build(arr,0,0,n-1);
        int q;
        cin>>q;
        while(q--)
        {
			int choice;
			cin>>choice;
			if(choice)
			{
				int a,b;
				cin>>a>>b;
				data f=query(0,0,n-1,a-1,b-1);
				cout<<f.ans<<endl;
			}
			else
			{
				int pos,val;
				cin>>pos>>val;
				update(0,0,n-1,pos-1,val);
			}
        }
    }
    return 0;
}
