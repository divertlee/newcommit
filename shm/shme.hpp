#ifndef _SHME_HPP_
#define _SHME_HPP_
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>
#include<unistd.h>

#define PATH_NAME "."//pathname
#define PROJ_ID 0x66//ID
#define MAX_SIZEE 4096//size
using namespace std;

int getshmhelper(key_t k,int flags)
{
     int shmid=shmget(k,MAX_SIZEE,flags);
 if(shmid<0)//创建失败
 {
    cerr<<errno<<"errno: "<<strerror(errno)<<endl;
    exit(2);
 }
 return shmid;
}

int getshm(key_t k)//获取共享内存
{

 return getshmhelper(k,IPC_CREAT);


}

int creatshm(key_t k)//创建新的共享内存
{
return getshmhelper(k,IPC_CREAT|IPC_EXCL| 0600);

}

key_t getkey()//获取key
{
    key_t k= ftok(PATH_NAME,PROJ_ID);
    if(k<0)
    {
        cerr<<errno<<"errno: "<<strerror(errno)<<endl;
        exit(-1);
    }
    return k;
}

void* attachshm(int shmid)//进程与共享内存挂接
{
    void*ret=shmat(shmid,nullptr,0);
    if((long long)ret==-1L)
    {
        cerr<<errno<<"errno: "<<strerror(errno)<<endl;
        exit(-1);
    }
    return ret;
}

void detech(void*start)//去关联
{
    if(shmdt(start))
    {
        cerr<<errno<<"errno: "<<strerror(errno)<<endl;
        exit(-1);
    }
}

void detachShm(int shmid)//释放共享内存
{
 int rm=shmctl(shmid,IPC_RMID,nullptr);
 if(rm<0)
 {
          cerr<<errno<<"errno: "<<strerror(errno)<<endl;
        exit(-1);
 }

}

#endif