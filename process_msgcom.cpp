
#include<iostream>
#include<unordered_map>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
using namespace std;

int main()
{
    //��һ�������ܵ����򿪶�д��
    int fds[2];
    int n = pipe(fds);
    assert(n == 0);//����0˵�������ܵ��ɹ�
    //�ڶ����������ӽ���
    pid_t id = fork();
    assert(id >= 0);

    if (id == 0)
    {
        close(fds[0]);//�ӽ��̸���д���رն���stdin
        int cnt = 0;
        const char* s = "�����ӽ��̣��ڸ��㷢��Ϣ";
        //�ӽ��̲���
        while (true)
        {
            cnt++;
            char buffer[1024];
            snprintf(buffer, sizeof buffer, "child say to parent:%s[%d],[%d]", s, cnt, getpid());
            //�������Ƕ������ַ���ȫ��д��buffer�ַ�����,����ĩβ�Զ����/0
            write(fds[1], buffer, strlen(buffer));//��buffer������ݰ��ֽ�д���ļ�������fdָ�����ļ���
            //�ӽ��̣�д�ˣ�˯�ߣ��������̣������Ƿ�������ȴ�)---��
           // sleep(5);

        }

        close(fds[1]);
        cout << "�ӽ����ѹر�д��" << endl;
        exit(0);
    }

    //�����̲���
    close(fds[1]);//�����̸�������ر�д��
    while (true)
    {
        char buffer[1024];
        ssize_t s = read(fds[0], buffer, sizeof(buffer) - 1);//��fd[0]ָ�����ļ������ݶ���buffer�У���sizeof(buffer)-1����buffer���Ԥ��һ��λ�ø�/0
        if (s > 0)//д��ɹ�
        {
            buffer[s] = 0;
            cout << "get msg: " << buffer << "| my pid: " << getpid() << endl;
        }
        else if (s == 0)//ûд��
        {
            cout << "read: " << endl;
            break;
        }
        //�����̣����ˣ�˯�ߣ����ӽ��̣�д�ˣ���Ϊ---д�˻����ܵ���һֱд��ֱ��д�������˿��Լ���ȡ
        sleep(2);
    }
    close(fds[0]);
    cout << "�����̹رն���" << endl;
    n = waitpid(id, nullptr, 0);
    assert(n == id);//�����̵ȴ��ӽ��̣������ӽ��̣�

    return 0;
}