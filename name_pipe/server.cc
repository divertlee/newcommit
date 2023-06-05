#include"pipehead.hpp"
using namespace std;

int main()
{
         MakeSeed();//建立伪随机数种子
 vector<func_t> funcMap;//建立一个任务表：父进程写入管道，子进程在管道读取，读取到的数据引导子进程去完成一些任务
loadTaskFunc(&funcMap);

 bool r= CreateFifo(NAME_PIPE);//创建管道文件
 assert(r);
 (void)r;
    cout<<"server begin"<<endl;
int rfd=open(NAME_PIPE,O_RDONLY);//当读端打开了文件，然而写端没有打开，那么读端就会阻塞在这里等待写端打开，写端打开了才往后走
    cout<<"server end"<<endl;
if(rfd<0)  exit(1);
//sleep(10);

//读
char buffer[1024];
while(true)
{

    ssize_t n=read(rfd,buffer,sizeof(buffer)-1);//读

    if(n>0)
    {
        buffer[n]=0;
       // cout<<"server read: "<<buffer<<endl;//打印读到的内容

    }
    else if(n==0)
    {
        cout<<"client quit!,i quit either"<<endl;//写端退出，读端也退出
        break;
    }else
    {
        cout<<"err string: "<<strerror(errno)<<endl;//打印错误信息
        break;
    }
    (void)n;
}

removeFifo(NAME_PIPE);//删除管道文件
    return 0;
}