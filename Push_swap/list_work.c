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

void	ft_insert_node(t_stack *temp, t_stack **last, int element)
{
	temp->next = (t_stack*)malloc(sizeof(t_stack));
	temp = temp->next;
	temp->value = element;
	temp->next = NULL;
	temp->prev = *last;
	*last = temp;
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
	ft_insert_node(temp, last, element);
}

int ft_atoi_check(const char *str)
{
	uint8_t i;
	long long nr;
	uint8_t n;

	i = 0;
	nr = 0;
	n = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == ' ') ||
			(str[i] == '\f') || (str[i] == '\v') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		n = 1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nr *= 10;
		nr += (long long)str[i] - '0';
		i++;
	}
	if (n)
		nr = -nr;
	if (nr > 2147483647 || nr < -2147483648)
		ft_error();
	return (int)nr;
}