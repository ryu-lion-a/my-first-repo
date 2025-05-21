#include "main.h"

t_box pushswap2(t_box result){
    result = atob(result);
    //return result;
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
    while(result.b_size != 0){
    //while(g < 15){
        j = 0;
        while(j < result.a_size)
        {
            if(result.a[j] < result.a[result.ahead]){
                result.ahead = j;
            }
            j++;

        }
        j = 0;
        tmpbmin = 10000; 
        while(j < result.b_size){
            //while(j < 1){
            k = 0;
            tmpamin = 10000;
            while(k < result.a_size){
                if((result.b[j] < result.a[k])&&(result.a[k] < tmpamin)){//k移動回数になる
                    tmpamin = result.a[k];
                    tmpa = k;               
                }
                //  if(j == 0)
                //     printf(" %d&%d ",tmpa,tmpamin);
                k++;
            }
            // if(j == 0)
            // printf("a %d\n",tmpa);
           
            if(tmpamin == 10000)
                tmpa = result.ahead;
                
            if(tmpa > j)
                ll = tmpa;
            else
                ll = j;
            
            if(result.b_size - j > result.a_size - tmpa)
                rrn = result.b_size + 1 - j;
            else
                rrn = result.a_size + 1 - tmpa;
            
            lr = j + result.a_size + 1 - tmpa;

            rl = tmpa + result.b_size + 1 - j;

            

            if(ll <= rrn&&ll <= lr&&ll <= rl)
                mincount = ll;
            if(rrn <= ll&&rrn <= lr&&rrn <= rl)
                mincount = rrn;
            if(lr <= rrn&&lr <= ll&&lr <= rl)
                mincount = lr;
            if(rl <= ll&&rl <= lr&&rl <= rrn)
                mincount = rl;
            if(tmpbmin > mincount){
                //printf("aaa%daaa%d\n",mincount,j);
                tmpbmin = mincount;
                tmp = j;
            }
            j++;
        }
        //printf("b %d\n",tmp);
        k = 0;
            tmpamin = 10000;
            // printf("q %d p\n",tmpamin);
            // printf("%d",result.ahead);
            i = 0;
            while(k < result.a_size){                
                if((result.b[tmp] < result.a[k])&&(result.a[k] < tmpamin)){//k移動回数になる
                    tmpamin = result.a[k];
                    tmpa = k;            
                }                              
                k++;
            }
            
            if(tmpamin == 10000)
               tmpa = result.ahead;
            //printf(" %d&%d&%d ",tmpa,tmp,result.b[tmp]);
            if(tmpa > tmp)
                ll = tmpa;
            else
                ll = tmp;
            
            if(result.b_size - tmp > result.a_size - tmpa)
                rrn = result.b_size + 1 - tmp;
            else
                rrn = result.a_size + 1 - tmpa;
            
            lr = tmp + result.a_size + 1 - tmpa;

            rl = tmpa + result.b_size + 1 - tmp;
            // printf(" %d&%d ",tmpa,tmp);
            // printf(" %d&%d&%d&%d \n",ll,rrn,lr,rl);

            if(ll <= rrn&&ll <= lr&&ll <= rl){
                j = 0;
                if(tmpa > tmp){
                    longer = tmpa;
                    shoter = tmp;
                }else{
                    longer = tmp;
                    shoter = tmpa;
                }
                        
                while(j < shoter){
                    result = rr(result);
                    j++;
                }
                if(tmpa > tmp){
                    while(j < longer)
                    {
                        result = ra(result);
                        j++;
                    }
                }else{
                    while(j < longer)
                    {
                        result = rb(result);
                        j++;
                    }
                }
                result = pa(result);
                }else if(rrn <= ll&&rrn <= lr&&rrn <= rl)
            {
                j = 0;
                // printf(" %d&%d ",tmpa,tmp);
                if(result.a_size - tmpa > result.b_size - tmp){
                    longer = result.a_size - tmpa;
                    shoter = result.b_size - tmp;
                }else{
                    longer = result.b_size - tmp;
                    shoter = result.a_size - tmpa;
                }
                        
                while(j < shoter){
                    result = rrr(result);
                    j++;
                }
                if(result.a_size - tmpa > result.b_size - tmp){
                    while(j < longer)
                    {
                        result = rra(result);
                        j++;
                    }
                }else{
                    while(j < longer)
                    {
                        result = rrb(result);
                        j++;
                    }
                }
                result = pa(result);
            }else if(lr <= rrn&&lr <= ll&&lr <= rl)
            {
                //printf(" %d&%d ",tmpa,tmp);
                j = 0;
                while(j < result.a_size - tmpa)
                {
                    result = rra(result);
                    j++;
                }
                j = 0;
                while(j < tmp)
                {
                    result = rb(result);
                    j++;
                }
                result = pa(result);

            }else if(rl <= ll&&rl <= lr&&rl <= rrn)
            {
                j = 0;
                while(j < tmpa)
                {
                    result = ra(result);
                    j++;
                }
                j = 0;
                while(j < result.b_size - tmp)
                {
                    result = rrb(result);
                    j++;
                }
                result = pa(result);

            }

        //g++;

}
        j = 0;
        while(j < result.a_size)
        {
            if(result.a[j] < result.a[result.ahead]){
                result.ahead = j;
            }
            j++;

        }
if(result.ahead < result.a_size - result.ahead){
    i = 0;
    while(i < result.ahead){
        result = ra(result);
        i++;
    }
}else{
        i = 0;
    while(i < result.a_size - result.ahead){
        result = rra(result);
        i++;
    }
}
return result;
}