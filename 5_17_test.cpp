
#include<iostream>
#include<unordered_map>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
using namespace std;

int main()
{
//第一步，父进程创建管道
    int fds[2];
    int n=pipe(fds);
    assert(n==0);//返回0保证匿名管道创建成功

//第二步，父进程创建子进程
pid_t id=fork();
assert(id>=0);//若fork成功，那么子进程返回0， 返回给父进程 子进程的id
if(id==0)//这里对子进程进行操作
{
    close(fds[0]);//子进程关闭读端
    const char* s="i am child , i am sending message to father";
    int cnt=0;
    while(true)
    {
        cnt++;
        char buffer[1024];//创建缓冲区
        snprintf(buffer,sizeof buffer,"child say to parent:%s,childpid[%d],[%d]",s,getpid(),cnt);
        cout<<"count: "<<cnt<<endl;//子进程一直写
        write(fds[1],buffer,strlen(buffer));//子进程往写端进行写入
        //sleep(50);//子进程间断时间写
        //break;
    }
    close(fds[1]);
    exit(0);
}

//父进程操作
close(fds[1]);//父进程关闭写端
while(true)
{
    sleep(2);//父进程间歇性休眠
char buffer[1024];//创建缓冲区    
cout<<"正在读取：......"<<endl;
ssize_t s=read(fds[0],buffer,sizeof(buffer)-1);//流一个位置给/0
cout<<"读取成功！"<<endl;
if(s>0)//写入成功
{
    buffer[s]=0;//给字符串末尾添加上0
    cout<<"father get message: "<<buffer<<"|fatherpid: "<<getpid()<<endl;
    break;
}else if(s==0)//没写入
{
    cout<<"read: nothing "<<endl;
    break;
}
}
close(fds[0]);
  cout<<"父进程关闭读端"<<endl;
int status=0;
    n=waitpid(id,&status,0);
    assert(n==id);//父进程等待子进程（回收子进程）
cout<<"子进程退出信号："<<(status&0x7F)<<endl;
    return 0;
}


// int main()
// {
//     //第一步创建管道，打开读写端
//     int fds[2];
//     int n=pipe(fds);
//     assert(n==0);//等于0说明创建管道成功
//     //第二步，创建子进程
//     pid_t id=fork();
//     assert(id>=0);

//     if(id==0)
//     {
//         close(fds[0]);//子进程负责写，关闭读端stdin
//          int cnt=0;
//     const char* s="我是子进程，在给你发消息";
//         //子进程操作
//         while(true)
//         {
//             cnt++;
//         char buffer[1024];
//         snprintf(buffer,sizeof buffer,"child say to parent:%s[%d],[%d]",s,cnt,getpid());
//         //将后面那段匿名字符串全部写入buffer字符串中,并在末尾自动添加/0
//         write(fds[1],buffer,strlen(buffer));//把buffer里的内容按字节写入文件描述符fd指定的文件中
//         //子进程（写端）睡眠，看父进程（读端是否会阻塞等待)---会
//        // sleep(5);
        
//         }

//         close(fds[1]);
//         cout<<"子进程已关闭写端"<<endl;
//         exit(0);
//     }

//     //父进程操作
//   close(fds[1]);//父进程负责读，关闭写段
//   while(true)
//   {
//     char buffer[1024];
//     ssize_t s=read(fds[0],buffer,sizeof(buffer)-1);//把fd[0]指定的文件的内容读到buffer中，读sizeof(buffer)-1，在buffer最后预留一个位置给/0
//     if(s>0)//写入成功
//     {
//         buffer[s]=0;
//         cout<<"get msg: "<<buffer<<"| my pid: "<<getpid()<<endl;
//     }else if(s==0)//没写入
//     {
//         cout<<"read: "<<endl;
//         break;
//     }
//     //父进程（读端）睡眠，看子进程（写端）行为---写端会往管道里一直写，直至写满，读端看自己读取
//     sleep(2); 
//   }
//   close(fds[0]);
//   cout<<"父进程关闭读端"<<endl;
//     n=waitpid(id,nullptr,0);
//     assert(n==id);//父进程等待子进程（回收子进程）

//     return 0;
// }