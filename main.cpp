#include "headers/human.hpp"
#include "headers/graph.hpp"

int main() {

    Human oleg("Oleg");
    Human nikita("Nikita");
    Human nastya("Nastya");
    Human vanya("Vanya");
    Human jenya("Jenya");

    Graph human_friends;
    human_friends.add_human(oleg);
    human_friends.add_human(nikita);
    human_friends.add_human(nastya);
    human_friends.add_human(vanya);
    human_friends.add_human(jenya);

    human_friends.add_edge(oleg, nikita);
    human_friends.add_edge(nikita, nastya);
    human_friends.add_edge(nastya, vanya);
    human_friends.add_edge(vanya, jenya);

    human_friends.print_n_handshakes();
    
    return 0;
}