#include <iostream>
#include <string>

class Processor
{
    public:
        virtual void process() = 0;
};

class Transmitter : public Processor
{
    private:
        std::string data;

    public:
        Transmitter(std::string data) : data(data) {}
        void process() override;
};

class Shell : public Processor
{
    protected:
        Processor* processor;

    public:
        Shell(Processor* processor) : processor(processor) {}
        void process() override;
};

class HammingCoder : public Shell
{
    public:
        HammingCoder(Processor* processor) : Shell(processor) {}
        void process() override;
};

class Encryptor : public Shell
{
    public:
        Encryptor(Processor* processor) : Shell(processor) {}
        void process() override;
};

int main()
{
    Processor* transmitter = new Transmitter("12345");
    transmitter->process();
    std::cout << std::endl;

    Shell* hammingCoder = new HammingCoder(transmitter);
    hammingCoder->process();
    std::cout << std::endl;

    Shell* encryptor = new Encryptor(hammingCoder);
    encryptor->process();
    
    return 0;
}

void Transmitter::process()
{
    std::cout << "Data " << data << " transmitted via the communication channel\n";
}

void Shell::process()
{
    processor->process();
}

void HammingCoder::process()
{
    std::cout << "noise-resistant Hamming code has been applied->";
    processor->process();
}

void Encryptor::process()
{
    std::cout << "data encryption->";
    processor->process();
}