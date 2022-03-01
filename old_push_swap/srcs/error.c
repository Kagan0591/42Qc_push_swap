#include "push_swap.h"

int	check_for_error(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 0)
		return (1);
	if (checkif_isint(argv) == false)
		return (write(2, "Error\n", 6));
	if (checkif_repeated_number(argv) == true)
		return (write(2, "Error\n", 6));
	return (0);
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
