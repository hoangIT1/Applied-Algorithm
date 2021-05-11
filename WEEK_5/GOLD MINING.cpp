#include <bits/stdc++.h>

using namespace std;

long long int n;
long long int maxval = -100;
long long int L1;
long long int L2;
long long int A[100001];
long long int F[100001];
/*
void ghinhan() {
    int temp = 0;
    for (int i = 0;i<s.size();i++) {
        temp += s.top();
        s.pop();
    }
    if (temp > maxval) maxval = temp;
}

void _try(int x) {
    if (x<0) {
        ghinhan();
    }
    s.push(x);
    for (int i = x-L2; i <= x-L1;i++) {
        _try(i);
    }
    s.pop();
}
*/
int main()
{
    cin>>n>>L1>>L2;
    for (int i = 1;i<=n;i++) {
        cin>>A[i];
    }
    for (int i = 1;i<=n;i++) {
        F[i] = A[i];
    }
    for (int i = L1+1;i<=n;i++) {
        for (int j=i-L2;j<=i-L1;j++) {
            if(j>0) F[i] = max(F[i], F[j]+A[i]);
        }
    }
    for (int i=1;i<=n;i++) {
        maxval = max(maxval,F[i]);
    }
    cout<<maxval<<endl;
}
