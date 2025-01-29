
void	assign_stack_index(t_node **stack_a, int size)
{
	int	*stack_a_dup;
	t_node	*temp;
	int	i;

	stack_a_dup = stack_dup(*stack_a, size); 
	quick_sort(stack_a_dup, 0, size - 1);
	// i = 0;
	// while (i < size)
	// {
	// 	printf("%d ", stack_a_dup[i]);
	// 	i++;
	// }
	// 	printf("\n");
	
	temp = *stack_a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->content == stack_a_dup[i])
				temp->index = i;
			i++;
		}
		temp = temp->next;
	}
	free(stack_a_dup);
}

// Helper function to find the correct position in stack A
int find_position(t_node *stack_a, int index)
{
    t_node *current = stack_a;
    int position = 0;

    while (current->next)
    {
        if (current->index > index && current->next->index < index)
            return position + 1; // Insert between current and current->next
        current = current->next;
        position++;
    }

    // If index is smaller than all or larger than all, insert at the start
    return 0;
}


// Helper function to calculate moves for an element in stack B
void calculate_moves(t_node *stack_a, t_node *stack_b, int *moves_a, int *moves_b)
{
    int size_a = node_lst_size(stack_a);
    int size_b = node_lst_size(stack_b);

    t_node *temp_b = stack_b;
    while (temp_b)
    {
        int pos_a = find_position(stack_a, temp_b->index);
        int pos_b = 0;

        // Find the position of temp_b in stack B
        t_node *temp = stack_b;
        while (temp != temp_b)
        {
            temp = temp->next;
            pos_b++;
        }

        // Calculate rotations for stack A
        if (pos_a <= size_a / 2)
            moves_a[pos_b] = pos_a; // Forward rotations
        else
            moves_a[pos_b] = pos_a - size_a; // Reverse rotations

        // Calculate rotations for stack B
        if (pos_b <= size_b / 2)
            moves_b[pos_b] = pos_b; // Forward rotations
        else
            moves_b[pos_b] = pos_b - size_b; // Reverse rotations

        temp_b = temp_b->next;
    }
}

// Helper function to choose the optimal element to push
int find_optimal_move(int *moves_a, int *moves_b, int size_b)
{
    int min_moves = INT_MAX;
    int optimal_index = 0;

    for (int i = 0; i < size_b; i++)
    {
        int total_moves = abs(moves_a[i]) + abs(moves_b[i]);
        if (total_moves < min_moves)
        {
            min_moves = total_moves;
            optimal_index = i;
        }
    }
    return optimal_index;
}

// Function to execute the chosen moves
void execute_moves(t_node **stack_a, t_node **stack_b, int move_a, int move_b)
{
    // Rotate or reverse rotate stack A
    while (move_a > 0)
    {
        rotate_stack(stack_a, 'a'); // Rotate stack A
        move_a--;
    }
    while (move_a < 0)
    {
        reverse_rotate(stack_a, 'a'); // Reverse rotate stack A
        move_a++;
    }

    // Rotate or reverse rotate stack B
    while (move_b > 0)
    {
        rotate_stack(stack_b, 'b'); // Rotate stack B
        move_b--;
    }
    while (move_b < 0)
    {
        reverse_rotate(stack_b, 'b'); // Reverse rotate stack B
        move_b++;
    }

    // Push the chosen element to stack A
    push_stack(stack_b, stack_a, 'a');
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp; 
}
int	*stack_dup(t_node	*stack_a, int size)
{
	// int		size;
	int		*stack_a_dup;
	t_node	*temp;
	int		i;
	
	// size = node_lst_size(stack_a);
	stack_a_dup = malloc((size) * sizeof(int));
	if (!stack_a_dup)
		return (NULL);
	temp = stack_a;
	i = 0;
	while (temp != NULL)
	{
		stack_a_dup[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (stack_a_dup);
}

int	partition(int *stack, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	
	pivot = stack[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (stack[j] < pivot)
		{
			i++;
			swap_int(&stack[i], &stack[j]);
		}
		j++;
	}
	swap_int(&stack[i + 1], &stack[high]);	
	return (i);
}
void	quick_sort(int	*stack, int low, int high)
{
	int	pivot_index;
	
	if (low < high)
	{
		pivot_index = partition(stack, low, high);
		quick_sort(stack, low, pivot_index - 1);
		quick_sort(stack, pivot_index + 1, high); 
	}
}

void quicksort_stack(t_node **stack_a, t_node **stack_b, int size)
{
    if (size <= 3)
    {
        // Base case: Directly sort the stack if size is 2 or 3
        if (size == 2)
		{
			printf("sort 2 element of stack\n");
            sort_stack_of_two(stack_a);
			print_list(*stack_a);
		}
        else if (size == 3)
		{
			printf("sort 3 element of stack\n");
            sort_stack_of_three(stack_a);
			print_list(*stack_a);
		}
        return;
    }

    // Find the pivot (you can use median or random element, here using median)
    int pivot = find_pivot(*stack_a, size); // Assumes you have a function to get pivot

    // Partition stack_a into stack_a (>= pivot) and stack_b (< pivot)
    partition_stack(stack_a, stack_b, pivot, size);
	ft_printf("Stack a (larger than pivot): \n ");
	print_list(*stack_a);
	ft_printf("Stack b (smaller than pivot): \n ");
	print_list(*stack_b);

    // Count the number of elements pushed to stack_b
    int count_b = size - node_lst_size(*stack_a);  // Number of elements in stack_b
    int count_a = size - count_b;  // Number of elements in stack_a

    // Recursively sort both parts
    if (count_a > 0)
        quicksort_stack(stack_a, stack_b, count_a); // Recursively sort the larger part in stack_a
    // if (count_b > 0)
    //     quicksort_stack(stack_b, stack_a, count_b); // Recursively sort the smaller part in stack_b

    // After sorting both parts, push back elements from stack_b to stack_a
    while (*stack_b)
    {
        push_stack(stack_b, stack_a, 'a'); // Push sorted elements back into stack_a
    }
}

int	find_pivot(t_node *stack, int size)
{
	int	*stack_a_dup;
	int	median;

	stack_a_dup = stack_dup(stack, size);
	quick_sort(stack_a_dup, 0, size - 1);
	// for (int i = 0; i < size; i++)
	// {
	// 	ft_printf("%d ", stack_a_dup[i]);
	// }
	// ft_printf("\n");
	median = stack_a_dup[size / 2]; //if divided by 2 return float
	free(stack_a_dup);
	return (median);

}

void partition_stack(t_node **stack_a, t_node **stack_b, int pivot, int size)
{
    int i = 0;

    while (i < size)
    {
        if (*stack_a == NULL)
            break;
        if ((*stack_a)->content < pivot)
        {
            push_stack(stack_a, stack_b, 'b');  // Push to stack_b if smaller than pivot
        }
        else
        {
            rotate_stack(stack_a, 'a');        // Rotate stack_a if greater than or equal to pivot
        }
        i++;
    }
}