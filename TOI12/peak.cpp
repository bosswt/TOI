#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<long long>good;
int main()
{
        long long n,k;
        scanf("%lld %lld",&n,&k);
        long long mountain[n];
        for(int i=0; i<n; i++) scanf("%lld",&mountain[i]);
        if(mountain[0] > mountain[1])
                good.push_back(mountain[0]);
        if(mountain[n-1] > mountain[n-2]) good.push_back(mountain[n-1]);
        for(int i=1; i<n-1; i++)
                if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1])
                        good.push_back(mountain[i]);
        if(good.size() == 0 || k == 0) printf("-1");
        else
        {
                sort(good.begin(),good.end(),greater<long long>());
                vector<long long>m;
                m.push_back(good[0]);
                for(int i=1; i<good.size(); i++)
                {
                        if(good[i] == good[i-1]) continue;
                        else m.push_back(good[i]);
                }
                int s = m.size();
                if(s >= k) for(int i=0; i<k; i++) printf("%lld\n",m[i]);
                else for(int i=m.size()-1; i>=0; i--) printf("%lld\n",m[i]);
        }
}
