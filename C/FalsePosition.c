#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define F(x) (x)*(x)+(x)-2
int main()
{
    int s,count;
    float a,b,root;
    printf("Solution by False-position method\n Input starting values\n");
    scanf("%f %f",&a,&b);
    fal(&a,&b,&s,&root,&count);
    if(s==0)
        printf("Starting points do not bracket any root\n");
    else
        printf("Root=%f\n F(root)=%f\n Iterations=%d\n",root,F(root),count);
}
fal(float *a, float *b, int *s, float *root, int *count)
{
    float x1,x2,x0,f1,f2,f0;
    x1=*a;
    x2=*b;
    f1=F(x1);
    f2=F(x2);
    if(f1*f2 >0)
    {
        *s=0;
        return;
    }
    else
        printf("   \n        x1         x2\n");
    *count=1;
begin:
    x0= x1-f1*(x2-x1)/(f2-f1);
    f0=F(x0);
    if(f1*f2<0)
    {
        x2=x0;
        f2=f0;
    }
    else
    {
        x1=x0;
        f1=f0;
    }
    printf("%5d %15.6f %15.6f\n",*count,x1,x2);
    if(fabs(x2-x1)/x2<EPS)
    {
        *s=1;
        *root=(x1+x2)/2.0;
        return;
    }
    else
    {
        *count=*count+1;
        goto begin;
    }
}
