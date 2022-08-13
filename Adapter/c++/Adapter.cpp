#include <iostream>

class Scales
{
    public:
        virtual float GetWeight() = 0;
};

class RussianScales : public Scales
{
    private:
        float currentWeight;

    public:
        RussianScales(float cw) : currentWeight(cw) {}
        float GetWeight() override;
};

class BritishScales
{
    private:
        float currentWeight;

    public:
        BritishScales(float cw) : currentWeight(cw) {}
        float GetWeight();
};

class AdapterForBritishScales : public Scales
{
    private:
        BritishScales* britishScales;

    public:
        AdapterForBritishScales(BritishScales* bs) : britishScales(bs) {}
        ~AdapterForBritishScales();
        float GetWeight() override;
};

int main()
{
    float kg = 55.0;
    float lb = 55.0;

    Scales* rScales = new RussianScales(kg);
    Scales* bScales = new AdapterForBritishScales(new BritishScales(lb));

    std::cout << rScales->GetWeight() << std::endl;
    std::cout << bScales->GetWeight() << std::endl;
    
    return 0;
}

float RussianScales::GetWeight()
{
    return currentWeight;
}

float BritishScales::GetWeight()
{
    return currentWeight;
}

AdapterForBritishScales::~AdapterForBritishScales()
{
    delete britishScales;
}

float AdapterForBritishScales::GetWeight()
{
    return britishScales->GetWeight() * 0.453;
}