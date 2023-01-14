#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//³¬Ê±
//double Sqrt(double x)
//{
//    double m = 0;
//    for (double i = 1; i <= 100; i++)
//    {
//        if (x > i*i)
//        {
//            m = i;
//        }
//        else
//        {
//            break;
//        }
//    }
//    for (int i = 0; i < 10000; i++)
//    {
//        if ((m * m - x) > 0.000000)
//        {
//            return m;
//        }
//        m += 0.0001;
//    }
//    return m;
//}

double Sqrt(double x)
{
    double m = 1;
    while (m * m - x > 1e-9)
    {
        m = (m + x/m) / 2;
    }
    return m;
}

int main() 
{
    double a;
    int b;
    while (scanf("%lf %d", &a, &b) != EOF)
    {
        double sum = 0;
        for (int i = 0; i < b; i++)
        {
            sum += a;
            a = Sqrt(a);
        }
        printf("%.2f\n", sum);
    }

    return 0;
}