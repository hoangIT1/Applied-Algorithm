#include <iostream>
using namespace std;
 
int main() {
	unsigned long long a,b;
	long long c = 1000000007;
	long long res,r;
	cin>>a>>b;
	res = 1;
	r = a%c;
	while (b>0) {
		if (b%2==1) {
			res = (res * r) % c;
		}
		r = (r*r)%c;
		b = b/2;
	}
	cout<<res<<endl;
}
