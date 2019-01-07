void	ft_lstaddt(t_list **alst, t_list *new)
{
	while (alst->next != NULL)
		*alst = alst->next;
	alst->next = new;
}
