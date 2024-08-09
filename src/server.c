/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:08:52 by emalungo          #+#    #+#             */
/*   Updated: 2024/08/09 18:26:47 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t g_char = 0;
volatile int g_bit_count = 0;

void handle_signal(int signal)
{
    static unsigned char current_char = 0;
    static int i = 0;

    current_char <<= 1;
    if (signal == SIGUSR2)
        current_char |= 1;
    i++;
    
    if (i == 8)  // Um caractere completo foi recebido (8 bits)
    {
        write(1, &current_char, 1);
        current_char = 0;  // Reinicia para o próximo caractere
        i = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = &handle_signal;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("Server PID: %d\n", getpid());

    while (1)
        pause();  // Espera por sinais

    return 0;
}