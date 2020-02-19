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
int n;
string str;
int32_t main()
{
    fastio
    int tcase=1;
    cin>>tcase;
    while(tcase--)
    {
       int n=0;
       cin>>n;
       string s;
       cin>>s;
       map<pair<int,int>,int> map1;
       int x=0;
       int y=0;
       int posl=-1;
       int posr=-1;
       int flag=0;
       int min1=1e18;
       map1[{0,0}]=-1;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='L')
               x--;
           else if(s[i]=='R')
               x++;
               else if(s[i]=='U')
               y++;
               else
               y--;
               if(map1.find({x,y})!=map1.end())
               {
               if(i-map1[{x,y}]+1<min1)
               {
                   posl=map1[{x,y}]+1;
                   posr=i;
                   min1=i-map1[{x,y}]+1;
               }
               map1[{x,y}]=i;
               flag=1;
               }
               else
               {
                   map1[{x,y}]=i;
               }
       }
       if(flag)
           cout<<posl+1<<" "<<posr+1<<endl;
       else
           cout<<-1<<endl;
    }
    return 0;
}
