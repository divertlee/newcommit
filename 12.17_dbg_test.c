#include<stdio.h>
#include<time.h>
 void Print(int num)
 {
	   long long timestamp = time(NULL);
	  printf("result= %d ,timestamp= %lld\n", num, timestamp);
	 }
 int Addsum(int i, int sum)
 {
	 int num = i;
	 for (; i <= sum; ++i)
 {
   num += i;
		 }
	return num;
	 }
int main()
 {
	 int sum = Addsum(0, 100);
	 Print(sum);
	   return 0;
	 }