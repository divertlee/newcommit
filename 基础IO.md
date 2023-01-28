# 基础IO

对电脑上的文件的理解：

<font size=5 color="red"> **1.文件=内容+属性，空文件也要在磁盘占空间**</font>

<font size=5 color="red"> **2.文件路径+文件名标识文件唯一性**</font>

<font size=5 color="red"> **3.对文件的操作即是对内容、属性的操作**</font>

<font size=5 color="red"> **4.如果没有指定文件路径，默认在当前路径进行文件访问**</font>

写代码时，运用各种文件函数接口对文件操作后，编译后形成二进制文件而没有运行时，对文件的操作没有被执行，那么<font size=4 color="green"> **代码对文件的操作，本质上是进程对文件的操作**</font>

**而文件有被打开文件和未被打开文件之分，访问文件的前提是打开文件，所以对文件进行操作， ** <font size=5 color="blue">**是进程对被打开文件进行操作！**</font>

## 回顾c语言的文件操作函数

回顾c语言学过的文件操作，操作文件首先要打开文件—要有个文件指针按相应方式打开

| **r**  | **按读方式打开文件，文件不存在则报错；**                     |
| ------ | :----------------------------------------------------------- |
| **w**  | **按写方式打开文件，文件不存在则创建；若只打开文件然后关闭文件则清空文件内容** |
| **r+** | **按读写方式打开文件，文件不存在则报错**                     |
| **w+** | **按读写方式打开文件，文件不存在则创建，若只打开文件然后关闭文件则清空文件内容** |
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

open的第二个函数的第一个参数是文件，第二个参数是int flags（标记位）—**以32个比特位传递选项，那么这些选项就不能重复。选项可以是O_RDONLY(只读)，O_WRONLY(只写)，O_RDWR(读写)**，**O_CREAT（创建文件）**，**O_TRUNC—覆盖原先文件内容，O_APPEND—追加内容**，第三个文件是权限

<font size=4 color="red">**返回值是文件描述符**</font>

![image-20230124213916020](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242139271.png)

至于这32个比特怎么传递选项的呢？这里我用简单的方式呈现，通过宏定义一些参数，然后传递一些int参数即可知道要什么选项了，且**标志位既有唯一性**

![image-20230124220436848](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242204761.png)

如果没有文件，底层的open函数是只读或只写的话，是不会创建文件的，需要传创建文件的标识符并且传入权限才能创建正常的文件

![image-20230124222810680](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242228192.png)

如果不想要系统规定的文件初始权限—664，可以在子进程就传入想要的掩码来改变文件的权限

![image-20230124223110923](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242231345.png)

![image-20230124223332234](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242233186.png)

并且这里传的掩码是改的子进程的掩码，不会影响父进程

### write—写入文件

**第一个参数是文件，第二个参数是要写入的内容，第三个参数是有效内容的大小**

![image-20230124224726753](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242247706.png)

如果没有传O_TRUNC参数的话，在原先的内容上再写入会出问题！

![image-20230124225534137](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242255229.png)

![image-20230124230651737](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242306640.png)

### read—读文件内容

**第一个参数是要读的文件，第二个参数是读取到的文件类型和位置，第三个参数的内容大小，返回值是读取到的文件大小，单位是字节个数，如果函数失败返回-1**

![image-20230124230814272](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242308066.png)

![image-20230126104357706](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261044620.png)

**这里的读文件内容，无论是二进制文件、字符串、自定义类型都是类型void***，所以在读不同文件是需要自己添加细节。比如读取字符串需要在有效内容末尾添加"\0"，若

![image-20230124231554263](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242315040.png)

![image-20230124231603399](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242316988.png)

### 感性+现象理解文件

文件操作即是进程和被打开文件的关系，进程可以打开多个文件，那么被打开的文件也要被操作系统管理起来。通过先描述再组织，操作系统为了管理对应的打开文件，必定要为文件创建对应的内核数据结构标识文件 struct file{  }->包含了文件的大部分属性

那是怎么管理的呢？

我先打开了5个文件，然后按顺序打印它们的文件描述符

![image-20230124234710411](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242347324.png)

发现是从3开始，且是按照整数顺序打印，那么整数顺序的结构是什么呢？

![image-20230124234746218](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242347208.png)

数组下标是也是按照整数顺序从0开始排列，有可能文件描述符的前三个分配给三个标准输入输出流

**stdin->键盘，stdout->显示器，stderr->显示器**

![image-20230124235143280](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242351231.png)

![image-20230124235159038](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301242352875.png)

