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
#define mpq priority_queue<pi,vector<pi>,greater<pi> >
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
vector<pi> adjlist[MAXN];
bool visited[MAXN]={0};
int prims(int x)
{
    int mincost=0;
    mpq que;
    pi p;
    que.push(mkp(0,x));
    while(!que.empty())
    {
        p=que.top();
        que.pop();
        int x=p.second;
        if(visited[x])continue;
        mincost+=p.first;
        visited[x]=true;
        for(int i=0;i<adjlist[x].size();i++)
        {
            int y=adjlist[x][i].second;
            if(!visited[y])
            {
                que.push(adjlist[x][i]);
            }
        }
    }
    return mincost;
}

int32_t main()
{
    fastio
    int tcase=1;
    //cin>>tcase;
    while(tcase--)
    {
        int n,m,x,y,weight;
        cin>>n>>m;
        while(m--)
        {
            cin>>x>>y>>weight;
            --x,--y;
            adjlist[x].push_back(mkp(weight,y));
            adjlist[y].push_back(mkp(weight,x));
        }
        cout<<prims(0)<<endl;
    }
    return 0;
}
