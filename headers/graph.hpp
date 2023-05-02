#ifndef GRAPH
#define GRAPH
#include "human.hpp"
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <set>
#include <map>

struct Pair
{
    const Human* lhs;
    const Human* rhs;
};

bool operator == (const Pair& a, const Pair& b) noexcept;

namespace std {
    template<>
    struct hash<Pair>
    {
        std::size_t operator()(Pair const& pair) const noexcept
        {
            const std::hash<const Human*> hasher;
            return hasher(pair.lhs) ^ hasher(pair.rhs);
        }
    };
}

class Graph
{
private:

    std::unordered_map<Human, std::set<const Human*>> m_humans;

public:

    Graph();
    ~Graph();
    Graph(const Graph& graph) = delete;
    //void show_Humans() noexcept;
    void add_human(const Human& human);
    void add_edge(const Human& lhs, const Human& rhs);
    //void del_Human(Human *human) noexcept;
    std::unordered_set<Pair> get_pairs() const;
    std::pair<std::unique_ptr<int[]>, std::map<const Human*, std::size_t>> find_paths() const;
    void print_n_handshakes(std::size_t count = 3) const;
};
#endif