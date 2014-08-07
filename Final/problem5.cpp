//5. Consider the following function and main program driver:

void f(int n){
    int a=0;
    int b=1;
    while (a < n){
        cout<<a<<endl;
        a=b;
        b=a+b;
    }
};

int main(){
    for(int i=1; i<50;i++){
        cout<<"i= "<<i<<endl;
        f(i);
        cout<<endl;
    }
    return 0;
}

//Write a recursive function to do the same thing
int fib(int n){
    if(n==1||n==2) return 1;
    else return fib(n-1) + fib(n-2);
}
