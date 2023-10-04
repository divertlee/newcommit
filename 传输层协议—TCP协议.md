#  传输层协议—TCP协议

[TOC]

TCP全称为 "传输控制协议(Transmission Control Protocol"). 人如其名, 要对数据的传输进行一个详细的控制;

应用层将数据向下交付给传输层后，其数据的发送和处理由传输层决定，TCP是传输层协议，即数据的发送和处理由TCP协议来决定，因此TCP被称为传输控制协议。

### TCP协议段格式

![image-20231002160719578](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310021607295.png)

#### 四位首部长度

![image-20231003150445983](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031504976.png)

* 四位首部长度标识报头大小。有时没有选项，标准报头不含选项。因此标准报头大小为20字节。而四位首部长度范围为0000~1111即[0,15]。该范围并不能涵盖报头大小。因此`报头大小=4位首部长度*4字节`。即tcp报头总长度范围[0,60]，但标准报头占20字节，因此tcp报头总长度范围[20,60]。超出20字节的部分即为选项部分。若此时报头大小为20字节，此时4位首部长度为[0101]。

#### TCP协议如何根据目的端口号将数据传输给指定进程？

![image-20231002172604997](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310021726107.png)

* 在操作系统内以链表的形式对进程pcb做管理外，还会以hash的方式对进程pcb做管理。以端口号为键值对进程pcb进行管理。
* 接收到tcp报文后，根据**目的端口号**去操作系统中管理进程pcb的hash数据结构中找到对应进程pcb。进程需要维护自己所管理的文件描述符表。进程pcb内有`struct file*`，该指针指向进程文件描述符表。
* 在进程文件描述符表内能够找到进程所管理的文件。文件内有自己的读写缓冲区。即在传输层中将tcp报头分离后，直接将tcp的有效载荷发送到进程所管理的读写缓冲区。**即以读取文件的方式读取到网络数据。**

实际上tcp报头底层也是一个结构体，其处理方式和处理udp方式大同小异。

```c
struct tcp_hdr
{
uint32_t src_port;
uint32_t dst_port;
uint32_t req;
uint32_t ack_req;
uint32_t header_length;
......
};
```

* 传输层接收到应用层向下交付的数据后。开辟一块空间，在该空间内创建tcp_hdr结构体，将结构体内的属性填充完整，然后`该空间+应用层交付的数据=tcp报文`，接着继续向下交付。

#### 32位序列号和32位确认序列号

![image-20231003150527003](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031505954.png)

实际上不止TCP/IP四层模型中存在协议，硬件中也存在协议。

内存和其他外设相连接的线称为IO总线。内存和CPU相连接的线称为系统总线。而设备之间通信必然是通过协议通信。而外设之间通信很少存在不可靠性问题，其中原因包括外设之间距离狠心，指令、数据传输不容易出现异常。而网络通信不是在本地单主机上通信，而是主机之间通信，而主机之间通信的桥梁是网络，在该前提上数据通信就存在可靠性问题。

##### 可靠性问题

网络通信不存在绝对的可靠性，但存在相对的可靠性。

![image-20231002181043526](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310021810352.png)

* 双方在通信，**历史信息的可靠性建立在收到响应的前提上**。例如小蓝法信息给小绿“今天学习了吗？”，这条信息本身不具备可靠性。小绿回复“学了学了好久呢”，即响应了小蓝发送给小绿的历史短信，此时“今天学习了吗？”这条信息才具备可靠性。
* **历史的信息具备可靠性，但最新消息不具备可靠性**。小绿回复小蓝“忘了”，该短信在没收到小蓝的回复之前都不具备可靠性。

> **通过32位序列号和32位确认序列号来直接确保可靠性**

该场景没有涉及到超时重传机制，只谈论序号和确认序号的作用

* tcp报头中有序号和确认序号。序号标识发送出去的信息。**由于tcp协议是无状态的，因此需要序号标定状态和连续性**。当收到报文时，需要去查询报头的序号，然后响应信息中包含确认序号。例如服务器收到客户端发送来的报文序号是10，那么发送回去的响应的确认序号是11，<font size=4 color=red>**表示11之前的序号的报文接收成功，且确认序号需要要求是连续的。**</font>例如客户端发送給服务器三条信息，依次序号是10，11，12，但序号11标定的信息掉包了导致服务器没有收到，因此服务器响应信息的确认序号只能是11。让客户端知道服务器没有收到序号为10之后的报文，触发重传机制重新发送序号为10之后的报文。

![image-20231003143711911](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031437823.png)

