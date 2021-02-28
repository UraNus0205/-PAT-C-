#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct point {
    double x;
    double y;
};

int main()
{
    int n;
    point p[3];
    while (cin>>n)
    {
        if (n == 0) break;
        while (n--)
        {
            double sx = 0, sy = 0;
            for (int i = 0; i < 3; i++)
            {
                scanf("%lf%lf", &p[i].x, &p[i].y);
                sx += p[i].x;
                sy += p[i].y;
            }
            printf("%.1f %.1f\n", sx/3, sy/3);
        }
    }
    return 0;
}
