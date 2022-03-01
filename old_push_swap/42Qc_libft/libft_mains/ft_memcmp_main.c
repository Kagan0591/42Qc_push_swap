#include <string.h>
#include <stdio.h>

int main () 

{
	char	str1[15];
	char	str2[15];
	int	ret;

	memcpy	(str1, "ABCDEFG", 11);
	memcpy	(str2, "ABCDEFG", 8);
	ret = ft_memcmp(str1, str2, 7);
	if (ret > 0) 
		printf("str2 is less than str1");
	else if (ret < 0) 
		printf("str1 is less than str2");
	else
		printf("str1 is equal to str2");
	return (0);
}