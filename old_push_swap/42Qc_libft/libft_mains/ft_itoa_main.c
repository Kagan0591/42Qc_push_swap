int main(void)
{
    int     nbr = -2147483648;
    printf("La valeur int min devrait etre -2147483648, La fonction retourne:\n");
    printf("%s\n\n", ft_itoa(nbr));
    nbr = 2147483647;
    printf("La valeur int max devrait etre 2147483647, La fonction retourne:\n");
    printf("%s\n\n", ft_itoa(nbr));
    nbr = -1234;
    printf("La valeur tester est -1234, La fonction retourne:\n");
    printf("%s\n", ft_itoa(nbr));
    nbr = 1234;
    printf("La valeur tester est 1234, La fonction retourne:\n");
    printf("%s\n", ft_itoa(nbr));
    nbr = 0;
    printf("La valeur tester est 0, La fonction retourne:\n");
    printf("%s\n", ft_itoa(nbr));
    return (0);
}
