import copy


class DataStack:

    def __init__(self, my_stack: 'DataStack' = None):
        self.__items = [0] * 10
        self.__length = 0

        if my_stack is not None:
            self.__items = copy.deepcopy(my_stack.__items)
            self.__length = my_stack.__length

    @property
    def items(self):
        return self.__items

    @property
    def length(self) -> int:
        return self.__length

    def push(self, value: int):
        self.__items[self.__length] = value
        self.__length += 1

    def pop(self) -> int:
        self.__length -= 1
        return self.__items[self.__length]

    def __eq__(self, other: 'DataStack') -> bool:
        it1, it2 = StackIterator(self), StackIterator(other)

        while not it1.is_end() or not it2.is_end():
            if next(it1) != next(it2):
                break
        return it1.is_end() and it2.is_end()


class StackIterator:

    def __init__(self, my_stack: DataStack):
        self.__stack = my_stack
        self.__index = 0

    def __iter__(self):
        return self

    def __next__(self):
        current_index = self.__index
        self.__index += 1
        if current_index < self.__stack.length:
            return self.__stack.items[current_index]
        return 0

    def is_end(self) -> bool:
        return self.__index == self.__stack.length + 1


if __name__ == '__main__':

    my_stack1 = DataStack()
    for i in range(1, 5):
        my_stack1.push(i)

    my_stack2 = DataStack(my_stack1)

    print(my_stack1 == my_stack2)

    my_stack2.push(10)

    print(my_stack1 == my_stack2)