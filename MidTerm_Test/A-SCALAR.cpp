#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long int a[1006], b[1006];
    long long int T, n;
    cin>>T;
    for (int j = 1;j<=T;j++) {
        long long int sum = 0;
        cin>>n;
        for (int i = 0;i<n;i++) {
            cin>>a[i];
        }
        for (int i=0;i<n;i++) {
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for (int i = 0;i<n;i++) {
            sum+=a[i]*b[n-1-i];
        }
        cout<<"Case #"<<j<<": "<<sum<<endl;
    }
    return 0;
}
