#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 100
int main()
{
    int i,j,n,count,s;
    float a[10][10],b[10],x[10];
    printf("Solution by Jacobi iteration\n What is the size n of the system?\n");
    scanf("%d",&n);
    printf("Input coefficients a[i,j],row by row\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%f",&a[i][j]);
    printf("Input vector b\n");
    for(i=1; i<=n; i++)
        scanf("%f",&b[i]);
    Jacobi(n,a,b,x,&count,&s);
    if(s==0)
        printf("No convergence in %d iterations\n",MAXIT);
    else
    {
        printf("\n           Solution vector X\n\n");
        for(i=1; i<=n; i++)
            printf("%15.6f",x[i]);
        printf("\nIterations=%d",count);
    }
}
Jacobi(int n, float a[10][10], float b[10],float x[10],int *count, int *s)
{
    int i,j,k;
    float sum,x0[10];
    for(i=1; i<=n; i++)
        x0[i]=b[i]/a[i][i];
    *count=1;
begin:
    k=0;
    for(i=1; i<=n; i++)
    {
        sum=b[i];
        for(j=1; j<=n; j++)
        {
            if(i==j)
                continue;
            sum=sum-a[i][j]*x0[j];
        }
        x[i]=sum/a[i][i];
        if(k==0)
        {
            if(fabs((x[i]-x0[i])/x[i])>EPS)
                k=1;
        }
    }
    if(k==1)
    {
        if(*count==MAXIT)
        {
            *s=0;
            return;
        }
        else
        {
            *s=1;
            for(i=1; i<=n; i++)
                x0[i]=x[i];
        }
        *count=*count+1;
        goto begin;
    }
    return;
}
