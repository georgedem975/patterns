import abc


class Reader(metaclass=abc.ABCMeta):

    @abc.abstractmethod
    def parse(self, url: str):
        pass


class ResourceReader:

    def __init__(self, reader: Reader):
        self.__reader = reader

    def set_strategy(self, reader: Reader):
        self.__reader = reader

    def read(self, url: str):
        self.__reader.parse(url)


class NewsSiteReader(Reader):

    def parse(self, url: str):
        print("parse site ", url)


class SocialNetworkReader(Reader):

    def parse(self, url: str):
        print("parse social networks ", url)


class TelegramChannelReader(Reader):

    def parse(self, url: str):
        print("parse telegram channel", url)


if __name__ == '__main__':
    resource_reader = ResourceReader(NewsSiteReader())

    url = 'news site'
    resource_reader.read(url)

    url = 'social network'
    resource_reader.set_strategy(SocialNetworkReader())
    resource_reader.read(url)

    url = 'telegram channel'
    resource_reader.set_strategy(TelegramChannelReader())
    resource_reader.read(url)