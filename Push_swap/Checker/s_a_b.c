#include "push_swap.h"

void	sa(t_stack **l_a, t_stack **last_a, int8_t flag)
{
	t_stack *temp1;
	t_stack *temp2;

	if (flag)
		write(1, "sa\n", 3);
	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		return ;
	temp1 = *l_a;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp2->prev = NULL;
	*l_a = temp2;
	if(temp1->next != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		temp1->prev = temp2;
	}
	if ((*l_a)->next->next == NULL)
		*last_a = (*l_a)->next;
}

void	sb(t_stack **l_b, t_stack **last_b, int8_t flag)
{
	t_stack *temp1;
	t_stack *temp2;

	if (flag)
		write(1, "sb\n", 3);
	if (*l_b == NULL)
		return ;
	if ((*l_b)->next == NULL)
		return ;
	temp1 = *l_b;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp2->prev = NULL;
	*l_b = temp2;
	if(temp1->next != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		temp1->prev = temp2;
	}
	if ((*l_b)->next->next == NULL)
		*last_b = (*l_b)->next;
}

void	ss(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b)
{
	sa(l_a, last_a, 0);
	sb(l_b, last_b, 0);
}