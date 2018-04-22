#include <iostream> 
#include <math.h>
using namespace std; 

int main() { 
	int num; 
	cin >> num;
	int price[num];
	int total = 0;
	for (int i = 0; i < num; i++) {
		cin >> price[i];
		total += price[i];
	}
	
	int list[num * (num-1)][num];
	int change = 2;
	int save = 0;
	for (int i = 0; i < (num * (num-1)); i++) {
		for (int j = 1; j <= num; j++) {
			if (j % (change*2) == 0)
				save = 0; 
			else if (j % change == 0)
				save = 1;
			list[j-1][i] = save;
		}
		change *= 2;
	}
	
	for (int i = 0; i < num * (num-1); i++) {
		for (int j = 0; j < num; j++) {
		cout << list[i][j];
		}
		cout << endl;
	}
	
	
 return 0; 
}
