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
vector<pair<int,int>>adjlist[100001];
bool visited[100001];
int dist[100001];
void bfs(int n, int start)
{
    visited[start]=true;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i=0;i<adjlist[temp].size();i++)
        {
            auto p = adjlist[temp][i];
            if(visited[p.first]==false)
            {
                dist[p.first]=dist[temp]^p.second;
                q.push(p.first);
                visited[p.first]=true;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(adjlist[i].size()==1&&dist[i]%2)res++;
    }
    cout<<res<<endl;
}

int32_t main()
{
    fastio
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            adjlist[i].clear();
            visited[i]=false;
            dist[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            int f,s,w;
            cin>>f>>s>>w;
            adjlist[f].push_back({s,w});
            adjlist[s].push_back({f,w});
        }
        bfs(n,1);
    }
}
