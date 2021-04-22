#include <bits/stdc++.h>

const long long mx = 1e6 + 5;
using namespace std;

long long int n;
long long int left_dec[mx];
long long int left_inc[mx];
long long int right_dec[mx];
long long int right_inc[mx];
long long int A[mx];
long long int tmp, heigh = 0 , valley = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (int i = 1;i<=n;i++) {
        cin>>A[i];
    }
    for (int i = 1;i<=n;i++) {
        left_dec[i] = 0;
        left_inc[i] = 0;
        right_inc[i] = 0;
        right_dec[i] = 0;
    }
    for (int i = 2;i<=n;i++) {
        if (A[i]>A[i-1]) left_inc[i] = left_inc[i-1]+1;
        if (A[i]<A[i-1]) left_dec[i] = left_dec[i-1]+1;
    }
    for (int i = n-1;i>=1;i--) {
        if (A[i]>A[i+1]) right_inc[i] = right_inc[i+1]+1;
        if (A[i]<A[i+1]) right_dec[i] = right_dec[i+1]+1;
    }
    for (int i = 1 ;i<=n;i++) {
        tmp = min(left_inc[i], right_inc[i]);
        heigh = max(heigh,tmp);
        tmp = min(right_dec[i], left_dec[i]);
        valley = max(valley,tmp);
    }
    cout<<heigh<<" "<<valley;
    return 0;
}