### 文件描述符fd

<font size=5 color="red">**文件描述符本质是数组下标**</font>

上层通过传给进程文件描述符，进程的struct files_struct *files指针找到文件描述符表的文件描述符对应的下标数组，该数组的指针会访问到对应的文件，然后返回给上层！

![image-20230125002826440](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301250028532.png)

#### 文件描述符的分配规则

这里我用系统调用文件函数创建一个文件，且把该文件描述符打印出来，可以看到该文件描述符是3即除去了012（stdin,stdout,stderr）三个标准输入输出流

![image-20230126151158816](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261512286.png)

现在我把0(stdin)关闭或者把2(stderr)关闭，再运行，可以看到文件描述符会是0或1，可以看到两个标准输入流被关闭时，open打开文件时返回的文件描述符可以是0或2了，但是如果是1（stdout—标准输出流的话），会发现打印不出来

![image-20230126151408927](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261514042.png)

![image-20230126151531089](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261515037.png)

![image-20230126151919129](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261519143.png)

**当stdin被关闭后，新文件先被打开，然后**<font size=5 color="red">**在文件描述符表里从小到大按顺序寻找最小且没有被占用的fd**</font>，**此时0是没有被占用的，那么0处的指针就会指向新文件。**



![image-20230126152830376](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261528352.png)

但是当关闭stdout时，要打印的内容没有显示出来，而是被打印到了新文件里，且由于标准输入输出流的缓冲区机制和文件缓冲区机制不同，此时文件里并没有要打印到stdout的内容，要打印进到文件里需要强制刷新缓冲区。

![image-20230126160406251](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261604409.png)

<font size=5 color="green">**此时上层使用的fd是1不变，但是在内核中更改了fd对应的struct file*的地址，**</font>应该传入到相应的文件缺传入到了另一个文件上，这就是输出重定向

### 重定向

在操作系统中，有三种重定向，分别是输出重定向，追加重定向，输入重定向

| **>**  | **输出** |
| ------ | -------- |
| **>>** | **追加** |
| **<**  | **输入** |

#### 重定向函数dup2

**int dup2(int oldfd,int newfd)**

传入两个文件描述符，如果成功就返回newfd，失败就返回-1

![image-20230126160559256](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261606454.png)

**把oldfd里的内容(指针)拷贝到newfd里去，那么newfd（ 指针）指向的内容就是oldfd指向的内容啦！**

![image-20230126161504521](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261615409.png)

##### 输出重定向

把本来打印到stdout的内容打印到了soo.txt文件里

![image-20230126162105541](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261621874.png)

![image-20230126162212888](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261622723.png)

##### 追加重定向

![image-20230126163127169](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261631951.png)

可以看到多运行几次后文件的内容被追加了

![image-20230126163159949](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261632871.png)

##### 输入重定向

把本来键盘输入的东西打印到屏幕上，转变成把文件里的内容打印到屏幕上

![image-20230126164144870](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261641228.png)

![image-20230126164153637](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261641461.png)

![image-20230126164200375](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301261642389.png)

像重定向这样的工作是父进程向子进程提供信息，比如文件各类指针，父进程把文件描述符表拷贝一份给子进程，来进行操作。这些都在内核数据结构里，而进程替换是在用户空间，子进程对文件的操作不会影响到进程替换。当父进程和子进程都指向同一个文件，文件里会有一个**引用计数**，计数为2，父进程关闭该文件时，父进程的指针不指向该文件。该计数减减等于1，等到子进程也关闭文件（计数减减等于0），没有指针指向该文件时这个文件才会真正关闭。

![image-20230126200226317](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301262002373.png)

#### 再次理解文件

各种外设都有自己的访问方式，但是在操作系统上都能统一成同一个struct file类型，上层通过操作系统的struct file的函数指针找到外设的驱动，在驱动里能找到对应的操作方法进行调用外设。而站在struct file上，一切的文件或者外设都是struct file，即<font size=5 color="blue">在Linux上一切皆文件！</font>

![image-20230126203040708](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301262030733.png)

## 理解缓冲区

 同时调用库函数的打印和系统调用的调用，打印到屏幕上，和重定向到文件里内容都是和.c文件对应的

![image-20230128110418648](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281104148.png)



但是在进程末尾fork创建子进程后，打印到屏幕上的内容是和之前一样，但是重定向到文件里却不一样了：<font size=4 color="red">**先是一遍系统调用，然后是库函数打印两遍**</font>这是为啥呢？

![image-20230128110515393](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281105505.png)

