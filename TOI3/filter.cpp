#include <iostream>
#include <cstring>
using namespace std;
int main()
{
        int w,h,n,x,a;
        int fifty = 0,zero = 0;
        cin>>w>>h>>n;
        int f[w];
        memset(f,0,sizeof(f));
        for(int i=0; i<n; i++)
        {
                cin>>x>>a;
                for(int i=x; i<x+a; i++)
                        if(i<=w)
                                f[i]+=50;
        }
        for(int i=0; i<w; i++)
        {
                if(f[i] == 50)
                        fifty++;
                else if(f[i] == 0)
                        zero++;
        }
        cout<<zero*h<<" "<<fifty*h;
}
