#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    int ones, count;
    while( scanf( "%d", &n ) != EOF ){
        ones = 1%n;
        count = 1;
        while( ones ){
            ones *= 10;
            ones++;
            ones %= n;
            count++;
        }

        printf( "%d\n", count );
    }

    return 0;
}