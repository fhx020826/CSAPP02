#include <iostream>
#include <sys/time.h>

using namespace std;

#define  ROW_SIZE (32)
#define  COL_SIZE (1024*1024)

struct	timeval	g_tstart[2], g_tend[2];
double  g_fCopyTime[2]; 

int src_data[ROW_SIZE][COL_SIZE];
int dst_data[ROW_SIZE][COL_SIZE];

void copyij(int src[ROW_SIZE][COL_SIZE],
            int dst[ROW_SIZE][COL_SIZE])
{
  int i,j;
  for (i = 0; i < ROW_SIZE; i++)
    for (j = 0; j < COL_SIZE; j++)
      dst[i][j] = src[i][j];
}

void copyji(int src[ROW_SIZE][COL_SIZE],
            int dst[ROW_SIZE][COL_SIZE])
{
  int i,j;
  for (j = 0; j < COL_SIZE; j++)
	  for (i = 0; i < ROW_SIZE; i++)
      dst[i][j] = src[i][j];
}
 
int main()
{
	gettimeofday(g_tstart, NULL);
	copyij(src_data, dst_data);
	gettimeofday(g_tend, NULL);
	
	gettimeofday(g_tstart+1, NULL);
	copyji(src_data, dst_data);
	gettimeofday(g_tend+1, NULL);
	
	for(int i=0;i<2;i++)
	{
		g_fCopyTime[i] = (g_tend[i].tv_sec - g_tstart[i].tv_sec)*1000 + (g_tend[i].tv_usec - g_tstart[i].tv_usec)*0.001; //unit: ms
	}
	cout<<"Matrix Size is: "<<ROW_SIZE<<"*"<<COL_SIZE<<endl;
    cout<<"Time of Copyij is: "<<g_fCopyTime[0]<<"ms"<<endl;
	cout<<"Time of Copyji is: "<<g_fCopyTime[1]<<"ms"<<endl;
	
	getchar();
	
	return 0;
}
