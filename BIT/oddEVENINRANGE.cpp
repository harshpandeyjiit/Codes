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

int BIT[100003],arr[100003],n;

void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
	  	BIT[x] += delta;
}

int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int32_t main()
{
    fastio
    int t=1;
    while(t--)
    {
		cin>>n;
		repre(i,1,n)
		{
			int x;
			cin>>x;
            arr[i]=x;
            if(x%2)update(i,1);
            else update(i,0);
		}
        int q;
        cin>>q;
        rep(i,q)
        {
            int a,l,r;
            cin>>a>>l>>r;
            if(a==1)
            {
                cout<<(r-l+1)-(query(r)-query(l-1))<<endl;
            }
            else if(a==2)
            {
                cout<<query(r)-query(l-1)<<endl;
            }
            else
            {
                if(r%2==1)
                {
                    if(arr[l]%2==0)update(l,1);
                    arr[l]=r;
                }
                else if(r%2==0)
                {
                    if(arr[l]%2)update(l,-1);
                    arr[l]=r;
                }
            }
        }
    }
    return 0;
}
