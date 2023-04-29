#ifndef GRAPH
#define GRAPH
#include "human.hpp"
#include <unordered_set>

struct Edge
{
    const Human* lhs;
    const Human* rhs;
};

bool operator == (const Edge& a, const Edge& b) noexcept;

namespace std {
    template<>
    struct hash<Edge>
    {
        std::size_t operator()(Edge const& edge) const noexcept
        {
            const std::hash<const Human*> hasher;
            return hasher(edge.lhs) ^ hasher(edge.rhs);
        }
    };
}

class Graph
{
private:

    std::unordered_set<Human> m_humans;
    std::unordered_set<Edge>  m_edges;

public:

    Graph();
    ~Graph();
    Graph(const Graph& graph) = delete;
    //void show_Humans() noexcept;
    void add_human(Human human);
    void add_edge(const Human& lhs, const Human& rhs);
    //void del_Human(Human *human) noexcept;
    void pair_Friends() noexcept;
};
#endif