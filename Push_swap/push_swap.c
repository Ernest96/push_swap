
int	main(int argc, char **argv)
{
	STACKS
	int j;
	char **str;

	while (++i < argc)
		{
			ft_check_arg(*(argv + i));
			str  = ft_strsplit(*(argv + i), ' ');
			j = -1;
			while (*(str + ++j))
				PUSH_A(ft_atoi_check(*(str + j)));
			j = -1;
			while (*(str + ++j))
				free(*(str + j));
			free(str);
		}
	if (ft_check_sort(l_a))
			return (0);
	push_swap(&l_a, &last_a, &l_b, &last_b);
	if (ft_check_sort(l_a))
		printf("ok");
}