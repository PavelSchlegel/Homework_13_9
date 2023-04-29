#include "headers/graph.hpp"

Graph::Graph() {

}

Graph::~Graph() {

}

bool operator == (const Edge& a, const Edge& b) noexcept
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

/*
void Graph::show_Humans() noexcept {
    for (auto rec : m_humans) {
        std::cout << rec->get_my_name() << std::endl;
    }
}
*/

void Graph::add_human(Human human)
{
    m_humans.insert(std::move(human));
}

void Graph::add_edge(const Human& lhs, const Human& rhs)
{
    if (auto search = m_humans.find(lhs); search != m_humans.end()) {
        if (auto rec = m_humans.find(rhs); rec != m_humans.end()) {
            Edge edge{&(*search), &(*rec)};
            m_edges.insert(edge);
        }
    }
}
/*
void Graph::del_Human(Human human) noexcept {
    for (auto it = m_humans.begin(); it != m_humans.end(); ++it) {
        if (*it == human) {
            m_humans.erase(it);
        }
    }
}
*/

void Graph::pair_Friends() noexcept {
   
}