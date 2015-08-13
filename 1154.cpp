#include<string>

  #include<iostream>

  

  using namespace std;

 

 int main()

 {

     int N,sum,m,i,base;

       string n;

    cin >> N;

     while(N--)

    {

  

         while((cin >> base) && base)

        {

             cin >> n;

             

             sum = 0, m = 0;

            for(i = 0; i < n.size(); i++)

             {

                sum += n[i] - '0';

                m = m * base + n[i] - '0';

             }

            

            cout << (m % sum == 0 ? "yes" : "no") << endl;

        }

        if(N)

            cout << endl;

     }

     return 0;

 }
