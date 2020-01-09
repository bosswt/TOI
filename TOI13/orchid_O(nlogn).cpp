#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
        int n;
        scanf("%d",&n);
        int orchid[n];
        vector<int>lis;
        for(int i=0; i<n; i++) scanf("%d",&orchid[i]);
        lis.push_back(orchid[0]);
        for(int i=1; i<n; i++)
        {
                if(orchid[i] >= lis.back())
                        lis.push_back(orchid[i]);
                else
                {
                        int index = upper_bound(lis.begin(),lis.end(),orchid[i])-lis.begin();
                        lis[index] = orchid[i];
                }
        }
        int s = lis.size();
        printf("%d",n-s);
}
