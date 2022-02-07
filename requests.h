#ifndef REQUESTS_H
#define REQUESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "util.h"

void getrequest(const char *url);
void postrequest(const char *url, const char *post);
void putrequest(const char *url, const char *putpost);
void deleterequest(const char *url, const char *deletepost);

#endif // REQUESTS_H
