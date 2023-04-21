# 基本的数学运算与矩阵运算

### 基本语法

#### 变量名

变量名大小写敏感，且只能由数字0~9、a~z,A~Z和_组成，且变量名不能以数字开头

##### 变量不能用关键字

在命令行窗口输入iskeyword可以查看matlab里面的关键字

![image-20230421212644786](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212126829.png)

除此之外，以下的词不适合做变量名

| ans  | 上一句的运算结果                                             |
| ---- | ------------------------------------------------------------ |
| i和j | 复数算子                                                     |
| inf  | 无穷                                                         |
| eps  | 浮点相对精度，即1.0到下一个浮点数之间的距离（值为2.2204e-16) |
| pi   | 圆周率Π                                                      |
| NaN  | 非数字                                                       |

#### 变量名优先级

![image-20230421214041054](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212142616.png)

变量名不应该当覆盖内置函数名；变量的优先级高于内置函数

如cos='things'

输入cos(3):对things字符串进行索引取值，得到'i'

此时还想要用cos去取得对应的余弦函数就会发生错误

![image-20230421214207653](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212142385.png)



即当右边工作区里有与内置函数名冲突的变量名时，使用相同名字的内置函数名时就会发生冲突，此时可以先在工作区清理掉该变量再使用内置函数

![image-20230421214537487](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212145286.png)

#### 变量类型

变量

![image-20230421211048542](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212110438.png)



### 索引

以A[1 21 6;5 17 9;31 2 7]这个行列式为例

A(8)：取出第8个元素

![image-20230421222521285](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212225045.png)

A([1 3 5]):取下标为1 3 5元素的值

![image-20230421222738203](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212227916.png)

 A([1 3;1 3])：取下标为1 3的值出来，打印两行

![image-20230421222836543](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212228782.png)

A(3,2):取下标为第3行第2列的元素

![image-20230421223120674](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212231411.png)

A([1 3],[1 3])：第一个中括号的意思是取第一行和第三行，第二个中括号里的是取第一列和第二列；综上取交集

![image-20230421223525756](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202304212235496.png)