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

    Matrix(size_t rows, size_t columns) {
        data.resize(rows);
        for (auto& row : data) {
            row.resize(columns);
        }
    }

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

    const std::vector<T>& operator [] (size_t i) const {
        return data[i];
    }

    std::vector<T>& operator [] (size_t i) {  // перегрузка по константности
        return data[i];
    }

    // Определим для краткости псевдоним для типа
    using const_iterator = typename std::vector<std::vector<T>>::const_iterator;

    // Используем этот псевдоним в объявлении функций
    const_iterator begin() const {
        return data.cbegin();
    }

    const_iterator end() const {
        return data.cend();
    }
    
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix) {
    const size_t rows = matrix.GetRows();
    const size_t columns = matrix.GetColumns();
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            if (j > 0) {
                out << "\t";
            }
            out << matrix[i][j];
        }
        out << "\n";
    }
    return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, Matrix<T>& matrix) {
    const size_t rows = matrix.GetRows();
    const size_t columns = matrix.GetColumns();
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            in >> matrix(i, j);
        }
    }
    return in;
}

int main() {

    Matrix<double> m(3, 4);  // создаём нулевую матрицу из 3 строк и 4 столбцов
    std::cin >> m; // заполняем построчно её 12 элементов из потока ввода

}