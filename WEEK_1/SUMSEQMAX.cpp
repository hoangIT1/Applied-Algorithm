#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int m = 1000000;
 
int main() {
	int s[m];
	int a[m];
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	int ans = s[0];
	for (int i=0;i<n;i++) {
        a[i] = s[i];
	}
	for (int i = 1;i < n;i++) {
		if (s[i-1] > 0) s[i] = s[i-1]+a[i];
		else s[i] = a[i];
		ans = (ans < s[i])?s[i]:ans;
	}
	cout<<ans;
}
