#include <iostream>
#include <bits/stdc++.h>
 
 
# define M_PI 3.14159265358979323846
 
using namespace std;
long long int N,F;
long long int r[10001];
long long int number;
bool check(double a) {
    int sum = 0;
    for (int i = 0;i<N;i++) {
        sum+=floor(M_PI*r[i]*r[i]/a);
    }
    return sum>=F+1;
}
 
bool cmp(long long int x, long long int y) {
    return x>y;
}
 
int main() {
	cin>>number;
	while (number>0) {
        cin>>N>>F;
        for (int i = 0;i<N;i++) {
            cin>>r[i];
        }
        sort(r,r+N,cmp);
        double low = 0.0;
        double high = M_PI*r[0]*r[0];
        while (high-low>1e-6) {
            double mid = (high+low)/2;
            if (check(mid)) {
                low = mid;
            }
            else high = mid;
        }
        printf("%.6f\n",low);
        number--;
	}
	return 0;
}
