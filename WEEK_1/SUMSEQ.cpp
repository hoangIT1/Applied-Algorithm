#include <iostream>
using namespace std;
 
 
int main() {
	long long n;
	long long sum = 0;
	long long c = 1000000007;
	unsigned long long a[1000000];
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < n; i++) {
		if (sum<c) {
			sum = sum+a[i]%c;
		}
		else {
			sum = sum % c;
			sum += a[i]%c;
		}
	}
	cout<<sum;
	return 0;
}
