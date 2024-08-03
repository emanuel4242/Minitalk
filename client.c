#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.c"


void    ft_sendmessage(unsigned char c, int pid)
{
    int i = 8;
    char temp;

    while(i-- )
    {
        temp = c >> i;
        if (temp % 2 == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(100);
    }
}
int main(int argc, char **argv)
{
    int pid;
    unsigned char   *str;
    int i;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = argv[2];
        i = 0;
        while (str[i])
        {
            ft_sendmessage(str[i], pid);
            i++;
        }
        ft_sendmessage('\0', pid);
    }
    else
        write(1, "This is not the structure", 24);
    return (0);
}