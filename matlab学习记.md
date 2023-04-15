## 变量命名规则

1. 变量区分大小写
2. 变量名可以以字母，数字和下划线组成
3. 文件名最好不要以数字开头
4. 变量名不要超过63位

## 数据类型

1. clc：清除command window的所有命令

2. clear all ：清除workspace 的所有变量
3. 注释：%% （加空格）
4. 字符和字符串 单引号里的内容如：'abc','a'

### 数字

1. +|-|*|/

### 字符串

1. 字符串或字符：str='str'
2. abs(字符串或字符)：输出字符对于的ASCII码值，若是字符串则是把字符的ASCII相加输出
3. char(ascii码):输出ASCII码值对于的字符
4. num2str(数字)：把数字类型转化字符串输出
5. length（字符串）：求字符串长度

### 矩阵

1. X矩阵表示：X=[1 2 3;4 5 6;7 8 9;]:维度之间用分号;间隔；数字之间用空格间隔
2. Y是X的转置：Y=X'
3. 单列表示矩阵Z=X(:)    竖着表示X矩阵：1 4 7 2 5 8 3 6 9
4. 方阵求逆：M=inv(X)
5. 矩阵求逆：M=pinv(X)
6. 零矩阵N（三维对应RGB）：N=zeros(4,3,3)：（行数,列数，维数）：这三个变量都可以变
7. rand：生成均匀分布的伪随机数（分布0~1之间），rand(m,n):生成m行n列均匀分布的伪随机rand(Randstream,m,n):利用指定的随机种子生成伪随机数

8. randn：生成标准正态分布的伪随机数，randn(m,n):生成m行n列标准正态分布的伪随机数矩阵
9. randi：生成均匀分布的伪随机整数 ；randi(iMax):在（0,iMax]生成均匀分布的伪随机整数；randi(iMax,m,n):在（0,iMax]之间生成m行n列的伪随机数矩阵；randi([iMin,iMax],m,n):在（iMin,iMax]之间生成m行n列的伪随机数矩阵

### 元胞数组

元胞数组是matlab中特有的一种数据类型，是数组中的一种，特有的是其中元素可以是不同的数据类型，类似于c语言中的结构体，c++中的类。它可以追踪一直到所有的变量全部翻译为基本的数据信息。（查询功能）。其索引和c和c++不同，索引是从1开始的

1. eye(3):生成3*3大小的单位矩阵（主对角线都是1）

![image-20230410170400489](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304101704258.png)

2. magic(n)：magic（魔方、魔术）：前n^2个数生成n阶幻方。幻方：列、行、对角线内的和都相等。和都为n*(n^2+1)/2

如magic(3):生成3阶幻方（1~9内的数字）

  ![image-20230410171259434](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304101713540.png)

### 结构体

结构体里面存元素，元素是键值对。默认第一个是键值（key），第二个是键值对应的信息（value）；类似于c++的键值对（key，value）。

形式：struct (键值1,键值1对应的信息,键值2,键值2对应的信息,......)

![image-20230410174519578](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304101745594.png)

  键值(成员序号)：取出来的是元胞数组（cell），键值{成员序号}：取出来的是成员里的内容![image-20230410175146904](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304101751003.png)

### 矩阵操作

1. 矩阵的定义和构造走

A=[1 2 3 4 5 6]:输出行矩阵

![image-20230412105115169](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121051094.png)

B=1：3：10：起点：步长：终点（也可以理解为最小值：等差：最大值）

以最左边的值为最小值，中间的值为当前值和后一个值的间隔差，最后的值为最大值

![image-20230412105239373](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121052153.png)

当当前值+间隔差大于最大值时，那么下一个值就不输出了（7+3=10>8,不输出10）

![image-20230412105415569](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121054427.png)

2. repmat(矩阵,M,N):B矩阵重复M行N列，可以理解为分块矩阵

![image-20230412105753461](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121057234.png)

3. ones(M,N):生成一个M行N列的矩阵，每个元素都为1

![image-20230412110017045](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121100600.png)

### 矩阵的四则运算

![image-20230412112719023](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121127913.png)

C=A+B：矩阵相加

![image-20230412112732388](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121127404.png)

D=A-B：矩阵相减

![image-20230412112702374](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121127383.png)

E=A*B'：A矩阵乘B的转置

![image-20230412112806661](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121128495.png)

F=A.*B：A矩阵和B矩阵的元素对应相乘

![image-20230412112824796](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121128657.png)

G=A/B：A矩阵乘B的逆矩阵

![image-20230412112845938](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304121128755.png)

K=A./B:A矩阵和B矩阵的元素对应相除

![image-20230414091014954](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304140910050.png)

### 矩阵的下标

先创建一个幻方矩阵

![image-20230414093204776](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304140932613.png)

1. 取矩阵下标对应的元素：I=H(m,n)【取出H矩阵的m行n列的元素】

![image-20230414093255919](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304140932308.png)

2. 取矩阵下标对应的行K=H(2,:)【取出H矩阵第2行的元素】

![image-20230414093445924](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304140934916.png)

3. 取矩阵下标对应的列M=H(:,3)【取出H矩阵第3列的元素】

![image-20230414093459905](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304140935728.png)

4. 取出H矩阵中大于20的元素，并且用m行和n列的以下标的形式展示

![image-20230414093622766](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304140936570.png)
