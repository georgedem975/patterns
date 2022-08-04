#include <iostream>
#include <vector>
#include <algorithm>

class IObserver
{
    public:
        virtual void update(double p) = 0;
};

class IObservable
{
    public:
        virtual void addObserver(IObserver* o) = 0;
        virtual void removeObserver(IObserver* o) = 0;
        virtual void notify() = 0;
        virtual ~IObservable() {}
};

class Product : public IObservable
{
    private:
        std::vector<IObserver*> observers;
        double price;
        
    public:
        Product(double p) : price(p) {}
        void changePrice(double p);
        void addObserver(IObserver* o) override;
        void removeObserver(IObserver* o) override;
        void notify() override;
};

class Wholesaler : public IObserver
{
    private:
        IObservable* product;

    public:
        Wholesaler(IObservable* obj) : product(obj)
        {
            obj->addObserver(this);
        }
        void update(double p) override;
};

class Buyer : public IObserver
{
    private:
        IObservable* product;

    public:
        Buyer(IObservable* obj) : product(obj)
        {
            obj->addObserver(this);
        }
        void update(double p) override;
};

int main()
{
    Product* product = new Product(400);

    Wholesaler* wholesaler = new Wholesaler(product);
    Buyer* buyer = new Buyer(product);

    product->changePrice(320);
    product->changePrice(280);

    return 0;
}

void Product::changePrice(double p)
{
    price = p;
    notify();
}

void Product::addObserver(IObserver *o)
{
    observers.push_back(o);
}

void Product::removeObserver(IObserver *o)
{
    observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

void Product::notify()
{
    for (auto o : observers)
    {
        o->update(price);
    }
}

void Wholesaler::update(double p)
{
    if (p < 300)
    {
        std::cout << "the wholesaler bought the goods at a price " << p << std::endl;
        product->removeObserver(this);
    }
}

void Buyer::update(double p)
{
    if (p < 350)
    {
        std::cout << "the buyer purchased the product at the price " << p << std::endl;
        product->removeObserver(this);
    }
}