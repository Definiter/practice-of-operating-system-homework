#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char* get_process_name(const int pid)
{
	char *name = (char *)calloc(1024, sizeof(char));
	if (name) {
		sprintf(name, "/proc/%d/cmdline",pid);
		FILE *fp = fopen(name,"r");
		if (fp) {
			size_t size;
			size = fread(name, sizeof(char), 1024, fp);
			if(size > 0 && '\n' == name[size - 1]){
				name[size - 1]='\0';
			}
			fclose(fp);
			return name;
		}
	}
	return NULL;
}

const int get_parent_pid(const int pid) {
	char st[1024];
	FILE *fp;
	int ppid;
	size_t size; 
	sprintf(st, "/proc/%d/stat", pid);
	fp = fopen(st, "r");
	if (fp) {
		size = fread(st, sizeof(char), 1024, fp);
		sscanf(st, "%*d%*s%*s%d", &ppid);
		fclose(fp);	
		return ppid;
	} else {
		return -1;
	}
}

int main() {
	pid_t pid, ppid;
	int perf = 0;
	pid = getpid();
	while (pid != 0) {
		ppid = get_parent_pid(pid);
		printf("[%d] %s -> [%d] %s\n", ppid, get_process_name(ppid),
			pid, get_process_name(pid));
		if (ppid > 0 && strstr(get_process_name(ppid), "perf") != NULL) {
			printf("Found perf.\n");
			perf = 1;
		}
		pid = ppid;
	}
	if (!perf) {
		printf("perf not found.\n");	
	}
	return 0;
}
