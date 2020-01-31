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
int32_t main()
{
    fastio
    int t=1;
    cin>>t;
    while(t--)
    {
		int n, m,flag=1;
		cin>>n>>m;
        vector<int> barray,solution;
        rep(i,n)
        {
            int temp;
            cin>>temp;
            barray.push_back(temp);
        }
        int indegree[n+1];
        vector<int> adjList[n+1];
        memset(indegree, 0, sizeof(indegree));
        int u, v;
        char ch;
        while(m--)
		{
            cin >> u >> ch >> v;
            if(ch=='<')
            {
                adjList[u].push_back(v);
                ++indegree[v];
            }
            else
            {
                adjList[v].push_back(u);
                ++indegree[u];
            }
        }
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 1; i <= n; ++i)
		{
            if(indegree[i] == 0)q.push(i);
        }
		while(!q.empty())
		{
            u = q.top();
			q.pop();
            solution.push_back(u);
            for(unsigned i = 0; i < adjList[u].size(); ++i)
			{
                v = adjList[u][i];
                --indegree[v];
                if(indegree[v] == 0) q.push(v);
            }
	    }
	    for(int i = 0; i < n; ++i)
		{
            if(solution[i]>n)flag=0;
		}
        int count=0;
        if(flag==0)cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<Endl;
            int tflag=0;
            rep(i,n)
            {
                if(barray[i]==solution[i])tflag++;
                else if(solution[i]>barray[i])tflag=-1,break;
            }
            if(tflag==-1)rep(i,n)cout<<solution[i]<<" ";
            else
            cout<<endl;
        }
	}
    return 0;
}
