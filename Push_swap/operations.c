#include <stdlib.h>
#include <stdio.h>
#define STACKS_1 t_stack *l_a = NULL, *l_b = NULL, *last_a = NULL, *last_b = NULL;
#define STACKS_2 t_stack *prev_last_a = NULL, *prev_last_b = NULL;

typedef struct  	s_list
{
	int				value;
	struct s_list	*next;
}					t_stack;

STACKS_1;
STACKS_2;

void	l_a_push_back(int element)
{
	t_stack *temp;

	if (l_a == NULL)
	{
		l_a = (t_stack*)malloc(sizeof(t_stack));
		l_a->value = element;
		l_a->next = NULL;
		last_a = l_a;
		return ;
	}
	temp = last_a;
	prev_last_a = last_a;
	temp->next = (t_stack*)malloc(sizeof(t_stack));
	temp = temp->next;
	temp->value = element;
	temp->next = NULL;
	last_a = temp;
	return ;
}

void	l_b_push_back(int element)
{
	t_stack *temp;

	if (l_b == NULL)
	{
		l_b = (t_stack*)malloc(sizeof(t_stack));
		l_b->value = element;
		l_b->next = NULL;
		last_b = l_b;
		return ;
	}
	temp = last_b;
	prev_last_b = last_b;
	temp->next = (t_stack*)malloc(sizeof(t_stack));
	temp = temp->next;
	temp->value = element;
	temp->next = NULL;
	last_b = temp;
	return ;
}

void	print_stack(t_stack *st)
{
	while (st)
	{
		printf("%d ", st->value);
		st = st->next;
	}
	printf("\n");
}

void	sa(void)
{
	int temp;

	if (l_a == NULL)
		return ;
	if (l_a->next == NULL)
		return ;
	temp = l_a->value;
	l_a->value = l_a->next->value;
	l_a->next->value = temp;
}

void	sb(void)
{
	int temp;

	if (l_b == NULL)
		return ;
	if (l_b->next == NULL)
		return ;
	temp = l_b->value;
	l_b->value = l_b->next->value;
	l_b->next->value = temp;
}

void	ss(void)
{
	sa();
	sb();
	return ;
}

void	pa(void)
{
	t_stack *temp;

	if (l_b == NULL)
		return ;
	temp = l_b;
	l_b = l_b->next;
	temp->next = l_a;
	l_a = temp;
}

void	pb(void)
{
	t_stack *temp;

	if (l_a == NULL)
		return ;
	temp = l_a;
	l_a = l_a->next;
	temp->next = l_b;
	l_b = temp;
}

void	ra(void)
{
	t_stack *temp;

	if (l_a == NULL)
		return ;
	if (l_a->next == NULL)
		return ;
	temp = l_a->next;
	last_a->next = l_a;
	l_a->next = NULL;
	l_a = temp;
	return ;
}


void	rb(void)
{
	t_stack *temp;

	if (l_b == NULL)
		return ;
	if (l_b->next == NULL)
		return ;
	temp = l_b->next;
	last_b->next = l_b;
	l_b->next = NULL;
	l_b = temp;
	return ;
}

void	rr(void)
{
	ra();
	rb();
}

void	rra(void)
{
	if (l_a == NULL)
		return ;
	if (l_a->next == NULL)
		return ;
	prev_last_a->next = NULL;
	last_a->next = l_a;
	l_a = last_a;
	last_a = prev_last_a;
	return ;
}

void	rrb(void)
{
	if (l_b == NULL)
		return ;
	if (l_b->next == NULL)
		return ;
	prev_last_b->next = NULL;
	last_b->next = l_b;
	l_b = last_b;
	last_b = prev_last_b;
	return ;
}

void	rrr(void)
{
	rra();
	rrb();
	return ;
}

int		main(void)
{
	l_a_push_back(10);
	l_a_push_back(12);
	l_a_push_back(20);
	l_b_push_back(14);
	l_b_push_back(100);
	l_b_push_back(200);
	printf("l_a : ");
	print_stack(l_a);
	printf("l_b : ");
	print_stack(l_b);
	rrr();
	printf("l_a : ");
	print_stack(l_a);
	printf("l_b : ");
	print_stack(l_b);
}