int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = digitsSize-1;
    *returnSize=digitsSize;
    int *result = malloc((digitsSize+1)*sizeof(int));
    while(i>=0){
        if(digits[i]<9){
            digits[i]++;
            return digits;
            break;
        }
        if(digits[i]==9){
            digits[i]=0;
             result[i+1] = digits[i];
             i--;
        }       
    }
    if(digits[0]==0){
        result[0]=1;
        *returnSize=digitsSize+1;
    }
   return result;
}