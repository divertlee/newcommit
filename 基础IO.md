# 基础IO

对电脑上的文件的理解：

<font size=5 color="red"> **1.文件=内容+属性，空文件也要在磁盘占空间**</font>

<font size=5 color="red"> **2.文件路径+文件名标识文件唯一性**</font>

<font size=5 color="red"> **3.对文件的操作即是对内容、属性的操作**</font>

<font size=5 color="red"> **4.如果没有指定文件路径，默认在当前路径进行文件访问**</font>

写代码时，运用各种文件函数接口对文件操作后，编译后形成二进制文件而没有运行时，对文件的操作没有被执行，那么<font size=4 color="green"> **代码对文件的操作，本质上是进程对文件的操作**</font>

**而文件有被打开文件和未被打开文件之分，访问文件的前提是打开文件，所以对文件进行操作，是进程对被打开文件进行操作！**

## 回顾c语言的文件操作函数

回顾c语言学过的文件操作，操作文件首先要打开文件—要有个文件指针按相应方式打开

| **w**  | **按读方式打开文件，文件不存在则报错；**                     |
| ------ | :----------------------------------------------------------- |
| **r**  | **按写方式打开文件，文件不存在则创建；若只打开文件然后关闭文件则清空文件内容** |
| **w+** | **按读写方式打开文件，文件不存在则报错**                     |
| **r+** | **按读写方式打开文件，文件不存在则创建，若只打开文件然后关闭文件则清空文件内容** |
| **a**  | **追加文本方式打开文件**                                     |

```cpp
  1 #include<stdio.h>
  2 #include<unistd.h>
  3 #include<string.h>
  4 #define FILE_NAME "gout.c"
  5 int main()
  6 {
  7  // FILE* fp=fopen(FILE_NAME,"w");//写方式打开
  8   FILE* fp=fopen(FILE_NAME,"r");//读方式打开
  9  if(NULL==fp)
 10  {
 11    perror("fopen fail!\n ");
 12    return 1;
 13  }
 14 
 15 char buff[64];
 16 while(fgets(buff,sizeof(buff)-1,fp)!=NULL)//把后者按规定大小读到前者里
 17 {
 18   buff[strlen(buff)-1]=0;//去掉自带的/n
 19   puts(buff);//按行打印
 20 }
 21 
 22 //int num=5;
 23 //while(num)
 24 //{fprintf(fp,"%s:%d\n","hello bug",num--);//fprintf-把后者按照规定方式写入.  25 //}
 26                                                                              
 26 
 27  fclose(fp);
 28 } 
```

除c语言外，其他语言也都有文件操作的函数，这些语言文件操作的库函数都是在操作系统系统调用文件操作函数之上包装的，所以下面来谈论操作系统的系统调用文件操作函数接口。

## 操作系统的文件操作函数

### open—打开文件

open的第二个函数的第一个参数是文件，第二个参数是int flags（标记）—**以32个比特位传递选项，那么这些选项就不能重复。选项可以是O_RDONLY(只读)，O_WRONLY(只写)，O_RDWR(读写)**，O_CREAT（创建文件），**O_TRUNC—覆盖原先文件内容，O_APPEND—追加内容**，第三个文件是权限

<font size=4 color="red">**返回值是文件描述符**</font>

![image-20230124213916020](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242139271.png)

至于这32个比特怎么传递选项的呢？这里我用简单的方式呈现，通过宏定义一些参数，然后传递一些int参数即可知道要什么选项了，且**标志位既有唯一性**

![image-20230124220436848](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242204761.png)

如果没有文件，底层的open函数是只读或只写的话，是不会创建文件的，需要传创建文件的标识符并且传入权限才能创建正常的文件

![image-20230124222810680](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242228192.png)

如果不想要系统规定的权限—664，可以在子进程就传入想要的掩码来改变文件的权限

![image-20230124223110923](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242231345.png)

![image-20230124223332234](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242233186.png)

并且这里传的掩码是改的子进程的掩码，不会影响父进程

### write—写入文件

**第一个参数是文件，第二个参数是要写入的内容，第三个参数是有效内容的大小**

![image-20230124224726753](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242247706.png)

如果没有传O_TRUNC参数的话，可能在原先的内容上再写入会出问题！

![image-20230124225534137](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242255229.png)

![image-20230124230651737](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242306640.png)

### read—读文件内容

**第一个参数是要读文件，第二个参数是读取到的文件类型和位置，第三个参数的内容大小，返回值是读取到的文件大小，单位是字节个数**

![image-20230124230814272](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242308066.png)

这里的读文件内容，无论是二进制文件、字符串、自定义类型都是类型void*，所以在读不同文件是需要自己添加细节。比如读取字符串需要在有效内容末尾添加"\0"

![image-20230124231554263](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242315040.png)

![image-20230124231603399](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242316988.png)

### 感性+现象理解文件

文件操作即是进程和被打开文件的关系，进程可以打开多个文件，那么被打开的文件也要被操作系统管理起来。通过先描述再组织，操作系统为了管理对应的打开文件，必定要为文件创建对应的内核数据结构标识文件                   struct file{  }->包含了文件的大部分属性

那是怎么管理的呢？

我先打开了5个文件，然后按顺序打印它们的文件标识符

![image-20230124234710411](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242347324.png)

发现是从3开始，且是按照整数顺序打印，那么整数顺序的结构是什么呢？

![image-20230124234746218](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242347208.png)

数组下标是按照整数顺序从0开始排列，前三个分配给三个标准输入输出流

**stdin->键盘，stdout->显示器，stderr->显示器**

![image-20230124235143280](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242351231.png)

![image-20230124235159038](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242352875.png)