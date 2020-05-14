#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int a;
    cout << "Factorial de: ";
    cin >> a;
    cout << "Resultado: " << factorial(a) << endl;
    return 0;
}
