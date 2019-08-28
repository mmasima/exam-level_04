#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int len;
	char *res;
	long tmp = (long)nbr;
	len = 0;

	if(nbr < 0)
		len = 1;
	if (nbr == 0)
		return ("0");
	while(tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	res = (char *)malloc(sizeof(char) * len);
	if(nbr < 0)
	{
		res[0] = '-';
		nbr = nbr * -1;
	}
	len--;
	while(nbr)
	{
		res[len] = nbr % 10 + 48;
		nbr = nbr / 10;
		len--;
	}
	return(res);
}

