#include<iostream>
#include<signal.h>
#include<unistd.h>
using namespace std;
void handler(int signo)
{
cout<<"进程捕捉到了一个信号，信号编号是： "<<signo<<endl;

}
int main()
{
    signal(2,handler);
    while(1)
    {
        cout<<"我是一个进程，mypid: "<<getpid()<<endl;
        sleep(1);
    }
    
    return 0;
}