#include <stdio.h>

long fibo(long ans, long prev, long count, long n){
	if(n==1||n==0){
		return n;
	}
	else{
		if(count<n){
			return fibo(prev, prev+ans, count+1, n);
		}
		return ans;
	}
}

long fib(long n){
	return fibo(0,1,0,n);
}

int main(){
	printf("%ld",fib(50));
}




// 0 1 1 2 3
