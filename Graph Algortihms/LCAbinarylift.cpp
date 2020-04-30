#include <iostream>
#include <bits/stdc++.h>

using namespace std;




int main() {



    bool prime[500000+1];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for(int p=2; p*p <=500000; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=500000; i += p)
                prime[i] = false;
        }
    }

    int a[500000];
    memset(a, 0, sizeof(a));
    int index = 0, count = 0;
    for (int p=2; p<=500000; p++)
       if (prime[p]){
          a[index++] = p;
    }

    int n;
    cin>>n;
    while(n--){

        int input ;
        cin>>input;
        int number = input;
        map<int, int> m;
        for(int i = 0; a[i] <= input; i++){
            int count = 0;
            bool isMultiple = false;
            while(number % a[i] == 0){
                // cout<<input<<" "<<number <<" "<<a[i]<<endl;
                number /= a[i];
                count++;
                // cout<<number <<" "<<count<<endl;
                isMultiple = true;
            }
            if(isMultiple)
                m[a[i]] = count;
        }
        long long sum = 0, product = 1;
        for( auto element : m){
            sum = 0;
            for(int j = 0; j <= element.second; j++){
                sum += pow(element.first , j);

           // cout<<sum<<"UUU"<<endl;
            }
            product *= sum;
        }
       cout<<(product - input)<<endl;

    }

    return 0;

}  
