import abc


class IDataReader(metaclass=abc.ABCMeta):

    @abc.abstractmethod
    def read(self):
        pass


class DataBaseReader(IDataReader):

    def read(self):
        print("data from the database ", end='')


class FileReader(IDataReader):

    def read(self):
        print("data from the file ", end='')


class Sender(metaclass=abc.ABCMeta):

    def __init__(self, data_reader: IDataReader):
        self.reader: IDataReader = data_reader

    def set_data_reader(self, data_reader: IDataReader):
        self.reader: IDataReader = data_reader

    @abc.abstractmethod
    def send(self):
        pass


class EmailSender(Sender):

    def __init__(self, data_reader: IDataReader):
        super().__init__(data_reader)

    def send(self):
        self.reader.read()
        print("sent by email")


class TelegramBotSender(Sender):

    def __init__(self, data_reader: IDataReader):
        super().__init__(data_reader)

    def send(self):
        self.reader.read()
        print("sent by telegram bot")


if __name__ == '__main__':

    sender: Sender = EmailSender(DataBaseReader())
    sender.send()

    sender.set_data_reader(FileReader())
    sender.send()

    sender = TelegramBotSender(DataBaseReader())
    sender.send()