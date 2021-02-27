# 第六章 C++标准模板库（STL介绍）



## 6.1 vector的常见用法详解

vector即“变长数组”。

### 1.vector的定义

单独定义一个vector：

```C++
vector<typename> name;
```

下面是一些简单的例子：

```C++ 
vector<int> name;
vector<double> name;
vector<char> name;
vector<node> name;
vector<vector<int> > name;
```

### 2.vector容器内元素的访问

#### （1）通过下标访问

对一个定义为`vector<typename> vi`的vector容器，直接访问`vi[index]`即可。 

#### （2）通过迭代器访问

迭代器（iterator）可以理解为一种类似指针的东西，其定义为：

```C++
vector<typename>::iterator it;
```

这样就得到了迭代器`it`，并且可以通过`*it`来访问vector里的元素。

例如有这样的一个vector容器：

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    //vi.begin()为取vi的首元素地址，而it指向这个地址。
    vector<int>::iterator it = vi.begin();
    for (int i = 0; i < 5; i++)
    {
        cout << *(it + i);//输出vi[i]
    }
    return 0;
}
```

输出结果：

```c++
1 2 3 4 5
```

从这里可以看出`vi[i]`和`*(vi.begin()+i)`是等价的。

上面说到了`begin()`函数的作用为取`vi`的首元素地址，那么这里还要提到`end()`函数。`end()`不是取`vi`的尾元素地址，而是**取尾元素地址的下一个地址**。`end()`作为迭代器末尾标志，不存储任何元素。

除此之外，迭代器还实现了两种自加操作：`++it`和`it++`,于是有了另一种遍历`vector`中元素的写法：

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    //vector的迭代器不支持it<vi.end()的写法，因此循环条件只能用it!=vi.end()
    vector<int>::iterator it = vi.begin();
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        cout << *it;
    }
    return 0;
}
```

输出结果：

```c++
1 2 3 4 5
```

在常用STL容器中，只有在vector和string中，才允许使用`vi.begin()+3`这种迭代器加上整数的写法。

### 3.vector常用函数实例解析

#### （1）clear()

`clear()`用来清空vector中的所有元素，时间复杂度为`O(N)`.

示例如下：

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    //vector的迭代器不支持it<vi.end()的写法，因此循环条件只能用it!=vi.end()
    vi.clear();
    cout << vi.size();
    return 0;
}
```

输出结果：

```C++
0
```

#### （2）insert()

`insert(it,x)`用来向vector的任意迭代器it处插入一个元素x,时间复杂度为`O(N)`.

示例如下：

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    //vector的迭代器不支持it<vi.end()的写法，因此循环条件只能用it!=vi.end()
    vi.insert(vi.begin() + 2, -1);
    for (int i = 0; i < vi.size(); i++)
    {
        cout << vi[i];
    }
    return 0;
}
```

输出结果：

```C++
1 2 -1 3 4 5
```

#### （3）erase()

`erase()`有两种用：删除单个元素、删除一个区间内的所有元素，时间复杂度为`O(N)`.

##### ①删除单个元素：

`erase(it)`即删除迭代器为it处的元素。

示例如下：

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    //vector的迭代器不支持it<vi.end()的写法，因此循环条件只能用it!=vi.end()
    vi.erase(vi.begin() + 2);
    for (int i = 0; i < vi.size(); i++)
    {
        cout << vi[i];
    }
    return 0;
}
```

输出结果：

```C++
1 2 4 5
```

##### ②删除一个区间内的所有元素：

`erase(first,last)`即删除`[first,last)`内的所有元素。

示例如下：

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }
    //vector的迭代器不支持it<vi.end()的写法，因此循环条件只能用it!=vi.end()
    vi.erase(vi.begin() + 2,vi.end());
    for (int i = 0; i < vi.size(); i++)
    {
        cout << vi[i];
    }
    return 0;
}
```

输出结果：

```C++
1 2
```

## 6.2  set的常见用法详解

### 1.set的定义

单独定义一个`set`：

```C++
set<typename> name;

set<int> name;
set<double> name;
set<char> name;
set<int> a[100];
```

### 2.set容器内元素的访问

`set`只能通过迭代器(iterator)访问：

```C++
set<typename>::iterator it;
```

这样就得到了迭代器`it`，并且可以通过`*it`来访问`set`里的元素。

由于**除了`vector`和`string`之外的STL容器都不支持`*(it+i)`的访问方式**，因此只能按如下方式枚举：

```C++
#include <iostream>
#include <set>

using namespace std;


int main()
{
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << *it;
    }
    return 0;
}
```

输出结果：

```C++
2 3 5
```

