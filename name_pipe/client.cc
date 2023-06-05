#include"pipehead.hpp"

using namespace std;

int main()
{
    cout<<"client begin"<<endl;
 int wfd=open(NAME_PIPE,O_WRONLY);
 cout<<"client end"<<endl;
if(wfd<0)  exit(1);

//写
    char buffer[1024];
while(true)
{
 cout<<"client says: ";

 fgets(buffer,sizeof(buffer),stdin);//把输入流的内容写进buffer,fgets会把\n也输入，所以要把\n去掉
 if(strlen(buffer)>0) buffer[strlen(buffer)-1]=0;

 ssize_t n= write(wfd,buffer,strlen(buffer));//把buffer的内容写进文件描述符里

 assert(n==strlen(buffer));
 (void)n;

}

    return 0;
}