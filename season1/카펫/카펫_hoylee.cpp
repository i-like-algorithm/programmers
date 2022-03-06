#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer = {0, 0};

    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i == 0 && (yellow / i + 2) * 2  + 2 * i == brown)
            return vector<int>{(yellow / i + 2), (i + 2)};
    }
    return vector<int>{0};
}
