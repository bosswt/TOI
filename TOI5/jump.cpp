#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>dist;
int far=-1;
int main()
{
        int n,k,dis;
        scanf("%d %d",&n,&k);
        for(int i=0; i<n; i++) scanf("%d",&dis),dist.push_back(dis);
        for(int i=0; i<n; i++)
        {
                int jump,num;
                vector<int>::iterator it;
                jump = dist[i]+k;
                it=upper_bound(dist.begin()+i,dist.end(),jump);
                it--;
                num = distance(dist.begin()+i,it);
                if(num > far)
                        far = num;
                // printf("%d %d %d\n",jump,num,*it);
        }
        printf("%d",far);
}
