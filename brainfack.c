#include <unistd.h>

int		ft_plus_scob(char *av, int i)
{
	int		c;

	c = 1;
	while(c)
	{
		++i;
		if (av[i] == '[')
			++c;
		if (av[i] == ']')
			--c;
	}
	return (i);
}

int		ft_minus_scob(char *av, int i)
{
	int		c;

	c = 1;
	while(c)
	{
		--i;
		if (av[i] == ']')
			++c;
		if (av[i] == '[')
			--c;
	}
	return (i);
}

void    ft_brainfuck(char *av)
{
	int     i;
	char    str[2049];
	int     count;

	count = 0;
	i = 0;
	while (count < 2049)
		str[count++] = 0;
	count = 0;
	while(av[i] != '\0')
	{
		if (av[i] == '+')
			++str[count];
		else if (av[i] == '-')
			--str[count];
		else if (av[i] == '>')
			++count;
		else if (av[i] == '<')
			--count;
		else if (av[i] == '.')
			write(1, &str[count], 1);
		else if (av[i] == '[')
		{
			if (str[count] == 0)
				i = ft_plus_scob(av, i);
		}
		else if (av[i] == ']')
		{
			if (str[count] != 0)
				i = ft_minus_scob(av, i);
		}
		++i;
	}
}

int     main(int ac, char **av)
{
    if (ac == 2)
        ft_brainfuck(av[1]);
	write(1, "\n", 1);
    return (0);
}