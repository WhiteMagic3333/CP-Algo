    #include<stdio.h>
    int T,n;
    int main(){
    	scanf("%d",&T);
    	while(T--){
    		scanf("%d",&n);
    		int a=0,b=0,mul=1;
    		for(int i=1;i<=10&&n;i++){
    			if(i&1)
    				a+=n%10*mul;
    			else b+=n%10*mul,mul*=10;
    			n/=10;
    		}
    		printf("%d\n",(a+1)*(b+1)-2);
    	}
    	return 0;
    }