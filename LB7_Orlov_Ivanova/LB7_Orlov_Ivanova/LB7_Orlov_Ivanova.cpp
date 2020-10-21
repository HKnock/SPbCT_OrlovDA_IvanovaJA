#include <iostream>
#include <queue>
using namespace std;

int n;

class cord {
    double x = 0, y = 0;
    queue <double> q;
public:
    void add(int n) {
        for (int i = 0; i < n; i++) {
            cout << "Введите х: ";
            cin >> x;
            try {
                if (x < -180 || x > 180)
                    throw "Выходит за границы";
            }
            catch (const char* exeption)
            {
                cerr << "error: " << exeption << '\n';
                i--;
                continue;
            }
            cout << "Введите y: ";
            cin >> y;
            try {
                if (y < -90 || y > 90)
                    throw "Выходит за границы";
            }
            catch (const char* exeption)
            {
                cerr << "error: " << exeption << '\n';
                i--;
                continue;
            }
            q.push(x);
            q.push(y);
        }
    }
    void vivod(int n) {
        for (int i = 0; i < n; i++) {
            cout << q.front() << ", ";
            q.pop();
            cout << q.front() << endl;
            q.pop();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    cord coordination;
    cout << "Сколько пар координат вы хотите ввести? ";
    cin >> n;
    coordination.add(n);
    coordination.vivod(n);
    return 0;
}