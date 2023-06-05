#include<iostream>
#include<vector>
#include<unistd.h>
#include<string.h>
#include<cassert>
#include<ctime>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;
#define PROCESS_NUM 3
#define MakeSeed() srand((unsigned long)time(nullptr)^getpid()^rand()%1234)//建立伪随机数种子
//创建父进程给子进程派发的任务列表
typedef void(*func_t)();//函数指针类型，函数返回值为void

void downloadTask()//模拟下载任务
{
    cout<<getpid()<<": 下载任务\n"<<endl;
    sleep(1);
}

void fflushTask()//模拟刷新任务
{
    cout<<getpid()<<": 刷新任务\n"<<endl;
    sleep(1);
}

void subscribeTask()//模拟订阅任务
{
    cout<<getpid()<<": 订阅任务\n"<<endl;
    sleep(1);
}
//把上面的三种任务load到列表中即让存放函数指针的vector的各个指针能够指向上面的函数，为了后面方便调用
void loadTaskFunc(vector<func_t>*out)
{
    assert(out);//vector创建成功
    out->push_back(downloadTask);
    out->push_back(fflushTask);
    out->push_back(subscribeTask);

}

//创建子进程对象
class  SubEp//endpoint---子进程对象
{

public:
SubEp(pid_t subid,int writefd)//第一个参数是子进程的pid，第二个参数是该子进程读端对于父进程的写端fd
:_subid(subid)
,_writefd(writefd)
{
   char namebuffer[1024];
   //第一个参数是表示第几号子进程，第二个参数是子进程的pid，第三个参数是该子进程读端对于的父进程的写端
   snprintf(namebuffer,sizeof namebuffer,"process: %d [pid(%d) - fd(%d)]",num++,_subid,_writefd);
   _name=namebuffer;
}
public:
static int num;
string _name;
pid_t _subid;
int _writefd;//该子进程与父进程匿名管道对于的父进程的写端fd
};
int SubEp::num=0;

int receiveTask(int readfd)
{
    int retcode=0;//返回任务码
    ssize_t s= read(readfd,&retcode,sizeof(retcode));//从读端读出来的任务码放到retcode里
    cout<<"process has read the TaskCode: "<<retcode<<endl;
    if(s==sizeof(int)) return retcode;
    else if(s<=0)return -1;
    else return 0;
}

void CreateSubProcesses( vector<SubEp>*subs,vector<func_t>& funcMap)
{
   vector<int> deleteFd;
//创建子进程并且创建好父进程与各个子进程通信的管道
int fds[2];
for(size_t i=0;i<PROCESS_NUM;i++)//创建子进程
{
        int n=pipe(fds);//建立父子间进程的匿名管道--建立成功返回0，建立失败返回-1
        assert(n==0);//判断管道是否建立成功
        (void)n;

        pid_t id=fork();//创建子进程
        if(id==0)//子进程进入判断语句
        {
            for(size_t i=0;i<deleteFd.size();i++) close(deleteFd[i]);//因为有写实拷贝，所以这里关闭不会影响父进程
//因为子进程会继承父进程文件描述符表，所以上一个子进程的读端对应的父进程的写端这个进程也会继承下来，即当前子进程和上一个子进程之间也有匿名管道
//可能会导致上一个子进程的父进程读端关闭，而此时还有当前这个子进程的读端连接着上一个子进程，使得上一个子进程不能正常关闭读端而造成bug
//所以要手动关闭当前子进程对应上一个子进程的读端的写端。
            close(fds[1]);//关闭子进程的写端-保留读端负责读
           //对子进程操作
     while(true)
     {
        //1. 获取任务码，让子进程阻塞等待父进程写写入的任务码，
        int taskcode=receiveTask(fds[0]);
        //2.完成任务--调用对应任务码的函数
        if(taskcode>=0 && taskcode<funcMap.size())
         funcMap[taskcode]();//调用函数完成任务
        else if(taskcode==-1)  break;
     }
            exit(0);
        }
  //写端关闭，读端读到0然后读端自己关闭
        close(fds[0]);//关闭当前子进程与父进程相联系的匿名管道的父进程的读端
        SubEp sub(id,fds[1]);//第一个参数传的是子进程的pid，第二个参数传的是此时子进程读端对于的父进程的写端
        subs->push_back(sub);
      deleteFd.push_back(fds[1]);//记录当前的写端供下个子进程用

}
}
void sendTask(const SubEp& process, int tasknum)
{
    cout<<"send Task num: "<<tasknum<<" to the process: "<<process._name<<endl;//打印日志：任务几发送给几号子进程
    ssize_t n=write(process._writefd,&tasknum,sizeof(tasknum));//该子进程读端对于的写端往管道里写入任务几-4个字节的数据
    assert(n==sizeof(int));//判断写入的数据是否是4个字节
    (void)n;
}

