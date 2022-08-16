#include <iostream>

class IEngine
{
    public:
        virtual void releaseEngine() = 0;
};

class JapaneseEngine : public IEngine
{
    public:
        void releaseEngine() override;
};

class RussianEngine : public IEngine
{
    public:
        void releaseEngine() override;
};

class ICar
{
    public:
        virtual void releaseCar(IEngine* engine) = 0;
};

class JapaneseCar : public ICar
{
    public:
        void releaseCar(IEngine* engine) override;
};

class RussianCar : public ICar
{
    public:
        void releaseCar(IEngine* engine) override;
};

class IFactory
{
    public:
        virtual IEngine* createEngine() = 0;
        virtual ICar* createCar() = 0;
};

class JapaneseFactory : public IFactory
{
    public:
        IEngine* createEngine() override;
        ICar* createCar() override;
};

class RussianFactory : public IFactory
{
    public:
        IEngine* createEngine() override;
        ICar* createCar() override;
};

int main()
{
    IFactory* jFactory = new JapaneseFactory();

    IEngine* jEngine = jFactory->createEngine();
    ICar* jCar = jFactory->createCar();

    jCar->releaseCar(jEngine);

    IFactory* rFactory = new RussianFactory();

    IEngine* rEngine = rFactory->createEngine();
    ICar* rCar = rFactory->createCar();

    rCar->releaseCar(rEngine);
    
    return 0;
}

void JapaneseEngine::releaseEngine()
{
    std::cout << "japanese engine\n";
}

void RussianEngine::releaseEngine()
{
    std::cout << "russian engine\n";
}

void JapaneseCar::releaseCar(IEngine *engine)
{
    std::cout << "assembled a Japanese car: ";
    engine->releaseEngine();
}

void RussianCar::releaseCar(IEngine *engine)
{
    std::cout << "assembled a Russian car: ";
    engine->releaseEngine();
}

IEngine *JapaneseFactory::createEngine()
{
    return new JapaneseEngine();
}

ICar *JapaneseFactory::createCar()
{
    return new JapaneseCar();
}

IEngine *RussianFactory::createEngine()
{
    return new RussianEngine();
}

ICar *RussianFactory::createCar()
{
    return new RussianCar();
}