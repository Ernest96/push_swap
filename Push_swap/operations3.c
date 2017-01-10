#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#define AC_RED     "\x1b[31m"
#define AC_GREEN   "\x1b[32m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"
#define STACKS_1 t_stack *l_a = NULL, *l_b = NULL;
#define STACKS_2 t_stack *last_a = NULL, *last_b = NULL;
#define SA   sa(&l_a, &last_a, 1);
#define SB   sb(&l_b, &last_b, 1);
#define SS   ss(&l_a, &last_a, &l_b, &last_b);
#define PA 	 pa(&l_a, &last_a, &l_b, &last_b);
#define PB 	 pb(&l_a, &last_a, &l_b, &last_b);
#define RRA  rra(&l_a, &last_a, 1);
#define RRB  rrb(&l_b, &last_b, 1);
#define RA   ra(&l_a, &last_a, 1);
#define RB   rb(&l_b, &last_b, 1);
#define RR   rr(&l_a, &last_a, &l_b, &last_b);
#define PUSH_A(a) push_back(a, &l_a, &last_a);
#define PUSH_B(a) push_back(a, &l_b, &last_b);

typedef struct  	s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_stack;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(nb / - 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10 && nb >= 0)
	{
		ft_putchar(nb + 48);
		return ;
	}
	if (nb != -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
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

	if (*head == NULL)
	{
		*head = (t_stack*)malloc(sizeof(t_stack));
		(*head)->value = element;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		*last = *head;
		return ;
	}
	temp = *last;
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
	write(1, "ss\n", 3);
	sa(l_a, last_a, 0);
	sb(l_b, last_b, 0);
}

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
	(*l_a)->prev = temp;
	*l_a = temp;
}

void	pb(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b)
{
	t_stack *temp;

	write(1, "pb\n", 3);
	if (*l_a == NULL)
		return ;
	if ((*l_a)->next == NULL)
		*last_b = NULL;
	temp = *l_a;
	if (temp->next != NULL)
		temp->next->prev = NULL;
	*l_a = temp->next;
	temp->next = *l_b;
	(*l_b)->prev = temp;
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
	write(1, "rr\n", 3);
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
	write(1, "rr", 3);
	ra(l_a, last_a, 0);
	rb(l_b, last_b, 0);
}

int	main(void)
{
	STACKS_1;
	STACKS_2;
	PUSH_A(0);
	PUSH_A(1);
	PUSH_A(2);
	PUSH_B(10);
	PUSH_B(9);
	PUSH_B(12);
	RA;
	RB;
	PUSH_A(3);
	PUSH_B(32);
	print_stack(l_a);
	print_reverse(last_a);
	print_stack(l_b);
	print_reverse(last_b);
}