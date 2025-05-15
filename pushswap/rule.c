/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryutaro <kryutaro@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:13:01 by kryutaro          #+#    #+#             */
/*   Updated: 2025/05/15 17:31:59 by kryutaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_box	sa(t_box result)
{
	int	tmp;

	if (result.a_size < 2)
	{
		return (result);
	}
	tmp = result.a[0];
	result.a[0] = result.a[1];
	result.a[1] = tmp;
	result.count++;
	return (result);
}

t_box	sb(t_box result)
{
	int	tmp;

	if (result.b_size < 2)
	{
		return (result);
	}
	tmp = result.b[0];
	result.b[0] = result.b[1];
	result.b[1] = tmp;
	result.count++;
	return (result);
}

t_box	ss(t_box result)
{
	result = sa(result);
	result = sb(result);
	result.count--;
	return (result);
}

t_box	pa(t_box result)
{
	int	i;
	int	tmp;

	if (result.b_size == 0)
		return (result);	
	i = 1;
	tmp = result.b[0];
	while (i < result.b_size)
	{
		result.b[i - 1] = result.b[i];
		i++;
	}
	result.b[i] = 0;
	i = result.a_size;
	while (0 < i)
	{
		result.a[i] = result.a[i - 1];
		i--;
	}
	result.a[i] = tmp;
	result.b_size--;
	result.a_size++;
	result.count++;
	return (result);
}

t_box	pb(t_box result)
{
	int	i;
	int	tmp;

	if (result.a_size == 0)
		return (result);
	i = 1;
	tmp = result.a[0];
	while (i < result.a_size)
	{
		result.a[i - 1] = result.a[i];
		i++;
	}
	result.a[i - 1] = 0;
	i = result.b_size;
	while (0 < i)
	{
		result.b[i] = result.b[i - 1];
		i--;
	}
	result.b[i] = tmp;
	result.b_size++;
	result.a_size--;
	result.count++;
	return (result);
}

t_box	ra(t_box result)
{
	int	tmp;
	int	i;

	if (result.a_size < 2)
	{
		return (result);
	}
	tmp = result.a[0];
	i = 0;
	while (i < result.a_size - 1)
	{
		result.a[i] = result.a[i + 1];
		i++;
	}
	result.a[i] = tmp;
	result.count++;
	return (result);
}

t_box	rb(t_box result)
{
	int tmp;
	int i;
	if (result.b_size < 2)
	{
		return (result);
	}
	tmp = result.b[0];
	i = 0;
	while (i < result.b_size - 1)
	{
		result.b[i] = result.b[i + 1];
		i++;
	}
	result.b[i] = tmp;
	result.count++;
	return (result);
}

t_box rr(t_box result){
	result = ra(result);
	result = rb(result);
	result.count--;
	return result;
}

t_box	rra(t_box result){
	int tmp;
	int i;
	if (result.a_size < 2)
	{
		return (result);
	}
	tmp = result.a[result.a_size - 1];
	i = result.a_size - 1;
	while(0 < i){
		result.a[i] = result.a[i - 1];
		i--;
	}
	result.a[0] = tmp;
	result.count++;
	return result;
}

t_box	rrb(t_box result){
	int tmp;
	int i;
	if (result.b_size < 2)
	{
		return (result);
	}
	tmp = result.b[result.b_size - 1];
	i = result.b_size - 1;
	while(0 < i){
		result.b[i] = result.b[i - 1];
		i--;
	}
	result.b[0] = tmp;
	result.count++;
	return result;
}

t_box rrr(t_box result){
	result = rra(result);
	result = rrb(result);
	result.count--;
	return result;
}