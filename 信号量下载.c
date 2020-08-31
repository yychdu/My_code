#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <windows.h>

#define MAXNUM 2
sem_t semDownload;
pthread_t a_thread, b_thread, c_thread;
int g_phreadNum = 1;

void InputInfo(void)
{
	printf("****************************************\n");
	printf("*** which task you want to download? ***\n");
	printf("*** you can enter [1-3],[0] is done  ***\n");
	printf("****************************************\n");
}
void *func1(void *arg)
{
	//等待信号量的值>0
	sem_wait(&semDownload);
	printf("==============  Downloading Task 1  ============== \n");
	Sleep(5000);
	printf("==============    Finished Task 1   ============== \n");
	g_phreadNum--;
	//等待线程结束 
	pthread_join(a_thread, NULL);
}

void *func2(void *arg)
{
	sem_wait(&semDownload);
	printf("==============  Downloading Task 2  ============== \n");
	Sleep(3000);
	printf("==============    Finished Task 2   ============== \n");
	g_phreadNum--;
	pthread_join(b_thread, NULL);
}

void *func3(void *arg)
{
	sem_wait(&semDownload);
	printf("==============  Downloading Task 3  ============== \n");
	Sleep(1000);
	printf("==============    Finished Task 3   ============== \n");
	g_phreadNum--;
	pthread_join(c_thread, NULL);
}

int main()
{
	int taskNum;
	InputInfo();

	while (scanf("%d", &taskNum) != EOF) {
		//输入0,判断是否正常退出
		if (taskNum == 0 && g_phreadNum <= 1) {
			break;
		}
		if (taskNum == 0){
			printf("Can not quit, casue count of threads is [%d]\n", g_phreadNum - 1);
		}
                //初始化信号量
		sem_init(&semDownload, 0, 0);
		printf("your choose Downloading Task [%d]\n", taskNum);
		//线程数超过2个则不下载
		if (g_phreadNum > MAXNUM) {
			printf("!!! You've reached a limit on the number of threads !!!\n");
			continue;
		}
		//用户选择下载Task
		switch (taskNum)
		{
		case 1:
			//创建线程1
			pthread_create(&a_thread, NULL, func1, NULL);
			//信号量+1，进而触发fun1的任务
			sem_post(&semDownload);
			//总线程数+1
			g_phreadNum++;
			break;
		case 2:
			pthread_create(&b_thread, NULL, func2, NULL);
			sem_post(&semDownload);
			g_phreadNum++;
			break;
		case 3:
			pthread_create(&c_thread, NULL, func3, NULL);
			sem_post(&semDownload);
			g_phreadNum++;
			break;
		default:
			printf("!!! eroor task [%d]  !!!\n", taskNum);
			break;
		}

	}

	//销毁信号量
	sem_destroy(&semDownload);
	return 0;
}