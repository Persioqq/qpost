#include <stdio.h>
#include <string.h>

#include "requests.h"

static void
help() 
{
	printf("\n\e[0;36;40musage:\033[m\n\n  \e[0;36;40mgetting help:\033[m\n    qpost help:\n\n  \e[0;36;40mget request:\033[m\n    qpost get [url]\n\n  \e[0;36;40mpost request:\033[m\n    qpost post [url] [thing to post]\n\n  \e[0;36;40mput request:\033[m\n    qpost put [url] [thing to put]\n\n  \e[0;36;40mdelete request:\033[m\n    qpost delete [url] [thing to delete]\n\n  \e[0;36;40mexamples:\033[m\n    get: qpost get 127.0.0.1:8080/countries\n    post: qpost post 127.0.0.1:8080/countries \'{\"Name\": \"USA\", \"Language\": \"English\"}\'\n\n");
}

int
main(int argc, char *argv[]) 
{
	if(argc == 1)
	{
		printf("\033[31;1merror:\033[m Missing argument\n");
		help();
		return 1;
	}

	else
	{
		if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0)
			help();
		
		else if(strcmp(argv[1], "get") == 0)
			getrequest(argv[2]);
		
		else if(strcmp(argv[1], "post") == 0)
		{
			if(argc == 3)
			{
				printf("\033[31;1merror:\033[m Missing argument to post\n");
				help();
				return 1;
			}
			
			postrequest(argv[2], argv[3]);
		}
		
		else if(strcmp(argv[1], "put") == 0)
		{
			if(argc == 3)
			{
				printf("\033[31;1merror:\033[m Missing argument to put\n");
				help();
				return 1;
			}
			
			putrequest(argv[2], argv[3]);
		}
		
		else if(strcmp(argv[1], "delete") == 0)
		{
			if(argc == 3)
			{
				printf("\033[31;1merror:\033[m Missing argument to delete\n");
				help();
				return 1;
			}
			
			deleterequest(argv[2], argv[3]);
		}
	}
  	
	return 0;
}
