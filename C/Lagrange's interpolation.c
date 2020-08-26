#include<stdio.h>
#include<math.h>
#define MAX 10
int main()
{
    int n,i,j;
    float x[MAX],f[MAX],xp,fp,lf,sum;
    printf("Input number of data points, n\n");
    scanf("%d",&n);
    printf("Input data points x[i] and values f[i]\n (one in each line)\n");
    for(i=1;i<=n;i++)
        scanf("%f %f",&x[i],&f[i]);
    printf("Input x at which interpolation is required\n");
    scanf("%f",&xp);
    sum=0.0;
    for(i=1;i<=n;i++)
    {
        lf=1.0;
        for(j=1;j<=n;j++)
        {
            if(i!=j)
                lf=lf*(xp-x[j])/(x[i]-x[j]);
        }
        sum=sum+lf*f[i];
    }
    fp=sum;
    printf("Lagrangian interpolation\n Interpolated function value\n at x=%f is %f\n",xp,fp);
}
