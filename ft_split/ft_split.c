#include <stdlib.h>
#include <stdio.h>

char 	ft_isblank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		ft_strlen(char *str)
{
	int x = 0;
	while (str[x])
		x++;
	return x;
}

char    **ft_split(char *str)
{
	int len;
	int y;
	int x;
	int word = 0;
	char **res;

	len = ft_strlen(str);
	y = 0;
	x = 0;
	if(!(res = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	while(str[x] && ft_isblank(str[x]))
		x++;
	while(str[x])
	{
		y = 0;
		if (!(res[word] = (char *)malloc(sizeof(char) * len)))
			return(NULL);
		while(str[x] && !(ft_isblank(str[x])))
		{
			res[word][y] = str[x];
			y++;
			x++;
		}
		while(str[x] && ft_isblank(str[x]))
			x++;
		res[word][len] = '\0';
		word++;
	}
	res[word] = NULL;
	return (res);
}

int main(int ac, char **av)
{
	int x = 0;
	char **str;
	if (ac == 2)
	{
		if (av[1])
		{
			str = ft_split(av[1]);
			while(str[x] != NULL)
				printf("%s\n", str[x++]);
		}
	}
	else
		printf("\n");
	return (0);
}
