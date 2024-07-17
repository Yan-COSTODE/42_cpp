#include "Base.hpp"

Base::~Base()
{
}

Base::Base()
{
}

Base::Base(const Base& _other)
{
    *this = _other;
}

Base& Base::operator=(const Base& _other)
{
    (void)_other;
    return *this;
}

Base *Base::generate()
{
    std::srand(std::time(0));

    int _rand = std::rand() % 3;

    switch (_rand) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void Base::identify(Base *_p)
{
    if (dynamic_cast<A *>(_p))
        std::cout << "\x1b[1;37mPointer: Base is of type A\x1b[0m" << std::endl;
    else if (dynamic_cast<B *>(_p))
        std::cout << "\x1b[1;37mPointer: Base is of type B\x1b[0m" << std::endl;
    else if (dynamic_cast<C *>(_p))
        std::cout << "\x1b[1;37mPointer: Base is of type C\x1b[0m" << std::endl;
    else
        std::cout << "\x1b[1;37mPointer: Base is of type unknown\x1b[0m" << std::endl;
}

void Base::identify(Base &_p)
{
    try {
        dynamic_cast<A&>(_p);
        std::cout << "\x1b[1;37mReference: Base is of type A\x1b[0m" << std::endl;
        return;
    }
    catch (const std::exception& _e) {
    }

    try {
        dynamic_cast<B&>(_p);
        std::cout << "\x1b[1;37mReference: Base is of type B\x1b[0m" << std::endl;
        return;
    }
    catch (const std::exception& _e) {
    }

    try {
        dynamic_cast<C&>(_p);
        std::cout << "\x1b[1;37mReference: Base is of type C\x1b[0m" << std::endl;
        return;
    }
    catch (const std::exception& _e) {
    }

    std::cout << "\x1b[1;37mReference: Base is of type unknown\x1b[0m" << std::endl;
}
