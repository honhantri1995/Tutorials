import copy
from typing import List

from json_parser import JsonParser

class Signal:
    class Orders:
        class Entry:
            def __init__(self):
                self.id = 0
                self.quantity = 0

        class Sl:
            def __init__(self):
                self.id = 0
                self.quantity = 0

        class Tp:
            def __init__(self):
                self.id = 0
                self.quantity = 0

        def __init__(self):
            self.entries: List[Signal.Orders.Entry()] = []
            self.sl = self.Sl()
            self.tps: List[Signal.Orders.Tp()] = []

    def __init__(self, id: str, position: str, leverage: int):
        self.id = id
        self.position = position
        self.leverage = leverage
        self.orders = copy.copy(self.Orders())   # Deep copy to prevent 'ValueError: Circular reference detected'


class JsonParser_Signal(JsonParser):
    def __init__(self, *args, **kwargs):
        super(JsonParser_Signal, self).__init__(*args, **kwargs)

    def read(self) -> List[Signal]:     # Note: Explicitly override this function to help IntelliSense able to autocomplete object items
        return super(JsonParser_Signal, self).read()

    def get(self, id) -> Signal:        # Note: Explicitly override this function to help IntelliSense able to autocomplete object items
        return super(JsonParser_Signal, self).get(id)
