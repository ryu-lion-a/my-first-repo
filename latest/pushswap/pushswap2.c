#include "main.h"


t_box	pushswap2(t_box result)
{
	result = atob(result);
	// return (result);
	int i;
	int j;
	int k;
	int l;
	int m;
	int tmpamin;
	int tmpa;
	int tmpbmin;
	int tmpb;
	int bsize;
	int ran;
	int rbn;
	int ll;
	int rrn;
	int rl;
	int lr;
	int mincount;
	int tmp;
	int longer;
	int shoter;
	int g = 0;
	tmpamin = 10000;
	bsize = result.b_size;
	while (result.b_size != 0)
	{
		// while(g < 15){
		j = 0;
		while (j < result.a_size)
		{
			if (result.a[j] < result.a[result.ahead])
			{
				result.ahead = j;
			}
			j++;
		}
		j = 0;
		tmpbmin = 10000;
		while (j < result.b_size)
		{
			// while(j < 1){
			k = 0;
			tmpamin = 10000;
			while (k < result.a_size)
			{
				if ((result.b[j] < result.a[k]) && (result.a[k] < tmpamin))
				{ // k移動回数になる
					tmpamin = result.a[k];
					tmpa = k;
				}
				//  if(j == 0)
				//     printf(" %d&%d ",tmpa,tmpamin);
				k++;
			}
			// if(j == 0)
			// printf("a %d\n",tmpa);

			if (tmpamin == 10000)
				tmpa = result.ahead;

			if (tmpa > j)
				ll = tmpa;
			else
				ll = j;

			if (result.b_size - j > result.a_size - tmpa)
				rrn = result.b_size + 1 - j;
			else
				rrn = result.a_size + 1 - tmpa;

			lr = j + result.a_size + 1 - tmpa;

			rl = tmpa + result.b_size + 1 - j;

			if (ll <= rrn && ll <= lr && ll <= rl)
				mincount = ll;
			if (rrn <= ll && rrn <= lr && rrn <= rl)
				mincount = rrn;
			if (lr <= rrn && lr <= ll && lr <= rl)
				mincount = lr;
			if (rl <= ll && rl <= lr && rl <= rrn)
				mincount = rl;
			if (tmpbmin > mincount)
			{
				// printf("aaa%daaa%d\n",mincount,j);
				tmpbmin = mincount;
				tmp = j;
			}
			j++;
		}
		// printf("b %d\n",tmp);
		k = 0;
		tmpamin = 10000;
		// printf("q %d p\n",tmpamin);
		// printf("%d",result.ahead);
		i = 0;
		while (k < result.a_size)
		{
			if ((result.b[tmp] < result.a[k]) && (result.a[k] < tmpamin))
			{ // k移動回数になる
				tmpamin = result.a[k];
				tmpa = k;
			}
			k++;
		}

		if (tmpamin == 10000)
			tmpa = result.ahead;
		// printf(" %d&%d&%d ",tmpa,tmp,result.b[tmp]);
		if (tmpa > tmp)
			ll = tmpa;
		else
			ll = tmp;

		if (result.b_size - tmp > result.a_size - tmpa)
			rrn = result.b_size + 1 - tmp;
		else
			rrn = result.a_size + 1 - tmpa;

		lr = tmp + result.a_size + 1 - tmpa;

		rl = tmpa + result.b_size + 1 - tmp;
		// printf(" %d&%d ",tmpa,tmp);
		// printf(" %d&%d&%d&%d \n",ll,rrn,lr,rl);

		if (ll <= rrn && ll <= lr && ll <= rl)
		{
			j = 0;
			if (tmpa > tmp)
			{
				longer = tmpa;
				shoter = tmp;
			}
			else
			{
				longer = tmp;
				shoter = tmpa;
			}

			while (j < shoter)
			{
				result = rr(result);
				j++;
			}
			if (tmpa > tmp)
			{
				while (j < longer)
				{
					result = ra(result);
					j++;
				}
			}
			else
			{
				while (j < longer)
				{
					result = rb(result);
					j++;
				}
			}
			result = pa(result);
		}
		else if (rrn <= ll && rrn <= lr && rrn <= rl)
		{
			j = 0;
			// printf(" %d&%d ",tmpa,tmp);
			if (result.a_size - tmpa > result.b_size - tmp)
			{
				longer = result.a_size - tmpa;
				shoter = result.b_size - tmp;
			}
			else
			{
				longer = result.b_size - tmp;
				shoter = result.a_size - tmpa;
			}

			while (j < shoter)
			{
				result = rrr(result);
				j++;
			}
			if (result.a_size - tmpa > result.b_size - tmp)
			{
				while (j < longer)
				{
					result = rra(result);
					j++;
				}
			}
			else
			{
				while (j < longer)
				{
					result = rrb(result);
					j++;
				}
			}
			result = pa(result);
		}
		else if (lr <= rrn && lr <= ll && lr <= rl)
		{
			// printf(" %d&%d ",tmpa,tmp);
			j = 0;
			while (j < result.a_size - tmpa)
			{
				result = rra(result);
				j++;
			}
			j = 0;
			while (j < tmp)
			{
				result = rb(result);
				j++;
			}
			result = pa(result);
		}
		else if (rl <= ll && rl <= lr && rl <= rrn)
		{
			j = 0;
			while (j < tmpa)
			{
				result = ra(result);
				j++;
			}
			j = 0;
			while (j < result.b_size - tmp)
			{
				result = rrb(result);
				j++;
			}
			result = pa(result);
		}

		// g++;
	}
	j = 0;
	while (j < result.a_size)
	{
		if (result.a[j] < result.a[result.ahead])
		{
			result.ahead = j;
		}
		j++;
	}
	if (result.ahead < result.a_size - result.ahead)
	{
		i = 0;
		while (i < result.ahead)
		{
			result = ra(result);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < result.a_size - result.ahead)
		{
			result = rra(result);
			i++;
		}
	}
	return (result);
}

