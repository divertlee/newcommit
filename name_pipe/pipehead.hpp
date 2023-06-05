#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<assert.h>
using namespace std;

#define NUM 5
#define NAME_PIPE "/home/ljp/name_pipe/mypipe"
#define MakeSeed() srand((unsigned long)time(nullptr)^getpid()^rand()%1234)//建立伪随机数种子

bool CreateFifo( const string & path){
umask(0);

int n=mkfifo(path.c_str(),0600);
if(n==0) return true;
else{
    cout<<"errno:"<<errno<<"err string: "<<strerror(errno)<<endl;
    return false;
}
}

void removeFifo(const string & path){
    int n=unlink(path.c_str());
    assert(n==0);
    (void)n;
}

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