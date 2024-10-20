#include "libft.h"

static int	ft_split_string_counter(char const *s, char c)
{
	int	i;
	int	string_count;

	i = 0;
	string_count = 0;
	while (s[i])
	{
		if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			while (s[i + 1] != '\0' && s[i] == c)
				i++;
			string_count++;
		}
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		string_count++;
	return (string_count);
}

static void	ft_split_string_appender(char const *s, char **str,
	int string_count, char c)
{
	int	i;
	int	start;
	int	strc;

	start = 0;
	strc = 0;
	i = 0;
	while (s[i] && strc < string_count)
	{
		if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (((s[i] == c && i > 0) && (s[i - 1] != c)) || s[i + 1] == '\0')
		{
			if (s[i] != c && s[i + 1] == '\0')
				str[strc] = ft_substr(s, start, i - start + 1);
			else
				str[strc] = ft_substr(s, start, i - start);
			while (s[i + 1] != '\0' && s[i + 1] == c)
				i++;
			strc++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		string_count;

	string_count = ft_split_string_counter(s, c);
	str = malloc(sizeof(char *) * (string_count + 1));
	if (!str)
		return (NULL);
	str[string_count] = NULL;
	ft_split_string_appender(s, str, string_count, c);
	return (str);
}
