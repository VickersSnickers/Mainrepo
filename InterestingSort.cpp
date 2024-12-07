#include <iostream>
#include <algorithm>
using namespace std;
int main()
    // Генерирует массив размером size с элементами меньше maxelem
{   int size = 1000, maxelem = 1000000000, a[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        a[i] = 1 + rand() % maxelem;

    // Алгоритм интересного массива
    sort(a,  a+size);
    int ans[size];
    int ind1 = 0, ind2 = size - 1;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 1)
            ans[i] = a[ind2--];
        else
            ans[i] = a[ind1++];
    }
    // Вывод интересного массива
    for (int i = 0; i < size; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}