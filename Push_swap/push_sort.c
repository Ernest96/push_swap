int ft_get_steps(t_stack *l_b, int value)
{
	int steps;

	steps = 0;
	while (value < l_b->value)
	{
		++steps;
		l_b = l_b->next;
	}
	return (steps);
}

void	push_sort_b(t_stack **l_a, t_stack **last_a, t_stack **l_b,
	t_stack **last_b)
{
	INIT_SIZE_STEPS
	if (*l_b == NULL)
		CASE_1
	else if ((*l_a)->value < (*last_b)->value)
		CASE_2
	else
	{
		steps = ft_get_steps(*l_b, (*l_a)->value);
		normalize = steps;
		if (steps <= b_size / 2)
			CASE_3
		else
		{
			CASE_4
			CASE_4_1
		}
		b_size++;
	}
}

void	ft_push_from_b(t_stack **l_a, t_stack **last_a, t_stack **l_b,
	t_stack **last_b)
{
	int steps;

	steps = 0;
	while (*l_b)
	{
		while ((*l_b)->value > (*l_a)->value)
		{
			++steps;
			RA;
		}
		if (steps > 0)
			while ((*l_b)->value > (*last_a)->value && *l_b)
				PA;
		if (!steps)
			PA;
		else if (steps > 0)
		{
			RRA;
			--steps;
		}
	}
}

void	push_swap(t_stack **l_a, t_stack **last_a, t_stack **l_b,
	t_stack **last_b)
{
	INIT_PIVOT_FLAG
	while ((*l_a)->value != pivot)
	{
		if ((*l_a)->value > (*l_a)->next->value && (*l_a)->next->value > (*last_a)->value)
			{
				SA;
				if (!flag)
					pivot = (*l_a)->value;
				flag = RA;
			}
		else if ((*l_a)->value > (*last_a)->value)
			{
				if (!flag)
					pivot = (*l_a)->value;
				flag = RA;
			}
		else if ((*l_a)->next->value == pivot && !*l_b)
			break ;
		else if ((*l_a)->next->value == pivot && (*l_a)->value > (*l_b)->value)
			break ;
		else 
			push_sort_b(l_a, last_a, l_b, last_b);
	}
	ft_push_from_b(l_a, last_a, l_b, last_b);
}