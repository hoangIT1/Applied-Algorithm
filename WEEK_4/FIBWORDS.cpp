/*
#include <bits/stdc++.h>

using namespace std;

string fibwords(int n) {
    if (n==0) return "0";
    if (n==1) return "1";
    if (n>=2) return fibwords(n-1)+fibwords(n-2);
}

int main()
{
    long long int n;
    long long int n_test = 0;
    long long int sum;
    string p,s;
    while (true){
        sum = 0;
        cin>>n;
        cin>>p;
        s = fibwords(n);
        for (int i = 0;i<s.length()-p.length()+1;i++) {
            long long int counte = 0;
            long long int k = 0;
            for (int j = i;j<p.length()+i ;j++) {
                if (s[j]== p[k]) counte++;
                k++;
            }
            if (counte == p.length()) sum++;
        }
        n_test++;
        cout<<"Case "<<n_test<<": "<<sum<<endl;
    }

    return 0;
}
*/

/*
#include<bits/stdc++.h>

using namespace std;

long long int c[1000001];
long long int mc[1000001];

string fibwords(int n) {
    if (n==0) return "0";
    if (n==1) return "1";
    if (n>=2) return fibwords(n-1)+fibwords(n-2);
}
long long count(string s, string p) {
    long long int sum = 0;
    for (int i = 0;i<s.length()-p.length()+1;i++) {
        long long int counte = 0;
        long long int k = 0;
        for (int j = i;j<p.length()+i ;j++) {
            if (s[j]== p[k]) counte++;
            k++;
        }
        if (counte == p.length()) sum++;
    }
    return sum;
}
long long count(int n, string p) {
    if(c[n]<0) {
        c[n] = count(n-1,p)
        + count(n-2,p)
        + mc[n%2];
    }
    return c[n]
}
long long solve(int n,string p) {
    int lp = p.size();
    if (n < n_prepare && l[n] < lp) {
        return 0;
    }
    for (int j = 0; j<=n;j++) {
        c[j] = -1;
    }
    int i = 1;
    while (l[i-1] < lp) {
        i++;
    }
    c[i-1] = count (f[i-1],p);
    c[i] = count (f[i], p);
    string x = f[i].substr(0, lp-1);
    string a = f[i].substr(f[i-1].size() - (lp - 1));
    string b = f[i].substr(f[i].size() - (lp -1));
    mc[i%2] = count(a+x,p);
    mc[(i+1)%2] = count(b+x,p);
    return count(n,p);
}
*/
#include <bits/stdc++.h>

 using namespace std;

 long long int n,n_test,c;
 string s0 = "0";
 string s1 = "1";
 string p,tmp;

 int f(int n, int m0, int s0) {
     if (n==0) return m0;
     if (n==1) return s0;
     if (n>=2) return f(n-1, m0, s0) + f(n-2,m0,s0);
 }
 long long int cnt(string str, string pattern) {
     if (str.size()<pattern.size()) return 0;
     long long int str_len = str.size();
     long long int pattern_len = pattern.size();
     long long int sum = 0;
     for (int i = 0;i<=str_len-pattern_len;i++) {
        if (str.substr(i, pattern_len) == pattern) sum++;
     }
     return sum;
 }

 int main() {
     n_test = 0;
     while (true) {
        n = -1;
        n_test++;
        cin>>n;
        cin>>p;
        s0 = "0";
        s1 = "1";
        if (n==-1) return 0;
        cout<<"Case "<<n_test<<": ";
        if (p == "1") {
            cout<<f(n,0,1)<<endl;
            continue;
        }
        if (p == "0") {
            cout<<f(n,1,0)<<endl;
            continue;
        }
        int i = 2;
        for (;i<=n;i++) {
            tmp = s1;
            s1 = s1 + s0;
            s0 = tmp;
            c = cnt(s1,p);
        }
        cout<<c<<endl;

     }
 }
