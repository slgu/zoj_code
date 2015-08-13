#include<iostream>  
#include<vector>  
#include<iterator>  
#include<numeric>  
using namespace std;  
const int INF = 9999999;  
int main()  
{  
    int keys,now,rows;  
    int time[501][501];  
    int flag[501];  
    int dist[501];  
    int from,to,i,j,start=1;  
    int min,max,end,t,endfrom,endto,flag1,pre;  
    while(cin>>keys>>rows && keys)  
    {  
        fill(flag,flag+501,0);  
        fill(dist,dist+501,INF);  
        for(i=1;i<=keys;i++)  
            for(j=1;j<=keys;j++)  
                time[i][j] = INF;         
        for(i=1;i<=rows;i++)  
        {  
            cin >> from >> to;  
            cin >> time[from][to];  
            time[to][from] = time[from][to];  
        }  
          
        now=1;dist[1]=0;flag[1]=1;  
        for(i=1;i<keys;i++)//dijkstra?????  
        {     
            for(j=1;j<=keys;j++)  
                if(flag[j] ==0 && dist[j] > dist[now] + time[now][j])  
                    dist[j] = dist[now] + time[now][j];  
            for(j=1,min=INF;j<=keys;j++)  
                if(dist[j] < min && flag[j] == 0)  
                {now=j;min=dist[j];}  
            flag[now]=1;  
        }  
          
        for(i=1,max=-1;i<=keys;i++)  
            if(dist[i]>max)   
                max=dist[end=i];//??????????  
        max*=2;    //*2????  
        for(i=1,flag1=0;i<=keys;i++)//???????????????????????????  
        {  
            for(j=1;j<=keys;j++)  
            {  
                if(dist[i] >= dist[j] &&time[i][j]<INF&& dist[j]+time[i][j]>dist[i])  
                {  
                     
                    t=dist[i]+dist[j]+time[i][j];  
                    if(t>max)  
                    {  
                        flag1=1;  
                        max=t;  
                        endfrom=i>j?j:i;  
                        endto=i>j?i:j;  
                    }  
                }  
                  
            }  
        }  
        
        cout<<"System #"<<start++<<endl;//c++???????  
        if(!flag1)   
            cout<<"The last domino falls after "<<max/2<<".0 seconds, at key domino "<<end<<".\n";  
        else  
        {      
            cout<<"The last domino falls after ";  
            max%2==0?cout<<max/2<<".0":cout<<max/2<<".5";  
            cout<<" seconds, between key dominoes "<<endfrom<<" and "<<endto<<".\n";  
        }  
        cout<<endl;  
          
    }  
    return 0;  
}  
