#include "push_swap.h"

void swap_(s_stack *stack) {
    if (stack && stack->head && stack->head->next != stack->head) { // Ensure at least two elements exist
        s_node *first = stack->head;
        s_node *second = first->next;
        first->next = second->next;
        second->next->prev = first;
        second->next = first;
        first->prev = second;
        stack->head = second; // Update head to the new first element
    }
}

void sa(s_stack *stack) {
    swap_(stack);
    write(1, "sa\n", 3);
}

void sb(s_stack *stack) {
    swap_(stack);
    write(1, "sb\n", 3);
}

void ss(s_stack *stack) {
    swap_(stack);
    write(1, "ss\n", 3);
}

void push_to(s_stack **a, s_stack **b) {
    if (!b || !(*b)->head) return; // Ensure b is not empty
    s_node *node = (*b)->head; // Top node of b
    // Remove from b
    if (node->next == node) { // Only one element
        (*b)->head = NULL;
    } else {
        (*b)->head = node->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    // Add to a
    if (!(*a)->head) { // If a is empty
        node->next = node->prev = node;
        (*a)->head = node;
    } else { // Insert before current head
        node->next = (*a)->head;
        node->prev = (*a)->head->prev;
        (*a)->head->prev->next = node;
        (*a)->head->prev = node;
        (*a)->head = node; // Update head
    }
}

void pa(s_stack **a, s_stack **b) {
    push_to(a, b);
}

void pb(s_stack **a, s_stack **b) {
    push_to(b, a);
}

void rotate(s_stack *stack) {
    if (stack && stack->head && stack->head->next != stack->head) {
        stack->head = stack->head->next; // Move head to the next element
    }
}

void ra(s_stack *stack) {
    rotate(stack);
    write(1, "ra\n", 3);
}

void rb(s_stack *stack) {
    rotate(stack);
    write(1, "rb\n", 3);
}


void rr(s_stack *a, s_stack *b) {
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void reverse_rotate(s_stack *stack) {
    if (stack && stack->head && stack->head->next != stack->head) {
        stack->head = stack->head->prev; // Move head to the previous element
    }
}

void rra(s_stack *stack) {
    reverse_rotate(stack); // rrb is identical to rra, but operates on stack b
    write(1, "rra\n", 4);
}

void rrb(s_stack *stack) {
    reverse_rotate(stack); // rrb is identical to rra, but operates on stack b
    write(1, "rrb\n", 4);
}


void rrr(s_stack *a, s_stack *b) {
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
