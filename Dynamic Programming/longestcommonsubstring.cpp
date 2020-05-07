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
#define ump unordered_map<int,int>
#define st set<int>
#define ust unordered_set<int>
#define mst multiset<int>
#define pq priority_queue
#define mpq priority_queue<int,vector<int>,grater<int> >
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define sumofdigits(sum,num) int sum = 0; while (n != 0) { sum = sum + n % 10; n = n/10; }
#define int2str(str,n) n=boost::lexical_cast<int>(str);
#define float2str(str,n) n=boost::lexical_cast<float>(str);
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
int dp[3005][3005];

void lcs(string x, string y)
{
    int ans=0;
    int m=x.length(),n=y.length();
    rep(i,m+1)
    {
        rep(j,n+1)
        {
            if(i==0 || j==0)
            {
              dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
              dp[i][j]=dp[i-1][j-1]+1;
              ans=max(ans,dp[i][j]);
            }
            else
            {
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //cout<<dp[m][n]<<endl;
    //To Print The longest Common SubString
    string z="";
    int i=m,j=n;
    while(i>0)
    {
        while(j>0)
        {
            if(dp[i][j]==(dp[i-1][j-1]+1))
            {
               z+=x[i-1];
               i--;
               j--;
            }
            else if(dp[i][j]==dp[i-1][j])i--;
            else j--;
        }
    }
    reverse(z.begin(),z.end());
    cout<<z<<endl;
}

int32_t main()
{
    fastio
    int t=1;
    //cin>>t;
    while(t--)
    {
        string x,y;
        cin>>x>>y;
        lcs(x,y);
    }
    return 0;
}
