#include <iostream>
#include <string>
#include <cmath>
using namespace std;
double x,y;
void compute(string num,string di)
{
        //cout<<num<<" "<<di<<endl;
        int n = stoi(num);
        if(di == "N")
                y+=n;
        else if(di == "NE")
        {
                x+=n*sqrt(2)/2;
                y+=n*sqrt(2)/2;
        }
        else if(di == "E")
                x+=n;
        else if(di == "SE")
        {
                x+=n*sqrt(2)/2;
                y-=n*sqrt(2)/2;
        }
        else if(di == "S")
                y-=n;
        else if(di == "SW")
        {
                x-=n*sqrt(2)/2;
                y-=n*sqrt(2)/2;
        }
        else if(di == "W")
                x-=n;
        else
        {
                x-=n*sqrt(2)/2;
                y+=n*sqrt(2)/2;
        }
        //cout<<"X : "<<x<<endl<<"Y : "<<y<<endl;
}
int main()
{
        string str;
        do {
                string num,di;
                cin>>str;
                for(int i=0; i<str.length(); i++)
                {
                        if(isdigit(str[i]))
                                num+=str[i];
                        else if(isalpha(str[i]))
                                di+=str[i];

                }
                if(str != "*")
                        compute(num,di);
        } while(str != "*");
        printf("%.3f %.3f\n",x,y);
        printf("%.3f",sqrt((x*x)+(y*y)));
}
// 3N 1E 1N 3E 2S 1W *
