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
#define Endl endl
#define ar(n) int arr[n]
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
int32_t main()
{
    fastio
    int t=1;
    while(t--)
    {
        multiset<int> myqueue;
        int n,k;
        cin>>n>>k;
        int arr[n],sum[n]={0};
        cin>>arr[0];
        sum[0]=arr[0];
        repr(i,1,n)
        {
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
        }
        int left=0,right=1,ans=1,maxi,temp=0;
        myqueue.insert(arr[0]);
        myqueue.insert(arr[1]);
        while(right<n && left<n)
        {
            maxi=*myqueue.rbegin();
            if(left==0)
            {
                temp=sum[right];
                if(temp+k>=(maxi*(right+1)))
                {
                    ans=max(ans,right-left+1);
                    right++;
                    myqueue.insert(arr[right]);
                }
                else
                {
                    auto it=myqueue.find(arr[left]);
                    myqueue.erase(it);
                    left++;
                }
            }
            else
            {
                temp=sum[right]-sum[left-1];
                if(temp+k>=(maxi*(right-left+1)))
                {
                    ans=max(ans,right-left+1);
                    right++;
                    myqueue.insert(arr[right]);
                }
                else
                {
                    auto it=myqueue.find(arr[left]);
                    myqueue.erase(it);
                    left++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
