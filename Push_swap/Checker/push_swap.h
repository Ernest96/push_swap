# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "get_next_line.h"
#define STACKS_1 t_stack *l_a = NULL, *l_b = NULL;
#define STACKS_2 t_stack *last_a = NULL, *last_b = NULL;
#define STACKS STACKS_1 STACKS_2 if(argc == 1) exit(0);
#define TO_CHECK char *line; int8_t op;
#define SA   sa(&l_a, &last_a, 0)
#define SB   sb(&l_b, &last_b, 0)
#define SS   ss(&l_a, &last_a, &l_b, &last_b)
#define PA 	 pa(&l_a, &last_a, &l_b, &last_b)
#define PB 	 pb(&l_a, &last_a, &l_b, &last_b)
#define RRA  rra(&l_a, &last_a, 0)
#define RRB  rrb(&l_b, &last_b, 0)
#define RRR  rrr(&l_a, &last_a, &l_b, &last_b)
#define RA   ra(&l_a, &last_a, 0)
#define RB   rb(&l_b, &last_b, 0)
#define RR   rr(&l_a, &last_a, &l_b, &last_b)
#define GET_OP	 op = ft_check_op(line); if (!op) ft_error();
#define PUSH_A(a) push_back(a, l_a, last_a)
#define AC_RED     "\x1b[31m"
#define AC_GREEN   "\x1b[32m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"

typedef struct  	s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int8_t	ft_check_arg(char *str);
int8_t ft_check_op_r(const char *s);
int8_t ft_check_sort(t_stack *l_a);
void	print_stack(t_stack *st);
void	print_reverse(t_stack *st);
void	ft_insert_node(t_stack *temp, t_stack **last, int element);
void	push_back(int element, t_stack **head, t_stack **last);
int ft_atoi_check(const char *str);
int ft_get_steps(t_stack *l_b, int value);
void	push_sort_b(t_stack **l_a, t_stack **last_a, t_stack **l_b,
	t_stack **last_b);
	void	ft_push_from_b(t_stack **l_a, t_stack **last_a, t_stack **l_b,
	t_stack **last_b);
void	push_swap(t_stack **l_a, t_stack **last_a, t_stack **l_b,
	t_stack **last_b);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int8_t	ft_isdigit(int c);
void	ft_error(void);
int	ft_strcmp(const char *s1, const char *s2);
void	sa(t_stack **l_a, t_stack **last_a, int8_t flag);
void	sb(t_stack **l_b, t_stack **last_b, int8_t flag);
void	ss(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b);
void	pa(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b);
void	pb(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b);
int8_t	 ra(t_stack **l_a, t_stack **last_a, int8_t flag);
void	rb(t_stack **l_b, t_stack **last_b, int8_t flag);
void	rr(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b);
void	rra(t_stack **l_a, t_stack **last_a, int8_t flag);
void	rrb(t_stack **l_b, t_stack **last_b, int8_t flag);
void	rrr(t_stack **l_a, t_stack **last_a, t_stack **l_b, t_stack **last_b);
char			**ft_strsplit(char const *str, char ok);
void	ft_is_sorted(t_stack *l_a, t_stack *l_b);
void	ft_sift(t_stack **l_a, t_stack **last_a, int argc, char **argv);
int8_t ft_check_op(const char *s);
void	do_op_b(t_stack **l_b, t_stack **last_b, int8_t op);
void	do_op_a(t_stack **l_a, t_stack **last_a, int8_t op);
# endif
