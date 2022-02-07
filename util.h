#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct memorystruct {
	char *memory;
	size_t size;
};

size_t writememorycallback(void *contents, const size_t size, const size_t nmemb, void *userp);

#endif // UTILS_H
