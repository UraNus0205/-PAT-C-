# 第二章 C/C++快速入门

## 一、数组

### 1.1 冒泡排序

```C++
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a[10]={0,1,2,3,7,8,9,4,5,6};
    int i,j;
    for(i=0;i<=8;i++)
    {
        int temp;
        for(j=0;j<9-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<=9;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
```

### 1.2 memset——对数组中每一个元素赋相同的值

格式：

```c
include <string.h>
memset (array,value,sizeof(array))
```

只建议赋值0或-1.

```c
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
    int a[5]={1,2,3,4,5};
    memset(a,0,sizeof(a));
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
```

### 1.3 sscanf与sprintf

格式：

```c
sscanf(str,"%d",&n);/*把str中的内容以%d的形式传给n*/
sprintf(str,"%d",n);/*把n中的内容以%d的形式传给str*/
```

```c
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
    printf("%d\n",n);
    sprintf(str2,"%d",n);
    printf("%s",str2);
    return 0;
}
```

