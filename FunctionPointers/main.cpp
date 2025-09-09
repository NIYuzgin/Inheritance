#include<iostream>
using namespace std;

const char* Hello() {
	return "Hello";
}

int Add(int a, int b) {
	return a + b;
}
int Subtract(int a, int b) {
	return a - b;
}
double Div(int a, int b) {
	return(double)a / b;
}
template<typename T>
T Calculate(int a, int b, T(*operation)(int, int)) {
	return(*operation)(a, b);

}

void main() {

	setlocale(LC_ALL, "");
	
	cout << Hello << endl;
	const char* (*pHello)() = Hello;
	cout << (*pHello)() << endl;

	/*
	int(*pAdd)(int, int) = Add;
	int(*pSubtract)(int, int) = Subtract;

	cout << (*pAdd)(2, 3) << endl;
	cout << (*pSubtract)(8, 3) << endl;
*/

	cout << Calculate(8, 3, Add) << endl;
	cout << Calculate(8, 3, Subtract) << endl;
	cout << Calculate(8, 3, Div) << endl;

}

/*
type function(parameters) {
ЕЕЕЕ;
group-of-statements;
ЕЕЕЕ;
}
type (*name) (parameters) = function;

type - тип возвращаемого значени€;
function Ц им€ функции;
name Ц им€ указател€ на функцию;
parameters Ц список принимаемых параметров;

!!! “ип возвращаемого значени€ и список принимаемых параметров 
у самой функции и указател€ на нее должны быть идентичными!!!



*/