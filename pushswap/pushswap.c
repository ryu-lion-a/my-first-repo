/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryutaro <kryutaro@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:12:41 by kryutaro          #+#    #+#             */
/*   Updated: 2025/05/13 13:12:41 by kryutaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
//aaaaaaaaaa
t_box pushswap(t_box result){
    int swich;
    swich = 0;
    int i = 0;
    int count;
    int j = 0;
    int a = 7;
    int b = 3;
    while(result.remain > 1){

        if(swich  == 0){
            result = atob(result);
            result.sizedata_blen = result.sizedata_blen + 1;
            swich = 1;
        }else{
            result = btoa(result);
            result.sizedata_alen = result.sizedata_alen + 1;
            swich = 0;
        }
        i++;
    } 
    //return result;
    if(result.sizedata_alen > result.sizedata_blen){
        if(result.a[0] > result.a[1]){
            result = sa(result);
        }
    }else{
        if(result.b[0] > result.b[1]){
            result = sb(result);
        }
    }
    while(result.sizedata_blen != 0){
    // int t = 0;
    //     while(t < 1){

        if(result.sizedata_alen > result.sizedata_blen){
            if((result.sizedata_b[result.sizedata_blen - 1] > ((a*result.sizedata_b[result.sizedata_blen - 2])/b))&&result.sizedata_a[0] > ((a*result.sizedata_a[result.sizedata_alen - 1])/b)){
                i = 0;
                if(result.sizedata_b[result.sizedata_blen - 1] >= result.sizedata_a[result.sizedata_alen - 1])
                    count = result.sizedata_a[result.sizedata_alen - 1];
                else
                    count = result.sizedata_b[result.sizedata_blen - 1];

                while(i < count){
                    result = rrr(result);
                    i++;
                }
                i = 0;
                while(i < result.sizedata_b[result.sizedata_blen - 1] - count){
                    result = rrb(result);
                    i++;
                }
                while(i < result.sizedata_a[result.sizedata_alen - 1] - count){
                    result = rra(result);
                    i++;
                }
                result.sizedata_b = rrsize(result.sizedata_b,result.sizedata_blen);
                result.sizedata_a = rrsize(result.sizedata_a,result.sizedata_alen);

            }else if(result.sizedata_b[result.sizedata_blen - 1] > ((a*result.sizedata_b[result.sizedata_blen - 2])/b)){
                    i = 0;
                while(i < result.sizedata_b[result.sizedata_blen - 1]){
                    result = rrb(result);
                    i++;
                }
                result.sizedata_b = rrsize(result.sizedata_b,result.sizedata_blen);

            }else if(result.sizedata_a[0] > ((a*result.sizedata_a[result.sizedata_alen - 1])/b)){
                    i = 0;
                while(i < result.sizedata_a[result.sizedata_alen - 1]){
                    result = rra(result);
                    i++;
                }
                result.sizedata_a = rrsize(result.sizedata_a,result.sizedata_alen);
            }
            i = 0;
            j = 0;
            while(i < result.sizedata_b[result.sizedata_blen - 1]){
                while((result.a[0] < result.b[result.b_size - 1])&&j < result.sizedata_a[0]){
                    result = pb(result);
                    j++;
                }
                result = rrb(result);
                i++;
            }
            while(j < result.sizedata_a[0]){
                    result = pb(result);
                    j++;
                }
            result.sizedata_b = rrsize(result.sizedata_b,result.sizedata_blen);
            result.sizedata_b[0] = result.sizedata_b[0] + result.sizedata_a[0];
            result.sizedata_a = sizedeltop(result.sizedata_a,result.sizedata_alen);
            result.sizedata_alen = result.sizedata_alen - 1;
            //return result;
            

        }else{
            if((result.sizedata_a[result.sizedata_alen - 1] > ((a*result.sizedata_a[result.sizedata_alen - 2])/b))&&result.sizedata_b[0] > ((a*result.sizedata_b[result.sizedata_blen - 1])/b)){
                i = 0;
                if(result.sizedata_a[result.sizedata_alen - 1] >= result.sizedata_b[result.sizedata_blen - 1])
                    count = result.sizedata_b[result.sizedata_blen - 1];
                else
                    count = result.sizedata_a[result.sizedata_alen - 1];
                while(i < count){
                    result = rrr(result);
                    i++;
                }
                i = 0;
                while(i < result.sizedata_a[result.sizedata_alen - 1] - count){
                    result = rra(result);
                    i++;
                }
                while(i < result.sizedata_b[result.sizedata_blen - 1] - count){
                    result = rrb(result);
                    i++;
                }
                result.sizedata_a = rrsize(result.sizedata_a,result.sizedata_alen);
                result.sizedata_b = rrsize(result.sizedata_b,result.sizedata_blen);

            }else if(result.sizedata_a[result.sizedata_alen - 1] > ((a*result.sizedata_a[result.sizedata_alen - 2])/b)){
                    i = 0;
                while(i < result.sizedata_a[result.sizedata_alen - 1]){
                    result = rra(result);
                    i++;
                }
                result.sizedata_a = rrsize(result.sizedata_a,result.sizedata_alen);

            }else if(result.sizedata_b[0] > ((a*result.sizedata_b[result.sizedata_blen - 1])/b)){
                    i = 0;
                while(i < result.sizedata_b[result.sizedata_blen - 1]){
                    result = rrb(result);
                    i++;
                }
                result.sizedata_b = rrsize(result.sizedata_b,result.sizedata_blen);
            }
            i = 0;
            j = 0;
            while(i < result.sizedata_a[result.sizedata_alen - 1]){
                while((result.b[0] > result.a[result.a_size - 1])&&j < result.sizedata_b[0]){
                    result = pa(result);
                    j++;
                }
                result = rra(result);
                i++;
            }
             while(j < result.sizedata_b[0]){
                    result = pa(result);
                    j++;
                }
            result.sizedata_a = rrsize(result.sizedata_a,result.sizedata_alen);
            result.sizedata_a[0] = result.sizedata_a[0] + result.sizedata_b[0];
            result.sizedata_b = sizedeltop(result.sizedata_b,result.sizedata_blen);
            result.sizedata_blen = result.sizedata_blen - 1;



        }
        // t++;

    }



    return result;
}

t_box atob(t_box result){
    int lissize;
    int *lisbox;
    int i;
    int j;
    int a;
    int sizetmp;
    lissize = sizelis(result.a,result.remain);

        sizetmp = result.remain;
        lisbox = (int *)malloc(sizeof(int) *(lissize));
        lisbox = lis(result.a,result.remain);
        i = 0;
        while(i < lissize){
            i++;
        }
        result.remain = result.remain - lissize;
        i = 0;
        while(i < sizetmp)
        {
            j = 0;
            a = 0;
            while(j < lissize)
            {
                if(result.a[0] == lisbox[j])
                    a = 1;
                j++;               
            }
            if(a == 1)
                result = ra(result);
            else
                result = pb(result);
            i++;
        }
    result = pushdata(result,lissize,0);
    free(lisbox);
    return result;

}

t_box btoa(t_box result){
    int lissize;
    int *lisbox;
    int i;
    int j;
    int a;
    int sizetmp;
    lissize = revsizelis(result.b,result.remain);
    sizetmp = result.remain;
        lisbox = (int *)malloc(sizeof(int) *(lissize));
        lisbox = revlis(result.b,result.remain);
        result.remain = result.remain - lissize;
        i = 0;
        while(i < sizetmp)
        {
            j = 0;
            a = 0;
            while(j < lissize)
            {
                if(result.b[0] == lisbox[j])
                    a = 1;
                j++;               
            }
            if(a == 1)
                result = rb(result);
            else
                result = pa(result);
            i++;
        }
    result = pushdata(result,lissize,1);
    free(lisbox);
    return result;
}

t_box pushdata(t_box result,int lissize,int swich){
    int i;
    i = 0;
    int j;
    if(swich == 0){
        while(result.sizedata_a[i + 1] != -1)
            i++;
        //result.sizedata_a[i] = lissize;
        // printf("\n%d\n",i);
        j = 0;
        while(j < i){
            result.sizedata_a[j] = result.sizedata_a[j + 1];
            j++;
        }
        result.sizedata_a[i] = lissize;
        i = 0;
        while(result.sizedata_b[i] != -1)
            i++;
        while(i > 0){
            result.sizedata_b[i] = result.sizedata_b[i - 1];
            i--;
        }
        
        result.sizedata_b[0] = result.remain;

    }else{
        while(result.sizedata_b[i + 1] != -1)
            i++;
        // result.sizedata_b[i] = lissize;
           j = 0;
        while(j < i){
            result.sizedata_b[j] = result.sizedata_b[j + 1];
            j++;
        }
        result.sizedata_b[i] = lissize;
        
        i = 0;
        while(result.sizedata_a[i] != -1)
            i++;
        while(i > 0){
            result.sizedata_a[i] = result.sizedata_a[i - 1];
            i--;
        }
        result.sizedata_a[0] = result.remain;
    }
    return result;   
}

int *rrsize(int *sizedata_a,int sizedata_alen){
    int tmp;
	int i;
	if (sizedata_alen < 2)
	{
		return (sizedata_a);
	}
	tmp = sizedata_a[sizedata_alen - 1];
	i = sizedata_alen - 1;
	while(0 < i){
		sizedata_a[i] = sizedata_a[i - 1];
		i--;
	}
	sizedata_a[0] = tmp;
	return sizedata_a;

}

int *sizedeltop(int *sizedata_a,int sizedata_alen){
	int i;
	if (sizedata_alen < 2)
	{
		return (sizedata_a);
	}
	i = 0;
	while(i < sizedata_alen){
		sizedata_a[i] = sizedata_a[i + 1];
		i++;
	}
	return sizedata_a;
}