* 而实际上客户端和服务器通信不是客户端发送一条请求给服务器，服务器响应一个ack给客户端。而是并发式的相互交流。数据对于接收方而言数据乱序是一种不可靠的表现，要通过序号来对数据进行排序，保证数据的按序到达。即序号和确认序号保证了信息的顺序性和连续性。

![image-20231003144823156](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031448146.png)

* **tcp协议是全双工的，因此需要两组序号来保证信息朝向的可靠性**。在发送信息的同时给对方确认ack，这样的报文提高了通信的效率。

### TCP报头标志位

TCP报文具有类型区别，区别在于其标志位的设置。实际上该标志位底层是位图，若标志位需要被设置，就由0置1。

![image-20231003150608573](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031506360.png)

![image-20231003150940510](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031509384.png)

> **SYN标志位标识请求报文**

![image-20231003151418603](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031514613.png)

在三次次握手中，客户端向服务器发送的请求报文中的YSN标志位就被置为1。

> **FIN标志位标识断开报文**

![image-20231003151509391](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031515161.png)

在四次挥手中客户端向服务器发送挥手请求的报文中FIN标志位就被置为1。

> **ACK标志位标识确认报文**

在网络通信中ACK标识的报文标识确认应答。

> **PSH标志位标识催促报文**

客户端和服务器通信时，可能会存在接收方处理数据不及时导致接收缓冲区满了，发送方无法再次发送数据的情况。

由于TCP是全双工的，通信双方都具备接收缓冲区和发送缓冲区。客户端向服务器发送数据，服务器将受到的数据放到接收缓冲区。服务器上层调用`read`将数据从接收缓冲区读取到上层进行处理。会存在上层处理数据的速度慢，客户端发送的数据快，导致服务器的接收缓冲区早早满了。此时客户端再发送数据就会造成丢包问题，而维护连接是需要消耗资源的，通信双方不能由于不能发送数据而长期维护连接。

因此客户端可以将PSH标志位由0置1，只将该标识PSH属性的报文发送给服务器，通知催促服务器尽快处理数据，给接收缓冲区腾出空间来接收新的报文。实际上报头的PSH标志位为1的报文都具备催促含义。

> **URG标志位标识需要紧急处理的数据**

数据对于接收方而言，数据乱序本身就是不可靠的表现。因此可以通过序号对报文标记，对序号进行一定策略的排序，保证数据的按序到达。而按序读取数据自然就产生了等待问题。对于某些需要特殊紧急处理的数据而言，按序等待处理就成了问题。因此需要用URG标定报文含有需要紧急处理的数据，即提示对方上层尽快将该数据读取进行处理。

实际上发送数据函数`sendto`就可以传递相关参数标识发送的报文具有需要紧急处理的含义

![image-20231003162226046](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031622849.png)

> 手册说明标志位

```cpp
MSG_OOB
Sends  out-of-band data on sockets that support this notion (e.g., of type SOCK_STREAM); the underlying protocol must
              also support out-of-band data.
```

* `sendto`的第四个参数传参`MSG_OOB`表示所发送的数据需要被紧急处理，即`out-of-band`（带外数据），带外数据的处理策略与tcp流的完全分开的，属于独立一套数据处理策略。

接收函数`recv`也可以传参`MSG-OOB`表示读取需要紧急处理的数据。

![image-20231003162557907](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031625660.png)

### 16位紧急指针

![image-20231003160901675](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031609573.png)

URG标定报文含有需要紧急处理的数据。**16位紧急指针表示需要紧急处理的数据在有效载荷中的偏移量。**

**而该需要被紧急处理的数据大小只能为1字节，即TCP的紧急指针只能传输1个字节的数据。**

> **RST标志位标识复位，发送给对方表示需要重置连接**

![image-20231003164618284](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031646955.png)

* 客户端和服务器双方通信时，先进行三次握手确定连接成功。然后客户端向服务发送数据。三次握手结束后，服务器由于设备原因单方面掉线，服务器重启后不再认定之前的三次握手，即此时服务器单方面认为没有完成连接，而客户端不知道服务器掉线因此单方面认为连接成功。然后客户端向服务器发送数据。服务器收到了客户端的数据，但由于没有与该客户端建立好连接而收到了发送来的数据感到疑惑，因此**服务器需要发送一个具有RST标志位的报文给客户端，表示重新与客户端进行三次握手，即重置连接。**

### 确认应答机制

![image-20231003172117540](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031721282.png)

* 在TCP协议中，实际上通信双方的接收缓冲区和发送缓冲区是以数组的方式进行管理。数组天生具有下标，即TCP报头的序号。而确认序号为序号+1可以理解为以序号为下标之前的数据全部接收完毕，下次发送数据给我以确认序号作为下标为起点往后开始发送。

