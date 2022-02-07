#include "requests.h"

#define USERAGENT "libcurl/7.81.0"

void 
getrequest(const char *url)
{
	CURL *curl_handle;
	CURLcode res;
	
	struct memorystruct chunk;
	chunk.memory = malloc(1);  
	chunk.size = 0;
	
	curl_handle = curl_easy_init();
	if(curl_handle)
	{
		curl_easy_setopt(curl_handle, CURLOPT_URL, url);
		curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	  	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, &writememorycallback);
	  	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
	  	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, USERAGENT);
	
	  	res = curl_easy_perform(curl_handle);
	
	  	if(res != CURLE_OK)
			fprintf(stderr, "\033[31;1merror:\033[m %s\n", curl_easy_strerror(res)); 
	  	else 
		{
	  		printf("\e[0;36;40mSize:\033[m %lu\n", (unsigned long)chunk.size);
			printf("\e[0;36;40mData:\033[m %s\n", chunk.memory);
	  	}

	  	curl_easy_cleanup(curl_handle);
	  	free(chunk.memory);
	}
}

void
postrequest(const char *url, const char *post)
{
	CURL *curl_handle;
	CURLcode res;
	
	curl_handle = curl_easy_init();
	if(curl_handle) 
	{
	  	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	  	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	  	curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, post);
	  	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, USERAGENT);
	
	  	res = curl_easy_perform(curl_handle);
	
	  	if(res != CURLE_OK)
			fprintf(stderr, "\033[31;1merror:\033[m %s\n", curl_easy_strerror(res));
	  	else 
		{
	  		printf("\e[0;36;40mPost Size:\033[m %lu\n", strlen(post));
	  		printf("\e[0;36;40mPost Data:\033[m %s\n", post);
	  	}

	  	curl_easy_cleanup(curl_handle);
	}
}

void
putrequest(const char *url, const char *putpost)
{
	CURL *curl_handle;
	CURLcode res;
	
	curl_handle = curl_easy_init();
	if(curl_handle) 
	{
	  	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	  	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	  	curl_easy_setopt(curl_handle, CURLOPT_CUSTOMREQUEST, "PUT"); 
		curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, putpost);
	  	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, USERAGENT);
	
	  	res = curl_easy_perform(curl_handle);
	
	  	if(res != CURLE_OK)
			fprintf(stderr, "\033[31;1merror:\033[m %s\n", curl_easy_strerror(res));
	  	else 
		{
	  		printf("\e[0;36;40mDelete Post Size:\033[m %lu\n", strlen(putpost));
	  		printf("\e[0;36;40mDelete Post Data:\033[m %s\n", putpost);
	  	}

	  	curl_easy_cleanup(curl_handle);
	}
}

void
deleterequest(const char *url, const char *deletepost)
{
	CURL *curl_handle;
	CURLcode res;
	
	curl_handle = curl_easy_init();
	if(curl_handle) 
	{
	  	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	  	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	  	curl_easy_setopt(curl_handle, CURLOPT_CUSTOMREQUEST, "DELETE"); 
		curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, deletepost);
	  	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, USERAGENT);
	
	  	res = curl_easy_perform(curl_handle);
	
	  	if(res != CURLE_OK)
			fprintf(stderr, "\033[31;1merror:\033[m %s\n", curl_easy_strerror(res));
	  	else 
		{
	  		printf("\e[0;36;40mDelete Post Size:\033[m %lu\n", strlen(deletepost));
	  		printf("\e[0;36;40mDelete Post Data:\033[m %s\n", deletepost);
	  	}

	  	curl_easy_cleanup(curl_handle);
	}
}
