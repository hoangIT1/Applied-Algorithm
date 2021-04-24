#include <bits/stdc++.h>

using namespace std;

int N,K;
long long int A[5005];
int main()
{
    cin>>N>>K;
    for (int i = 1 ; i <= N;i++) {
        cin>>A[i];
    }
    int cnt = 0;
    for (int i = 1; i <= N-2; i++) {
        for (int j = i+1; j <= N-1; j++) {
            for (int k = j+1; k <= N; k++) {
                if (A[i] + A[j] + A[k] == K) {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
