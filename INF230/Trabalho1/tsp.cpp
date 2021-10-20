#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

std::vector<std::vector<int>> read_matrix();
std::vector<int> default_path(int n);
std::vector<int> next_permutation(std::vector<int> permutation);
void print_vector(const std::vector<int> &v);
int get_score(const std::vector<int> &path, const std::vector<std::vector<int>> &matrix);

int main(int argc, char *argv[]) {
    int inicial = -1;
    if (argc > 1) {
        inicial = atoi(argv[1]);
    }
    auto matrix = read_matrix();
    auto path = default_path(matrix.size());
    std::reverse(path.begin(), path.end());
    std::vector<std::vector<int>> permutations;
    permutations.push_back(default_path(matrix.size()));

    while (permutations.back() != path) {
        permutations.push_back(next_permutation(permutations.back()));
        if (inicial >= 0) {
            if (permutations.back()[0] > inicial) {
                permutations.pop_back();
                break;
            }
        }
    }

    for (int i = 0; i < permutations.size(); i++) {
        permutations[i].push_back(permutations[i][0]);
    }

    std::vector<int> best_path = permutations[0];
    int best_score = get_score(best_path, matrix);

    for (auto &i: permutations) {
        int score = get_score(i, matrix);
        if (score < best_score) {
            best_path = i;
            best_score = score;
        }
    }

    std::cout << "Rota:\n";
    print_vector(best_path);
    std::cout << "Distância: " << best_score << std::endl;

    return 0;
}

int get_score(const std::vector<int> &path, const std::vector<std::vector<int>> &matrix) {
    int score = 0;
    for (int i = 1; i < path.size(); i++) {
        score += matrix[path[i]][path[i - 1]];
    }

    return score;
}

void print_vector(const std::vector<int> &v) {
    for(int i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> default_path(int n) {
    std::vector<int> path(n);
    std::iota(std::begin(path), std::end(path), 0);

    return path;
}

std::vector<int> next_permutation(std::vector<int> permutation) {
    int j = permutation.size() - 2;
    while (permutation[j] > permutation[j + 1]) j--;
    int k = permutation.size() - 1;
    while (permutation[j] > permutation[k]) k--;
    std::swap(permutation[j], permutation[k]);
    int r = permutation.size() - 1;
    int s = j + 1;
    while (r > s) {
        std::swap(permutation[r], permutation[s]);
        r--; s++;
    }

    return permutation;
}

std::vector<std::vector<int>> read_matrix() {
    int n, aux;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
    }
    std::string line;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> aux;
            matrix[i][j] = aux;
        }
    }

    return matrix;
}