#include <iostream>
#define ARR_MAX 102
using namespace std;

int main() {
    int mines[ARR_MAX][ARR_MAX] = {0};
    int ans[ARR_MAX][ARR_MAX] = {0};

    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) {
            cin >> mines[i][j];
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int temp = 0;
            for (int k = 0; k < 8; ++k){
                int adt = mines[i + dy[k]][j + dx[k]];
                temp += adt;
            }
            ans[i][j] = temp;
        }
    }
    cout << endl;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) {
            if (mines[i][j] == 1){
                cout << "* ";
            } else {
            cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}