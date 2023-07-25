#include <stdio.h>
#include <stdlib.h>
#define N 100

float x[N];

float max(float x, float y)
{
    return x>y ? x : y;
}

int compare(const void* a, const void* b) {
    float fa = *((float*) a);
    float fb = *((float*) b);
    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

float fasb(float x)
{
    return x>0 ? x : -x; 
}
/*基础扫描算法*/
float maxsum(float arr[], int n)
{
    float maxsofar = *arr;
    float maxendinghere = *arr;
    for(int i=0 ; i<n ; i++)
    {
        maxendinghere = max(maxendinghere + arr[i], arr[i]);
        maxsofar = max(maxendinghere, maxsofar);
    }
    return maxsofar;
}

/*最接近t的子向量*/
float findclosesubarr(float arr[], int n, float t)
{
    float realarr[n];
    float *cumarr = realarr+1;
    cumarr[-1] = 0;
    for(int i=0 ; i<n ; i++)
        cumarr[i] = cumarr[i-1] + arr[i];

    qsort(cumarr, n, sizeof(float), compare);

    float diff[n];
    for(int i=0 ; i<n ; i++)
        diff[i] = cumarr[i] - t;
    float min = INT_MAX;
    for(int i=0 ; i<n-1 ; i++)
    {
        float abs_diff = fasb(diff[i+1]-diff[i]);
        if(abs_diff < min)
            min = abs_diff;
    }
    return min;
}
int main()
{
    float arr[5] = {-1,-2,-4,-2,-5};
    printf("%f\n",maxsum(arr, 5));
}