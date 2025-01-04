import os
import json

def create_file_if_not_exist(path: str):
    if not os.path.isfile(path):
        with open(path, 'w', encoding='utf-8'): pass

def dict_to_obj(dic: dict) -> object:
    ''' Work for both simple and nested dict '''
    class obj:
        def __init__(self, dic):
            self.__dict__.update(dic)
    return json.loads(json.dumps(dic, ensure_ascii=False), object_hook=obj)

def object_to_dict(obj: object) -> dict:
    if isinstance(obj, dict):
        return {k: object_to_dict(v) for k, v in obj.items()}
    elif hasattr(obj, "__dict__"):
        return {k: object_to_dict(v) for k, v in obj.__dict__.items()}
    elif isinstance(obj, list):
        return [object_to_dict(i) for i in obj]
    else:
        return obj

def objects_to_dicts(obj: object) -> list:
    if isinstance(obj, dict):
        return {k: object_to_dict(v) for k, v in obj.items()}
    elif hasattr(obj, "__dict__"):
        return {k: object_to_dict(v) for k, v in obj.__dict__.items()}
    elif isinstance(obj, list):
        return [object_to_dict(i) for i in obj]
    else:
        return obj
