#include<iostream>

using namespace std;

int main()

{

       int n;

       cin>>n;

       for(int i=1;i<=n;i++)

       {

              float x,y;

              int k;

              cin>>x>>y;

              k=int(3.1416*(x*x+y*y)/100)+1;

              cout<<"Property "<<i<<": This property will begin eroding in year "<<k<<"."<<endl;

       }

       cout<<"END OF OUTPUT."<<endl;

       return 0;

}