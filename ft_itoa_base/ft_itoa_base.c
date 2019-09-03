#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	char * base_str = "0123456789ABCDEF";
	int len;
	long nbr;
	char *str;

	len = 0;
	nbr = value;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	nbr = value;
	if (value == 0)
		return ("0");
	if (value < 0)
	{
		if (base == 10)
			len++;
		nbr *= -1;
	}
	str = (char *)malloc(sizeof(char) * len);
	str[len] = '\0';
	while(nbr)
	{
		str[--len] = base_str[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
	{
		str[0] = '-';
	}
	return (str);
}
int main()
{
	int value = -11;
	int base = 10;
	printf("%s", ft_itoa_base(value, base));
	return (0);
}
