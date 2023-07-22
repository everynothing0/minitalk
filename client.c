/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:38:41 by cde-voog          #+#    #+#             */
/*   Updated: 2023/07/21 14:45:02 by cde-voog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_error(int err)
{
	if (err == 0)
	{
		ft_putstr_fd("You must enter valid PID\n", 1);
		exit(1);
	}
	else if (err == 1)
	{
		ft_putstr_fd("You must enter valid string\n", 1);
		exit(1);
	}
	else if (err == 2)
	{
		ft_putstr_fd("Something happened, couldn't send the data\n", 1);
		exit(1);
	}
	else if (err == 3)
	{
		ft_putstr_fd("Wrong PID format \n", 1);
		exit(1);
	}
	else if (err == 4)
	{
		ft_putstr_fd("You can send one string \n", 1);
		exit(1);
	}
}

void	ft_send_data(int data, int pid)
{
	int		i;
	char	c;

	c = data;
	i = 128;
	while (i > 0)
	{
		if (c / i)
		{
			if (kill(pid, SIGUSR1) == -1)
				show_error(2);
			c -= i;
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				show_error(2);
		}
		i /= 2;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	i = 0;
	if (!argv[1])
		show_error(0);
	else if (!argv[2])
		show_error(1);
	if (argc == 3)
	{
		if (argv[1])
			while (argv[1][i])
				if (!ft_strchr("0123456789", argv[1][i++]))
					show_error(3);
		str = argv[2];
		pid = ft_atoi(argv[1]);
		while (*(str))
			ft_send_data(*(str)++, pid);
		ft_send_data('\n', pid);
	}
	else if (argc > 3)
		show_error(4);
	return (0);
}
