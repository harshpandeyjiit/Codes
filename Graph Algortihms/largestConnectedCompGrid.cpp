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
#define F first
#define S second
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

#define llp 1000000007
int t;
int a[1002][1002];
bool vt[1002][1002];
int n, m;
int maxi;
int troop;

void travel(int A, int b)
{
    queue<pair<int,int> >q=queue<pair<int,int> >();
    q.push({A,b});
    int size=1;
    vt[A][b]=true;
    while(!q.empty())
    {
        auto P=q.front();
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(i==0&&j==0)continue;
                if(vt[P.F+i][P.S+j]==false && a[P.F+i][P.S+j]==1)
                {
                        vt[P.F+i][P.S+j]=true;
                        size++;
                        q.push({P.F+i,P.S+j});
                }
            }
        }
    }
    maxi=max(maxi,size);
}

int32_t main()
{
    fastio
    int t=1;
    cin>>t;
    while(t--)
    {
        maxi=0;
        troop=0;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(vt,false,sizeof(vt));
        for(int i=1; i<=n;i++)
        {
            for(int j=1; j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m;j++)
            {
                if(a[i][j]==1 && vt[i][j]==false)
                {
                    troop++;
                    travel(i,j);
                }
            }
        }
        cout<<troop<<" "<<maxi<<"\n";
    }
    return 0;
}
