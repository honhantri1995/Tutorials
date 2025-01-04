import os
import json

def create_file_if_not_exist(path: str):
    if not os.path.isfile(path):
        with open(path, 'w', encoding='utf-8'): pass

def dict_to_obj(dic: dict):
    ''' Dump dict to Python object. Work for both simple and nested dict'''

    class obj:
        def __init__(self, dic):
            self.__dict__.update(dic)

    return json.loads(json.dumps(dic), object_hook=obj)

def object_to_dict(obj: object) -> dict:
    if hasattr(obj, '__dict__'):
        return obj.__dict__
    return None

def object_list_to_dict(objs: list):
    dicts = []
    for obj in objs:
        dicts.append(object_to_dict(obj))
    return dicts