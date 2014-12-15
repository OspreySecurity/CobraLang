

#ifndef COMMON_H_
#define COMMON_H_

#define STRING_LIMIT 50000

// In c, bool isn't defined as a type. So here you go
typedef int bool;
#define true 1;
#define false 0;

char* substr(const char* str, int start, int length);

#endif // COMMON_H_