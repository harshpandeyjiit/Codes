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
int Merge(int arr[], int aux[], int low, int mid, int high)
{
	int k = low, i = low, j = mid + 1;
	int inversionCount = 0;
	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j]) {
			aux[k++] = arr[i++];
		}
		else {
			aux[k++] = arr[j++];
			inversionCount += (mid - i + 1);
		}
	}
	while (i <= mid)
		aux[k++] = arr[i++];
	for (int i = low; i <= high; i++)
		arr[i] = aux[i];
	return inversionCount;
}

int MergeSort(int arr[], int aux[], int low, int high)
{

	if (high == low)
		return 0;
	int mid = (low + ((high - low) >> 1));
	int inversionCount = 0;
	inversionCount += MergeSort(arr, aux, low, mid);
	inversionCount += MergeSort(arr, aux, mid + 1, high);
	inversionCount += Merge(arr, aux, low, mid, high);
	return inversionCount;
}

int32_t main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        rep(i,n)cin>>arr[i];
        int aux[n];
    	for (int i = 0; i < n; i++)aux[i] = arr[i];
    	cout<<MergeSort(arr, aux, 0, n - 1)<<endl;
    }
    return 0;
}
