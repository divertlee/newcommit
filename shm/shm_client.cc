#include"shme.hpp"

int main()
{
  key_t k=getkey();
printf("0x%x\n",k);
 int shmid=getshm(k);//获取共享内存
    cout<<"shmid: "<<shmid<<endl;
    //挂接
   char* atshm=(char*)attachshm(shmid);
 printf("client attach address: %p\n",atshm);
 //通信：client作为写端
 int cnt=0;
char bufffer[1024];
const char* message="hello server:im client,im talking to you";
while(true)
{
    snprintf(atshm,MAX_SIZEE,"%s[pid: %d][消息编号: %d]",message,getpid(),cnt++);
    sleep(5);
}

 //进程与共享内存去关联
detech(atshm);
    return 0;
}