#include <vector>

using namespace std;

int check[100][100];

void recursive(vector<vector<int> > &picture, int m, int n, int i, int j, int picture_number,
               int &size) {
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return ;
    }
    if (check[i][j] == 1 || picture[i][j] != picture_number) {
        return ;
    }
    check[i][j] = 1;
    size++;
    recursive(picture, m, n, i + 1, j, picture_number, size);
    recursive(picture, m, n, i - 1, j, picture_number, size);
    recursive(picture, m, n, i, j + 1, picture_number, size);
    recursive(picture, m, n, i, j - 1, picture_number, size);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int size;
    vector<int> answer(2);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            check[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            size = 0;
            if (picture[i][j] != 0 && check[i][j] == 0) {
                recursive(picture, m, n, i, j, picture[i][j], size);
                number_of_area++;
                if (max_size_of_one_area < size)
                    max_size_of_one_area = size;
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}