### 超时重传机制

> 发送数据给对方，对方超过一定时间没有响应应答，自身重新发送数据给对方



客户端向服务器发送数据，会有以下两种场景：客户端认为服务器没有收到数据，客户端重新发送数据给服务器。

> 场景一：客户端向服务器发送数据，数据在服务器收到之前丢包了，即服务器没有收到数据，因此服务器就没有向客户端响应ACK报文。经过一定时间后，客户端触发超时重传机制，重新向服务器发送数据。

![image-20231003173448523](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031734473.png)

> 场景二：客户端向服务器发送数据，服务器收到了数据，向客户端响应了ACK报文，但ACK报文掉包了，即客户端没有收到服务器发送来的响应，此时客户端会认为服务器没有收到数据，经过一段时间后，客户端会重新向服务器发送数据。

![image-20231003174239816](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031742520.png)

这个场景下服务器就会收到两份相同的报文，收到重复的报文也是不可靠性的一种，因此服务器需要对报文进行去重操作，通过**报文的序号**进行去重。

* 客户端发送数据，到重新发送数据期间有一个时间间隔。由于这两次发送的数据是相同的，因此这份数据在收到应答之前应该在接收缓冲区中保存。客户端迟迟没有收到应答，超过特定的时间间隔后重新发送数据给服务器。
* 该决定超时重传机制的特定时间间隔不应该是固定的，因为网络通信的时间长短不只由通信双方决定，还由网络决定，网络是变化的波动的，因此可以认定该特定的时间间隔也是变化的波动的。

#### 再谈三次握手四次挥手

![image-20231003175851663](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310031758261.png)

> **实际上三次握手所发送的是具备一定类型的TCP报头**

* 客户端向服务器发送SYN实际上是发送一个TCP报头，该TCP报头的SYN标记位被置为1，表示请求。
* 服务器响应客户端的SYN+ACK实际是发送一个TCP报头，该报头的SYN和ACK标记位都被置为1，表示请求和确认应答。
* 客户端响应服务器ACK实际上是发送一个TCP报头，该报头的ACK标记位被置为1，表示确认应答。

> 三次握手不一定非得成功，在三次握手中最后一个ACK才是最新消息，因此前两条通信报文丢失了会触发重连或者重传，而最后一个ACK就无法保证可靠性。

因此三次握手能够保证需要保证以下几点：

1. 客户端能够发送请求，然后能够接收到服务器发送的响应，即保证了客户端具备了发、收的能力。
2. 服务器接收到了客户端的第一通信即syn请求，接收到了客户端第二通信即ack应答，即保证了服务器也具备了发、收的能力。
3. 客户端和服务器都具备了发送数据、接收数据的能力，才能保证tcp连接是全双工的。
4. 客户端先向服务器发送连接请求，那么就要求客户端先确保能够建立好连接，即优先确保客户端具备发送数据、接收数据的能力。服务器被客户端连接，就要求服务器需要在客户端确保能够建立连接之后确保建立好连接。

> 建立连接的保证为什么是三次握手？

1. 操作系统中会有许多进程，因此当该主机作为通信一方时，操作系统中就会存在很多连接。连接是需要被管理起来的，而维护一个连接是具有成本的。因此建立连接的方式尤为重要。
2. 一次握手就连接建立成功的话，很容易导致恶意客户端多次向服务器发送syn请求建立多个连接导致服务器再也无法与其它需要建立连接的客户端通信，即容易造成syn洪水问题。
3. 两次握手就建立成功的话，当客户端发送出syn请求时保证了客户端建立好了连接，服务器发送了ACK+syn响应时保证了服务器建立好了连接，其原理跟一次握手无太大差异，也容易造成syn洪水问题。
4. 三次握手是以最小成本验证全双工通信信道是通畅的。
5. 服务器受到攻击，而三次握手是用来保证双工建立好连接的，并不能解决受到攻击问题。

tcp通信需要建立连接，建立连接保证了可靠性，实际上连接并不能直接确保可靠性。经过三次握手后，操作系统中会根据三次握手双方交互的信息建立连接结构体，连接结构体能够保证连接管理机制、超时重连机制、流量控制等等，这些机制直接保证了连接的可靠性。

### 连接管理机制

![image-20231004141848125](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310041418060.png)

* 通信双方经过三次握手后，在操作系统中建立好了连接结构体。结构体内有位图记录连接的状态。

在四次挥手期间：

> 断开连接是双方的事情，需要征得双方同意。

