from typing import List
from threading import Lock

import csv

import util

class CsvParser:
    ''' Parse CSV files with basic operations (read, write, get, add, update, remove, clear).
        NOTE: To be able to work, your CSV root object must has item called "id" as its unique identifier
    '''
    def __init__(self, filepath: str, fieldnames: list, delimiter=','):
        self.filepath = filepath
        self.delimiter = delimiter
        self.lock = Lock()

        if not fieldnames:
            raise Exception('Fieldnames cannot be empty')
        self.fieldnames = fieldnames

        # NOTE: Why UTF-8 with BOM?
        #   It's more convenient for end users to edit CSV files in Excel rather than in plain text.
        #   However, Excel mgith not recognize the UTF-8 encoding automatically.
        #   Adding a Byte Order Mark (BOM) at the beginning of the CSV file helps Excel recognize the file as UTF-8 encoded.
        self.ENCODING = 'utf-8-sig'

        util.create_file_if_not_exist(self.filepath)

    def read(self, strip=False, ignore_empty_line=False) -> List[object]:
        try:
            with self.lock:
                items = []
                with open(self.filepath, mode='r', newline='', encoding=self.ENCODING) as file:
                    reader = csv.DictReader(file, delimiter=self.delimiter)
                    if strip:
                        reader = [ { k.strip(): v.strip() for k, v in row.items() } for row in reader ]
                    for row in reader:
                        if ignore_empty_line:
                            if all(v.strip() == '' for _, v in row.items()):
                                continue
                        items.append(util.dict_to_obj(row))
            return items

        except Exception as ex:
            print(f'Failed to read CSV file {self.filepath}. Exception: {ex}')
            return []

    def write(self, items: List[object]) -> bool:
        try:
            with self.lock:
                with open(self.filepath, mode='w', newline='', encoding=self.ENCODING) as file:
                    writer = csv.DictWriter(file, fieldnames=self.fieldnames, delimiter=self.delimiter)
                    writer.writeheader()

                    rows = []
                    for item in items:
                        rows.append(util.object_to_dict(item))
                    writer.writerows(rows)
            return True

        except Exception as ex:
            print(f'Failed to write CSV file {self.filepath}. Exception: {ex}')
            return False

    def add(self, item: object) -> bool:
        try:
            if self.exists(item.id):
                print(f'ID {item.id} already exists. Cannot add another one')
                return False

            with self.lock:
                with open(self.filepath, mode='a', newline='', encoding=self.ENCODING) as file:
                    dict_writer = csv.DictWriter(file, fieldnames=self.fieldnames, delimiter=self.delimiter)
                    dict_writer.writerow(util.object_to_dict(item))
            return True

        except Exception as ex:
            print(f'Failed to add item to CSV file {self.filepath}. Exception: {ex}')
            return False

    def insert(self, index: int, item: object) -> bool:
        try:
            if self.exists(item.id):
                print(f'ID {item.id} already exists. Cannot add another one')
                return False

            items = self.read()
            items.insert(index, item)
            self.write(items)

        except Exception as ex:
            print(f'Failed to insert item to CSV file {self.filepath} at index {index}. Exception: {ex}')

    def get(self, id) -> object:
        try:
            items = self.read()
            for item in items:
                if item.id == id:
                    return item
            return None

        except Exception as ex:
            print(f'Failed to get item from CSV file {self.filepath}. Exception: {ex}')
            return None

    def update(self, id, item: object) -> bool:
        try:
            items = self.read()
            for i, ite in enumerate(items):
                if ite.id == id:
                    items[i] = item          # Won't work if "ite = item"
                    self.write(items)
                    return True

            print(f'Cannot find item with ID {id} to update')
            return False

        except Exception as ex:
            print(f'Failed to update item in CSV file {self.filepath}. Exception: {ex}')
            return False

    def remove(self, id) -> bool:
        try:
            items = self.read()
            for item in items[:]:
                if item.id == id:
                    items.remove(item)
                    self.write(items)
                    return True

        except Exception as ex:
            print(f'Failed to remote item from CSV file {self.filepath}. Exception: {ex}')
            return False

    def exists(self, id, items=[]) -> bool:
        try:
            if not items:
                items = self.read()

            for item in items:
                if item.id == id:
                    return True
            return False

        except Exception as ex:
            print(f'Failed to check if ID {id} exist in CSV file {self.filepath}. Exception: {ex}')
            return False

    def clear(self):
        try:
            with self.lock:
                open(self.filepath, 'w', encoding='utf-8').close()
                with open(self.filepath, mode='w', newline='', encoding="utf-8") as file:
                    dict_writer = csv.DictWriter(file, fieldnames=self.fieldnames, delimiter=self.delimiter)
                    dict_writer.writeheader()

            return True

        except Exception as ex:
            print(f'Failed to clear CSV file {self.filepath}. Exception: {ex}')
            return False
