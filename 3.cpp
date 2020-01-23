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
#define flagoat2str(str,n) n=boost::lexical_cast<flagoat>(str);
using namespace __gnu_pbds;
using namespace std;
#define Endl endl
#define ar(n) int arr[n]
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
int n,f=0,flag=0;
int32_t main()
{
    fastio
    int t=1;
    cin>>t;
    while(t--)
    {
        f=0,flag=0;
		cin>>n;
		for(int i=2;i*i<n;i++)
        {
			if(n%i==0)
            {
				f=i;
				break;
			}
		}
		if(f==0)
        {
			cout<<"NO"<<endl;
		}
		else
        {
			n=n/f;
			for(int i=f+1;i*i<=n;i++)
            {
				if(n%i==0)
                {
				    if(i==n/i||f==n/i)
                    {
				        cout<<"NO"<<endl;
				        flag=1;
				        break;

				    }
					else
                    {
					    cout<<"YES"<<endl;
					    cout<<f<<" "<<i<<" "<<n/i<<endl;
                        flag=1;
					    break;

					}
				}
			}
			if(flag==0)cout<<"NO"<<endl;
		}
	}
    return 0;
}
