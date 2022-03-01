#include <stdio.h>
#include <string.h>

int	main (void) 

{
	char	str1[15];
	char	str2[15];
	int	ret;

	strcpy (str1, "0123456799");
	strcpy (str2, "0123456789");
	ret = ft_strncmp(str1, str2, 20);
	if (ret < 0)
		printf("str1 is less than str2");
	else if (ret > 0)	
		printf("str2 is less than str1");
	else
		printf("str1 is equal to str2");
	return (0);
}