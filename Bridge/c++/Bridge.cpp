#include <iostream>

class DataReader
{
    public:
        virtual void read() = 0;
};

class DataBaseReader : public DataReader
{
    public:
        void read() override;
};

class FileReader : public DataReader
{
    public:
        void read() override;
};

class Sender
{
    protected:
        DataReader* reader;

    public:
        Sender(DataReader* dataReader) : reader(dataReader) {}
        void SetDataReader(DataReader* dataReader);
        virtual void send() = 0;
};

class EmailSender : public Sender
{
    public:
        EmailSender(DataReader* dataReader) : Sender(dataReader) {}
        void send() override;
};

class TelegramBotSender : public Sender
{
    public:
        TelegramBotSender(DataReader* dataReader) : Sender(dataReader) {}
        void send() override;
};

int main()
{
    Sender* sender = new EmailSender(new DataBaseReader());
    sender->send();

    sender->SetDataReader(new FileReader());
    sender->send();

    sender = new TelegramBotSender(new DataBaseReader());
    sender->send();

    return 0;
}

void DataBaseReader::read()
{
    std::cout << "data from the database ";
}

void FileReader::read()
{
    std::cout << "data from the file ";
}

void Sender::SetDataReader(DataReader *dataReader)
{
    reader = dataReader;
}

void EmailSender::send()
{
    reader->read();
    std::cout << "sent by email\n";
}

void TelegramBotSender::send()
{
    reader->read();
    std::cout << "sent by telegram bot\n";
}