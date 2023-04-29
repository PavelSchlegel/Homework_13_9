#ifndef HUMAN
#define HUMAN

#include <string>

class Human
{
private:
    std::string m_name;

public:
    Human(const std::string& name);
    const std::string& name() const noexcept;

    friend bool operator == (const Human& lhs, const Human& rhs) noexcept
    {
        return lhs.m_name == rhs.m_name;
    }
};

namespace std {
    template<>
    struct hash<Human>
    {
        std::size_t operator()(Human const& human) const noexcept
        {
            return std::hash<std::string>{}(human.name());
        }
    };
}

#endif