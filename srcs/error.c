#include "push_swap.h"

int	check_for_error(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 0)
		return (1);
	if (checkif_isint(argv) == false)
		return (write(2, "Error\n", 6));
	if (checkif_isdigit(argv) == false)
		return (write(2, "Error\n", 6));
	if (checkif_repeated_number(argv) == true)
		return (write(2, "Error\n", 6));
	return (0);
}

/* Une fonction pour vérifier si il s'agit bien d'un chiffre pour
 * chaques arguments vector (argv)
 */
boolean	checkif_isdigit(char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if (argv[1][i] == ' ')
					i++;
				else
					return (false);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (ft_isdigit(argv[1][i] == 0))
			{
				if (argv[1][i] == ' ')
					i++;
				else
					return (write(2, "Error\n", 6));
			}
			i++;
		}
		return (0);
	}
/* Une fonction pour vérifier si il s'agit bien d'un integrer pour
 * chaques arguments vector (argv)
 */
boolean	checkif_isint(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) < -2147483648 || ft_atoll(argv[i]) > 2147483647)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

/* Une fonction pour vérifier si il n y a pas de doublon pour
 * chaques arguments vector (argv)
 */
boolean	checkif_repeated_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;

	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv [i]) == ft_atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
		j = (i + 1);
	}
	return (false);
}
