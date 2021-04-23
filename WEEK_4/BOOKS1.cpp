#include <bits/stdc++.h>

using namespace std;

long long int N;
long long int m,k;
long long int P[505],b[505],ans[505];

bool is_divided(long long int maxval) {
    long long int sum = 0;
    long long int cnt = 0;
    for (int i = 1;i<=m;i++) {
        b[i] = 0;
    }
    for (int i = m;i>=1;i--) {
        if (sum+P[i]<=maxval && i>=k-cnt) sum+=P[i];
        else {
            sum = P[i];
            b[i] = 1;
            cnt++;
        }
    }
    if (cnt == k-1) {
        for (int i = 1;i<=m;i++) {
            ans[i] = b[i];
        }
        return true;
    }
    return false;
}

void print_result() {
    for (int i = 1;i<=m;i++) {
        cout<<P[i];
        if (ans[i] == 0) cout<<" ";
        if (ans[i] == 1) cout<<" / ";
    }
    cout<<endl;
}

int main()
{
    cin>>N;
    while (N--) {
        cin>>m>>k;
        long long int mid = 0;
        long long int high;
        long long int low = 0;
        for (int i = 1;i<=m;i++) {
            cin>>P[i];
            high+=P[i];
            low=max(low,P[i]);
        }
        memset(ans,0,sizeof(ans));
        while (low<=high) {
            mid = (high+low)/2;
            if (is_divided(mid)) {
                high = mid-1;
            }
            else low = mid+1;
        }
        print_result();
    }
    return 0;
}
