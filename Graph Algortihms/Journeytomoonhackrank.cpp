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
int gcd(int a, int b){return b ? gcd (b, a % b) : a;}
#define MAXN 100005
vector<int> adjlist[MAXN];
int level[MAXN],visited[MAXN],count[MAXN];
queue<int> q;
int current,color=1,size=1,ans=1;

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
                size++;
                visited[*it]=1;
                level[*it]=color;
                q.push(*it);
            }
        }
        q.pop();
    }
}

int32_t main()
{
    fastio
    int tcase=1;
    //cin>>tcase;
    while(tcase--)
    {
        int u,v;
        cin>>u>>v;
        memset(level,-1,sizeof(level));
        memset(visited,0,sizeof(visited));
        rep(i,v)
        {
            int a,b;
            cin>>a>>b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        vector<int> countrySizes;
        rep(i,u)
        {
            if(!visited[i])
            {
                level[i]=color;
                q.push(i);
                visited[i]=1;
                bfs();
                //cout<<size<<endl;
                countrySizes.push_back(size);
                ++color;
                size=1;
            }
        }
        int sum = 0;
        int result = 0;
        for(int size : countrySizes)
        {
           result += sum*size;
           sum += size;
        }
        cout<<result;
    }
    return 0;
}


bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    int p=sqrt(n);
    for(int i=5;i<=p;i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}

int binpow(int a,int b)
{
    int res=1;
    while (b > 0)
    {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
