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
#define MAXN 111
int vis[MAXN],vis2[MAXN],dp[MAXN],arr[MAXN];
int32_t main()
{
    fastio
    int tcase=1;
    cin>>tcase;
    while(tcase--)
    {
        memset(dp,0,MAXN);
        memset(vis,0,MAXN);
        memset(arr,0,MAXN);
        memset(vis2,0,MAXN);
        int n;
        cin>>n;
        repre(i,1,n)
        {
            cin>>arr[i];
            vis[arr[i]]=1;
        }
        int piv=1,flag=0,tmp,cur,ind;
        repre(i,1,n)
        {
            tmp=99999;
            repre(j,1,n)
            {
                if(vis2[j])continue;
                cur=arr[j];
                if(cur<tmp)
                {
                    tmp=cur;
                    ind=j;
                }
            }
            vis2[ind]=1;
            while(vis[piv])piv++;
            vis[piv]=1;
            dp[ind]=piv;
        }
        repre(i,1,n)
        {
            if(min(arr[i],dp[i])!=arr[i])
            {
                flag=1;
                break;
            }
        }
        if(flag)cout<<"-1"<<endl;
        else
        {
            repre(i,1,n)
            {
                repre(j,i+1,n)
                {
                    if(min(arr[i],dp[j])==arr[i] && dp[i]>dp[j])swap(dp[i],dp[j]);
                }
            }
            repre(i,1,n)cout<<arr[i]<<" "<<dp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
