#include "/Users/boss_wt/stdc++.h"
using namespace std;
int n,cat[2000001],sorting[2000001],latest,largest;
vector<int>cages;
bool put(int &s)
{
        int temp;
        bool searching=false;
        for(int i=0; i<n; i++)
        {
                if(s<cat[i])
                {
                        if(searching)
                        {
                                if(temp != cat[i]) return false;
                                else searching =false;
                        }
                        else temp=cat[i],searching=true;
                }
        }
        return true;
}
int main()
{
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
                scanf("%d",&cat[i]);
                sorting[i] = cat[i];
        }
        sort(sorting,sorting+n);
        cages.push_back(0);
        for(int i=0; i<n; i+=2)
                cages.push_back(sorting[i]);
        int l=0,r=cages.size()-1;
        while(l<r)
        {
                int mid = (l+r)/2;
                int cur_cage = cages[mid];
                if(put(cur_cage))
                        r = mid;
                else l=mid+1;
        }
        printf("%d",cages[r]);
}