// t_box	atob(t_box result)
// {
// 	int lissize;
// 	int *lisbox;
// 	int i;
// 	int j;
// 	int a;
// 	int sizetmp;
// 	lissize = sizelis(result.a, result.remain);

// 	sizetmp = result.remain;
// 	lisbox = (int *)malloc(sizeof(int) * (lissize));
// 	lisbox = lis(result.a, result.remain);
// 	i = 0;
// 	while (i < lissize)
// 	{
// 		i++;
// 	}
// 	result.remain = result.remain - lissize;
// 	i = 0;
// 	while (i < sizetmp)
// 	{
// 		j = 0;
// 		a = 0;
// 		while (j < lissize)
// 		{
// 			if (result.a[0] == lisbox[j])
// 				a = 1;
// 			j++;
// 		}
// 		if (a == 1)
// 			result = ra(result);
// 		else
// 			result = pb(result);
// 		i++;
// 	}
// 	result = pushdata(result, lissize, 0);
// 	free(lisbox);
// 	return (result);
// }
t_box	atob(t_box result)
{
	int lissize;
	int *lisbox;
	int i;
	int j;
	int a;
	int sizetmp;
	lissize = sizelis(result.a, result.remain);

	sizetmp = result.remain;
	lisbox = (int *)malloc(sizeof(int) * (lissize));
	lisbox = lis(result.a, result.remain);
	i = 0;
	while (i < lissize)
	{
		i++;
	}
	result.remain = result.remain - lissize;
	i = 0;
	while (i < sizetmp)
	{
		j = 0;
		a = 0;
		while (j < lissize)
		{
			if (result.a[0] == lisbox[j])
				a = 1;
			j++;
		}
		if (a == 1)
			result = ra(result);
		else
			result = pb(result);
		i++;
	}
	result = pushdata(result, lissize, 0);
	free(lisbox);
	return (result);
}

t_box	pushdata(t_box result, int lissize, int swich)
{
	int i;
	i = 0;
	int j;
	if (swich == 0)
	{
		while (result.sizedata_a[i + 1] != -1)
			i++;
		// result.sizedata_a[i] = lissize;
		// printf("\n%d\n",i);
		j = 0;
		while (j < i)
		{
			result.sizedata_a[j] = result.sizedata_a[j + 1];
			j++;
		}
		result.sizedata_a[i] = lissize;
		i = 0;
		while (result.sizedata_b[i] != -1)
			i++;
		while (i > 0)
		{
			result.sizedata_b[i] = result.sizedata_b[i - 1];
			i--;
		}

		result.sizedata_b[0] = result.remain;
	}
	else
	{
		while (result.sizedata_b[i + 1] != -1)
			i++;
		// result.sizedata_b[i] = lissize;
		j = 0;
		while (j < i)
		{
			result.sizedata_b[j] = result.sizedata_b[j + 1];
			j++;
		}
		result.sizedata_b[i] = lissize;

		i = 0;
		while (result.sizedata_a[i] != -1)
			i++;
		while (i > 0)
		{
			result.sizedata_a[i] = result.sizedata_a[i - 1];
			i--;
		}
		result.sizedata_a[0] = result.remain;
	}
	return (result);
}

int	*rrsize(int *sizedata_a, int sizedata_alen)
{
	int tmp;
	int i;
	if (sizedata_alen < 2)
	{
		return (sizedata_a);
	}
	tmp = sizedata_a[sizedata_alen - 1];
	i = sizedata_alen - 1;
	while (0 < i)
	{
		sizedata_a[i] = sizedata_a[i - 1];
		i--;
	}
	sizedata_a[0] = tmp;
	return (sizedata_a);
}