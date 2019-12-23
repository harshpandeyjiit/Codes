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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderedSet;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> orderedMSet;
//*p.find_by_order(index) return value at index
//p.order_of_key(key) return index
struct nodes
{
    int l,r,c;
}query[40005];

int answer[10000009];
int parent[10000009];

void init()
{
  rep(i,10000009)
  {
    answer[i]=0;
    parent[i]=i;
  }
}

int find_set(int a)
{
  while(a!=parent[a])
  {
    parent[a]=parent[parent[a]];
    a=parent[a];
  }
  return a;
}

int32_t main()
{
	fastio
    int t=1;
    cin>>t;
    while(t--)
    {
        init();
        int L;
        cin>>L;
        for (int j = 0; j <L; j++)
        {
            cin>>query[j].l>>query[j].r;
            query[j].c=j+1;
        }
        for (int i = L-1; i >= 0; i--)
        {
			int l = query[i].l;
		    int r = query[i].r;
		    int c = query[i].c;
		    for (int v = find_set(l); v <=r; v=find_set(v))
			{
		        if(answer[v]==0)answer[v] = c;
		        parent[v] = v + 1;
		    }
        }
        unordered_map<int,int> mpa;
        int res=0;
        for(int i=1;i<=10000000;i++)
        {
          if(answer[i]>0)
          {
            if(mpa[answer[i]]==0)res++;
            mpa[answer[i]]++;
          }
        }
        cout<<res<<endl;
    }
    return 0;
}
