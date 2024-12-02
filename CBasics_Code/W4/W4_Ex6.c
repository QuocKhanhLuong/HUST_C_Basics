#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{   
    double a, b, c;
    if(argc != 4) {
        printf("Wrong number of arguments.\n");
        return 1;
    }  
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    if (a == 0) 
    {
        if (b == 0) 
        {
            if (c == 0) 
            {
                printf("Vo so nghiem.");
            } 
            else 
            {
                printf("Vo nghiem.");
            }
        
        }
        else
        {   
            double x = -b/c;
            printf("Phuong trinh co nghiem duy nhat: x = %lf", x);
        }
    }
    else
    {
        double delta = b*b - 4*a*c;
        if (delta >0) 
        {
            double x1 = (-b + sqrt(delta))/(2*a);
            double x2 = (-b - sqrt(delta))/(2*a);
            printf("Phuong trinh co 2 nghiem phan biet: %lf\n %lf", x1, x2);
        }
        else if (delta == 0)
        {
            double x = -b/(2*a);
            printf("Phuong trinh co nghiem kep: %lf", x);
        }
        else 
        {
            printf("Phuong trinh khong co nghiem thuc.");
        }
        
        {

        }
    }
}