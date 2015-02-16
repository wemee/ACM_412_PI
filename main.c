#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b);
void swap(int *a, int *b);

int main(int argc, const char * argv[]) {
    int n, i, j, coprime_count;
    int *ary;
    while( scanf("%d", &n)!=EOF ) {
        if (n==0)
            break;
        ary = malloc(n * sizeof(int));
        for (i=0; i<n; i++)
            scanf("%d", ary+i);
        
        coprime_count = 0;
        for (i=0; i<n-1; i++)
            for (j=i+1; j<n; j++)
                if (gcd(ary[i], ary[j])==1)
                    coprime_count++;
        
        if (coprime_count == 0)
            printf("No estimate for this data set.\n");
        else
            printf("%f\n", sqrt( 6*(n*(n-1)/2) / (float)coprime_count) );
        
        free(ary);
    }
    return 0;
}

int gcd(int a, int b){
    if (b>a)
        swap(&a, &b);
    if (a%b != 0)
        return gcd(b, a%b);
    return b;
}

void swap(int *a, int *b){
    int t=*a;
    *a = *b;
    *b = t;
}
