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