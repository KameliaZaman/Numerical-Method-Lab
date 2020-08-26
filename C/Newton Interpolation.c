#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j;
    float xp,fp,sum,pi,x[10],f[10],a[10],d[10][10];
    printf("Input the number of data points\n");
    scanf("%d",&n);
    printf("Input values of x and f(x),\n One set on each line\n");
    for(i=1; i<=n; i++)
        scanf("%f %f",&x[i],&f[i]);  /*Construct difference table   */
    for(i=1; i<=n; i++)
        d[i][1]=f[i];
    for(j=2; j<=n; j++)
        for(i=1; i<=n-j+1; i++)
            d[i][j]=(d[i+1][j-1]-d[i][j-1])/(x[i+j-1]-x[i]);  /*Set the coefficients of interpolation polynomial  */
    for(j=1; j<=n; j++)
        a[j]=d[1][j];   /*Compute interpolation value */
    printf("Input xp where interpolation is required\n");
    scanf("%f",&xp);
    sum=a[1];
    for(i=2; i<=n; i++)
    {
        pi=1.0;
        for(j=1; j<=i-1; j++)
            pi=pi*(xp-x[j]);
        sum=sum+a[i]*pi;
    }
    fp=sum;
    printf("Newton interpolation\n Interpolated value\n at x=%f is %f\n",xp,fp);
}
