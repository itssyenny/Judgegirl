#include<stdio.h>
#define Max(a,b) (a > b ? a : b)
int ptr[500] = {0}, JobArrival[500], TaskInfo[500][500][2], tasky[500];
int MachineReady[500] = {0};
int main() {
	int N, M; scanf("%d%d", &N, &M);
	int nTask = 0;
	for(int i = 0; i < M; i++) {
		scanf("%d%d", &JobArrival[i], &tasky[i]);
		for(int j = 0; j < tasky[i]; j++) {
			scanf("%d%d", &TaskInfo[i][j][0], &TaskInfo[i][j][1]);
		}
		nTask += tasky[i];
	}
	for(int i = 0; i < nTask; i++) {
		int minJob = 0, minCompTime = 1000000, minM = -1;
		
		for(int j = 0; j < M; j++) {
			int mtype = TaskInfo[j][ptr[j]][0], time = TaskInfo[j][ptr[j]][1];
			if(ptr[j] == tasky[j]) continue; //if it has finished all the tasks, continue to other job.
			if(Max(JobArrival[j], MachineReady[mtype]) + time < minCompTime) {
				minCompTime = Max(JobArrival[j], MachineReady[mtype]) + time;
				minJob = j;
				minM = mtype;
			}
		}
		ptr[minJob]++;
		JobArrival[minJob] = minCompTime;
		MachineReady[minM] = minCompTime;
	}

	for(int i = 0; i < M; i++) {
		printf("%d\n",JobArrival[i]);
	}

	return 0;
}