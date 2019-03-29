int fib(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fib(n-1) + fib(n-2);
}

long long itfib(long long n){
    long long i, tab[n];
    tab[0]=1;
    tab[1]=1;
    for(i=2; i<n; i++)
        tab[i]=tab[i-1]+tab[i-2];
    return tab[n-1];
}