#include <iostream>
using namespace std;
int cur[3],shift[3];
int encode(int num)
{
        for(int i=0; i<3; i++)
        {
                num = (((cur[i]+num-1))%9);
                if(num ==0) num=9;
        }
        cur[0] = (cur[0]+shift[0])%9;
        if(cur[0] == 0) cur[0] = 9;
        cur[1] = (cur[1]-1)%9;
        if(cur[1] == 0) cur[1] = 9;
        cur[2] = (cur[2]+shift[2])%9;
        if(cur[2] == 0) cur[2] = 9;
        return num;
}
int main()
{
        char n;
        string code;
        for(int i=0; i<3; i++)
        {
                cin>>n;
                cur[i] = n-'0';
                shift[i] = cur[i];
        }
        cin>>code;
        string res;
        int len=code.length();
        for(int i=0; i<len; i++)
        {
                cout<<encode(code[i]-'0');
        }
}
