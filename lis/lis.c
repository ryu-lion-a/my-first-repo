
#include "main.h"
//１サイズ大きくとって終端に－１置いた方が安全そう。
int *makeinit(int *longest,int size,int p){
    int i;
    i = 0;
    while(i < size)
    {
        longest[i] = p;
        i++; 
    }
    return longest;
}
int *copypush(int *resulti,int *resultj,int size,int pushnum){
    int i;
    i = 0;
    //printf("%d",size);
    while((resultj[i] != -1)){
        resulti[i] = resultj[i];
        i++;
    }
    //printf("i%d",i);
    resulti[i] = pushnum;
    return resulti;
}
int *lis(int *numbox,int size){
    int **resultbox;
    int *longest;
    int i;
    int j;
    int lnum;
    int *result;
    lnum = 0;
    resultbox = (int **)malloc(sizeof(int *)*size);
    longest = (int *)malloc(sizeof(int)*size);
    longest = makeinit(longest,size,1);
    i = 0;
    while(i < size)
    {
        j = 0;
        resultbox[i] = (int *)malloc(sizeof(int)*size);
        resultbox[i] = makeinit(resultbox[i],size,-1);
        
        resultbox[i][0] = numbox[i];
       
        
        while(j < i)
        {
            if((numbox[i] > numbox[j])&&(longest[i] < longest[j] + 1))
            { 
                resultbox[i] = copypush(resultbox[i],resultbox[j],size,numbox[i]);
                longest[i] = longest[j] + 1;

            }
            j++;
        }
      i++;
     }
    i = 0;
    j = 0;
    while(i < size)
    {
        if(lnum < longest[i]){
            lnum = longest[i];
            j = i;
        }
        i++;
    }//後でフリーする
    return resultbox[j]; 

}