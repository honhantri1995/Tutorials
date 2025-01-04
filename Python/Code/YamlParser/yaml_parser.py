from typing import List
from threading import Lock

import yaml     # pip install pyyaml

import util

class YamlParser:
    def __init__(self, filepath: str):
        self.filepath = filepath
        self.lock = Lock()

    def read(self) -> List[object]:
        try:
            items = []
            with open(self.filepath, encoding='utf-8') as file:
                datas = yaml.load_all(file, Loader=yaml.loader.FullLoader)
                for data in datas:
                    items.append(util.dict_to_obj(data))
            return items

        except Exception as ex:
            print(f'Failed to read YAML file {self.filepath}. Exception: {ex}')
            return items

    def write(self, items: List[object]) -> bool:
        try:
            pass
        except Exception as ex:
            print(f'Failed to write YAML file {self.filepath}. Exception: {ex}')
            return False

    def add(self, item: object) -> bool:
        try:
            pass
        except Exception as ex:
            print(f'Failed to add item to YAML file {self.filepath}. Exception: {ex}')
            return False

    def get(self, id) -> object:
        try:
            pass
        except Exception as ex:
            print(f'Failed to get item from YAML file {self.filepath}. Exception: {ex}')
            return None

    def update(self, id, item: object) -> bool:
        try:
            pass
        except Exception as ex:
            print(f'Failed to update item in YAML file {self.filepath}. Exception: {ex}')
            return False

    def remove(self, id) -> bool:
        try:
            pass
        except Exception as ex:
            print(f'Failed to remote item from YAML file {self.filepath}. Exception: {ex}')
            return False

    def exists(self, id, items=[]) -> bool:
        try:
            pass
        except Exception as ex:
            print(f'Failed to check if ID {id} exist in YAML file {self.filepath}. Exception: {ex}')
            return False
