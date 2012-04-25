//
//  watchfox.c
//  craftIkWF
//
//  Created by Cyrus Hackford on 4/25/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, const char **argv) {
	int WFExitCode=EXIT_SUCCESS;
	
	printf("craftIk WatchFox(TM)\nIn case server daemon exits, crashes, etc, WatchFox(TM) will restart the process.\n\n");
	
	while(1) {
		pid_t WFChildProcessID=fork();
		
		if(WFChildProcessID==-1) { // fork() fail.
			fprintf(stderr, "ERROR: Attempt to create a child process has failed. (0x%X) :(\n\nTerminating...\n", errno);
			abort();
		} else if(WFChildProcessID==0) { // on child's side.
			execv("craftIk", (char *const *)argv);
			
			// Lines below will never be executed upon successful execv() call.
			fprintf(stderr, "ERROR: Child says: 'Failed to execute server daemon. (0x%X) :('\n\nTerminating...\n", errno);
			WFExitCode=0xC820;
			
			break;
		} else { // on WatchFox(TM)'s side.
			int WFChildExitCode=EXIT_SUCCESS;
			
			waitpid(WFChildProcessID, &WFChildExitCode, 0);
			if(WFChildExitCode==0xC820)
				abort();
			else if(WFChildExitCode==0xB05D)
				break;
		}
		
		printf("Server restart in 5 seconds. To stop, press ctrl+C now.\n");
		sleep(5);
	}
	
	return WFExitCode;
}