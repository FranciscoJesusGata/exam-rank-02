#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i++]);
	return (i);
}

int main(int argc, char **argv)
{
	int *dup;
	int len;
	int i;
	int j;

	if (argc == 3 && argv[1] && argv[2])
	{
		len = ft_strlen(argv[1]);
		dup = malloc(sizeof(int) * len);
		i = 0;
		while(i < len)
		{
			dup[i] = 0;
			i++;
		}
		i = 0;
		j = 0;
		while(argv[2][i])
		{
			
		}
	}
	write(1, "\n", 1);
	return (0);
}