#include "push_swap.h"

int	main(int argc, char **argv)
{
	STACKS
	ft_sift(&l_a, &last_a, argc, argv);
	if (ft_check_sort(l_a))
			return (0);
	push_swap(&l_a, &last_a, &l_b, &last_b);
	if (ft_check_sort(l_a))
		printf("ok");
	print_stack(l_a);
}