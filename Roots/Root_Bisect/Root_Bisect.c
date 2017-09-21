// This file is for pointer training
// I'll try to use function pointer to
//find a ROOT for continuous function
// using bisection method in interval
// a, b start and end

long double  fun(double x);
float bisect(double,double,long double(*Ptr)(double),float);
#include <stdio.h>

int main(void)
{
    float root;
    float start = 1.0;
    float end = 2.0;
    float error = 0.0001;
    root = bisect(start,end,fun,error);
    printf("root found at %4.2f",root);
    return 0;
}


long double  fun(double x)
{
    return ((5*x*x)+3*x-14);

}
float bisect(double start,double end,long double(*Ptr)(double),float epslon)
{
    double new_point = (start+end)/2;
    long double Fofa, Fofc;
    char found = 0;

    do
    {
        Fofc = (*Ptr)(new_point);
        Fofa = (*Ptr)(start);
        //Fofb = (*Ptr)(end);
printf("Epslon = %0.5f",epslon);
        if(((Fofc>0)&& (Fofc<=epslon))|| ((Fofc<0)&&(Fofc>=-epslon)))
            found =1;
        else if ((Fofc * Fofa) < 0)
        {
            end = new_point;
            //start = start;
        }
        else
        {
            //end = new_point;
            start = new_point;
        }
                new_point = (start+end)/2;
    }
    while(found == 0);
        return new_point;
}
