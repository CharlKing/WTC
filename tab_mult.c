#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr/10);
		ft_putnbr(nbr%10);
	}
	else
		ft_putchar(nbr + '0');
}

int	atoi(char *str)
{
	int i = 0;
	int out = 0;

	while (str[i] != '\0')
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (out);
}

int	main(int argc, char **argv)
{
	if(argc != 1)
	{
		int i = 1;
		int nbr = atoi(argv[1]);

		while (i < 10)
		{
			ft_putnbr(i);
			ft_putchar(' ');
			ft_putchar('x');
			ft_putchar(' ');
			ft_putnbr(nbr);
			ft_putchar(' ');
			ft_putchar('=');
			ft_putchar(' ');
			ft_putnbr(nbr*i);
			i++;
			ft_putchar('\n');
		}
	}
	else
		write(1, "\n", 1);
}
