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
#define ump unordered_map<int,int>
#define st set<int>
#define ust unordered_set<int>
#define mst multiset<int>
#define pq priority_queue
#define mpq priority_queue<int,vector<int>,grater<int> >
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
int func(int input[],int length)
{
int prev = -1;
    int current, next;
    int prevCount = 0, currentCount = 1;

    // longest constant range length
    int longest = 1;

    // first number
    current = input[0];

    for (int i = 1; i < length; i++)
    {
        next = input[i];

        // If we see same number
        if (next == current)
        {
            currentCount++;
        }

        // If we see different number,
        // but same as previous.
        else if (next == prev)
        {
            prevCount += currentCount;
            prev = current;
            current = next;
            currentCount = 1;
        }

        // If number is neither same
        // as previous nor as current.
        else
        {
            longest = max(longest,
                          currentCount + prevCount);
            prev = current;
            prevCount = currentCount;
            current = next;
            currentCount = 1;
        }
    }

    return max(longest,
               currentCount + prevCount);
}

int32_t main()
{
    fastio
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        rep(i,n)cin>>arr[i];
        cout<<func(arr,n);
    }
    return 0;
}
