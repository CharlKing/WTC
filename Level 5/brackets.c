#include <unistd.h>

int	is_bracket(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return (1);
	if (c == ')' || c == ']' || c == '}')
		return (2);
	return (0);
}

int	match_brackets(char a, char b)
{
	char ba[3] = {'(', '[', '{'};
	char bb[3] = {')', ']', '}'};
	int i = 0;
	int j = 0;

	while (a != ba[i])
		i++;
	while (b != bb[j])
		j++;
	return (i == j);
}

int	check_brackets(char *str)
{
	int stack[4096];
	int top = 0;
	int i = 0;
	
	stack[0] = 0;
	while (str[i])
	{
		if (is_bracket(str[i]) == 1)
			stack[++top] = str[i];
		if (is_bracket(str[i]) == 2)
		{
			if (match_brackets(stack[top],str[i]))
				top--;
			else
				return (0);
		}
		i++;
	}
	return (!top);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		while (i < argc)
		{
			char *str = argv[i];
			if (check_brackets(str))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
