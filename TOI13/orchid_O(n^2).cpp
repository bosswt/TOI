#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> height;
bool cmp(int &a,int &b)
{
        return a>b;
}
int main()
{
        int n,h;
        scanf("%d",&n);
        int lis[n];
        for(int i=0; i<n; i++) scanf("%d",&h),height.push_back(h),lis[i]=1;
        for(int i=1; i<n; i++)
        {
                for(int j=0; j<i; j++)
                {
                        if(height[j] <= height[i])
                                lis[i] = max(lis[i],lis[j]+1);
                }
        }
        // for(int i=0; i<n; i++)
        //         printf("%d ",lis[i]);
        sort(lis,lis+n,cmp);
        int s = height.size();
        printf("%d",s-lis[0]);
}
