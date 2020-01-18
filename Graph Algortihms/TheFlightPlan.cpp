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
#define MAXN 100005
vector<int> adjlist[MAXN];
int visited[MAXN]={0};
int predecessor[MAXN]={0};
int dist[MAXN]={0};
queue<int> q;
int current,x,y;
void bfs()
{
    while(!q.empty())
    {
        current=q.front();
        vector<int>::iterator it;
        sort(adjlist[current].begin(),adjlist[current].end());
        for(it=adjlist[current].begin();it!=adjlist[current].end();it++)
        {
            if(!visited[*it])
            {
                dist[*it]=dist[current]+1;
                predecessor[*it]=current;
                visited[*it]=1;
                q.push(*it);
            }
        }
        q.pop();
    }
}

int32_t main()
{
    fastio
    int t=1;
    while(t--)
    {
        int n,m,k,c;
        cin>>n>>m>>k>>c;
        rep(i,m)
        {
            int a,b;
            cin>>a>>b;
            adjlist[a-1].pb(b-1);
            adjlist[b-1].pb(a-1);
        }
        cin>>x>>y;
        q.push(x-1);
        visited[x-1]=1;
        bfs();
        vector<int> mypath;
        int i=y-1;
        while(i!=x-1)
        {
            mypath.push_back(predecessor[i]);
            i=predecessor[i];
        }
        reverse(mypath.begin(),mypath.end());
        cout<<mypath.size()+1<<endl;
        for(int i=0;i<mypath.size();i++)cout<<mypath[i]+1<<" ";
        cout<<y<<endl;
    }
    return 0;
}
