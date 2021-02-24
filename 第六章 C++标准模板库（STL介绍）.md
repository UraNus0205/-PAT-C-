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