import json
import threading
import os
from typing import List
import utils

class JsonParser():
    ''' Parse JSON files with basic operations (read, write, get, add, update, remove, clear).
        NOTE: To be able to work, your JSON root object must has item called "id" as its unique identifier
    '''
    def __init__(self, path: str, indent=4):
        self.path = path
        self.indent = indent
        self.lock = threading.Lock()

        utils.create_file_if_not_exist(self.path)

    def write(self, items: List[object]):
        try:
            items_json = json.dumps(items, default=lambda o: o.__dict__, indent=self.indent, ensure_ascii=False)
            with self.lock:
                with open(self.path, "w", encoding='utf-8') as file:
                    file.write(items_json)
            return True

        except Exception as ex:
            print(f'Failed to write items to JSON file {self.path}. Exception: {ex}')
            return False

    def read(self) -> List[object]:
        try:
            # Make sure file is not empty to prevent exception "Expecting value: line 1 column 1 (char 0)"
            if os.stat(self.path).st_size == 0:
                return []

            with self.lock:
                with open(self.path, "r", encoding='utf-8') as file:
                    items_json = json.load(file)

            items = []
            for item_json in items_json:
                item = utils.dict_to_obj(item_json)
                items.append(item)
            return items

        except Exception as ex:
            print(f'Failed to read items from JSON file {self.path}. Exception: {ex}')
            return []

    def get(self, id):
        try:
            items = self.read()

            for item in items:
                if item.id == id:
                    return item
            return None

        except Exception as ex:
            print(f'Failed to get item by ID {id} from JSON file {self.path}. Exception: {ex}')
            return None

    def is_exist(self, id, items=[]):
        try:
            if not items:
                items = self.read()

            for item in items:
                if item.id == id:
                    return True
            return False

        except Exception as ex:
            print(f'Failed to check if ID {id} exist in JSON file {self.path}. Exception: {ex}')
            return False

    def add(self, item: object):
        try:
            items = self.read()
            if self.is_exist(item.id, items=items):
                print(f'ID {item.id} already exists. Cannot add another one')
                return False

            items.append(item)
            self.write(items)
            return True

        except Exception as ex:
            print(f'Failed to add item to JSON file {self.path}. Exception: {ex}')
            return False

    def update(self, id, item: object):
        try:
            items = self.read()
            for i, ite in enumerate(items):
                if str(ite.id) == str(id):
                    items[i] = item     # Won't work if "ite = item"
                    self.write(items)
                    return True

        except Exception as ex:
            print(f'Failed to update item in JSON file {self.path}. Exception: {ex}')
            return False

    def remove(self, id):
        try:
            items = self.read()
            for ite in items[:]:
                if str(ite.id) == str(id):
                    items.remove(ite)
                    self.write(items)
                    return True

        except Exception as ex:
            print(f'Failed to remove item from JSON. Exception: {ex}')
            return False

    def clear(self):
        try:
            with self.lock:
                open(self.path, 'w', encoding='utf-8').close()
            return True

        except Exception as ex:
            print(f'Failed to clear JSON file {self.path}. Exception: {ex}')
            return False
