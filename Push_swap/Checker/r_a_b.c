#include "push_swap.h"

int8_t	 ra(t_stack **l_a, t_stack **last_a, int8_t flag)
{
	t_stack *temp;

	if (flag)
		write(1, "ra\n", 3);
	if (*l_a == NULL)
		return (0);
	if ((*l_a)->next == NULL)
		return (0);
	temp = *l_a;
	*l_a = (*l_a)->next;
	if (*l_a)
		(*l_a)->prev = NULL;
	temp->prev = *last_a;
	temp->next = NULL;
	(*last_a)->next = temp;
	(*last_a) = temp;
	return (1);
}

void	rb(t_stack **l_b, t_stack **last_b, int8_t flag)
{
	t_stack *temp;

	if (flag)
		write(1, "rb\n", 3);
	if (*l_b == NULL)
		return ;
	if ((*l_b)->next == NULL)
		return ;
	temp = *l_b;
	*l_b = (*l_b)->next;
	(*l_b)->prev = NULL;
	temp->prev = *last_b;
	temp->next = NULL;
	(*last_b)->next = temp;
	(*last_b) = temp;
}

void	rr(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b)
{
	ra(l_a, last_a, 0);
	rb(l_b, last_b, 0);
}