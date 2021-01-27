# 第六章 C++标准模板库（STL介绍）

## 6.4 map的常用用法详解

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