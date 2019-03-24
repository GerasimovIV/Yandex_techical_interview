#include <iostream> 
#include <string> 
#include <time.h> 
#include <chrono> 
#include <cstdio> 
#include <fstream> 
using namespace std; 

bool check(string& mas, int n) 
{ 
	int couter = 0; 
	for (int i = 0; i < 2 * n; i++) 
	{ 
		if (mas[i] == '(') 
		{ 
			couter += 1; 
		} 
		else 
		{ 
			if (mas[i] == ')') 
			{ 
				couter -= 1; 
			} 
		} 
		if (couter < 0) 
		{ 
			return false; 
		} 
	} 
	if (couter == 0) 
	{ 
		return true; 
	} 
	else 
	{ 
		return false; 
	} 
} 
void generation(int& n, int skobki_open, int skobki_close, string mas, ofstream& f) 
{ 
	if (skobki_open + skobki_close == 2 * n) 
	{ 
		if (check(mas, n) == true) 
		{ 
			f << mas << endl; 
		} 
		return; 
	} 
	if (skobki_open < n) 
	{ 
		generation(n, skobki_open + 1 , skobki_close, mas + "(", f); 
	} 
	if (skobki_close < n) 
	{ 
		generation(n, skobki_open, skobki_close + 1, mas + ")", f); 
	} 

	return; 
} 

int main() 
{ 
int n; 
ofstream f;
ifstream r; 
f.open("output.txt"); 
r.open("input.txt"); 
r >> n;

string mas; 
mas.reserve(2 * n); 
auto begin = std::chrono::steady_clock::now(); 
generation(n, 0, 0, mas, f); 
//auto end = std::chrono::steady_clock::now(); 
//auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin); 
//std::cout << "The time: " << elapsed_ms.count() << " ms\n"; 
f.close();
r.close(); 
//system("pause"); 
return 0; 
}