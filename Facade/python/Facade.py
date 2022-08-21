class ProviderCommunication:

    def receive(self):
        print('receiving products from the manufacturer')

    def payment(self):
        print('payment')


class Site:

    def placement(self):
        print('placement on the website')

    def delete(self):
        print('removal from the site')


class Database:

    def insert(self):
        print('writing to the database')

    def delete(self):
        print('deleting from the database')


class MarketPlace:

    def __init__(self):
        self._provider_communication = ProviderCommunication()
        self._site = Site()
        self._database = Database()

    def product_receipt(self):
        self._provider_communication.receive()
        self._site.placement()
        self._database.insert()

    def product_release(self):
        self._provider_communication.payment()
        self._site.delete()
        self._database.delete()


if __name__ == '__main__':

    market_place = MarketPlace()
    market_place.product_receipt()
    print()
    market_place.product_release()