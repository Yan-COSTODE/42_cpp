#include "Base.hpp"

int main()
{
    Base* bases[4];
    bases[0] = new A();
    bases[1] = new B();
    bases[2] = new C();
    bases[3] = Base::generate();

    for (int i = 0; i < 4; ++i) {
        Base::identify(bases[i]);
        Base::identify(*(bases[i]));
        delete bases[i];
    }
}