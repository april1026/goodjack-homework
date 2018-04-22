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
	
	int list[num * (num-1) / 2][num];
	int change = 1;
	bool save = 0;
	for (int i = 0; i < (num * (num-1) / 2); i++) {
		for (int j = 1; j <= num; j++) {
			if (i == 0)
				list[j-1][i] = (j % 2); 
			else if (j % change == 0){
				if (save == 0)
					save = 1;
				else if (save == 1)
					save = 0;
				list[j-1][i] = save;
			}
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
