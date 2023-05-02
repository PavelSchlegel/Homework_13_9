#include "headers/graph.hpp"
#include <iostream>

Graph::Graph() {

}

Graph::~Graph() {

}

bool operator == (const Pair& a, const Pair& b) noexcept
{
    if (a.lhs == b.lhs) {
        if (a.rhs == b.rhs) {
            return true;
        }
    }

    if (a.lhs == b.rhs) {
        if (a.rhs == b.lhs) {
            return true;
        }
    }
    return false;
}

void Graph::add_human(const Human& human)
{
    m_humans[human] = {};
}

void Graph::add_edge(const Human& lhs, const Human& rhs)
{
    if (auto it = m_humans.find(rhs); it != m_humans.end()) {
        m_humans[lhs].insert(&(it->first));
    }
    if (auto it = m_humans.find(lhs); it != m_humans.end()) {
        m_humans[rhs].insert(&(it->first));
    }
}

std::unordered_set<Pair> Graph::get_pairs() const
{
    std::unordered_set<Pair> pairs;
    for (auto it = m_humans.begin(); it != m_humans.cend(); ++it) {
        for (auto jt = std::next(m_humans.begin()); jt != m_humans.end(); ++jt) {
            pairs.insert(Pair{&it->first, &jt->first});
        }
    }
    return pairs;
}

std::set<std::pair<int, int>> get_pairs(const std::vector<int>& array)
{
    std::set<std::pair<int, int>> result;
    for (std::size_t i = 0; i < array.size(); ++i) {
        for (std::size_t j = i + 1; j < array.size(); ++j) {
            result.insert(std::make_pair(array[i], array[j]));
        }
    }

    return result;
}

std::pair<std::unique_ptr<int[]>, std::map<const Human*, std::size_t>> Graph::find_paths() const
{
    constexpr int VERYBIGINT = 1000000;
    std::map<const Human*, std::size_t> indexes;
    std::size_t index = 0;
    for (const auto& [human, _]: m_humans) {
        indexes[&human] = index;
        index += 1;
    }
    std::unique_ptr<int[]> weights(new int[m_humans.size() * m_humans.size()]);
    // инициализаци матрицы
    std::fill_n(weights.get(), m_humans.size() * m_humans.size(), VERYBIGINT);
    std::size_t i = 0;
    for (const auto& [human, edges]: m_humans) {
        for (const auto& edge: edges) {
            auto j = indexes[edge];
            if (j == i) {
                weights[i * m_humans.size() + j] = 0;
            } else {
                weights[i * m_humans.size() + j] = 1;
            }
        }
        weights[i * m_humans.size() + i] = 0;
        i += 1;
    }
    for (const auto& [human, _]: m_humans) {
        auto ck = indexes[&human];
        for (const auto& [human, _]: m_humans) {
            auto ci = indexes[&human];
            if (ck == ci) {
                continue;
            }
            for (const auto& [human, _]: m_humans) {
                auto cj = indexes[&human];
                if (cj == ck) {
                    continue;
                }
                if (weights[ci * m_humans.size() + ck] + weights[ck * m_humans.size() + cj] < weights[ci * m_humans.size() + cj]) {
                    // пересчет мматрицы путей
                    weights[ci * m_humans.size() + cj] = weights[ci * m_humans.size() + ck] + weights[ck * m_humans.size() + cj];
                }
            }
        }
    }
    return std::make_pair(std::move(weights), std::move(indexes));
}

void Graph::print_n_handshakes(std::size_t count) const
{
    auto [weights, indexes] = find_paths();
    for (const auto& [hi, i]: indexes) {
        for (const auto& [hj, j]: indexes) {
            const auto weight = weights[i * m_humans.size() + j];
            if (weight == count) {
                std::cout << hi->name() << " -> " << hj->name() << std::endl;
            }
        }
    }
}

