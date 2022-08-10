#include <iostream>

class Transmitter
{
    protected:
        virtual void voiceRecord();
        virtual void simpling() {};
        virtual void digitization() {};
        virtual void modulation() = 0;
        virtual void transmission();

    public:
        void processStart();
        virtual ~Transmitter(){}
};

class AnalogTransmitter : public Transmitter
{
    public:
        void modulation() override;
};

class DigitTransmitter : public Transmitter
{
    public:
        void simpling() override;
        void digitization() override;
        void modulation() override;
};

int main()
{
    Transmitter* analogTransmitter = new AnalogTransmitter();
    analogTransmitter->processStart();

    std::cout << std::endl;

    Transmitter* digitTransmitter = new DigitTransmitter();
    digitTransmitter->processStart();

    delete analogTransmitter;
    delete digitTransmitter;

    return 0;
}

void Transmitter::voiceRecord()
{
    std::cout << "recording a fragment of speech\n";
}

void Transmitter::transmission()
{
    std::cout << "signal transmission via radio channel\n";
}

void Transmitter::processStart()
{
    voiceRecord();
    simpling();
    digitization();
    modulation();
    transmission();
}

void AnalogTransmitter::modulation()
{
    std::cout << "modulation of the analog signal\n";
}

void DigitTransmitter::simpling()
{
    std::cout << "sampling of the recorded fragment\n";
}

void DigitTransmitter::digitization()
{
    std::cout << "digitization\n";
}

void DigitTransmitter::modulation()
{
    std::cout << "digital signal modulation\n";
}