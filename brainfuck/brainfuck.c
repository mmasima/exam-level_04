#include <unistd.h>

int		main(int ac, char **av)
{
	char	*str;
	int	tab[4096];
	int	*ptr;
	int	x;
	int	loop;

	ptr = tab;
	x = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str[x])
		{
			if (str[x] == '+')
				++(*ptr);
			else if (str[x] == '-')
				--(*ptr);
			else if (str[x] == '>')
				ptr++;
			else if (str[x] == '<')
				ptr--;
			else if (str[x] == '.')
				write(1, ptr, 1);
			else if (str[x] == '[' && *ptr == 0)
			{
				loop = 1;
				while (loop != 0)
				{
					x++;
					if (str[x] == '[')
						loop++;
					if (str[x] == ']')
						loop--;
				}
			}
			else if (str[x] == ']' && *ptr != 0)
			{
				loop = 1;
				while (loop != 0)
				{
					x--;
					if (str[x] == ']')
						loop++;
					if (str[x] == '[')
						loop--;
				}
			}
			x++;
		}
			
	}
}
