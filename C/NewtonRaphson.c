#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define F(x) (x)*(x)+(x)-2
#define FD(x) 2*(x)+1
int main()
{
    int count;
    float x0,xn,fx,fdx;
    printf("Input initial value of x\n");
    scanf("%f",&x0);
    printf("Solution by Newton-Raphson method\n");
    count=1;
begin:
    fx=F(x0);
    fdx=FD(x0);
    xn=x0-fx/fdx;
    if(fabs((xn-x0)/xn)<EPS)
        printf("Root=%f\n Function value=%f\n Number of iterations=%d\n",xn,F(xn),count);
    else
    {
        x0=xn;
        count=count+1;
        goto begin;
    }
}
