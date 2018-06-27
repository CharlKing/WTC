#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	hcd(int x, int y)
{
	int hcd = 1;
	int temp = 0;

	if (y > x)
	{
		temp = x;
		x = y;
		y = temp;
	}
	temp = 1;

	while (temp < y)
	{
		if((x%temp) == 0 && (y%temp) == 0)
			hcd = temp;
		temp++;
	}
	return (hcd);

}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d\n",hcd(atoi(argv[1]),atoi(argv[2])));
	}
	else
		printf("\n");
}
