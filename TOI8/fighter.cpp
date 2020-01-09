#include <iostream>
using namespace std;
int odd_hp,even_hp,odd_combo,even_combo,p,k;
int main()
{
        cin>>p;
        odd_hp = p;
        even_hp = p;
        for(int i=0; i<2*p; i++)
        {
                cin>>k;
                if(k%2 == 0)
                {
                        odd_combo = 0;
                        even_combo++;
                        if(even_combo >= 3)
                                odd_hp-=3;
                        else odd_hp-=1;
                        if(odd_hp <= 0)
                        {
                                cout<<"0\n"<<k;
                                return 0;
                        }
                }
                else
                {
                        even_combo = 0;
                        odd_combo++;
                        if(odd_combo>=3)
                                even_hp-=3;
                        else even_hp-=1;
                        if(even_hp <= 0)
                        {
                                cout<<"1\n"<<k;
                                return 0;
                        }
                }
        }
}
