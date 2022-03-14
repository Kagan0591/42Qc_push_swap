// GCC remplit les block avec des zero .. :(

int	main(void)
{
	int	*numbers;
	int	memb;
	int	size;
	int	i;
	
	memb = 16;
	size = 4;
	numbers = ft_calloc(memb, 2);
	i = 0;
	while (i < 30)
	{
		printf("%d\n", numbers[i]);
		i++;
	}
	i = 0;
	printf("Il y a %d bloc memoire de %d octets\n\n\n", memb, size);
	printf("Nous avons ecrit 26200 a chaque emplacement memoire !\n");
	while (i < 20)
	{
		numbers[i] = 26200;
		printf("%d\n", numbers[i]);
		i++;
	}
	printf("%d\n", i);
	free(numbers);
	return (0);
}