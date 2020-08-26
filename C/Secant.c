#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define F(x) (x)*(x)+(x)-2
int main()
{
    int count,s;
    float a,b,root,x1,x2;
    printf("Solution by Secant method\n Input two starting points\n");
    scanf("%f %f",&a,&b);
    sec(&a,&b,&root,&count,&s);
    if(s==0)
        printf("Division by zero\n Last x1=%f\n Last x2=%f\n Iterations=%d\n",x1,x2,count);
    else
        printf("Root=%f\n Function value at root=%f\n Iterations=%d\n",root,F(root),count);
}
sec(float *a, float *b,float *root, int *count, int *s)
{
    float x3,f1,f2,x1,x2;
    x1=*a;
    x2=*b;
    f1=F(x1);
    f2=F(x2);
    *count=1;
begin:
    if(fabs(f1-f2)<= 1.E-10)
    {
        *s=0;
        return;
    }
    x3=x2-f2*(x2-x1)/(f2-f1);
    if(fabs((x3-x2)/x3)<EPS)
    {
        *root=x3;
        *s=1;
        return;
    }
    else
    {
        x1=x2;
        x2=x3;
        f1=f2;
        f2=F(x3);
        *count=*count+1;
        goto begin;
    }
}
