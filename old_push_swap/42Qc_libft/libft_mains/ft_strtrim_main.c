int main(void)
{
    char    *s2;
    char    *s1 = "";
    char    *set = "";

    s2 = ft_strtrim(s1, set);
    printf("Comparaison %d\n", strcmp(s2, ""));
    printf("%s\n", s2);
    return (0);
}
