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
#define N 311111
#define A 1111111
#define BLOCK 555

int cnt[A], a[N], ans[N], answer = 0;

struct node
{
	int left, right, i;
}q[N];

bool cmp(node x, node y)
{
	if(x.left/BLOCK != y.left/BLOCK)
	{
		return x.left/BLOCK < y.left/BLOCK;
	}
	return x.right < y.right;
}

void add(int position)
{
	cnt[a[position]]++;
	if(cnt[a[position]] == 1)
    {
		answer++;
	}
}

void remove(int position)
{
	cnt[a[position]]--;
	if(cnt[a[position]] == 0)
    {
		answer--;
	}
}

int32_t main()
{
    fastio
	int n;
	cin>>n;
	rep(i,n)cin>>a[i];
	int m;
	cin>>m;
	rep(i,m)
	{
		cin>>q[i].left>>q[i].right;
		q[i].left--;
		q[i].right--;
		q[i].i=i;
	}
	sort(q,q+m,cmp);
	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++)
    {
		int L = q[i].left, R = q[i].right;
		while(currentL < L)
        {
			remove(currentL);
			currentL++;
		}
		while(currentL > L)
        {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R)
        {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1)
        {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}
    rep(i,m)cout<<ans[i]<<endl;
}
