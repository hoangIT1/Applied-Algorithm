#include <bits/stdc++.h>
using namespace std;
 
 
long long getMaxArea(long long hist[], long long n)
{
   
    stack<long long> s;
 
    long long max_area = 0;  
    long long tp;            
    long long area_with_top; 
 
   
    long long i = 0;
    while (i < n)
    {
        
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        
        else
        {
            tp = s.top(); 
            s.pop();      
 
           
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}
 
 
long long hist[1000005];
int main()
{
    long long n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        
 
        for (long long j = 0; j < n; j++)
        {
            cin >> hist[j];
        }
        cout << getMaxArea(hist, n) << endl;
    }
 
    return 0;
}
