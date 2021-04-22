#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
 
bool parenthessmatching(string s)
{
    stack <char> a;
    char x;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]!='('&&s[i]!='['&&s[i]!=')'&&s[i]!=']'&&s[i]!='{'&&s[i]!='}')
        {
            continue;
        }
        if (s[i]=='('||s[i]=='['||s[i]=='{')
        {
            a.push(s[i]);
            continue;
        }
        if (a.empty()) return false;
        switch (s[i])
        {
        case ')':
            {
                x=a.top();
                a.pop();
                if (x=='['||x=='{') return false;
                break;
            }
        case ']':
            {
                x=a.top();
                a.pop();
                if (x=='('||x=='{') return false;
                break;
            }
        case '}':
        	{
        		x=a.top();
        		a.pop();
        		if (x=='('||x=='[') return  false;
        		break;
        	}
        }
    }
    return (a.empty());
}
void printresult(string s)
{
    if (parenthessmatching(s)==true) cout<<"1"<<endl;
    else cout<<"0"<<endl;
}
int main()
{
	int n;
	cin>>n;
    string dau;
    do{
    	cin>>dau;
    	printresult(dau);
    	n--;
    }
    while (n>0);
    return 0;
}
