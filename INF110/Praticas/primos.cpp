#include <iostream>
#include <cmath>
using namespace std;
bool eh_primo(int n){
	if(n==1)
		return false;
	else{ for(int i=2;i<=sqrt(n);i++){
				if(n%i==0) 
				return false;
			}
		return true;
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << "Primos entre " << a << " e " << b << ":";
	for(int i = a; i <= b; i++)
		if (eh_primo(i)) //Se for primo
			cout << " " << i; //imprime o valor
	cout << endl;
	return 0;
}
