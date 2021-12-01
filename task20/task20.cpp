// Проверить, является ли последовательность между первым совершенным числом в массиве и последним арифмитической прогрессией
#include <iostream>
using namespace std;
void fill(int* a, int n);
void find(int* a, int n, int& firsti, int& lasti);
bool chek_ar(int* a, int n, int firsti, int lasti);
bool chek_sovv(int n);
int main()
{
	int n, firsti, lasti;
	printf("vvedite razmernost'\n");
	scanf_s("%d", &n);
	int* A = new int[n];
	printf("zapolnite massiv\n");
	fill(A, n);
	find(A, n, firsti, lasti);
	//printf("%d\n", firsti);
	//printf("%d\n", lasti);
	if (chek_ar(A, n, firsti, lasti))
		printf("yavlyaetsya");
	else
		printf("ne yavlyaetsya");
}

//заполнение элементов
void fill(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		
			scanf_s("%d", &a[i]);
		
	}
}
//поиск совершенного числа в матрице
void find(int* a, int n, int& firsti,int& lasti)
{
	firsti = INT_MAX;
	lasti = INT_MIN;
	for (int i = 0; i < n; i++)
	{		
			if (chek_sovv(a[i]))
			{
				firsti = i;				
				break;
			}				
	}
	for (int i = n - 1; i >= 0; i--)
	{	
			if (chek_sovv(a[i]))
			{
				lasti = i;				
				break;
			}	
	}
}
//проверка на совершенство
bool chek_sovv(int n)
{
	int sd = 1;
	int n1 = n / 2;
	for (int i = 2; i <= n1; i++)
	{
		if (n % i == 0)

			sd = sd + i;
	}
	if (sd == n && n != 1)
		return true;
	else
		return false;
}
//проверка на арифметическую прогрессию
bool chek_ar(int* a, int n,int firsti, int lasti)
{
	int raz;
	raz = a[firsti+2] - a[firsti+1];
	bool fl = true;
	for (int i = firsti +3; i < lasti; i++)
	{
		if (a[i] - a[i - 1] != raz)
		{
			fl = false;
		}
		//printf("%d", a[i]);
	}
	return fl;
}