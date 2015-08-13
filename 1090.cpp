#include<cstdio>
#include<cmath>
#define pi 3.141592653589793

double x[4],y[4];
double dis(double a,double b)
{
       return sqrt(a*a+b*b);
} 

int main()
{
    while(6==scanf("%lf%lf%lf%lf%lf%lf",&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]))
    {
          double a=dis(x[1]-x[2],y[1]-y[2]),b=dis(x[1]-x[3],y[1]-y[3]),c=dis(x[2]-x[3],y[2]-y[3]);
          double p=(a+b+c)/2;
          double s=sqrt(p*(p-a)*(p-b)*(p-c));
          double t=2*pi*a*b*c/4/s;
          printf("%.2f\n",t);                            
    }
    return 0;
}
