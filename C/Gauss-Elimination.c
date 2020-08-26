#include<stdio.h>
int main()
{
    int s,n,i,j;
    float a[10][10],b[10],x[10];
    printf("Solution by simple Gauss method\n What is the size of the system(n)?\n");
    scanf("%d",&n);
    printf("Input coefficients a(i,j), row-wise,\n one row on each line.\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%f",&a[i][j]);
    printf("Input vector b\n");
    for(i=1; i<=n; i++)
        scanf("%f",&b[i]);
    gauss1(n,a,b,x,&s);
    if(s==0)
        printf("Singular matrix, reorder equations.\n");
    else
    {
        printf("Solution vector X\n");
        for(i=1; i<=n; i++)
            printf("%10.6f\n",x[i]);
    }
}
gauss1(int n, float a[10][10], float b[10], float x[10], int *s)
{
    int i,j,k;
    float piv,fac,sum;
    for(k=1; k<=n-1; k++)
    {
        piv=a[k][k];
        if(piv<0.000001)
        {
            *s=0;
            return;
        }
        *s=1;
        for(i=k+1; i<=n; i++)
        {
            fac=a[i][k]/piv;
            for(j=k+1; j<=n; j++)
                a[i][j]=a[i][j]-fac*a[k][j];
            b[i]=b[i]-fac*b[k];
        }
    }
    /*-----------Back substitution begins------------*/
    x[n]=b[n]/a[n][n];
    for(k=n-1; k>=1; k--)
    {
        sum=0.0;
        for(j=k+1; j<=n; j++)
            sum=sum+a[k][j]*x[j];
        x[k]=(b[k]-sum)/a[k][k];
    }
    return;
}
