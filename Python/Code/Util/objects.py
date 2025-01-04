from typing import List
import threading

from util.logger import Logger

class Objects:
    def __init__(self):
        self.objects : List[object] = []
        self.lock = threading.Lock()

    def get_all(self):
        return self.objects

    def get_last(self) -> object:
        try:
            return self.objects[-1]
        except Exception as ex:
            Logger.error(f'Fail to get last object. Exception: {ex}')
            return None

    def get(self, id: str) -> object:
        try:
            for _obj in self.objects:
                if _obj.id == id:
                    return _obj
            return None
        except Exception as ex:
            Logger.error(f'Fail to get item with ID {id}. Exception: {ex}')
            return None

    def update(self, obj: object) -> bool:
        try:
            with self.lock:
                for _obj in self.objects[:]:
                    if _obj.id == obj.id:
                        _obj = obj
                        break
            return True
        except Exception as ex:
            Logger.error(f'Fail to update item with ID {obj.id}. Exception: {ex}')
            return False

    def add(self, obj: object, overwrited=False):
        try:
            if self.exist(obj):
                if overwrited:
                    self.update(obj)
                else:
                    Logger.error('Cannot add item because ID exists')
            else:
                with self.lock:
                    self.objects.append(obj)
            return True
        except Exception as ex:
            Logger.error(f'Fail to add item with ID {obj.id}. Exception: {ex}')
            return False

    def remove(self, obj: object):
        try:
            with self.lock:
                for _obj in self.objects[:]:
                    if _obj.id == obj.id:
                        self.objects.remove(_obj)
                        break
            return True
        except Exception as ex:
            Logger.error(f'Fail to remove remove with ID {obj.id}. Exception: {ex}')
            return False
    
    def write(self, objs: List[object]):
        self.objects = objs

    def exist(self, id):
        try:
            for _obj in self.objects:
                if _obj.id == id:
                    return True
            return False
        except Exception as ex:
            Logger.error(f'Fail to check existence of item with ID {id}. Exception: {ex}')
            return False
