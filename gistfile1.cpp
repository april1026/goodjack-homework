#include <iostream> 
using namespace std; 

int main() { 
	int num; 
	cin >> num;
	int price[num];
	int total = 0;
	int listnum = 1;
	for (int i = 0; i < num; i++) {
		cin >> price[i];
		total += price[i];
		listnum *= 2;
	}
	
	int list[num][listnum];
	int change = 1;
	bool save = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < listnum; j++) {
			if (i == 0)
				list[i][j] = j % 2; 
			else if (j % change == 0){
				if (save == 0)
					save = 1;
				else if (save == 1)
					save = 0;
				list[i][j] = save;
			}else
				list[i][j] = save;
		}
		change *= 2;
		save = 1;
	}
	
	/*
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < listnum; j++) {
		cout << list[i][j];
		}
		cout << endl;
	}
	*/
	
 return 0; 
}
