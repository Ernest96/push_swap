#include "push_swap.h"

int8_t	ft_check_arg(char *str)
{
	if (*str == 0)
		ft_error();
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
		if (!ft_isdigit(*str) && *str != ' ' && *str != '-' && *str != '+')
			ft_error();
		else
			++str;
	return (1);
}

int8_t ft_check_op_r(const char *s)
{
	if (*s == 'r')
	{
		if (!ft_strcmp(s, "ra"))
			return (3);
		if (!ft_strcmp(s, "rb"))
			return (13);
		if (!ft_strcmp(s, "rra"))
			return (4);
		if (!ft_strcmp(s, "rrb"))
			return (14);
		if (!ft_strcmp(s, "rr"))
			return (23);
		if (!ft_strcmp(s, "rrr"))
			return (24);
	}
	return (0);
}

int8_t ft_check_sort(t_stack *l_a)
{
	if (l_a == NULL)
		ft_error();
	while (l_a->next)
	{
		if (l_a->value > l_a->next->value)
			return (0);
		l_a = l_a->next;
	}
	return (1);
}
