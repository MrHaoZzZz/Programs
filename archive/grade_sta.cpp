#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<int>& grades) {
    int n{};
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp{};
        std::cin >> temp;
        grades.push_back(temp);
    }
}

int calc_sum(const std::vector<int>& grades) {
    int sum{0};
    for (int grade : grades) sum += grade;
    return sum;
}

void print(int sum, int max_score, int min_score, double median) {
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Max: " << max_score << '\n';
    std::cout << "Min: " << min_score << '\n';
    std::cout << "Median: " << median << '\n';
}

int main() {
    std::vector<int> grades;
    input(grades);
    std::sort(grades.begin(), grades.end());

    int sum = calc_sum(grades);
    int max_score = grades.back();
    int min_score = grades.front();
    double median = (grades.size() % 2 == 1)
        ? grades[grades.size() / 2]
        : (grades[grades.size() / 2 - 1] + grades[grades.size() / 2]) / 2.0;

    print(sum, max_score, min_score, median);
    return 0;
}