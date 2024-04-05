#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h> // For malloc, free

int is_empty(s_stack *stack);
s_node *peek(s_stack *stack);


int is_empty(s_stack *stack) {
    return stack->head == NULL;
}

s_node *peek(s_stack *stack) {
    // Return the top element of the stack without removing it
    return stack->head;
}

int	stack_size(s_stack *lst)
{
	int		count;
	s_node	*current;

	if (lst == NULL || lst->head == NULL)
	{
		return (0); // Handle empty list case
	}
	count = 0;
	current = lst->head;
	s_node *start = lst->head; // Store the starting node
	// Traverse the circular linked list
	while (1)
	{
		count++;
		current = current->next;
		if (current == start)
		{
			break ; // Break the loop when we reach the starting node again
		}
	}
	return (count);
}

long find_max(s_stack *stack) {
    if (stack == NULL || stack->head == NULL) {
        fprintf(stderr, "Stack is empty.\n");
        exit(1); // or handle the error as appropriate
    }

    s_node *current = stack->head;
    long max_value = current->data; // Initialize max with the head's data

    // Iterate through the stack. Since it's circular, stop when we circle back to the head.
    do {
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    } while (current != stack->head);

    return max_value;
}


void sort_stacks(s_stack **a, s_stack **b) {
    int size = stack_size(*a);
    int max_bits = 0;
    long max_num = find_max(*a);

    // Calculate the maximum number of bits needed to represent the largest number
    while ((max_num >> max_bits) != 0) max_bits++;

    // For each bit, distribute elements based on the current bit
    for (int i = 0; i < max_bits; i++) {
        for (int j = 0; j < size; j++) {
            long num = (*a)->head->data;
            if ((num >> i) & 1) {
                ra(*a); // If the current bit is 1, rotate A
            } else {
                pb(a, b); // If the current bit is 0, push to B
            }
        }
        // Move everything back to A
        while (!is_empty(*b)) {
            pa(a, b);
        }
    }
}

int main(int argc, char **argv) {
    long *numbers_array;
    int size;
    s_stack *a;
    s_stack *b;

    // Assume return_numbers and array_to_stack are implemented elsewhere
    numbers_array = return_numbers(argc, argv, &size);
    a = array_to_stack(numbers_array, size);
    b = (s_stack *)malloc(sizeof(s_stack));
    b->head = NULL; // Initialize B as empty

    // SORTING HERE
    sort_stacks(&a, &b);
    display(a);
    // Cleanup
    free(numbers_array);
    free_stack(a);
    free(b);
    return 0;
}

// Implement free_stack and any other necessary utility functions