看到了现象，就去追根溯源

### 感性理解缓冲区

<font size=5 color="green">**缓冲区是内存中的一部分**</font>

有些卷王过年不回家，回家不过年,哈哈哈开个玩笑~~~  

那么在外地忙于生计的人儿没时间回家过年，与亲人两地相隔，母亲想寄一些吃的喝的给你，如果母亲只身负责把东西拿去给孩子，就会很占用母亲的时间且来回要好久，但是把东西给快递站，以打包快递方式发送给孩子，那么解放了母亲的时间，东西又很快的到孩子手上。

那么母亲就是进程，快递站就是缓冲区，你就是磁盘，<font size=5 color="red">**缓冲区负责把进程的数据，传递到磁盘里！节省了进程进行数据io的时间！**</font>

![image-20230128114048976](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281140822.png)

## 缓冲区刷新策略

<font size=4 color="green">**1.立即刷新—>无缓冲** **2.行刷新—>行缓存—比如显示器**   **3.缓冲区满—>全缓冲—比如磁盘文件**</font>

显示器是给人看的，一行一行打印到显示器给人看。等缓冲区满了，然后一次性全缓冲是效率最高的！

而总结成两者情况：<font size=4 color="red">**一是用户强制刷新，比如fflush，二是进程退出—进行缓冲区刷新**</font>

缓冲区到底在哪呢？通过现象，库函数打印了两次，而系统系统调用打印了一次，说明缓冲区不在内核；fork之后父子数据发生写时拷贝，子进程也就有了同样的数据，即产生了两份数据。

综上，printf、fprintf、fputs自带缓冲区，且在用户级语言层，库函数在系统调用的上层，是对系统调用的封装，但是write没有，说明缓冲区是二次加上的，又因为是c，所以由c标准库提供。

<font size=5 color="purple">**用户级缓冲区存在FILE结构体中**</font>

<font size=4 color="red">**库函数通过FILE*到内存找到对应的FILE结构体（用来存放文件的有关信息），结构体里就有缓冲区，文件描述符等等。找到后把相应内容写到里面的缓冲区，然后缓冲区里又封装了fd，在相应时候就会把缓冲区里的数据刷新到外设里！**</font>

最后得出现象的原因：**有fork：外设是stdout时，在进行fork之前，三条库函数已经把数据按照行缓存的方式打印到屏幕上，此时到fork创建子进程时父进程缓冲区已经没有这部分数据了，子进程也就没有拷贝这部分数据；若是重定向到文件里：fork之前，库函数按照全缓存的方式打印到文件里。fork创建子进程的时候，缓冲区里还有数据，子进程也拷贝了一份数据，紧接着就是进程退出，父子进程退出时都要把进行缓冲区刷新，所以文件里库函数方式的就打印了两次。但是系统调用write只用了fd，没有用到FILE所以只打印了一次。**

### 写一份缓冲区机制

#### mystdio.h

```cpp
  1 #pragma once 
  2 
  3 #include<errno.h>
  4 #include<unistd.h>
  5 #include<sys/types.h>
  6 #include<sys/stat.h>
  7 #include<fcntl.h>
  8 #include<string.h>
  9 #include<stdlib.h>
 10 #include<assert.h>
 11 
 12 
 13 #define SIZE 1024    //大小
 14 #define SYNC_NOW  1  //无缓冲
 15 #define SYNC_LINE 2  //行缓存
 16 #define SYNC_FULL 4  //全缓存
 17 
 18 typedef struct _FILE{
 19 
 20 int flags;//刷新方式
 21 int fileno;//文件描述符
 22 char buffer[SIZE];//缓冲区
 23 int cap;//容量
 24 int size;//使用量
 25 
 26 }FILE_;
 27 
 28 FILE_ *fopen_(const char* path_name,const char *mode);//路径 权限
 29 void fwrite_(const void *ptr,int num,FILE_ *fp);//去向 大小 来源                                                     
 30 void fflush_(FILE_ *fp);
 31 void fclose_(FILE_ *fp);//来源

```

#### mystdio.c

