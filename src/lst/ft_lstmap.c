/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:04:43 by pguthaus          #+#    #+#             */
/*   Updated: 2021/09/08 00:20:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstmap_two(t_list **result, t_list **node_result, t_list *node,
	void *(*f)(void *))
{
	*result = ft_lstnew(f(node->content));
	*node_result = *result;
}

static void	ft_lstmap_three(t_list **result, t_list **node_result, t_list *node,
	void (*del)(void *), void *(*f)(void *))
{
	(*node_result)->next = ft_lstnew(f(node->content));
	if (!(*node_result)->next)
		ft_lstclear(result, del);
	(*node_result) = (*node_result)->next;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list			*result;
	t_list			*node_result;
	t_list			*node;

	node = lst;
	node_result = NULL;
	if (!f || !del)
		return (node_result);
	while (node)
	{
		if (!node_result)
		{
			ft_lstmap_two(&result, &node_result, node, f);
			if (node_result == NULL)
				return (NULL);
		}
		else
		{
			ft_lstmap_three(&result, &node_result, node, del, f);
		}
		node = node->next;
	}
	return (result);
}
