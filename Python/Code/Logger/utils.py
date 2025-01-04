from datetime import datetime
import os

DATETIME_SECOND_FORMAT = '%Y-%m-%d %H:%M:%S'
DATETIME_SECOND_NOSPACE_FORMAT = '%Y%m%d_%H%M%S'

############################### TIME #################################
def get_current_time_s(format=DATETIME_SECOND_FORMAT) -> str:
    current_time = datetime.now().strftime(format)
    return current_time

############################### FILE #################################
def get_dir_path_from_file_path(path):
    return os.path.dirname(os.path.abspath(path))

def remove_extension_from_filepath(path_with_ext):
    return os.path.splitext(path_with_ext)[0]

def get_file_size(path, unit='byte'):
    size_in_byte = os.stat(path).st_size

    if unit == 'mb':
        size = size_in_byte / 1000000
    else:
        size = size_in_byte
    return size