#include <iostream>
using namespace std;
int nugget,flag[101],state;
int main()
{
        cin>>nugget;
        for(int i=0; i<nugget; i++)
        {
                for(int j=0; j<nugget; j++)
                {
                        for(int k=0; k<nugget; k++)
                        {
                                int sum = i*6+j*9+k*20;
                                if(sum<=nugget) flag[sum]=1;
                        }
                }
        }
        for(int i=1; i<=nugget; i++)
        {
                if(flag[i] == 1)
                {
                        cout<<i<<endl;
                        state = 1;
                }
        }
        if(!state) cout<<"no";
}
