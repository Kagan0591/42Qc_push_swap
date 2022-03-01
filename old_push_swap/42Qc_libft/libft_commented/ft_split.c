/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:37:48 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/01 16:38:04 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// THE FUNCTION FOR COUNTING THE NUMBERS OF CHARACTERE INTO WORDS //
static size_t	wordlenght(const char *s, const char delemiter, size_t s_lenght)
{
	size_t	count_char;

	count_char = 0;
	while (s[s_lenght] != '\0')
	{
		if ((char)s[s_lenght] == delemiter)
			return (count_char);
		while ((char)s[s_lenght] != delemiter && s[s_lenght] != '\0')
		{
			count_char++;
			s_lenght++;
		}
	}
	return (count_char);
}

// THE FUNCTION FOR COUNTING THE NUMBER OF WORDS INTO THE STRING //
static size_t	count_words(char *s, char delemiter, size_t s_lenght, size_t word_count)
{
	while (s[s_lenght] != '\0')
	{
		if (s[s_lenght] != delemiter)
		{
			word_count++;
			while (s[s_lenght] != delemiter && s[s_lenght] != '\0')
				s_lenght++;
			count_words(s, delemiter, s_lenght, word_count);
		}
		else
			s_lenght++;
	}
	return (word_count);
}
// THE FUNCTION FOR COPYING EACH STRING OF WORD INTO THE MASTER STRING //
static void    makestr(char *string_source, char **string_master, char c)
{
	size_t	string_source_lenght;
	size_t	i_string_master;
	size_t	lenght_of_word;

	string_source_lenght = 0;
	i_string_master = 0;
	lenght_of_word = 0;
	while (string_source[string_source_lenght] != '\0')
	{
		while (string_source[string_source_lenght] == c)
			string_source_lenght++;
		lenght_of_word = wordlenght(string_source, c, string_source_lenght);
		if (lenght_of_word != 0)
		{
			string_master[i_string_master] = ft_substr(\
				string_source, (unsigned int) string_source_lenght, lenght_of_word);
			string_source_lenght = string_source_lenght + lenght_of_word;
			i_string_master++;
		}
	}
	string_master[i_string_master] = 0;
}

// THE MASTER FUNCTION ORCHESTRING THE SPLIT //
char	**ft_split(char const *s, char c)
{
	size_t	lenght_of_word;
	char	**master_str;

	lenght_of_word = 0;
	if (!s)
		return (0);
	master_str = malloc((count_words((char *)s, c, 0, 0) + 1) * sizeof(char *));
	if (!master_str)
		return (0);
	makestr((char *)s, master_str, c);
	return (master_str);
}
