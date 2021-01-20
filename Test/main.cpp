#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
    char str1[20]="12345";
    char str2[20]="";
    int n;
    sscanf(str1,"%d",&n);
    printf("%d",n);
    sprintf(str2,"%d",n);
    printf("%s",str2);
    return 0;
}
