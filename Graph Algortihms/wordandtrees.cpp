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
#include<bits/stdc++.h>
using namespace std;
vector<int> adjlist[100000];
vector<bool> visited;
int dp[1000006][26];
char ch[1000006];

void dfs(int u)
{
    int i;
    visited[u]=true;
    for(auto it:adjlist[u])
    {
        if( visited[it]==false)
        {
            dfs(it);
            for(i=0;i<26;i++)dp[u][i]+=dp[it][i];
        }
    }
    dp[u][ch[u]-97]++;
}

int main()
{
    int n,q,u,v,i;
    cin>>n>>q;
    b.assign(100004,false);
    for(i=1;i<=n;i++)
    cin>>ch[i];
    int kk=n-1;
    while(kk--)
    {
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    dfs(1);
    while(q--)
    {
        int x,sum=0;
        string s;
        cin>>x>>s;
        int f[26]={0};
        for(i=0;i<s.length();i++)f[s[i]-97]++;
        for(i=0;i<26;i++)
        {
            if(dp[x][i]<=f[i])sum+=f[i]-dp[x][i];
        }
        cout<<sum<<"\n";
    }
}
