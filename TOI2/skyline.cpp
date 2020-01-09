#include <iostream>
#include <climits>
using namespace std;
int building[3001],last,start=INT_MAX;
int main()
{
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
                int l,h,r;
                cin>>l>>h>>r;
                if(r>last)
                        last = r;
                if(l<start)
                        start = l;
                for(int j=l; j<r; j++)
                        building[j] = max(building[j],h);
        }
        for(int i=start; i<=last; i++)
                if(building[i] != building[i-1]) cout<<i<<" "<<building[i]<<" ";
}
