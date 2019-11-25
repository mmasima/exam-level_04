#include <stdio.h>

//bubble sort
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int x;
	unsigned int y;
	int min;
	int tmp;

	x = 0;
	if (size == 0)
		return ;
	while(x < size - 1)
	{
		y = x;
		min = tab[x];
		while(y < size)
		{
			if (min > tab[y])
			{
				tmp = tab[y];
				tab[y] = min;
				min = tmp;
			}
			y++;
		}
		tab[x] = min;
		x++;
	}
}

int		main(void)
{
	int tab[] = { -1, 6, 7, 3, -6, 7, 2, 4, 5, 2147483647, -2147483648 };
	unsigned int size = 11;

	sort_int_tab(tab, size);

	unsigned int i = 0;
	while (i < size)
	{
		printf("element %d: %d\n", i, tab[i]);
		i++;
	}
	return 0;
}
