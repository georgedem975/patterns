#include <iostream>

class IProduction
{
    public:
        virtual void release() = 0;
};

class Car : public IProduction
{
    public:
        void release() override;
};

class Truck : public IProduction
{
    public:
        void release() override;
};

class IWorkShop
{
    public:
        virtual IProduction* create() = 0;
};

class CarWorkShop : public IWorkShop
{
    public:
        IProduction* create() override;
};

class TruckWorkShop : public IWorkShop
{
    public:
        IProduction* create() override;
};

int main()
{
    IWorkShop* creator = new CarWorkShop();

    IProduction* car = creator->create();

    creator = new TruckWorkShop();

    IProduction* truck = creator->create();

    car->release();
    truck->release();

    return 0;
}

void Car::release()
{
    std::cout << "car\n";
}

void Truck::release()
{
    std::cout << "truck\n";
}

IProduction *CarWorkShop::create()
{
    return new Car();
}

IProduction *TruckWorkShop::create()
{
    return new Truck();
}