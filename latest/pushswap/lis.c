
#include "main.h"

//１サイズ大きくとって終端に－１置いた方が安全そう。
int	*makeinit(int *longest, int size, int p)
{
	int i;
	i = 0;
	while (i < size)
	{
		longest[i] = p;
		i++;
	}
	return (longest);
}
int	*copypush(int *resulti, int *resultj, int size, int pushnum)
{
	int i;
	i = 0;
	// printf("%d",size);
	while ((resultj[i] != -1))
	{
		resulti[i] = resultj[i];
		i++;
	}
	// printf("i%d",i);
	resulti[i] = pushnum;
	return (resulti);
}
int	*lis(int *numbox, int size)
{
	int **resultbox;
	int *longest;
	int i;
	int j;
	int lnum;
	int *result;
	lnum = 0;
	resultbox = (int **)malloc(sizeof(int *) * size);
	longest = (int *)malloc(sizeof(int) * size);
	longest = makeinit(longest, size, 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		resultbox[i] = (int *)malloc(sizeof(int) * size);
		resultbox[i] = makeinit(resultbox[i], size, -1);

		resultbox[i][0] = numbox[i];

		while (j < i)
		{
			if ((numbox[i] > numbox[j]) && (longest[i] < longest[j] + 1))
			{
				resultbox[i] = copypush(resultbox[i], resultbox[j], size,
						numbox[i]);
				longest[i] = longest[j] + 1;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		if (lnum < longest[i])
		{
			lnum = longest[i];
			j = i;
		}
		i++;
	} //後でresultboxフリーする
	free(longest);
	result = (int *)malloc(sizeof(int) * (lnum + 1));
	result = makeinit(result, lnum + 1, -1);
	i = 0;
	while (i < lnum)
	{
		result[i] = resultbox[j][i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		free(resultbox[i]);
		i++;
	}
	free(resultbox);

	return (result);
}

int	*revlis(int *numbox, int size)
{
	int **resultbox;
	int *longest;
	int i;
	int j;
	int lnum;
	int *result;
	lnum = 0;
	resultbox = (int **)malloc(sizeof(int *) * size);
	longest = (int *)malloc(sizeof(int) * size);
	longest = makeinit(longest, size, 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		resultbox[i] = (int *)malloc(sizeof(int) * size);
		resultbox[i] = makeinit(resultbox[i], size, -1);

		resultbox[i][0] = numbox[i];

		while (j < i)
		{
			if ((numbox[i] < numbox[j]) && (longest[i] < longest[j] + 1))
			{
				resultbox[i] = copypush(resultbox[i], resultbox[j], size,
						numbox[i]);
				longest[i] = longest[j] + 1;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		if (lnum < longest[i])
		{
			lnum = longest[i];
			j = i;
		}
		i++;
	} //後でresultboxフリーする
	free(longest);
	result = (int *)malloc(sizeof(int) * (lnum + 1));
	result = makeinit(result, lnum + 1, -1);
	i = 0;
	while (i < lnum)
	{
		result[i] = resultbox[j][i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		free(resultbox[i]);
		i++;
	}
	free(resultbox);

	return (result);
}

int	sizelis(int *numbox, int size)
{
	int *longest;
	int i;
	int j;
	int lnum;
	lnum = 0;
	longest = (int *)malloc(sizeof(int) * size);
	longest = makeinit(longest, size, 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if ((numbox[i] > numbox[j]) && (longest[i] < longest[j] + 1))
			{
				longest[i] = longest[j] + 1;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		if (lnum < longest[i])
		{
			lnum = longest[i];
			j = i;
		}
		i++;
	} //後でresultboxフリーする
	free(longest);
	return (lnum);
}

int	revsizelis(int *numbox, int size)
{
	int *longest;
	int i;
	int j;
	int lnum;
	lnum = 0;
	longest = (int *)malloc(sizeof(int) * size);
	longest = makeinit(longest, size, 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if ((numbox[i] < numbox[j]) && (longest[i] < longest[j] + 1))
			{
				longest[i] = longest[j] + 1;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		if (lnum < longest[i])
		{
			lnum = longest[i];
			j = i;
		}
		i++;
	} //後でresultboxフリーする
	free(longest);
	return (lnum);
}

int	longestcheck(int *result, int size)
{
	int i;
	int tmp;
	int tmp1;
	int moverr;
	int moverr1;
	i = 0;
	tmp = 0;
	while (i < size)
	{
		tmp1 = sizelis(result, size);
		// printf("\n%d ",tmp1);
		if (tmp < tmp1)
		{
			tmp = tmp1;
			moverr = i + 1;
		}
		if (tmp == tmp1)
			moverr1 = i + 1;
		result = rrsize(result, size);

		i++;
	}
	// printf("p%dq\np%dq\n",moverr,moverr1);
	if ((100 - moverr1) < moverr)
		return (moverr1);
	return (moverr);
}

t_box	makelong(t_box result, int move)
{
	int i;
	i = 0;
	if (move < result.a_size / 2)
	{
		while (i < move)
		{
			result = rra(result);
			i++;
		}
	}
	else
	{
		while (i < result.a_size - move)
		{
			result = ra(result);
			i++;
		}
	}

	return (result);
}

int	rlongestcheck(int *result, int size)
{
	int i;
	int tmp;
	int tmp1;
	int moverr;
	int moverr1;
	i = 0;
	tmp = 0;
	while (i < size)
	{
		tmp1 = revsizelis(result, size);
		printf("\n%d ", tmp1);
		if (tmp < tmp1)
		{
			tmp = tmp1;
			moverr = i + 1;
		}
		if (tmp == tmp1)
			moverr1 = i + 1;
		result = rrsize(result, size);

		i++;
	}
	// printf("p%dq\np%dq\n",moverr,moverr1);
	if ((100 - moverr1) < moverr)
		return (moverr1);
	return (moverr);
}