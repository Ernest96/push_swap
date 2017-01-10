int8_t ft_check_op(const char *s)
{
	int8_t result;

	if (*s == 's')
	{
		if (!ft_strcmp(s, "sa"))
			return (1);
		if (!ft_strcmp(s, "sb"))
			return (11);
		if (!ft_strcmp(s, "ss"))
			return (21);
	}
	if (*s == 'p')
	{
		if (!ft_strcmp(s, "pa"))
			return (2);
		if (!ft_strcmp(s, "pb"))
			return (12);
	}
	result = ft_check_op_r(s);
	return (result);
}


void	do_op_b(t_stack **l_b, t_stack **last_b, int8_t op)
{
	if (op == 11)
		sb(l_b, last_b, 0);
	else if (op == 13)
		rb(l_b, last_b, 0);
	else if (op == 14)
		rrb(l_b, last_b, 0);
}

void	do_op_a(t_stack **l_a, t_stack **last_a, int8_t op)
{
	if (op == 1)
		sa(l_a, last_a, 0);
	else if (op == 3)
		ra(l_a, last_a, 0);
	else if (op == 4)
		rra(l_a, last_a, 0);
}
