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
    
    return 0;
}