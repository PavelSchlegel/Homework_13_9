#include "headers/human.hpp"

Human::Human(const std::string& name)
: m_name(name)
{
}

const std::string& Human::name() const noexcept {
    return m_name;
}