void loadBalanceContrl(const vector<SubEp>& subs,const vector<func_t> &funcMap,int comcode)
{
    int processnum=subs.size();//子进程的个数
    int tasknum=funcMap.size();//任务的个数
    bool numoftime=(comcode==0?true:false);//若命令码是0则一直运行，若命令码为正数x，则允许x次后退出
    while(true)
    {
        //rand()为伪随机数
   //1.找到哪一个子进程
   int subIndex=rand()%processnum;
    //2.找到哪一个执行哪一个任务
   int taskIndex=rand()%tasknum;
    //3.任务发送给选择的进程
     sendTask(subs[subIndex],taskIndex);//第一个参数传第几个子进程，第二个参数传第几个任务
     sleep(1);
  if(!numoftime)
  {
    comcode--;
    if(comcode==0)
    break;
  }
    }
    //走到这里则是父进程给子进程通信完了，需要逐个关闭子进程读端对于的写端--倒退关解决bug
    // for(size_t i=0;i<subs.size();i++)//子进程从后往前倒过来关闭写端会出现bug？？
    // {
    //   close(subs[i]._writefd);
    //   cout<<"close process: [ "<<i<<" ]'s writeeop"<<endl;
    // //    waitpid(subs[i]._subid,nullptr,0);
    // //     cout<<"wait success for process: "<<subs[i]._subid<<endl;
    // }
        for(size_t i=0;i<subs.size();i++)//从后往前关闭写端
    {
      close(subs[i]._writefd);
      cout<<"close process: [ "<<i<<" ]'s writeeop"<<endl;
          //  waitpid(subs[i]._subid,nullptr,0);//关闭完直接让父进程回收子进程
        //cout<<"wait success for process: "<<subs[i]._subid<<endl;
    }
}

void waitProcess(const vector<SubEp>& processes)//从前往后回收子进程
{
    for(size_t i=0;i<processes.size();i++)
    {
        waitpid(processes[i]._subid,nullptr,0);
        cout<<"wait success for process: "<<processes[i]._subid<<endl;
    }
}
// void waitProcess(const vector<SubEp>& processes)//从后往前回收子进程
// {
//     for(size_t i=processes.size()-1;i>=0;i--)
//     {
//         waitpid(processes[i]._subid,nullptr,0);
//         cout<<"wait success for process: "<<processes[i]._subid<<endl;
//     }
// }

int main()
{
    MakeSeed();//建立伪随机数种子

vector<SubEp> subs;//创建子进程对象并将子进程对象放进数组里
vector<func_t> funcMap;//建立一个任务表：父进程写入管道，子进程在管道读取，读取到的数据引导子进程去完成一些任务
loadTaskFunc(&funcMap);

//1.创建子进程并且创建好父进程与各个子进程通信的管道,并且让子进程阻塞等待父进程写入
CreateSubProcesses(&subs,funcMap);

//2.对父进程操作

//父进程给子进程发送命令码，为0则一直运行，为正数x则运行x次后退出
int Runcount=0;
cout<<"请输入需要执行几次任务，输入0则为一直循环执行任务，请输入: ";
cin>>Runcount;
cout<<endl;
//这个函数负责让父进程给子进程发送命令码，让子进程去执行任务，要求子进程做到负载均衡     
loadBalanceContrl(subs,funcMap,Runcount);//第一个参数是子进程列表，第二个参数任务列表，第三个参数是父进程给子进程发送的命令码 

//3.回收子进程
waitProcess(subs);
    return 0;
}