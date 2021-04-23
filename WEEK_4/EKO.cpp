#include <bits/stdc++.h>

using namespace std;

unsigned long int N,M;
unsigned long long int A[1000001];

bool check(unsigned long long maxwood) {
    unsigned long int sum = 0;
    for (int i = 1;i<=N;i++) {
        if (A[i]>maxwood) {
            sum+=A[i]-maxwood;
        }
        if (sum>=M)
            return 1;
    }
    return 0;
}

bool cmp(long long x, long long y)
{
    return x > y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    unsigned long long low = 0;
    unsigned long long high = 0;
    unsigned long long mid = 0;
    for (int i = 1;i<=N;i++) {
        cin>>A[i];
    }
    sort(A+1,A+N+1,cmp);
    high = A[1];
    while (high>low+1) {
        mid = (high+low)/2;
        if (check(mid)) {
            low = mid;
        }
        else high = mid;
    }
    cout<<low;
    return 0;
}
