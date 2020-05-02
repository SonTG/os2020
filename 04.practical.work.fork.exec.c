#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
	printf("Main before fork()\n");
	int pid = fork();
  
	if (pid == 0){
		int pid2 = fork();
    
		if (pid2 == 0){
			printf("I am child after fork(), launching ps -ef\n");
			char *args[] = {"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", args);
		}
    else {
		  wait(NULL);
		  printf("I am parent after fork(), child is %d\n", pid2);
		}
    
		printf("I am child after fork(), launching free -h\n");
		char *args[] = {"free", "-h", NULL};
		execvp("free", args);
	}
  else {
	  wait(NULL);
		printf("I am parent after fork(), child is %d\n", pid);
	}
	printf("Complete!\n");
	return 0;

}
