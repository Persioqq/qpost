#include "util.h"

size_t
writememorycallback(void *contents, const size_t size, const size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
  	struct memorystruct *mem = (struct memorystruct *)userp;
	char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  	
	if(ptr == NULL)
	{
		printf("\033[31;1merror:\033[m Not enough memory\n");
		return 0;
  	}

  	mem->memory = ptr;
  	memcpy(&(mem->memory[mem->size]), contents, realsize);
  	mem->size += realsize;
  	mem->memory[mem->size] = 0;

  	return realsize;
}
