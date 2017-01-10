#include "push_swap.h"

void	pa(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b)
{
	t_stack *temp;

	write(1, "pa\n", 3);
	if (*l_b == NULL)
		return ;
	if ((*l_b)->next == NULL)
		*last_b = NULL;
	temp = *l_b;
	if (temp->next != NULL)
		temp->next->prev = NULL;
	*l_b = temp->next;
	temp->next = *l_a;
	if(*l_a != NULL)
		(*l_a)->prev = temp;
	else
		*last_a = temp;
	*l_a = temp;
}

void	pb(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b)
{
	t_stack *temp;

	write(1, "pb\n", 3);
	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		*last_a = NULL;
	temp = *l_a;
	if (temp->next != NULL)
		temp->next->prev = NULL;
	*l_a = temp->next;
	temp->next = *l_b;
	if(*l_b != NULL)
		(*l_b)->prev = temp;
	else
		*last_b = temp;
	*l_b = temp;
}
