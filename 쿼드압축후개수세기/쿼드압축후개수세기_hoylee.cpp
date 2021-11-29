#include <string>
#include <vector>

using namespace std;
vector<int> ns(2,0);
void check(vector<vector<int>> *arr, int x, int y, int size)
{
    int tmp = (*arr)[x][y];
    bool flag = true;
    for (int i = x; i < x + size && flag; i++)
    {
        for (int j = y; j < y + size && flag; j++)
        {
            if ((*arr)[i][j] != tmp)
                flag = false;
        }
    }
    if (flag == true)
        ns[tmp]++;
    else
    {
        size = size / 2;
        check(arr, x, y, size);
        check(arr, x, y+size, size);
        check(arr, x+size, y, size);
        check(arr, x+size, y+size, size);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    check(&arr, 0,0,arr.size());
    return ns;
}
