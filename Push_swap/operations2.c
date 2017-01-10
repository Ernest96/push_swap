#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#define STACKS_1 t_stack *l_a = NULL, *l_b = NULL;
#define STACKS_2 t_stack *prev_last_a = NULL, *prev_last_b = NULL;
#define SA   sa(&l_a, &prev_last_a, 1);
#define SB   sb(&l_b, &prev_last_b, 1);
#define SS   ss(&l_a, &prev_last_a, &l_b, &prev_last_b);
#define PA 	 pa(&l_a, &prev_last_a, &l_b, &prev_last_b);
#define PB 	 pb(&l_a, &prev_last_a, &l_b, &prev_last_b);
#define PUSH_A(a) push_back(a, &l_a, &prev_last_a);
#define PUSH_B(a) push_back(a, &l_b, &prev_last_b);
#define INIT_H (*head)->value = element; (*head)->next = (*head)->prev = NULL;
#define INIT_E temp->value = element; temp->next = NULL; temp->prev = previous;



void	sa(t_stack **l_a, t_stack **prev_last_a, int8_t flag)
{
	t_stack *st_temp1;
	t_stack *st_temp2;

	if (flag)
		write(1, "sa\n", 3);
	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		return ;
	if ((*l_a)->next->next == NULL)
	{
		*l_a = (*l_a)->next;
		st_temp1 = *prev_last_a;
		*prev_last_a = (*prev_last_a)->next;
		(*prev_last_a)->next = st_temp1;
		st_temp1->next = NULL;
		st_temp1->prev = *l_a;
		(*l_a)->prev = NULL;
		return ;
	}
	st_temp1 = *l_a;
	*l_a = (*l_a)->next;
	st_temp2 = (*l_a)->next;
	(*l_a)->next = st_temp1;
	st_temp1->next = st_temp2;
	st_temp1->prev = *l_a;
	st_temp2->prev = st_temp1;
	(*l_a)->prev = NULL;
}


void	sb(t_stack **l_b, t_stack **prev_last_b, int8_t flag)
{
	t_stack *st_temp1;
	t_stack *st_temp2;

	if (flag)
		write(1, "sb\n", 3);
	if (*l_b == NULL)
		return ;
	if ((*l_b)->next == NULL)
		return ;
	if ((*l_b)->next->next == NULL)
	{
		*l_b = (*l_b)->next;
		st_temp1 = *prev_last_b;
		*prev_last_b = (*prev_last_b)->next;
		(*prev_last_b)->next = st_temp1;
		st_temp1->next = NULL;
		return ;
	}
	st_temp1 = *l_b;
	*l_b = (*l_b)->next;
	st_temp2 = (*l_b)->next;
	(*l_b)->next = st_temp1;
	st_temp1->next = st_temp2;
}

void	ss(t_stack **l_a, t_stack **prev_last_a, t_stack **l_b, t_stack **prev_last_b)
{
	sa(l_a, prev_last_a, 0);
	sb(l_b, prev_last_b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **l_a, t_stack **prev_last_a,t_stack **l_b,
	t_stack **prev_last_b)
{
	t_stack *temp;

	write(1, "pa\n", 3);
	if (*l_b == NULL)
		return ;
	if ((*l_b)->next == NULL)
		*prev_last_b = NULL;
	else if((*l_b)->next->next == NULL)
		*prev_last_b = NULL;
	temp = *l_b;
	*l_b = (*l_b)->next;
	temp->next = *l_a;
	*l_a = temp;
	if (temp->next == NULL)
		*prev_last_a = NULL;
	else if (temp->next->next == NULL)
		*prev_last_a = temp;
}

void	pb(t_stack **l_a, t_stack **prev_last_a, t_stack **l_b,
	t_stack **prev_last_b)
{
	t_stack *temp;

	write(1, "pb\n", 3);
	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		*prev_last_a = NULL;
	else if((*l_a)->next->next == NULL)
		*prev_last_a = NULL;
	temp = *l_a;
	*l_a = (*l_a)->next;
	temp->next = *l_b;
	*l_b = temp;
	if (temp->next == NULL)
		*prev_last_b = NULL;
	else if (temp->next->next == NULL)
		*prev_last_b = temp;
}

void	ra(t_stack **l_a, t_stack **prev_last_a)
{
	t_stack *last;

	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		return ;
	last = (*prev_last_a)->next;
	(*prev_last_a)->next = NULL;
	last->next = *l_a;
	*l_a = last;
	if ((*l_a)->next->next == NULL)
		(*prev_last_a) = *l_a;

}

int	main(void)
{
	STACKS_1;
	STACKS_2;
	PUSH_A(99);
	PUSH_A(901);
	PUSH_A(91);
	SA;
	print_stack(l_a);
	print_reverse(prev_last_a);
	print_stack(l_b);
}