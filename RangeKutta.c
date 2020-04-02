#include<stdio.h>
float func(float x,float y);
int main()
{
    float xn;
    //printf("Enter xn:"); 
    scanf("%f",&xn);  // xn will be taken from test cases

    //Use printf statement as:  printf("y=%f\n",y0); 
    int i;
    float h = 0.2, x0 = 0.3, y0 = 2.0, k1, k2, k3, k4;
    while(x0<xn)
    {
        k1 = func(x0, y0);
        k2 = func((x0 + 0.5*h), (y0 + 0.5*k1*h));
        k3 = func((x0 + 0.5*h), (y0 + 0.5*k2*h));
        k4 = func((x0 + h), (y0 + k3*h));

        y0 += (k1 + 2*k2 + 2*k3 + k4)*h/6.0;
        x0 += h;
    }
    printf("y=%f\n",y0); 
    return 0;
}
float func(float x,float y){
    return (x*(2*x + 1) - 3*y*y)/10.0;
}