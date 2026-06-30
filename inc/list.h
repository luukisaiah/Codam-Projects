/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                              :+:    :+:           */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 15:09:17 by lderks        #+#    #+#                 */
/*   Updated: 2025/11/11 13:34:30 by lderks         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "typedef.h"

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **list, void (*func)(void *content));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstnew_safe(t_minishell *shell, void *content);
int		ft_lstsize(t_list *lst);
void	lstclear_safe(t_minishell *shell, t_list **lst,
			void (*func)(t_minishell *shell, void *content));

#endif
