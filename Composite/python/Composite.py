import abc


class Item(metaclass=abc.ABCMeta):

    def __init__(self, name: str):
        self._item_name: str = name
        self._owner_name: str = None

    def set_owner(self, o: str):
        self._owner_name = o

    @abc.abstractmethod
    def add(self, sub_item: 'Item'):
        pass

    @abc.abstractmethod
    def remove(self, sub_item: 'Item'):
        pass

    @abc.abstractmethod
    def display(self):
        pass


class ClickableItem(Item):

    def __init__(self, name: str):
        super().__init__(name)

    def add(self, sub_item: Item):
        raise Exception('exception')

    def remove(self, sub_item: 'Item'):
        raise Exception('exception')

    def display(self):
        print(self._owner_name + self._item_name)


class DropDownItem(Item):

    def __init__(self, name: str):
        super().__init__(name)
        self.__children = []

    def add(self, sub_item: 'Item'):
        sub_item.set_owner(self._item_name)
        self.__children.append(sub_item)

    def remove(self, sub_item: 'Item'):
        self.__children.remove(sub_item)

    def display(self):
        for item in self.__children:
            if self._owner_name is not None:
                print(self._owner_name, end='')
            item.display()


if __name__ == '__main__':

    file: Item = DropDownItem('file->')

    create: Item = DropDownItem('create->')
    open: Item = DropDownItem('open->')
    exit: Item = ClickableItem('exit')

    file.add(create)
    file.add(open)
    file.add(exit)

    project: Item = ClickableItem('project...')
    repository: Item = ClickableItem('repository...')

    create.add(project)
    create.add(repository)

    solution: Item = ClickableItem('solution...')
    folder: Item = ClickableItem('folder...')

    open.add(solution)
    open.add(folder)

    file.display()
    print()

    file.remove(create)

    file.display()