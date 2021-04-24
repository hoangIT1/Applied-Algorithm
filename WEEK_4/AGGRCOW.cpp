#include <bits/stdc++.h>

using namespace std;

long long int N,C, n_test, low, high, mid;
unsigned long int X[1000001];

bool check(unsigned long int maxval) {
    unsigned long int cur = X[1];
    unsigned long int cnt = 1;
    for (int i = 2; i <= N; i++) {
        if (X[i] - cur >=  maxval) {
            cnt++;
            cur = X[i];
            if (cnt >= C) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n_test;
    while (n_test--) {
        cin>>N>>C;
        for (int i = 1; i <= N; i++) {
            cin>>X[i];
        }
        sort(X+1,X+1+N);
        low = 1;
        high = X[N];
        while (low+1<high) {
            mid = (low+high)/2;
            if (check(mid)) {
                low = mid;
            }
            else high = mid;
        }
        cout<<low<<endl;
    }
}
