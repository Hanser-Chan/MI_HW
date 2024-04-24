#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

#include <errno.h>
#include <cstring>

int global_var = 100;

int main()
{
    int pid = -1;
    char *str = NULL;
    int str_len = strlen("I come from parent process.");

    str = (char *)malloc(str_len);

    if (NULL == str)
    {
        printf("memory is not enough.\n");
        exit(-1);
    }
    memset(str, 0x00, str_len);
    strncpy(str, "I come from parent process.", str_len);

    pid = fork();

    if (pid == 0)
    {
        printf("here in child,my pid is %d\n", getpid());

        printf("parent bring info: global_var:%d,str:%s\n", global_var, str);
    }
    else if (pid > 0)
    {
        printf("here in parent, child pid is %d\n", pid);
    }
    else
    {
        printf("fork error[%s]\n", strerror(errno));
    }

    return 0;
}
