#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "func1.c"
#include "func2.c"
#include "get_next_line.c"
#define STACKS_1 t_stack *l_a = NULL, *l_b = NULL; uint8_t i = 0; int element;
#define STACKS_2 t_stack *last_a = NULL, *last_b = NULL; char *line; int8_t op;
#define STACKS STACKS_1 STACKS_2 if(argc == 1) exit(0);
#define SA   sa(&l_a, &last_a, 1)
#define SB   sb(&l_b, &last_b, 1)
#define SS   ss(&l_a, &last_a, &l_b, &last_b)
#define PA 	 pa(&l_a, &last_a, &l_b, &last_b)
#define PB 	 pb(&l_a, &last_a, &l_b, &last_b)
#define RRA  rra(&l_a, &last_a, 1)
#define RRB  rrb(&l_b, &last_b, 1)
#define RRR  rrr(&l_a, &last_a, &l_b, &last_b)
#define RA   ra(&l_a, &last_a, 1)
#define RB   rb(&l_b, &last_b, 1)
#define GET_OP	 op = ft_check_op(line); if (!op) ft_error();
#define RR   rr(&l_a, &last_a, &l_b, &last_b)
#define PUSH_A(a) push_back(a, &l_a, &last_a)
#define PUSH_B(a) push_back(a, &l_b, &last_b)

typedef struct  	s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i == 0 && (*(s1 + j) != 0 || *(s2 + j) != 0))
	{
		i = *(unsigned char *)(s1 + j) - *(unsigned char *)(s2 + j);
		j++;
	}
	return (i);
}

void	print_stack(t_stack *st)
{
	while (st)
	{
		ft_putnbr(st->value);
		ft_putchar(' ');
		st = st->next;
	}
	ft_putchar('\n');
}

void	print_reverse(t_stack *st)
{
	while (st)
	{
		ft_putnbr(st->value);
		ft_putchar(' ');
		st = st->prev;
	}
	ft_putchar('\n');
}

void	push_back(int element, t_stack **head, t_stack **last)
{
	t_stack *temp;
	t_stack *temp_prev;

	if (*head == NULL)
	{
		*head = (t_stack*)malloc(sizeof(t_stack));
		(*head)->value = element;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		*last = *head;
		return ;
	}
	temp = *head;
	while (temp->next)
	{
		if (element == temp->value)
			ft_error();
		temp_prev = temp;
		temp = temp->next;
		temp->prev = temp_prev;
	}
	if (element == temp->value)
		ft_error();
	temp->next = (t_stack*)malloc(sizeof(t_stack));
	temp = temp->next;
	temp->value = element;
	temp->next = NULL;
	temp->prev = *last;
	*last = temp;
	return ;
}

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

void	pa(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b)
{
	t_stack *temp;

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
	rra(l_a, last_a, 0);
	rrb(l_b, last_b, 0);
}

void	ra(t_stack **l_a, t_stack **last_a, int8_t flag)
{
	t_stack *temp;

	if (flag)
		write(1, "ra\n", 3);
	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		return ;
	temp = *l_a;
	*l_a = (*l_a)->next;
	if (*l_a)
		(*l_a)->prev = NULL;
	temp->prev = *last_a;
	temp->next = NULL;
	(*last_a)->next = temp;
	(*last_a) = temp;
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

int8_t	ft_check_arg(char *str)
{
	if (*str == 0)
		ft_error();
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
		if (!ft_isdigit(*str))
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

void	ft_is_sorted(t_stack *l_a)
{
	if (l_a == NULL)
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

int	main(int argc, char **argv)
{
	STACKS
	while (++i < argc)
		if (ft_check_arg(*(argv + i)))
			PUSH_A(ft_atoi_check(*(argv + i)));
	while (get_next_line(1, &line))
	{
		GET_OP
		if (op == 2)
			PA;
		else if (op == 12)
			PB;
		else if (op == 21)
			SS;
		else if (op > 10 && op < 20)
			do_op_b(&l_b, &last_b, op);
		else if (op < 10)
			do_op_a(&l_a, &last_a, op);
		else if (op == 23)
			RR;
		else if (op == 24)
			RRR;
		free(line);
	}
	print_stack(l_a);
	ft_is_sorted(l_a);
}