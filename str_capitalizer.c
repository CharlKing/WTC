#include <unistd.h>

int	strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);	
}

char	lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

char 	*str_capitalize(char *str)
{	
	int len = strlen(str);
	int i = 0;

	while (i <= len)
	{
		if(i == 0)
			str[0] = capitalize(str[0]);
		else
		{
			if (str[i - 1] == ' ' || str[i - 1] == '\t')
				str[i] = capitalize(str[i]);
			else
				str[i] = lower(str[i]);
		}
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		int i = 1;
		while (i < argc)
		{
			write(1, str_capitalize(argv[i]),strlen(argv[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
