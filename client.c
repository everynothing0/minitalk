/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:38:41 by cde-voog          #+#    #+#             */
/*   Updated: 2023/07/21 14:08:42 by cde-voog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	to_return;
	int		sign;

	to_return = 0;
	sign = 1;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		to_return = to_return * 10 + (str[i] - 48);
		i++;
	}
	to_return *= sign;
	return ((int)to_return);
}

//int	strange(const char *str)
//{
//	int		i;
//
//	i = 0;
//	while (str[i] >= 32 && str[i] <= 47)
//		i++;
//	return (i);
//}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!fd || !s)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

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
	//else if (err >= 33 && err <= 47)
	//{
		//ft_putstr_fd("Doesn't work with ipic\n", 1);
	//	exit(1);
	//}
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
