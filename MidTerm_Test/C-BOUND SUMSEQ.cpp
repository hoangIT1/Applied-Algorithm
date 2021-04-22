#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long int n,m,M;
    long long int a[20006];
    cin>>n>>m>>M;
    for (int i = 0;i<n;i++) {
        cin>>a[i];
    }
    long long int count = 0;
    for (int i=0;i<n;i++) {
        long long int sum = 0;
        for (int j=i;j<n;j++) {
            sum+=a[j];
            if (sum >= m && sum <= M) count++;
        }
    }
    cout<<count;
    return 0;
}
