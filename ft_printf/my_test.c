#include <stdio.h>
#include "ft_printf.h"

#define MINE printed += ft_printf
#define ORIGINAL original += printf

int		main(void)
{
	int printed;
	int original;

	printed = 0;
	original = 0;

	printf("Basic usage\n\n");

	MINE("");
	ORIGINAL("");
	MINE("I LOVE BURRITOS");
	ORIGINAL("I LOVE BURRITOS");
	MINE("\n");
	ORIGINAL("\n");

	MINE("%s\n", "");
	ORIGINAL("%s\n", "");
	MINE("%s\n", "pimpam");
	ORIGINAL("%s\n", "pimpam");
	MINE("%s\n", "podfgkhpertkhg4e5'gh345t'0r'gkethk'09w43'tk4t");
	ORIGINAL("%s\n", "podfgkhpertkhg4e5'gh345t'0r'gkethk'09w43'tk4t");
	MINE("%s\n", NULL);
	ORIGINAL("%s\n", NULL);
	MINE("%s - %s - %s\n", "", "pimpam", NULL);
	ORIGINAL("%s - %s - %s\n", "", "pimpam", NULL);
	MINE("\n");
	ORIGINAL("\n");
	MINE("%d\n", 42);
	ORIGINAL("%d\n", 42);
	MINE("%d\n", 1);
	ORIGINAL("%d\n", 1);
	MINE("%d\n", 2020);
	ORIGINAL("%d\n", 2020);
	MINE("%d\n", (int)2147483647);
	ORIGINAL("%d\n", (int)2147483647);
	MINE("%d\n", (int)2147483648);
	ORIGINAL("%d\n", (int)2147483648);
	MINE("%d\n", (int)-2147483648);
	ORIGINAL("%d\n", (int)-2147483648);
	MINE("%d\n", (int)-2147483649);
	ORIGINAL("%d\n", (int)-2147483649);
	MINE("\n");
	ORIGINAL("\n");
	MINE("%x\n", 0);
	ORIGINAL("%x\n", 0);
	MINE("%x\n", 42);
	ORIGINAL("%x\n", 42);
	MINE("%x\n", 2020);
	ORIGINAL("%x\n", 2020);
	MINE("%x\n", (int)2147483647);
	ORIGINAL("%x\n", (int)2147483647);
	MINE("%x\n", (int)2147483648);
	ORIGINAL("%x\n", (int)2147483648);
	MINE("%x\n", (int)-2147483648);
	ORIGINAL("%x\n", (int)-2147483648);
	MINE("%x\n", (int)-2147483649);
	ORIGINAL("%x\n", (int)-2147483649);
	MINE("\n");
	ORIGINAL("\n");
	MINE("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ORIGINAL("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	MINE("%d - %x - %d - %x - %d - %x - %d - %x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ORIGINAL("%d - %x - %d - %x - %d - %x - %d - %x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	MINE("%0d\n", 42);
	ORIGINAL("%0d\n", 42);
	MINE("%3d\n", 42);
	ORIGINAL("%3d\n", 42);
	MINE("%10d\n", 42);
	ORIGINAL("%10d\n", 42);
	MINE("%0.0d\n", 42);
	ORIGINAL("%0.0d\n", 42);
	MINE("%0.3d\n", 42);
	ORIGINAL("%0.3d\n", 42);
	MINE("%0.10d\n", 42);
	ORIGINAL("%0.10d\n", 42);
	MINE("%3.0d\n", 42);
	ORIGINAL("%3.0d\n", 42);
	MINE("%10.0d\n", 42);
	ORIGINAL("%10.0d\n", 42);
	MINE("%3.3d\n", 42);
	ORIGINAL("%3.3d\n", 42);
	MINE("%10.10d\n", 42);
	ORIGINAL("%10.10d\n", 42);
	printf("\nft_printf wrote: %d\nprintf wrote: %d\n", printed, original);

}
