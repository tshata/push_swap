/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:30:24 by tshata            #+#    #+#             */
/*   Updated: 2018/08/28 18:33:45 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
typedef struct	s_stacknode
{
	int 				data;
	struct s_stacknode 	*next;
} 		t_stacknode;		

/*
 **function to create new node
 */
t_stacknode		*new_node(int data)
{
	t_stacknode	*stacknode;

	stacknode = (t_stacknode*)malloc(sizeof(t_stacknode));
	stacknode->data = data;
	stacknode->next = NULL;
	return (stacknode);
}

int		isempty(t_stacknode	*root)
{
	return (!root);
}

void	push(t_stacknode **root, int data)
{
	t_stacknode	*stacknode = new_node(data);
	stacknode->next = *root;
	*root = stacknode;
	printf("%d pushed to stack\n", data);
}

int		pop(t_stacknode **root)
{
	int popped;

	popped = 0;
	if (isempty(*root))
		return (INT_MIN);
	t_stacknode	*temp = *root;
	*root = (*root)->next;
	popped = temp->data;
	free(temp);

	return (popped);
}

int	peek(t_stacknode *root)
{
	if (isempty(root))
		return INT_MIN;
	return root->data;
}
int		main(int argc,char **argv)
{
	int i;
	t_stacknode *root;

	root = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	else 
	{
		while(i < 20)
		{	
			printf("%d popped from stack\n", pop(&root));
			printf("Top element is %d\n", peek(root));
			push(&root, i);
			push(&root, i + i);
			i++;
			printf("%d popped from stack\n", pop(&root));
			printf("Top element is %d\n", peek(root));
		}
	}

return(0);
}
