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
vector<vector<int>> v;
int level[3000]={0};
bool vis[3000];
int lol[1000005][2];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s]=0;
    vis[s]=true;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        rep(i,v[p].size())
        {
            if(vis[v[p][i]]==false)
            {
                level[v[p][i]]=level[p]+1;
                q.push(v[p][i]);
                vis[v[p][i]]=true;
            }
        }
    }
}

void init(int n)
{
    rep(i,n+5)vis[i]=false;
}

int32_t main()
{
    fastio
    int t=1,k=0;
    cin>>t;
    while(t--)
    {
        int nodes,edges,x,y;
        cin>>nodes>>edges;
        v.resize(nodes+5);
        v.clear();
        rep(i,edges)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
            lol[i][0]=x;
            lol[i][1]=y;
        }
        init(nodes);
        repre(i,1,nodes)
        {
            if(!vis[i])bfs(i);
        }
        int flag=0;
        rep(i,edges)
        {
            if((level[lol[i][0]]-level[lol[i][1]])%2==0)
            {
                flag=1;
                break;
            }
        }
        k++;
        if(flag)cout<<"Scenario #"<<k<<":\nSuspicious bugs found!\n";
        else cout<<"Scenario #"<<k<<":\nNo suspicious bugs found!\n";
    }
    return 0;
}
