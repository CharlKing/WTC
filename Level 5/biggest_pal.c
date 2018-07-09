#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int len = 0;
	while(str[len] != '\0')
		len++;
	return (len);
}

int	is_pal(char *str, int x, int y)
{

	int a = x;
	int b = y;

	while ((b - a) > 0)
	{
		if (str[a++] != str[b--])
			return (0);
	}
		return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int len = ft_strlen(argv[1]);
		char *str = argv[1];
		int pal_start = 0;
		int pal_end = 0;
		int loop = 1;

		for (int i = 0; i <= len && loop; i++)
		{
			for (int j = i; j < len; j++)
			{
				if (is_pal(str, i, j))
				{
					if ((j-i) >= (pal_end - pal_start))
					{
						pal_start = i;
						pal_end = j;
						if ((j - i) > (len/2))
							loop = 0;
					}
				}
			}
		}
		write(1, (str + pal_start), (pal_end - pal_start + 1));
	}
	write (1, "\n", 1);
}
