//
//  WatchFox.c
//  craftIk
//
//  Created by Cyrus Hackford on 5/29/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, const char **argv) {
	char **WFExecArgs=NULL;
	int WFExitCode=EXIT_SUCCESS;
	
	printf("craftIk WatchFox(TM)\nIn case server daemon crashes, WatchFox(TM) will restart the process.\n\n");
	
	WFExecArgs=(char **)malloc(sizeof(char *)*2);
	if(WFExecArgs==NULL) {
		fprintf(stderr, "ERROR: Not enough memory on the system. (0x%X) :(\n\nTerminating...\n", errno);
		abort();
	}
	WFExecArgs[0]=strstr(argv[0], "craftIk_run");
	if(WFExecArgs==NULL)
		WFExecArgs[0]="./"; // fallback?
	else {
		int WFTemp=(int)(WFExecArgs[0]-argv[0]);
		
		WFExecArgs[0]=(char *)malloc(sizeof(char)*((size_t)(WFTemp+1)));
		strncpy(WFExecArgs[0], argv[0], WFTemp);
	}
	WFExecArgs[1]=NULL;
	
	while(1) {
		pid_t WFChildProcessID=fork();
		
		if(WFChildProcessID==-1) { // fork() fail.
			fprintf(stderr, "ERROR: Attempt to create a child process has failed. (0x%X) :(\n\nTerminating...\n", errno);
			abort();
		} else if(WFChildProcessID==0) { // on child's side.
			execv("craftIk", WFExecArgs);
			
			// Lines below will never be executed upon successful execv() call.
			fprintf(stderr, "ERROR: Child says: 'Failed to execute server daemon. (0x%X) :('\n\nTerminating...\n", errno);
			WFExitCode=0xC4B5;
			
			break;
		} else { // on WatchFox(TM)'s side.
			int WFChildExitCode=EXIT_SUCCESS;
			
			waitpid(WFChildProcessID, &WFChildExitCode, 0);
			if(WFChildExitCode==0xC4B5)
				abort();
			else if(WFChildExitCode==0xB05D)
				break;
		}
		
		printf("Server restart in 5 seconds. To stop, press ctrl+C now.\n");
		sleep(5);
	}
	free(WFExecArgs[0]);
	free(WFExecArgs);
	
	return WFExitCode;
}