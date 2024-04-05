#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Define the Node structure
typedef struct s_node
{
	long			data;
	struct s_node	*prev;
	struct s_node	*next;
}					s_node;

// Define the Stack structure
typedef struct s_stack
{
	struct s_node	*head;
}					s_stack;

int					ft_atoi(const char *nptr);
char				**ft_split(const char *s, char delimiter);
long				*return_numbers(int argc, char **argv, int *size);
int					duplicate_numbers(long *numbers, int size);
void				display(struct s_stack *stack);
s_stack				*array_to_stack(long arr[], int size);
void				free_stack(struct s_stack *stack);
int					is_sorted(s_stack *stack);
int					isSortedDesc(s_stack *stack);
void sa(s_stack *stack);
void sb(s_stack *stack);
void ss(s_stack *stack);
void pa(s_stack **a, s_stack **b);
void pb(s_stack **a, s_stack **b);
void ra(s_stack *stack);
void rb(s_stack *stack);
void rr(s_stack *a, s_stack *b);
void rra(s_stack *stack);
void rrb(s_stack *stack);
void rrr(s_stack *a, s_stack *b);
void	push(s_stack *stack, long data);

#endif