1. 先发送断开请求的一方进入`FIN_WAIT 1`状态。例如客户端主动与服务器断开连接，客户端向服务器发送断开请求FIN后，立刻进入`FIN_WAIT 1`状态。
2. 服务器收到断开请求后，响应ACK，然后进入`CLOSE_WAIT`状态。服务器在响应ACK后立刻发送FIN断开请求。客户端收到服务器发送过来的断开请求FIN，立刻响应ACK报文，同时进入`TIME_WAIT`状态。

总结一下：

* 主动断开连接的一方，四次挥手完成后，最终状态是`TIME_WAIT`状态并维持一段是时间。被动断开连接的一方，两次挥手完成后，会进入`CLOSE_WAIT`状态。

实际上在客户端与服务器通信时，可以让客户端主动与服务器断开连接，然后让服务器不close sock也不退出进程，那么服务器就处于`CLOSE_WAIT`状态。

> httpserver.hpp

```cpp
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <functional>
#include "protocol.hpp"
#define NUM 1024
static const uint16_t gport = 8080;
static const int gbacklog = 5;
using namespace std;
namespace Server
{
    enum
    {
        USAGE_ERR = 1,
        SOCK_ERR,
        BIND_ERR,
        LISTEN_ERR
    };
    class httpserver;
    using func_t = function<bool(const HttpRequest &, HttpResponse &)>; // 重定义func_t
    class httpserver
    {
    public:
        httpserver(func_t func, const uint16_t &port = gport) : _port(port), _listensock(-1), _func(func) {}
        void inithttpserver()
        {
            // 1.创建套接字
            _listensock = socket(AF_INET, SOCK_STREAM, 0);
            if (_listensock < 0)
            {
                exit(SOCK_ERR);
            }
            // 2.bind ip和port
            struct sockaddr_in local;
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            local.sin_addr.s_addr = INADDR_ANY;
            if (bind(_listensock, (struct sockaddr *)&local, sizeof(local)) < 0) // 绑定失败
            {
                exit(BIND_ERR);
            }
            // 3.将套接字设置为监听模式
            if (listen(_listensock, gbacklog) < 0)
            {
                exit(LISTEN_ERR);
            }
        }

        void HandlerHttp(int sock)
        {
            while(true)
            {
                sleep(1);
            }
        }

        void start()
        {
            while (true)
            {
                struct sockaddr_in cli;
                socklen_t len = sizeof(cli);
                bzero(&cli, len);

                int sock = accept(_listensock, (struct sockaddr *)&cli, &len);
                if (sock < 0)
                {
                    continue;
                }

                cout << "accept sock: " << sock << endl;

                // 多进程版---
                pid_t id = fork(); // 创建子进程
                if (id == 0)       // 子进程进入
                {
                    close(_listensock); // 子进程不需要用于监听因此关闭该文件描述符
                    if (fork() > 0)
                        exit(0);

                    // //孙子进程
                    HandlerHttp(sock); // 调用操作函数
                    // close(sock);
                    // exit(0);//不关闭sock也不退出进程
                }
                // 父进程
                close(sock); // 父进程不使用文件描述符就关闭
                waitpid(id, nullptr, 0);
            }
        }

        ~httpserver() {}

    private:
        int _listensock; // 用于监听服务器的sock文件描述符
        uint16_t _port;  // 端口号
        func_t _func;
    };

}
```

* 服务器不close文件描述符，也不退出进程。

![image-20231004151139488](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310041511224.png)

如果服务器出现大量的CLOSE_WAIT状态，要么是服务器压力过大来不及执行close（服务端还有数据没有推送完），要么是你的close直接就是忘写了。

![image-20231004170535786](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310041705121.png)

需要注意的是：

断开连接的一方从`TIME_WIAT`状态到`CLOSED`状态会有一个超时机制，该超时时间为2MSL（Maximum Segment Lifetime—最长报文段寿命：它是任何报文在网络上存在的最长的最长时间，超过这个时间报文将被丢弃。）。该时间设定为2MSL的原因有：

