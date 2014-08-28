#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>

main(){
	char buffer[256];
	char cwd[1024];
	char* token;
	char* username;
	username = getlogin();
	getcwd(cwd, sizeof(cwd));
	printf("Hello %s, your current directory is: %s. \n", username, cwd);
	
	for(;;){
		if(fgets(buffer, 256, stdin) == NULL || (strcmp(buffer, "exit\n") == 0)){
			return(0);
		}
		
		//strips the newline character at end of input
		size_t ln = strlen(buffer) - 1;
		if(buffer[ln] == '\n') buffer[ln] = '\0';
		
		if(strlen(buffer) > 0){
			
			token = strtok(buffer, " ,.");
			
			if(strcmp(token, "repeat") == 0){
				token = strtok(NULL,  " ,.");
				while(token != NULL){
					printf("%s ", token);
					token = strtok(NULL, " ,.");
				}
				printf("\n");
			}
			else if(strcmp(token, "welcome") == 0){
				token = strtok(NULL,  " ,.");
				printf("Hello, %s\n", token);
			}
			else if(strcmp(token, "junk") == 0){
				printf("junk is here\n");
			}
		}
	}
}
