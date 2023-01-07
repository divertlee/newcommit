# error: ‘for’ loop initial declarations are only allowed in C99 mode的报错原因和两种解决办法

for(**int i=0**;i<5;i++)

{

......

}

错误：使用gcc编译代码报错 ：error: ‘for’ loop initial declarations are only allowed in C99 mode

 note: use option -std=c99 or -std=gnu99 to compile your code

原因：这是因为gcc是基于c89的标准，不能直接在for循环里定义循环变量，而c99标准则可以在for循环里定义循环变量。

### 解决办法1：在for循环外定义循环变量

<font size=3 color="red">**int i;**</font>

for(i=0;i<5;i++)

{

......

}

![image-20230102203137922](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301022037215.png)

![image-20230102203729956](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301022037946.png)

在for循环外面定义变量后则不报错

![image-20230102203811745](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301022038052.png)

![image-20230102203843838](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301022038768.png)

### 解决办法2：**在makefile或者Makefile文件后添加 -std=c99**

如：

test: test.c

​	gcc -o $@ $^ <font size=3 color="red">**-std=c99**</font>

.PHONY:clean

clean:

​	rm -f test

![image-20230102204010123](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301022040116.png)

![image-20230102204020481](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202301022040210.png)