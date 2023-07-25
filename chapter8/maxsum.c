#include <stdio.h>


double maxsum(int n, double x[n])
{
    int i, j, k;
    double sum, maxsofar=0;
    for(i=0 ; i<n ; i++)
    {
        for(j=i ; j<n ; j++)
        {
            sum = 0;
            for(k=i ; k<j ; k++)
                sum += x[k];
            if(sum > maxsofar)
                maxsofar = sum;
        }
    }
    return maxsofar;
}
double maxsum2(int n, double x[n])
{
    int i, j;
    double sum, maxsofar=0;
    for(i=0 ; i<n ;i++)
    {
        sum=0; 
        for(j=i ; j<n ; j++)
        {
            sum += x[j];
            if(sum > maxsofar)
                maxsofar = sum;
        }
    }
    return maxsofar;
}
double maxsum2b(int n, double x[n])
{
    int i, j;
    double *cumarr, sum, maxsofar=0;
    double cumvec[n+1];
    cumarr = cumvec+1;
    for(i=0 ; i<n ; i++)
        cumarr[i] = cumarr[i-1]+x[i];
    for(i=0 ; i<n ; i++)
    {
        for(j=i ; j<n ; j++)
        {
            sum = cumarr[j] - cumarr[i-1];
            if(maxsofar < sum)
                maxsofar = sum;
        }
    }
    return maxsofar;
}
double maxsum(int n, double x[n])
{
    
    int i, j;
    double sum=0, lmax=0, rmax=0; 
    for(i=0 ; i<n/2 ; i++)
    {
        sum += x[i];
        if(sum>lmax)
           lmax = sum; 
    }
    sum=0;
    for(i=0 ; i<n/2 ; i++)
    {
        sum += x[i];
        if(sum>rmax)
           rmax = sum; 
    }
    return max()
}