可以发现，`set`内的元素自动递增排序，且自动去重。

### 3.set常用函数实例解析

#### (1)insert()

`insert(x)`可以将x插入set容器中，且自动递增排序并去重，时间复杂度为`O(logN)`.

#### (2)find()

`find(value)`返回set中对应值为value的迭代器，时间复杂度为`O(logN)`.

```C++
#include <iostream>
#include <set>

using namespace std;


int main()
{
    set<int> st;
    for (int i = 3; i <= 5; i++)
    {
        st.insert(i);
    }
    set<int>::iterator it = st.find(4);
    cout << *it;
    return 0;
}
```

输出结果：

```C++
4
```

#### (3)erase()

##### ①删除单个元素

删除单个元素有两种方法：

+ `st.erase(it)`,it为所需要删除元素的迭代器。时间复杂度为`O(1)`.示例如下：

  ```C++
  #include <iostream>
  #include <set>
  
  using namespace std;
  
  
  int main()
  {
      set<int> st;
      for (int i = 3; i <= 5; i++)
      {
          st.insert(i);
      }
      st.erase(st.find(4));
      for (set<int>::iterator it = st.begin(); it != st.end(); it++)
      {
          cout << *it;
      }
      return 0;
  }
  ```

  输出结果：

  ```C++
  3 5
  ```

+ `st.erase(value)`,value为所需要删除元素的值。时间复杂度为O(logN).示例如下：

  ```C++
  #include <iostream>
  #include <set>
  
  using namespace std;
  
  
  int main()
  {
      set<int> st;
      for (int i = 3; i <= 5; i++)
      {
          st.insert(i);
      }
      st.erase(4);
      for (set<int>::iterator it = st.begin(); it != st.end(); it++)
      {
          cout << *it;
      }
      return 0;
  }
  ```

  输出结果：

  ```C++
  3 5
  ```

##### ②删除一个区间内的所有元素

`st.erase(first,last)`可以删除一个区间内的所有元素，其中first为删除所需要删除区间的起始迭代器，而last则为所需要删除区间的末尾迭代器的**下一个**地址，即删除`[first,last)`。时间复杂度为`O(last-first)`.示例如下：

```C++
#include <iostream>
#include <set>

using namespace std;


int main()
{
    set<int> st;
    for (int i = 3; i <= 10; i++)
    {
        st.insert(i);
    }
    set<int>::iterator it = st.find(5);
    st.erase(it,st.end());
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << *it;
    }
    return 0;
}
```

输出结果：

```C++
3 4
```

#### (4)size()

`size()`用来获得set内元素的个数，时间复杂度为`O(1)`.示例如下：

```C++
#include <iostream>
#include <set>

using namespace std;


int main()
{
    set<int> st;
    for (int i = 3; i <= 10; i++)
    {
        st.insert(i);
    }
    set<int>::iterator it = st.find(5);
    cout << st.size();
    return 0;
}
```

输出结果：

```C++
8
```

#### (5)clear()

`clear()`用来清空set中的所有元素，时间复杂度为`O(N)`.示例如下：

```C++
#include <iostream>
#include <set>

using namespace std;


int main()
{
    set<int> st;
    for (int i = 3; i <= 10; i++)
    {
        st.insert(i);
    }
    st.clear();
    cout << st.size();
    return 0;
}
```

输出结果：

```C++
0
```

## 6.3 string的常见用法详解

### 1.string的定义

定义`string`的方式跟基本数据类型相同，只需要在`string`后跟上变量名即可：

```C++
string str = "abcd";
```

### 2.string中内容的访问

#### (1)通过下标访问

一般可以直接像字符数组那样去访问`string`：

```C++
#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str = "abcd";
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
    return 0;
}
```

输出结果：

```C++
abcd
```

如果要是如何输出整个字符串，只能用`cin`和`cout`:

```C++
#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str;
    cin >> str;
    cout << str;
    return 0;
}
```

也可以使用`printf`来输出`string`，即用`c_str()`将`string`类型转换为字符数组进行输出，示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str = "abcd";
    printf("%s\n", str.c_str());
    return 0;
}
```

输出结果：

```C++
abcd
```

#### (2)通过迭代器访问

一般仅通过（1）即可满足访问的要求，但是有些函数比如`insert()`和`erase()`则要求以迭代器为参数。

由于`string`不像其他STL容器那样需要参数，因此可以直接如下定义：

```C++
string::iterator it
```

这样就得到了迭代器`it`，并且可以通过`*it`来访问`string`里的每一位：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str = "abcd";
    string::iterator it;
    for(it=str.begin();it!=str.end();it++)
    {
        cout << *it;
    }
    return 0;
}
```

