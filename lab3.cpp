#include <iostream>

using namespace std;

int main()
{
    srand(time(0));
    int line;
    int column;
    int n = 4;
    long long array[n][n];
    long long array2[n-1][n-1];
    int i = 0;
    
    cout<<"Массив случайных чисел " << n << " на " << n << " :"<<endl;
    
    while (i < n)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            array[i][j] = rand() % 9 + 1;
            cout<<array[i][j]<<" ";
        }
        cout << endl;
	asm(
		"movl %[i], %%eax\n\t"	/*что было по адресу iго элемента в eax*/
		"incl %%eax\n\t" /*инкрементирую eax*/
		"movl %%eax, %[i]\n\t" /*записываю в индекс содержание eax*/
		
		:[i]"=m"(i)			
		:		/*для переноса с ассемблера в код на с++*/			
		:"%eax");			
    }
    
    cout << endl ;
    cout << " Введите удаляемую строку: ";
    cin >> line;
    cout << " Введите удаляемый столбец: ";
    cin >> column;
    
    line--;
    column--;
    i = 0;

    cout << endl ;
    cout<<" Измененный массив:"<<endl;
    
    while (i < n)
    {
        if (i != line)
        {
            cout << "\t";
            for (int j = 0; j < n; j++)
            {
                if (j != column)
                {
                    array2[i][j] = array[i][j];
                    cout<<array2[i][j]<<" ";
                }
                else { continue; }
            }
            cout<<endl;
	    asm(
		"movl %[i], %%eax\n\t"		 
		"incl %%eax\n\t"
		"movl %%eax, %[i]\n\t"
		
		:[i]"=m"(i)			
		:				
		:"%eax");			
        }
        else { i++; }
    }
}
