#include <iostream> 
#include <math.h>
using namespace std; 

int main() { 
	int number; 
	cin >> number;
	int price[number];
	int total = 0;
	for (int i = 0; i < number; i++) {
		cin >> price[i];
		total += price[i];
	}
	
	int list[number * (number-1)][number];
	int change = 2;
	int save = 0;
	for (int i = 0; i < (number * (number-1)); i++) {
		for (int j = 1; j <= number; j++) {
			if (j % (change*2) == 0)
				save = 0; 
			else if (j % change == 0)
				save = 1;
			list[j-1][i] = save;
		}
		change *= 2;
	}
	
	for (int i = 0; i < number * (number-1); i++) {
		for (int j = 0; j < number; j++) {
		cout << list[i][j];
		}
		cout << endl;
	}
	
	
 return 0; 
}