1. **确保即使对方没有收到ACK也有足够的时间发送FIN使我方收到，并且回复ACK让对方收到。**例如客户端主动向服务区断开连接。客户端经历三次挥手后进入`TIME_WAIT`状态并维持一段时间，随后回复服务器ACK表示应答。然而由于网络问题使得该ACK丢包了，服务器经过一段时间没有收到ACK应答后会触发重传机制从新向客户端发送FIN断开请求，并等待客户端响应自己ACK应答。此时由于客户端没有立刻进入`CLOSED`状态还处于`TIME_WAIT`状态，允许接收FIN请求并相应服务器ACK应答。
2. **使得历史的滞留的报文消散。**例如客户端与服务器四次挥手中，服务器向客户端一共发送了两次FIN请i去，第一个请求丢失，第二个到达了客户端。假如服务器向客户端发送的第一个报文没有丢失，而是在某些网络节点停留了，以至于延误到连接释放后的某个时间才到达客户端。这本来是已失效的报文段，但客户端并不知道，就会又建立一次连接。而等待的这2MSL就是为了解决这个问题的，服务器在发送完最后一个确认报后，在经过时间2MSL，就可以使本链接持续时间内所产生的所有报文段都从网络中消失，这样就可以使下一个新的连接中不会出现这种旧的连接请求报文段。

由于主动断开连接的一方最后会处于`TIME_WAIT`状态并维持一段时间。那么服务器主动断开连接时，就不能立刻重启与客户端建立连接，而是处于`TIME_WAIT`状态。而处于`TIME_WAIT`状态即说明TCP协议层的连接没有完全断开，因此不能再次监听（使用）同样的端口号。

```
$ ./httpserver
 bind error:Address already in use
```

可以通过`cat /proc/sys/net/ipv4/tcp_fin_timeout`查看MSL的值。MSL在RFC1122中规定为两分钟,但是各操作系统的实现不同, 在Centos7上默认配置的值是60s。

![image-20231004175413552](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310041754711.png)

### 解决TIME_WAIT状态引起的bind失败的方法

> 在server的TCP连接没有完全断开之前不允许重新监听, 某些情况下可能是不合理的

* 服务器需要处理非常大量的客户端的连接(每个连接的生存时间可能很短, 但是每秒都有很大数量的客户 端来请求）。
* 这个时候如果由服务器端主动关闭连接(比如某些客户端不活跃, 就需要被服务器端主动清理掉), 就会产 生大量TIME_WAIT连接。
* 由于我们的请求量很大, 就可能导致TIME_WAIT的连接数很多, 每个连接都会占用一个通信五元组(源ip,  源端口, 目的ip, 目的端口, 协议). 其中服务器的ip和端口和协议是固定的. 如果新来的客户端连接的ip和 端口号和TIME_WAIT占用的链接重复了, 就会出现问题。

因此可以使用`setsockopt()`设置socket描述符的 选项`SO_REUSEADDR`为1, 表示**允许创建端口号相同但IP地址不同的多个socket描述符**。

> socksetopt函数原型

```cpp
#include <sys/types.h>
#include <sys/socket.h>
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
```

* `sockfd`：套接字描述符，指定要设置选项的套接字。
* `level`：选项的级别，用于指定选项所属的协议族或套接字类型。常用的级别包括`SOL_SOCKET`（通用套接字选项）和`IPPROTO_TCP`（TCP协议选项）等。
* `optname`：选项的名称，用于指定要设置的具体选项。设置SO_REUSEADDR表示允许在套接字关闭后立即重用相同的地址和端口。
* `optval`：指向存储选项值的缓冲区的指针。
* `optlen`：选项值的长度。
* 返回值：返回值为0表示设置选项成功，返回-1表示设置选项失败。

> httpserver.hpp

```cpp
        void inithttpserver()
        {
            // 1.创建套接字
            _listensock = socket(AF_INET, SOCK_STREAM, 0);
            if (_listensock < 0)
            {
                exit(SOCK_ERR);
            }
            //2.1套接字关闭后立即重用相同的地址和端口
            int opt=1;
            int k=setsockopt(_listensock,SOCK_STREAM,SO_REUSEADDR,&opt,sizeof(opt));
            if(k<0)
            {
                perror("setsockopt error");
                exit(1);
            }
            // 2.2.bind ip和port
            struct sockaddr_in local;
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            local.sin_addr.s_addr = INADDR_ANY;
            if (bind(_listensock, (struct sockaddr *)&local, sizeof(local)) < 0) // 绑定失败
            {
                exit(BIND_ERR);
            }
            // 3.将套接字设置为监听模式
            if (listen(_listensock, gbacklog) < 0)
            {
                exit(LISTEN_ERR);
            }
        }
```

* 给setsockopt传参`_listensock`表示该参数为需要设置选项的套接字。
* 传参`SOCK _STREAM`表示该套接字用于创建面向连接的可靠字节流套接字。
* 传参选项`SO_REUSEADDR`表示允许在套接字关闭后立即重用相同的地址和端口。
* optval设置为非零值，表示启用了该选项。

![image-20231004181122667](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202310041811620.png)

### 流量控制

