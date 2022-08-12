#include <iostream>
#include <string>

class Zoo;

class Cinema;

class Circus;

class IVisitor
{
    public:
        virtual void visit(Zoo& zoo) = 0;
        virtual void visit(Cinema& cinema) = 0;
        virtual void visit(Circus& circus) = 0;
};

class Place
{
    public:
        virtual void accept(IVisitor& v) = 0;
        virtual ~Place() = default;
};

class Zoo : public Place
{
    public:
        void accept(IVisitor& v) override;
};

class Cinema : public Place
{
    public:
        void accept(IVisitor& v) override;
};

class Circus : public Place
{
    public:
        void accept(IVisitor& v) override;
};

class HolidayMaker : public IVisitor
{
    public:
        std::string value;
        void visit(Zoo& zoo) override;
        void visit(Cinema& cinema) override;
        void visit(Circus& circus) override;
};

int main()
{
    Zoo zoo;
    Cinema cinema;
    Circus circus;

    Place* places[] = { &zoo, &cinema, &circus };

    for (auto place : places)
    {
        HolidayMaker visitor;
        place->accept(visitor);
        std::cout << visitor.value << std::endl;
    }

    return 0;
}

void Zoo::accept(IVisitor &v)
{
    v.visit(*this);
}

void Cinema::accept(IVisitor &v)
{
    v.visit(*this);
}

void Circus::accept(IVisitor &v)
{
    v.visit(*this);
}

void HolidayMaker::visit(Zoo &zoo)
{
    value = "zoo";
}

void HolidayMaker::visit(Cinema &cinema)
{
    value = "cinema";
}

void HolidayMaker::visit(Circus &circus)
{
    value = "circus";
}