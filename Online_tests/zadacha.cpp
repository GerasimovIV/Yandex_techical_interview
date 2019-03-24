#include <iostream>
using namespace std;
#include <string>
bool check(string mas, int n)
{
	int couter = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (mas[i] == '(')
        {
            couter += 1;
        }
        if (mas[i] == ')')
        {
            couter -= 1;
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

inline void print_skobki(int n, string mas)
{
	for (int i = 0; i < 2 * n; i ++)
	{
		cout << mas[i];
	}
	cout << endl;
}

void generation(int n, int skobki_open, int skobki_close, string mas)
{
	if (skobki_open + skobki_close == 2 * n)
	{
		if (check(mas, n) == true)
		{
            cout << mas << endl;
		}
		return;
	}
	if (skobki_open < n)
	{
		mas += "(";
        generation(n, skobki_open + 1, skobki_close, mas);
	}
    if (skobki_close < n)
    {
    	mas += ")";
        generation(n, skobki_open, skobki_close  + 1, mas);
    }
}

int main()
{

	int n;
	cin >> n;
	string mas;
	mas.reserve(2 * n);
	generation(n, 0, 0, mas);
	return 0;
}