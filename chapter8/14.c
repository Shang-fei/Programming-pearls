float fasb(float x)
{
    return x>0 ? x : -x; 
}

int closestSubarraySum(int n, float arr[], int m){
    float realarr[n];
    float *cumarr = realarr + 1;
    cumarr[-1] = 0;
    for (int i = 0; i < n; i++) {
        cumarr[i] = cumarr[i-1] + arr[i];
    }

    int min_i = 0;
    float min = INT_MAX;
    for (int i = 0; i < n-m; i++) {
        float abs_diff = fasb(cumarr[i+m] - cumarr[i-1]);
        if (abs_diff < min){
            min= abs_diff;
            min_i = i;
        }
    }
    return min_i;
}