输出结果：

```C++
abcd
```

最后指出，**`string`和`vector`一样，支持直接对迭代器进行加减某个数字，如str.begin()+3的写法是可行的。**

### 3.string常用函数实例解析

#### (1)operator+=

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str1 = "abc", str2 = "xyz", str3;
    str3 = str1 + str2;
    str1 += str2;
    cout << str1 << endl;
    cout << str3 << endl;
    return 0;
}
```

输出结果：

```C++
abcxyz
abcxyz
```

#### (2)compare operator

两个`string`类型可以直接使用==、！=、<、>、<=、>=比较大小，比较规则是字典序。

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str1 = "aa", str2 = "aaa", str3 = "abc", str4 = "xyz";
    if (str1 < str2) cout << "str1 < str2" <<endl;
    if (str1 != str3) cout << "str1 != str3" << endl;
    if (str4 >= str3) cout << "str4 >= str3" << endl;
    return 0;
}
```

输出结果：

```C++
str1 < str2
str1 != str3
str4 >= str3
```

#### (3)length()/size()

实例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str1 = "abcxyz";
    cout << str1.length() << " " << str1.size();
    return 0;
}
```

输出结果：

```C++
6 6
```

#### (4)insert()

`string`的`insert()`函数有多种写法，这里给出常用的写法，时间复杂度为`O(N)`.

##### ①insert(pos,string),在pos号位置插入字符串string。

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str1 = "abcxyz", str2 = "opq";
    cout << str1.insert(3,str2);
    return 0;
}
```

输出结果：

```C++
abcopqxyz
```

##### ②insert(it,it2,it3),it为原字符串的欲插入位置，it2和it3为待插字符串的首尾迭代器，用来标志串[it2,it3)将被插在it的位置上。

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str1 = "abcxyz", str2 = "opq";
    str1.insert(str1.begin() + 3, str2.begin(), str2.end() - 1);
    cout << str1;
    return 0;
}
```

输出结果：

```C++
abcopxyz
```

#### (5)erase()

以下两种用法的时间复杂度均为`O(N)`.

##### ①删除单个元素

`str.erase(it)`用于删除单个元素，`it`为需要删除的元素的迭代器。

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str = "abcdefg";
    str.erase(str.begin() + 4);
    cout << str;
    return 0;
}
```

输出结果：

```C++
abcdfg
```

##### ②删除一个区间内的所有元素

删除一个区间内的所有元素有两种方法：

+ `str.erase(first,last)`,即删除`[first,last)`.

  示例如下：

  ```C++
  #include <iostream>
  #include <string>
  #include <stdio.h>
  using namespace std;
  
  
  int main()
  {
      string str = "abcdefg";
      str.erase(str.begin() + 4,str.end()-1);
      cout << str;
      return 0;
  }
  ```

  输出结果：

  ```C++
  abcdg
  ```

+ `str.erase(pos,length)`，其中pos为需要开始删除的起始位置，length为删除的字符个数。

  示例如下：

  ```C++
  #include <iostream>
  #include <string>
  #include <stdio.h>
  using namespace std;
  
  
  int main()
  {
      string str = "abcdefg";
      str.erase(4, 2);
      cout << str;
      return 0;
  }
  ```

  输出结果：

  ```C++
  abcdg
  ```

#### (6)clear()

`clear()`用以清空string中的数据，时间复杂度一般为`O(1)`.

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str = "abcdefg";
    str.clear();
    cout << str.size();
    return 0;
}
```

输出结果：

```C++
0
```

#### (7)substr()

`substr(pos,len)`返回从pos号位开始、长度为len的子串，时间复杂度为`O(N)`.

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str = "abcdefg";
    cout << str.substr(4,2);
    return 0;
}
```

输出结果：

```C++
ef
```

#### (8)string::npos

`string::npos`是一个常数，其本身的值是-1，但由于是`unsigned_int`类型，因此也可以认为是`unsigned_int`类型的最大值。`string::npos`用以作为`find`函数失配时的返回值。

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str = "This is an apple.";
    int pos = 0, x;
    while ((x=str.find(" ",pos)) != string::npos)
    {
        cout << x << endl;
        pos = x + 1;
    }
    return 0;
}
```

输出结果：

```C++
4
7
10
```

#### (9)find()

`str.find(str2)`,当`str2`时`str`的子串时，返回其在`str`中第一次出现的位置；如果`str2`不是`str`的子串，那么返回`string::npos`.

`str.find(str2,pos)`,从`str`的`pos`号位开始匹配`str2`，返回值与上相同。

时间复杂度为`O(nm)`,n和m分别为`str`和`str2`的长度。

#### (10)replace()

`str.replace(pos,len,str2)`把`str`从`pos`号位开始、长度为`len`的子串替换为`str2`.

`str.replace(it1,it2,str2)`把`str`的迭代器`[it1,it2)`范围的子串替换为`str2`.

时间复杂度为`O(str.length())`.

示例如下：

```C++
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    string str1 = "This is an apple.";
    string str2 = "This is an apple.";
    cout << str1.replace(2, 7, " ") << endl;
    cout << str2.replace(str2.begin(), str2.end() - 4, " ") << endl;
    return 0;
}
```

输出结果：

```C++
Th n apple.
 ple.
