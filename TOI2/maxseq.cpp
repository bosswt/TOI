#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
        int max_ending_here = 0,max_so_far = 0,n,start,last,s;
        cin>>n;
        int a[2501];
        for(int i=0; i<n; i++)
        {
                cin>>a[i];
                max_ending_here += a[i];
                if(max_ending_here < 0)
                {
                        max_ending_here = 0;
                        s = i+1;
                }
                else if(max_ending_here > max_so_far)
                {
                        max_so_far  = max_ending_here;
                        start = s;
                        last = i;
                }
        }
        if(max_so_far > 0)
        {
                for(int i=start; i<=last; i++)
                        cout<<a[i]<<" ";
                cout<<endl<<max_so_far;
        }
        else cout<<"Empty sequence";
}
