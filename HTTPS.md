# HTTPS

### HTTPS是什么

HTTPS 也是⼀个应⽤层协议，HTTPS（全称：Hypertext Transfer Protocol Secure）是以安全为目标的 HTTP 通道，在HTTP的基础上通过传输加密和身份认证保证了传输过程的安全性。HTTP 协议内容都是按照⽂本的⽅式明⽂传输的. 这就导致在传输过程中出现⼀些被篡改的情况，HTTPS避免了这种情况。

### 改进目标

HTTPS 协议是由 HTTP 加上 TLS/SSL 协议构建的可进行加密传输、身份认证的网络协议，主要通过数字证书、加密算法、非对称密钥等技术完成互联网数据传输加密，实现互联网传输安全保护。设计目标主要有三个。

* 数据保密性：保证数据内容在传输的过程中不会被第三方查看。就像快递员传递包裹一样，都进行了封装，别人无法获知里面装了什么。
* 数据完整性：及时发现被第三方篡改的传输内容。就像快递员虽然不知道包裹里装了什么东西，但他有可能中途掉包，数据完整性就是指如果被掉包，我们能轻松发现并拒收。
* 身份校验安全性：保证数据到达用户期望的目的地。就像我们邮寄包裹时，虽然是一个封装好的未掉包的包裹，但必须确定这个包裹不会送错地方，通过身份校验来确保送对了地方。

### 什么是加密、解密

加密：把明文（要传输的内容）进行一系列变换，生成密文。

解密：把密文进行一系列变换，还原成明文。

### 为什么要加密

![image-20230921180342266](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309211803091.png)

* 数据在客户端和服务器之间传输，数据从服务器应用层从上往下依次封装、传输，然后从服务器的物理层传输到客户端的物理层进而客户端能拿到数据，**其中要经过交换机、路由器等中间设备**，才能发送到客户端。若使用的是HTTP协议的明文传输，黑客在中间进行网络嗅探，很容易就能对数据进行攻击。因此需要給HTTP的明文进行加密，黑客就算在中间拿到了数据无法解密，就无法进行数据攻击。

### 常见的加密方式

> **对称加密**

* 采⽤单钥密码系统的加密⽅法，同⼀个密钥可以同时⽤作信息的加密和解密，这种加密⽅法称为对称加密，也称为单密钥加密。
* 特征：加密和解密所⽤的密钥是相同的。
* 特点：算法公开、计算量⼩、加密速度快、加密效率⾼。
* 常见对称加密算法：DES、3DES、AES、TDEA等。

![image-20230921181945417](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309211819310.png)

例如一个简单的对称加密：**按位异或**

> 明文a=1234,密匙key=8888,密钥对明文进行加密：a^key得到密文a`=9834。
>
> 同理用同一个密钥对密文进行解密：a`^key得到明文a=1234。

![image-20230921213445766](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309212134841.png)

#### 对称加密场景

有三个好朋友tom、jerry和hook。tom想告诉Jerry一个密码，但又不想被hook知道，因此tom就和jerry约定好一个加密解密的条件：

将话语的字符在字母表上的位置+1的行为定义为加密，将话语的字符在字母表上的位置-1的行为定义为解密。密钥就是在字母表上前后移动字符的步数1。

例如tom想根jerry说：

```
i like eating apple
```

tom将这句话的每一个字符都在字母表上的位置+1，得到

```
j mjlf fbujoh bqqmf
```

然后将上面加密过的话告诉jerry和hook，由于Jerry知道密钥，因此Jerry知道tom在说什么，hook不知道密钥就不知道这句话是什么意思。

![image-20230921221337964](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309212213848.png)

但密钥的传递就成了问题。tom告诉Jerry密钥的同时不能保证不被hook窃听到。

### 非对称加密

* 需要两个密钥来进⾏加密和解密，这两个密钥是公开密钥（public key，简称公钥）和私有密钥 （private key，简称私钥）。
* 特点：算法强度复杂、安全性依赖于算法与密钥但是由于其算法复杂，⽽使得加密解密速度没有对称加密解密的速度快。
* 常⻅⾮对称加密算法：RSA，DSA，ECDSA等。
* 通过公钥对明文加密形成密文，就需要通过私钥对该密文进行解密还原得到明文。
* 同理通过私钥对明文加密形成密文，就需要通过公钥对该密文进行解密还原得到明文。
* 即公钥加密，私钥解密；或者私钥加密，公钥解密；二者必须一一配对，因此要求算法非常复杂，导致运算速度非常慢，这比对称加密慢很多。

对称加密：一个密钥对称加密: 单个密钥即可加密也可解密

特点: 算法简单，加密解密速度快

非对称加密:有两个密钥:私钥和公钥

加密与解密:公钥加密，私钥解密，私钥加密公钥解密
特点:算法复杂，加密解密速度慢

数据摘要：对数据进行hash运算，使其形成一串具有固定长度的数字摘要。

特点：只有加密，解密非常困难，即数据摘要通常用来表示数据的唯一性，用来比对

数字签名：对数据摘要进行加密形成数字签名





对信息进行处理形成数据摘要，其摘要是不可逆的，用来进行数据对比。同一份数据经过处理形成同一份数据摘要。例如上传网盘的内容可以形成数据摘要，拿去服务器上进行比对若存在则不需要进行上传即秒传。

对数据摘要进行加密形成数据指纹