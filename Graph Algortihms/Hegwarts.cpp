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

void bfs(int n)
{
    queue<int> q;
    set<int> ss;
    q.push(n);
    ss.insert(n);
    int steps=0;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        if(temp==1&&n==1)
        {
            cout<<steps<<endl;
            return;
        }
        else if(temp==1)
        {
            cout<<steps+1<<endl;
            return;
        }
        if(temp==n-1)
        {
            steps++;
            n--;
        }
        if(temp%3==0)
        {
            int prev=ss.size();
            ss.insert(temp/3);
            int next=ss.size();
            if(next!=prev)
            {
                q.push(temp/3);
            }
        }
        if(temp%2==0)
        {
            int prev=ss.size();
            ss.insert(temp/2);
            int next=ss.size();
            if(next!=prev)
            {
                q.push(temp/2);
            }
        }
        q.push(temp-1);
    }
}


int32_t main()
{
    fastio
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bfs(n);
    }
    return 0;
}
