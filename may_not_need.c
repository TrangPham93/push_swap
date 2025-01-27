
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