```cpp
 1 #include"mystdio.h"
  2                                                                                                                                                                                        
  3 FILE_ *fopen_(const char* path_name,const char *mode)//路径 权限
  4 {                                                               
  5   int flags=0;
  6   int Moded=0666;
  7   if(strcmp(mode,"r")==0)
  8   {                      
  9     flags|=O_RDONLY;
 10    }                
 11   else if(strcmp(mode,"w")==0)
 12   {                           
 13    flags|=(O_WRONLY|O_CREAT|O_TRUNC);
 14   }                                  
 15   else if(strcmp(mode,"a")==0)
 16   {                           
 17     flags|=(O_WRONLY|O_CREAT|O_APPEND);
 18   }else                                
 19   {     
 20     //TODO
 21   }       
 22   int fd=0;
 23   if(flags&O_RDONLY) fd=open(path_name,flags);
 24   else fd=open(path_name,flags,Moded);        
 25   if(fd<0)                            
 26   {       
 27     const char* err=strerror(errno);
 28     write(2,err,strlen(err));       
 29    return NULL;              
 30   }            
 31    
 32   FILE_ *fp=(FILE_*)malloc(sizeof(FILE_));
 33   assert(fp);// 失败就断言                
 34 //成功就初始化            
 35 fp->flags=SYNC_LINE;//默认行缓冲
 36 fp->fileno=fd;//文件描述符      
 37 fp->cap=SIZE;//容量       
 38 fp->size=0;//使用量
 39 memset(fp->buffer,0,SIZE);//缓冲区初始化为0
 40 return fp;//成功就返回FILE*指针            
 41 }                              
 42 
 43                                            
 44 void fwrite_(const void *ptr,int num,FILE_ *fp)//去向 大小 来源
 45 {                                                                                                                                                                                      
 46    //1.写到缓冲区里
 47    memcpy(fp->buffer+fp->size,ptr,num);//des,sor,size 
 48    fp->size+=num;
 49    //2.判断是否刷新了
 50    if(fp->flags&SYNC_NOW)
 51    {
 52      //写到文件里
 53      write(fp->fileno,fp->buffer,fp->size);
 54      fp->size=0;
 55    }
 56    else if(fp->flags&SYNC_FULL)
 57    {
 58     if(fp->size==fp->cap)
 59      {
 60      write(fp->fileno,fp->buffer,fp->size);
 61      fp->size=0;
 62      }
 63   } 
 64    else if(fp->flags& SYNC_LINE)
 65    {
 66      if(fp->buffer[fp->size-1]=='\n')//不考虑abcd\nabab
 67      {
 68      write(fp->fileno,fp->buffer,fp->size);
 69      fp->size=0;
 70      }
 71    }
 72    else 
 73    {
 74      //FAIL
 75    }
 76 
 77 }
 78 void fflush_(FILE_* fp)
 79 {
 80   if(fp->size>0) write(fp->fileno,fp->buffer,fp->size);
 81 }
 82 void fclose_(FILE_ *fp)//来源
 83 {
 84   fflush_(fp);
 85   close(fp->fileno);
 86 }

```

试一下行缓冲

![image-20230128184759931](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281848561.png)

![image-20230128185936782](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281859005.png)

##### 命令行清空文件： 【空格】 >  文件名

全缓冲

![image-20230128190143307](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281901887.png)

![image-20230128190338375](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281903191.png)

无缓冲

![image-20230128191323069](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281913885.png)

![image-20230128192242390](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301281922221.png)

### 内核缓冲区

按照上面的策略：把数据写入磁盘：通过库函数printf或者系统调用write写入缓冲区，然后按照指定方式（无缓冲、行缓冲、全缓冲）刷新缓冲区，把数据拷贝到文件里。

但实际上不是这样。**首先通过语言层面的文件函数(fwrite等）把数据拷贝到语言层缓冲区，再通过指定缓冲方式（无、行、全）通过系统调用（write)把数据拷贝到内核中的struct file中的内核层面缓冲区，然后以操作系统按照自己的方式（可能内存不够了刷新，也可能按照一定频率刷新）把数据拷贝到磁盘中。**一共三次拷贝。

![image-20230128213614225](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301282351177.png)

<font size=5 color="blue">**所以语言层文件函数fwrite等和系统调用函数write等写入函数应该叫拷贝函数。**</font>

#### fsync 写入函数

**fsync是写入函数，数据在内核缓冲区时，调用该函数不再按照操作系统自己的方式来刷新缓冲区，而是将操作系统缓冲区的数据强行同步到文件中。**

![image-20230128214731595](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301282350011.png)

同时也可能给我们写的小程序更改一下。

![image-20230128215207244](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301282350660.png)

```cpp
 78 void fflush_(FILE_* fp)
 79 {
 80  // if(fp->size>0) write(fp->fileno,fp->buffer,fp->size);
 fsync(fp->fileno);//强制刷新内核缓冲区
 fp->size=0;
 81 }
```

