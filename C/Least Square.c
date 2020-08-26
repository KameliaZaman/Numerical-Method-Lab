#include<stdio.h>
#include<math.h>
#define EPS 0.000001
int main()
{
    int i,n;
    float x[10],y[10],sumx,sumy,sumxx,sumxy,xmean,ymean,denom,a,b;
    printf("Input number of data points,n\n");
    scanf("%d",&n);
    printf("Input x and y values\n One set on each line\n");
    for(i=1; i<=n; i++)
        scanf("%f %f",&x[i],&y[i]);
    sumx=0.0;
    sumy=0.0;
    sumxx=0.0;
    sumxy=0.0;
    for(i=1; i<=n; i++)
    {
        sumx=sumx+x[i];
        sumy=sumy+y[i];
        sumxx=sumxx+x[i]*x[i];
        sumxy=sumxy+x[i]*y[i];
    }
    xmean=sumx/n;
    ymean=sumy/n;
    denom=n*sumxx-sumx*sumx;
    if(fabs(denom)>EPS)
    {
        b=(n*sumxy-sumx*sumy)/denom;
        a=ymean-b*xmean;
        printf("Linear Regression Line y=a+bx\n The coefficients are:\n a=%f\n b=%f\n",a,b);
    }
    else
        printf("No solution\n");
    return 0;
}
