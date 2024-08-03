#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_binary_to_char(int   sig)
{
    static unsigned int bit;
    static char i;

    i |= (sig = SIGUSR1);
    bit++;
    if (bit == 8)
    {
        write(1, &i, 1);
        bit = 0;
        i = 0;
    }
    else
         i <<= 1;
}
int main(int argc, char **argv)
{
    signal(SIGUSR1, ft_binary_to_char());
    signal(SIGUSR2, ft_binary_to_char());

    while(1)
    {
        pause(void);
    }
    return (0);
}