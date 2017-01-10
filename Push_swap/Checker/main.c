#include "push_swap.h"

int	main(int argc, char **argv)
{
	STACKS
	TO_CHECK
	ft_sift(&l_a, &last_a, argc, argv);
	if (l_a == NULL)
		return (0);
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
	ft_is_sorted(l_a, l_b);
}
