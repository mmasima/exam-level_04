#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_isblank(char c)
{
	return (c == '\n' || c == '\t' || c == ' ');
}


void	 ft_putstr(char *str)
{
	int x;

	x = 0;
	while(str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}
void rev_str(char *str)
{
	int x;
	int words;
	int z;
	char **res;

	x = 0;
	words = 0;
	res = (char **)malloc(sizeof(char *) * (2048));
	while(str[x] && ft_isblank(str[x]))
		x++;
	while(str[x])
	{
		if (!(res[words] = (char *)malloc(sizeof(char) * (4098))))
			return ;
		z = 0;
		while(str[x] && !ft_isblank(str[x]))
		{
			res[words][z] = str[x];
			z++;
			x++;
		}
		while(str[x] && ft_isblank(str[x]))
			x++;
		res[words][z] = '\0';
		words++;
	}
	res[words] = NULL;
	z = 0;
	words -= 1;
	while(words >= 0)
	{
		ft_putstr(res[words]);
		if (words == 0)
			return ;
		write(1," ", 1);
		words--;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_str(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
