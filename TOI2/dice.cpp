#include <iostream>
#include <vector>
using namespace std;
int main()
{
        int n;
        string cmd;
        cin>>n;
        vector<int>sol;
        for(int i=0; i<n; i++)
        {
                int iT = 1,iF = 2,iL = 3,iB = 5,iR = 4,iBT = 6;
                cin>>cmd;
                for(int j=0; j<cmd.length(); j++)
                {
                        int T,F,L,B,R,BT;
                        switch(cmd[j])
                        {
                        case 'F':
                                T=iB;
                                F = iT;
                                L = iL;
                                B = iBT;
                                R = iR;
                                BT = iF;
                                iT = T;
                                iF = F;
                                iL = L;
                                iB = B;
                                iR =R;
                                iBT = BT;
                                break;
                        case 'B':
                                T = iF;
                                F = iBT;
                                L = iL;
                                B = iT;
                                R = iR;
                                BT = iB;
                                iT = T;
                                iF = F;
                                iL = L;
                                iB = B;
                                iR =R;
                                iBT = BT;
                                break;
                        case 'L':
                                T = iR;
                                F = iF;
                                L = iT;
                                B = iB;
                                R = iBT;
                                BT = iL;
                                iT = T;
                                iF = F;
                                iL = L;
                                iB = B;
                                iR =R;
                                iBT = BT;
                                break;
                        case 'R':
                                T = iL;
                                F = iF;
                                L = iBT;
                                B = iB;
                                R = iT;
                                BT = iR;
                                iT = T;
                                iF = F;
                                iL = L;
                                iB = B;
                                iR =R;
                                iBT = BT;
                                break;
                        case 'C':
                                T = iT;
                                F = iR;
                                L = iF;
                                B = iL;
                                R = iB;
                                BT = iBT;
                                iT = T;
                                iF = F;
                                iL = L;
                                iB = B;
                                iR =R;
                                iBT = BT;
                                break;
                        case 'D':
                                T = iT;
                                F = iL;
                                L = iB;
                                B = iR;
                                R = iF;
                                BT = iBT;
                                iT = T;
                                iF = F;
                                iL = L;
                                iB = B;
                                iR =R;
                                iBT = BT;
                                break;
                        default: cout<<"Error!";
                                break;
                        }
                }
                //  cout<<iT<<" "<<iF<<" "<<iL<<" "<<iB<<" "<<iR<<" "<<iBT<<endl;
                sol.push_back(iF);
        }
        for(auto i = sol.cbegin(); i!=sol.cend(); i++)
                cout<<*i<<" ";
}
