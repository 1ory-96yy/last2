#include <iostream>
#include <vector>
#include <algorithm>

class Container {
private:
    std::vector<int> data;

public:
    Container(const std::vector<int>& initial_data) : data(initial_data) {}

    int find_min() const {
        return *std::min_element(data.begin(), data.end());
    }

    int find_max() const {
        return *std::max_element(data.begin(), data.end());
    }

    void sort_descending() {
        std::sort(data.begin(), data.end(), std::greater<int>());
    }

    void sort_ascending() {
        std::sort(data.begin(), data.end());
    }

    void increase_by(int increment) {
        std::transform(data.begin(), data.end(), data.begin(),
            [increment](int x) { return x + increment; });
    }

    void decrease_by(int decrement) {
        std::transform(data.begin(), data.end(), data.begin(),
            [decrement](int x) { return x - decrement; });
    }

    void remove_value(int value) {
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
    }

    void print() const {
        for (int num : data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> initial_data = { 5, 2, 8, 1, 7, 3, 6 };
    Container container(initial_data);

    int min_val = container.find_min();
    std::cout << "Min value: " << min_val << std::endl;

    int max_val = container.find_max();
    std::cout << "Max value: " << max_val << std::endl;

    container.sort_ascending();
    std::cout << "Sorted ascending: ";
    container.print();

    container.sort_descending();
    std::cout << "Sorted descending: ";
    container.print();

    container.increase_by(10);
    std::cout << "Increased by 10: ";
    container.print();

    container.decrease_by(5);
    std::cout << "Decreased by 5: ";
    container.print();

    container.remove_value(7);
    std::cout << "Removed value 7: ";
    container.print();

    return 0;
}
