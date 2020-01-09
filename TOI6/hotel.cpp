#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;
int cost[1500001],ans=INT_MAX;
int main()
{
        int n;
        scanf("%d",&n);
        cost[0] = 0;
        for(int i=1; i<1500000; i++)
        {
                cost[i] = cost[i-1]+500;
                if(i-2>=0) cost[i] = min(cost[i],cost[i-2]+800);
                if(i-5>=0) cost[i] = min(cost[i],cost[i-5]+1500);
                if(i-15>=0) cost[i] = min(cost[i],cost[i-15]+3000);
        }
        for(int i=n; i<1500000; i++) ans = min(ans,cost[i]);
        printf("%d",ans);
}
