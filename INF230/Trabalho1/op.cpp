#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <tuple>
#include <utility>

void print_vector(const std::vector<int> &v);
int get_score(const std::vector<int> &path, const std::vector<int> &scores);
int get_time(const std::vector<int> &path, const std::vector<std::vector<int>> &matrix);
std::vector<int> next_permutation(std::vector<int> permutation);
void print_vector(const std::vector<int> &v);
std::vector<int> default_path(int n, int r);
std::vector<int> default_path(int r);
std::vector<int> next_rcombination(std::vector<int> combination, int n);

int main() {
    int pontos_de_interesse, tempo_limite, n;
    std::cin >> pontos_de_interesse;
    std::vector<int> scores(pontos_de_interesse - 2, 0);
    std::vector<std::vector<int>> matrix(pontos_de_interesse - 1);

    for (int i = 0; i < pontos_de_interesse - 1; i++) {
        matrix[i].resize(pontos_de_interesse - 1);
    }

    for (auto &i: scores) {
        std::cin >> i;
    }

    std::cin >> tempo_limite;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cin >> n;
            matrix[i][j] = n;
        }
    }

    std::vector<std::vector<int>> combination;

    for(int i = 2; i < n; i ++){
        std::vector<int> path = default_path(n - 1,i);
        combination.push_back(default_path(i));

        while(combination.back() != path){
            combination.push_back(next_rcombination(combination.back(), n - 1));
        }
    }

    std::vector<std::tuple<std::vector<int>, int>> permutation;

    for(auto &i:combination) {
        auto path = i;
        std::sort(path.begin(), path.end());
        // print_vector(path);
        permutation.push_back(std::make_pair(i, 0));

        std::reverse(path.begin(), path.end());

        while(std::get<0>(permutation.back()) != path){
            permutation.push_back(std::make_tuple(next_permutation(std::get<0>(permutation.back())), 0));
        }
    }

    permutation.erase(
            std::remove_if(permutation.begin(), permutation.end(),
                           [&pontos_de_interesse] (auto perm) { return std::get<0>(perm)[0] != 0 || std::get<0>(perm).back() != (pontos_de_interesse - 1); }),
            permutation.end()
    );

    for (auto &perm: permutation) {
        std::get<1>(perm) = get_time(std::get<0>(perm), matrix);
    }

    std::vector<int> best_path;
    int best_score = 0;
    int best_time = 0;

    for (auto &path: permutation) {
        auto [ caminho, distancia ] = path;
        auto score = get_score(caminho, scores);
        if (score > best_score && distancia <= tempo_limite) {
            best_path = caminho;
            best_score = score;
            best_time = distancia;
        }
    }

    std::cout << "O melhor caminho é o: ";
    print_vector(best_path);
    std::cout << "Com o Score " << best_score << " e o tempo " << best_time << std::endl;

    return 0;
}

int get_score(const std::vector<int> &path, const std::vector<int> &scores) {
    int score = 0;

    for (int i = 1; i < path.size() - 1; i++) {
        score += scores[path[i] - 1];
    }

    return score;
}

int get_time(const std::vector<int> &path, const std::vector<std::vector<int>> &matrix) {
    int tempo = 0;
    for (int i = 1; i < path.size(); i++) {
        tempo += matrix[path[i - 1]][path[i] - 1];
    }

    return tempo;
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

void print_vector(const std::vector<int> &v) {
    for(int i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> default_path(int n, int r) {
    std::vector<int> path(r);
    std::iota(std::begin(path), std::end(path), n - r + 1);

    return path;
}

std::vector<int> default_path(int r) {
    std::vector<int> path(r);
    std::iota(std::begin(path), std::end(path), 0);

    return path;
}

std::vector<int> next_rcombination(std::vector<int> combination, int n) {
    int i = combination.size();

    while (combination[i-1] == n - combination.size() + i) i--;

    combination[i-1] += 1;

    for (int j = i + 1; j <= combination.size(); j++) {
        combination[j-1] = combination[i-1] + j - i;
    }

    return combination;
}