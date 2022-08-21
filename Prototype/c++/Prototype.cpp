#include <iostream>
#include <string>

class Animal
{
    public:
        virtual void SetName(std::string name){}
        virtual std::string GetName() = 0;
        virtual Animal* clone() const = 0;
};

class Sheep : Animal
{
    private:
        std::string name;
        Sheep(const Sheep& donor) : name(donor.name) {}

    public:
        Sheep() {}
        ~Sheep() {}
        void SetName(std::string name) override;
        std::string GetName() override;
        Sheep* clone() const;
};

int main()
{
    Sheep* sheepDonor = new Sheep();
    std::string name = "sheep";
    sheepDonor->SetName(name);

    Sheep* sheepClone = sheepDonor->clone();

    std::cout << sheepDonor->GetName() << std::endl;
    std::cout << sheepClone->GetName() << std::endl;
    
    return 0;
}

void Sheep::SetName(std::string name)
{
    this->name = name;
}

std::string Sheep::GetName()
{
    return name;
}

Sheep *Sheep::clone() const
{
    return new Sheep(*this);
}