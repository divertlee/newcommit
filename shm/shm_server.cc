#include"shme.hpp"

int main()
{
 key_t k=getkey();//获取key
printf("0x%x\n",k);
 int shmid=creatshm(k);//创建共享内存
    cout<<"shmid: "<<shmid<<endl;
    //挂接
   char* atshm=(char*)attachshm(shmid);
 printf("server attach address: %p\n",atshm);

while(true)
{
    printf("client says: %s\n",atshm);
    sleep(1);
}

//进程与共享内存去关联
detech(atshm);
sleep(1);
  //释放共享内存
  detachShm(shmid);
    return 0;
}   