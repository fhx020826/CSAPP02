#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N  10
char  password[2][N];
int main()
{
	long long x =-9223372036854775808;
	printf("x=%lld,%0x\n",x,x);
	printf( "127 > (unsigned char)128U  =  %d\n", ( 127 > (unsigned char)128U)  );
	printf( "127 > 128  =  %d\n",(127 > 128) ) ;
	printf( "127 > (char)128  =  %d\n",(127 > (char)128) ) ;	
	exit(0);
//	printf("Please input a string \n");
//	scanf("%8s",password[0]);
//	printf("Read str is:%s\n",password[0]);
	
//	while(getchar()!= '\n');
	
//	fgets(password[1],N-1,stdin);
//	printf("Read str is:%s\n",password[1]);
   return 0;
}