```



## 6.4 map的常见用法详解

### 1.map的定义

单独定义一个map：

```C++
#include<map>
map<typename1,typename2> mp;
```

如果是字符串到整型的映射，必须使用string而不能使用char数组：

```c++
map<string,int> mp;
```

### 2.map容器内元素的访问

#### （1）通过下标访问

对一个定义为`map<char,int> mp`的map来说，可以直接使用`mp['c']`的方式访问它对应的整数。要注意，**map中的键值是唯一的**，也就是说，下面的代码将会输出30：

```c++
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

int main(){
	map<char,int> mp;
	mp['c']=20;
	mp['c']=30;
	cout<<mp['c']<<endl;
	return 0;
}
```

#### （2）通过迭代器访问

map迭代器的定义和其他STL容器迭代器定义的方式相同：

```C++
map<typename1,typename2> ::iterator it;
```

map可以通过使用`it->first`来访问键，使用`it->second`来访问值。

```C++
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

int main(){
	map<char,int> mp;
	mp['m']=20;
	mp['r']=30;
	mp['a']=40;
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
```

结果为：

```C++
 a 40
 m 20
 r 30
```

会发现**map会以键从小到大的顺序自动排序**，这是由于map内部是以红黑树实现的，建立映射时会自动实现从小到大的排序功能。

### 3.map常用函数实例解析

#### （1）find()

`find(key)`返回键为key的映射的迭代器，时间复杂度为`O(logN)`,N为map中映射的个数。

```c++
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

int main() {
	map<char, int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	map<char, int>::iterator it = mp.find('b');
	cout << it->first << " " << it->second << endl;
	return 0;
}
```

输出结果：

```C++
b 2
```

#### （2）erase()

`erase()`有两种用法：删除单个元素、删除一个区间内的所有元素。

①删除单个元素

删除单个元素有两种方法：

- `mp.erase(it)`,it为需要删除的元素的迭代器，时间复杂度为`O(1)`

  ```c++
  #include<cstdio>
  #include<map>
  #include<iostream>
  using namespace std;
  
  int main() {
  	map<char, int> mp;
  	mp['a'] = 1;
  	mp['b'] = 2;
  	mp['c'] = 3;
  	map<char, int>::iterator it = mp.find('b');
  	mp.erase(it);
  	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
  	{
  		cout << it->first << " " << it->second << endl;
  	}
  	return 0;
  }
  ```

  输出结果：

  ```C++
  a 1
  c 3
  ```

- `mp.erase(key)`,key为欲删除的映射的键。时间复杂度为`O(logN)`,N为map内元素的个数。

  ```C++
  #include<cstdio>
  #include<map>
  #include<iostream>
  using namespace std;
  
  int main() {
  	map<char, int> mp;
  	mp['a'] = 1;
  	mp['b'] = 2;
  	mp['c'] = 3;
  	mp.erase('b');
  	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
  	{
  		cout << it->first << " " << it->second << endl;
  	}
  	return 0;
  }
  ```

  输出结果：

  ```C++
  a 1
  c 3
  ```

  ②删除一个区间内的所有元素

  `mp.erase(first,last)`,其中first为需要删除的区间的起始迭代器，而last则为需要删除的区间的末尾迭代器的**下一个地址**，即左闭右开区间`[first,last)`.时间复杂度为O(last-first)。

  ```C++
  #include<cstdio>
  #include<map>
  #include<iostream>
  using namespace std;
  
  int main() {
  	map<char, int> mp;
  	mp['a'] = 1;
  	mp['b'] = 2;
  	mp['c'] = 3;
  	map<char, int>::iterator it = mp.find('b');
  	mp.erase(it,mp.end());
  	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
  	{
  		cout << it->first << " " << it->second << endl;
  	}
  	return 0;
  }
  ```

  输出结果：

  ```C++
  a 1
  ```

#### （3）size()

`size()`用来获得map中映射的对数，时间复杂度为`O(1)`。

```C++
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

int main() {
	map<char, int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	cout << mp.size() << endl;
	return 0;
}
```

输出结果：

```C++
3
```

#### （4）clear()

`clear()`用来清空map中的所有元素，时间复杂度为O(N),其中N为map中元素的个数。

```C++
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;

int main() {
	map<char, int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	mp.clear();
	cout << mp.size() << endl;
	return 0;
}
```

输出结果：

```C++
0
```

### 4.map的常见用途

①需要建立字符（或字符串）与整数之间映射的题目，使用map可以减少代码量。

②判断大整数或其他类型数据是否存在的题目，可以把map当做bool数组用。

③字符和字符串的映射也可能会用到。

PS：map的键和值是唯一的，若一个键对应多个值，就只能使用multimap。 

## 6.5 queue的常见用法详解

queue翻译为队列，在STL中主要则是实现了一个先进先出的容器。

### 1.queue的定义

```C++
#include <queue>
queue <typename> name;
```

### 2.queue容器内元素的访问

由于queue本身就是一种先进先出的限制性数据结构，因此在STL中只能通过`front()`来访问队首元素，或是通过`back()`来访问队尾元素。

示例如下：

```C++
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }
    cout << q.front() << q.back();
    return 0;
}
```

输出结果：

```C++
1 5
```

### 3.queue常用函数实例解析

#### (1)push()

`push(x)`将`x`进行入队，时间复杂度为`O(1)`.

#### (2)front()、back()

`front()、back()`可分别获得队首元素和队尾元素，时间复杂度为`O(1)`.

#### (3)pop()

`pop()`令队首元素出队，时间复杂度为`O(1)`.

示例如下：

```C++
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }
    for (int i = 1; i <= 3; i++)
    {
        q.pop();
    }
    cout << q.front() ;
    return 0;
}
```

输出结果：

```C++
4
```

#### (4)empty()

`empty()`检测`queue`是否为空，返回`true`则空，返回`false`则非空，时间复杂度为`O(1)`.

示例如下：

```C++
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }
    for (int i = 1; i <= 4; i++)
    {
        q.pop();
    }
    cout << q.empty() << endl;
    q.pop();
    cout << q.empty() << endl;
    return 0;
}
```

输出结果：

```C++
0
1
```

#### (5)size()

`size()`返回`queue`内元素的个数，时间复杂度为`O(1)`.

### 4.queue的常见用途

当需要实现广度优先搜索时，可以不用自己手动实现一个队列，而是用`queue`作为代替，以提高程序的准确性。

使用`front()`和`back()`函数前，必须用`empty()`判断队列是否为空，以免因队空出现错误。

## 6.6 priority_queue的常见用法详解

priority_queue又称为优先队列，其底层使用堆进行实现的。在优先队列中，队首元素一定是当前队列中优先级最高的那一个。

### 1.priority_queue的定义

```c++
#include<queue>

