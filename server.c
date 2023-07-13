/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:37:50 by cde-voog          #+#    #+#             */
/*   Updated: 2023/07/13 16:38:24 by cde-voog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

static void	ft_display(pid_t pid)
{
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_display(pid);
	signal(SIGUSR2, ft_handler);
	signal(SIGUSR1, ft_handler);
	while (1)
		pause();
	return (0);
}
