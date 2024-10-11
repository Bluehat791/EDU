#include <iostream> 
#include <vector>

using namespace std;
template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

    // Вспомогательная функция, чтобы сделать массив прямоугольным
    void MakeRectangle() {
        // Вычисляем максимальную длину строки
        size_t maxSize = 0;
        for (const auto& row : data) {
            if (row.size() > maxSize) {
                maxSize = row.size();
            }
        }

        for (auto& row : data) {  // итерация без const позволяет изменять row
            row.resize(maxSize);  // увеличиваем длины строк при необходимости
        }
    }
public:

    Matrix(const std::vector<std::vector<T>>& d): data(d) {  // инициализируем вектор переданным значением
        MakeRectangle();  // соблюдаем инвариант
    }

    size_t GetRows() const {
        return data.size();
    }

    size_t GetColumns() const {
        // У пустого вектора data обращаться к нулевому элементу нельзя
        if (data.empty()) {
            return 0;
        }
        return data[0].size();
    }
};

int main() {

    Matrix<int> m({
        {1, 2, 3},
        {4, 5, 6},
    });

    std::cout << m.GetRows() << "\n";  // 2
    std::cout << m.GetColumns() << "\n";  // 3
}