priority<typename> name;
```

### 2.priority_queue容器内元素的访问

和队列不同的是，优先队列`front()`函数和`back()`函数,而只能通过`top()`函数来访问队首元素。

示例如下：

```C++
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(4);
    q.push(5);
    q.push(3);
    cout << q.top();
    return 0;
}
```

输出结果：

```C++
5
```

### 3.priority_queue常用函数实例解析

#### (1)push()

`push(x)`令`x`入队，时间复杂度为`O(logN)`.

#### (2)top()

`top()`返回队首元素，时间复杂度为`O(1)`.

#### (3)pop()

`pop()`令队首元素出队，时间复杂度为`O(logN)`.

#### (4)empty()

`empty()`检测优先队列是否为空，时间复杂度为`O(1)`.

#### (5)size()

`size()`返回优先队列内元素的个数，时间复杂度为`O(1)`.

### 4.priority_queue内元素优先级的设置

#### (1)基本数据类型的优先级设置

对基本数据类型来说，以下两种优先队列的定义是等价的：

```C++
priority_queue<int> q;
priority_queue<int,vector<int>,less<int> > q;
```

`less<int>`表示数字大的优先级越大；`greater<int>`表示数字小的优先级越大。

#### (2)结构体的优先级设置

本节最开头举了一个水果的例子，可以对水果的名称和价格建立一个结构体，如下所示：

```c++
struct fruit{
	string name;
	int price;
};
```

现在希望按水果的价格高的为优先级高，就需要重载小于号“<”。

```C++
struct fruit{
	string name;
	int price;
	friend bool operator <(fruit f1,fruit f2)
	{
		return f1.price<f2.price;
	}
};

priority_queue<fruit> q;
```