#include "../src/shared_ptr.h"

void func(shared_ptr<int> p)
{
}

int main()
{
    // shared_ptr<int> p = new int(1024);
    shared_ptr<int> p(new int(1024));
    if (p)
    {
    }

    const shared_ptr<int> p2{new int{1024}};
    *p2;

    shared_ptr<const int> p3{new int{1024}};

    // explicit shared_ptr(T * ptr) 不能隐式转换
    func(new int{1024});
}