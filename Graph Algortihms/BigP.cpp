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
#define MAXN 1005
vector<int> adjlist[MAXN];
int visited[MAXN]={0},lucky[1005];
queue<int> q;
int current;
void bfs()
{
    while(!q.empty())
    {
        current=q.front();
        vector<int>::iterator it;
        for(it=adjlist[current].begin();it!=adjlist[current].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=1;
                q.push(*it);
                lucky[*it]=lucky[current]+1;
            }
        }
        //cout<<current<<" ";
        q.pop();
    }
}

int32_t main()
{
    fastio
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        rep(i,n)lucky[i]=10000000;
        rep(i,m)
        {
            int a,b;
            cin>>a>>b;
            adjlist[a].pb(b);
            adjlist[b].pb(a);
        }
        q.push(0);
        visited[0]=1;
        lucky[0]=0;
        bfs();
        repr(i,1,n)
        {
            if(lucky[i]!=10000000)cout<<lucky[i]<<endl;
            else cout<<"-1"<<endl;
        }
    }
    return 0;
}
