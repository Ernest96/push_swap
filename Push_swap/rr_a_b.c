void	rra(t_stack **l_a, t_stack **last_a, int8_t flag)
{
	t_stack *temp;

	if (flag)
		write(1, "rra\n", 4);
	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		return ;
	temp = *last_a;
	*last_a = (*last_a)->prev;
	(*last_a)->next = NULL;
	temp->next = *l_a;
	temp->prev = NULL;
	(*l_a)->prev = temp;
	*l_a = temp;
}

void	rrb(t_stack **l_b, t_stack **last_b, int8_t flag)
{
	t_stack *temp;

	if (flag)
		write(1, "rrb\n", 4);
	if (*l_b == NULL)
		return ;
	if ((*l_b)->next == NULL)
		return ;
	temp = *last_b;
	*last_b = (*last_b)->prev;
	(*last_b)->next = NULL;
	temp->next = *l_b;
	temp->prev = NULL;
	(*l_b)->prev = temp;
	*l_b = temp;
}

void	rrr(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b)
{
	write(1, "rrr\n", 4);
	rra(l_a, last_a, 0);
	rrb(l_b, last_b, 0);
}
