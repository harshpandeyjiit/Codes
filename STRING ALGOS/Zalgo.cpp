#include <bits/stdc++.h>
using namespace std;
#define SIZE 300000 + 5

int P[SIZE * 2];
int ans=0;

string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

bool longestPalindromeSubstring(const string &s)
{
    memset(P,0,sizeof(P));
    string Q = convertToNewString(s);
    int c = 0, r = 0;                // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++)
    {
        int iMirror = c - (i - c);

        if(r > i)
        {
            P[i] = min(r - i, P[iMirror]);
        }
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }
        if (i + P[i] > r)
        {
            c = i;
            r = i + P[i];
        }
    }
    int ff=2;
    for (int i = 1; i < Q.size() - 1; i++)
    {
        if (P[i]>=ff)
        {
            return true;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<string> x;
    for(int i=0;i<n-1;i++)
    {
        for(int j=2;j<=n-i;j++)
        {
            string r=s.substr(i,j);
            if(longestPalindromeSubstring(r))
            {
                cout<<r<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
