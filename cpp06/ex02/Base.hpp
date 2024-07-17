#pragma once

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base {
    public:
        virtual ~Base();
        Base();
        Base(const Base& _other);
        Base& operator=(const Base& _other);
        static Base* generate();
        static void identify(Base *_p);
        static void identify(Base& _p);
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {
    
};

#endif
