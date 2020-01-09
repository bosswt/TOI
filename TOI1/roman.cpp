#include <iostream>
using namespace std;
int d,temp,counti,countv,countx,countl,countc;
int main()
{
        cin>>d;
        for(int i=d; i>0; i--)
        {
                temp = i;
                while(temp > 0)
                {
                        if(temp >= 100)
                        {
                                temp-=100;
                                countc++;
                        }
                        else if(temp >= 90)
                        {
                                temp-=90;
                                countc++;
                                countx++;
                        }
                        else if(temp >= 50)
                        {
                                temp-=50;
                                countl++;
                        }
                        else if(temp >= 40)
                        {
                                temp-=40;
                                countl++;
                                countx++;
                        }
                        else if(temp >= 10)
                        {
                                temp-=10;
                                countx++;
                        }
                        else if(temp == 9)
                        {
                                temp=0;
                                counti++;
                                countx++;
                        }
                        else if(temp >= 5)
                        {
                                temp-=5;
                                countv++;
                        }
                        else if(temp == 4)
                        {
                                temp=0;
                                counti++;
                                countv++;
                        }
                        else if(temp == 3)
                        {
                                temp=0;
                                counti+=3;
                        }
                        else if(temp == 2)
                        {
                                temp=0;
                                counti+=2;
                        }
                        else if(temp == 1)
                        {
                                temp=0;
                                counti++;
                        }
                }
        }
        cout<<counti<<" "<<countv<<" "<<countx<<" "<<countl<<" "<<countc;
}
