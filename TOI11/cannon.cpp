#include <iostream>
#include <cstdio>
using namespace std;
int cannon[1000001],n,m,k,l,p;
int main()
{
        scanf("%d %d %d %d",&n,&m,&k,&l);
        for(int i=0; i<n; i++) scanf("%d",&cannon[i]);
        for(int i=0; i<k; i++)
        {
                int sum=0;
                int idx=0;
                for(int j=0; j<m; j++)
                {
                        scanf("%d",&p);
                        int left = max(0,p-l);
                        int right = min(9999999,p+l);
                        while(idx<n && cannon[idx] < left) idx++;
                        while(idx<n && cannon[idx] >= left && cannon[idx] <= right)
                        {
                                //printf("%d ",cannon[idx]);
                                idx++;
                                sum++;
                        }
                }
                printf("%d\n",sum);
        }
}
