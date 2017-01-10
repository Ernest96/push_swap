#include "push_swap.h"

void	ft_is_sorted(t_stack *l_a, t_stack *l_b)
{
	if (l_a == NULL || l_b != NULL)
	{
		write(1, AC_RED, 5);
		write(1, "KO\n", 3);
		write(1, AC_RESET, 4);
		exit(0);
	}
	while (l_a->next)
	{
		if (l_a->value > l_a->next->value)
		{
			write(1, AC_RED, 5);
			write(1, "KO\n", 3);
			write(1, AC_RESET, 4);
			exit(0);
		}
		l_a = l_a->next;
	}
	write(1, AC_CYAN, 5);
	write(1, "OK\n", 3);
	write(1, AC_RESET, 4);
	exit(0);
}

void	ft_sift(t_stack **l_a, t_stack **last_a, int argc, char **argv)
{
	int i;
	int j;
	char **str;

	i = 0;
	while (++i < argc)
	{
		ft_check_arg(*(argv + i));
		str  = ft_strsplit(*(argv + i), ' ');
		j = -1;
		while (*(str + ++j))
			PUSH_A(ft_atoi_check(*(str + j)));
		j = -1;
		while (*(str + ++j))
			free(*(str + j));
		free(str);
	}

}
