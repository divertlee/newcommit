1 #include"process.h"
2 char style[S_NUM] = { '+','.','*','>','/' };
3 void ProcessOn()
4 {
    5 int num = 0;
    6 char arr[SUM];
    7 memset(arr, '\0', sizeof(arr));
    8 const char* lable = "|\\¡ª¡ª/";
    9 while (num <= 100)
        10 {
        11 printf("[%-100s][%-3d%%][%c]\r", arr, num, lable[num % 4]);
        12 fflush(stdout);
        E > 13 arr[num++] = style;
        14 usleep(50000);
        15 }
    16 printf("\n");
    17 }
~
