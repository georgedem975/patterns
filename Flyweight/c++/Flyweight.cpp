#include <iostream>
#include <string>
#include <unordered_map>

struct Shared
{
    std::string company;
    std::string position;

    Shared(const std::string company, const std::string position)
    : company(company), position(position) {}
};

struct Unique
{
    std::string passport;
    std::string name;

    Unique(const std::string name, const std::string passport)
    : passport(passport), name(name) {}
};

class Flyweight
{
    private:
        Shared* shared;

    public:
        Flyweight(const Shared* shared) : shared(new Shared(*shared)) {}
        Flyweight(const Flyweight& other) : shared(new Shared(*other.shared)) {}
        ~Flyweight();
        void process(const Unique& unique) const;
};

class FlyweightFactory
{
    private:
        std::unordered_map<std::string, Flyweight> flyweights;
        std::string GetKey(const Shared& shared) const;

    public:
        FlyweightFactory(std::initializer_list<Shared> shareds);
        Flyweight GetFlyweight(const Shared& shared);
        void listFlyweights() const;
};

void addSpecialistDatabase(FlyweightFactory& flyweightFactory, const std::string company,
                            const std::string position, const std::string name, const std::string passport);

int main()
{
    FlyweightFactory* flyweightFactory = new FlyweightFactory({
        {"Microsoft", "manager"},
        {"Google", "manager"},
        {"Google", "developer"},
        {"Apple", "developer"}
    });

    flyweightFactory->listFlyweights();

    addSpecialistDatabase(*flyweightFactory,
                           "Google",
                           "developer",
                           "George",
                           "12345");

    addSpecialistDatabase(*flyweightFactory,
                           "Apple",
                           "manager",
                           "Mark",
                           "67890");

    flyweightFactory->listFlyweights();

    return 0;
}

Flyweight::~Flyweight()
{
    delete shared;
}

void Flyweight::process(const Unique &unique) const
{
    std::cout << "New data: shared - " << shared->company << "_" <<
    shared->position << " unique - " << unique.name << "_" << unique.passport << std::endl;
}

std::string FlyweightFactory::GetKey(const Shared &shared) const
{
    return shared.company + "_" + shared.position;
}

FlyweightFactory::FlyweightFactory(std::initializer_list<Shared> shareds)
{
    for (const Shared& shared : shareds)
    {
        this->flyweights.insert(std::make_pair<std::string, Flyweight>(this->GetKey(shared), Flyweight(& shared)));
    }
}

Flyweight FlyweightFactory::GetFlyweight(const Shared &shared)
{
    std::string key = this->GetKey(shared);
    if (this->flyweights.find(key) == this->flyweights.end())
    {
        std::cout << "Flyweight factory: object not found " << key << std::endl;
        this->flyweights.insert(std::make_pair(key, Flyweight(&shared)));
    }
    else
    {
        std::cout << "Flyweight factory: object found " << key << std::endl;
    }
    return this->flyweights.at(key);
}

void FlyweightFactory::listFlyweights() const
{
    size_t count = this->flyweights.size();
    std::cout << "\nFlyweight factory: count = " << count << std::endl;
    for (std::pair<std::string, Flyweight> pair : this->flyweights)
        std::cout << pair.first << std::endl;
}

void addSpecialistDatabase(FlyweightFactory& flyweightFactory, const std::string company,
                            const std::string position, const std::string name, const std::string passport)
{
    std::cout << std::endl;
    const Flyweight& flyweight = flyweightFactory.GetFlyweight({ company, position });
    flyweight.process({ name, passport });
}