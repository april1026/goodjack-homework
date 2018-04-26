#include <iostream> 
using namespace std; 

int main() { 
	int num; 
	cin >> num;
	int price[num];
	int listnum = 1;
	for (int i = 0; i < num; i++) {
		cin >> price[i];
		listnum *= 2;
	}
	
	//排列組合(總表)(2進位表) V 
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
	
	//找最小 
	int total[2];
	for (int i = 0; i < 2; i++)
		total[i] = 0;
	int biggest = 0; //0一定比較小 
	int way;
	int cash = 0;
	for (int j = 1; j < listnum; j++) {
		int i;
		for (i = 0; i < num; i++) {
			if (list[i][j] == 1)
				total[0] += price[i];
			else if (list[i][j] == 0)
				total[1] += price[i];
		}
		//cout << total[0] << endl;
		if (total[0] % 100 == 0)
			cash = 100 - (total[1] % 100);
		else if (total[1] % 100 == 0)
			cash = 100 - (total[0] % 100);
		else if (total[0] % 100 == 0 && total[1] % 100 == 0)
			cash = 0;
		else
			cash = 100 - (total[0] % 100) + 100 - (total[1] % 100);
		//cout << cash <<"c" << endl;
		if (cash > biggest){
			biggest = cash;
			way = i-1;
		}
		cash = 0;
		for (i = 0; i < 2; i++)
			total[i] = 0;
	}
	
	//cout
	for (int i = 0; i < num; i++){
		if (list[way][i] == 1)
			cout << "A買商品" << i+1 << endl;
		else if (list[way][i] == 0)
			cout << "B買商品" << i+1 << endl;			
	}
	cout << "可換現金" << biggest << "元"; 
	
	return 0; 
}
