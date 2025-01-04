from datetime import datetime, timedelta
import time
import math
import os
import json
import glob

class Time:
    class TIMESTAMP_UNIT:
        SECOND = 's'
        MILLISECOND = 'ms'

    class DATETIME_FORMAT:
        DATE = '%Y-%m-%d'
        DATETIME_SECOND = '%Y-%m-%d %H:%M:%S'
        DATETIME_MILLISECOND = '%Y-%m-%d %H:%M:%S.%f'

    class LocalTime:
        def get_current_timestamp(unit='s', epoch=False) -> int:
            timestamp = time.time()
            match unit:
                case Time.TIMESTAMP_UNIT.SECOND:
                    pass
                case Time.TIMESTAMP_UNIT.MILLISECOND:
                    timestamp = timestamp * 1000
                case _:
                    raise Exception(f'Unit {unit} is not supported')
            if not epoch:
                timestamp = int(timestamp)
            return timestamp

        def get_current_datetime() -> datetime:
            ''' Microsecond unit: 2024-08-07 23:21:10.905000
            '''
            return datetime.now()

        def get_current_datetime_str(fmt='%Y-%m-%d %H:%M:%S') -> str:
            curtime = datetime.now().strftime(fmt)
            match fmt:
                case Time.DATETIME_FORMAT.DATETIME_SECOND:
                    pass
                case Time.DATETIME_FORMAT.DATETIME_MILLISECOND:
                    curtime = curtime[:-3]
                case _:
                    raise Exception(f'Format {fmt} is not supported')
            return curtime

        def convert_datetime_str_to_timestamp(datetime_str: str, fmt='%Y-%m-%d %H:%M:%S', unit='s') -> datetime:
            timestamp = datetime.timestamp(datetime.strptime(datetime_str, fmt))
            match unit:
                case Time.TIMESTAMP_UNIT.SECOND:
                    timestamp = int(timestamp)
                case Time.TIMESTAMP_UNIT.MILLISECOND:
                    timestamp = int(timestamp * 1000)
                case _:
                    raise Exception(f'Unit {unit} is not supported')
            return timestamp

        def convert_timestamp_to_datetime(timestamp: int, fmt='%Y-%m-%d %H:%M:%S') -> datetime:
            unit = Time.get_timestamp_unit(timestamp)
            match unit:
                case Time.TIMESTAMP_UNIT.SECOND:
                    pass
                case Time.TIMESTAMP_UNIT.MILLISECOND:
                    timestamp = timestamp / 1000
                case _:
                    raise Exception(f'Unit {unit} is not supported')
            dt = datetime.strptime(datetime.fromtimestamp(timestamp).strftime(fmt), fmt)
            return dt

        def convert_timestamp_to_datetime_str(timestamp: int, fmt='%Y-%m-%d %H:%M:%S') -> str:
            unit = Time.get_timestamp_unit(timestamp)
            match unit:
                case Time.TIMESTAMP_UNIT.SECOND:
                    pass
                case Time.TIMESTAMP_UNIT.MILLISECOND:
                    timestamp = timestamp / 1000
                case _:
                    raise Exception(f'Unit {unit} is not supported')
            dt = datetime.fromtimestamp(timestamp).strftime(fmt)
            return dt

    class UtcTime:
        def get_current_timestamp(unit='s') -> int:
            timestamp = datetime.utcnow().timestamp()
            match unit:
                case Time.TIMESTAMP_UNIT.SECOND:
                    timestamp = int(timestamp)
                case Time.TIMESTAMP_UNIT.MILLISECOND:
                    timestamp = int(timestamp * 1000)
                case _:
                    raise Exception(f'Unit {unit} is not supported')
            return timestamp

    class Date:
        def get_dates_between(start_date: str, end_date: str) -> list:  # List of Date object
            '''
                Input: start_date: 2023-03-13, end_date: 2023-03-26
                Output: 2023-03-13, 2023-03-14 ... 2023-03-26
            '''
            startdate_datetimeobj = datetime.strptime(start_date, Time.DATETIME_FORMAT.DATE)      # 2023-03-13 00:00:00
            enddate_datetimeobj = datetime.strptime(end_date, Time.DATETIME_FORMAT.DATE)

            startdate_dateobj = startdate_datetimeobj.date()                        # 2023-03-13
            enddate_dateobj = enddate_datetimeobj.date()

            delta = enddate_dateobj - startdate_dateobj

            days = []
            for i in range(delta.days + 1):
                day = startdate_dateobj + timedelta(days=i)
                days.append(day)
            return days

        def is_date_between(cur_date: str, start_date: str, end_date: str, fmt='%Y-%m-%d') -> bool:
            curdate_timestamp = Time.LocalTime.convert_datetime_str_to_timestamp(cur_date, fmt=fmt, unit=Time.TIMESTAMP_UNIT.SECOND)
            startdate_timestamp = Time.LocalTime.convert_datetime_str_to_timestamp(start_date, fmt=fmt, unit=Time.TIMESTAMP_UNIT.SECOND)
            enddate_timestamp = Time.LocalTime.convert_datetime_str_to_timestamp(end_date, fmt=fmt, unit=Time.TIMESTAMP_UNIT.SECOND)
            return startdate_timestamp <= curdate_timestamp <= enddate_timestamp

        def get_next_date(cur_date: str, increment=1) -> str:
            curdate_dateobj = datetime.strptime(cur_date, Time.DATETIME_FORMAT.DATE).date()
            nextdate_dateobj = curdate_dateobj + timedelta(days=increment)
            return nextdate_dateobj.strftime(Time.DATETIME_FORMAT.DATE)

        def get_previous_date(cur_date: str, decrement=1) -> str:
            curdate_dateobj = datetime.strptime(cur_date, Time.DATETIME_FORMAT.DATE).date()
            prevdate_dateobj = curdate_dateobj - timedelta(days=decrement)
            return prevdate_dateobj.strftime(Time.DATETIME_FORMAT.DATE)

    def get_timestamp_unit(timestamp: int):
        digit_count = len(str(timestamp))
        unit = ''
        match digit_count:
            case 10:
                unit = Time.TIMESTAMP_UNIT.SECOND
            case 13:
                unit = Time.TIMESTAMP_UNIT.MILLISECOND
        return unit

    def is_timeout(past_timestamp, current_timestamp, max_duration: float):
        ''' Make sure all parameters have the same timestamp unit
        '''
        diff = current_timestamp - past_timestamp
        return diff > max_duration

class IO:
    class Path:
        def extract_dirpath_from_filepath(filepath: str):
            return os.path.dirname(os.path.abspath(filepath))

        def extract_filepath_without_extension(filepath: str):
            return os.path.splitext(filepath)[0]

        def extract_filename_from_filepath(path: str, with_extension=True):
            filename = os.path.basename(path)
            if not with_extension:
                filename = os.path.splitext(filename)[0]
            return filename

    class Directory:
        def get_current_absolute_dirpath():
            return os.path.abspath(os.getcwd())

        def get_filepaths(dirpath: str, extension='', file_name_prefix='', recursive=False):
            filepaths = []
            if extension:
                pattern = f'/{file_name_prefix}*.{extension}'
            else:
                pattern = '/{}**'
            for path in glob.iglob(dirpath + pattern, recursive=recursive):
                filepaths.append(path)
            return filepaths

        def create(path: str, recursive=True):
            if not os.path.isdir(path):
                if recursive:
                    os.makedirs(path, exist_ok=True)
                else:
                    os.mkdir(path)

    class File:
        def get_size(path, unit='byte'):
            size_in_byte = os.stat(path).st_size
            if unit == 'mb':
                size = size_in_byte / 1000000
            else:
                size = size_in_byte
            return size

        def exist(path: str):
            if not os.path.isfile(path):
                return False
            return True

        def create(path: str):
            if not os.path.isfile(path):
                with open(path, 'w', encoding='utf-8'): pass

class Number:
    def truncate(number: float, precision: int):
        ''' Round down (truncation)
        '''
        multiplier = 1
        for _ in range(0, precision):
            multiplier *= 10
        num = math.floor(number * multiplier) / multiplier
        return num

    def divide_equally(total: float, part_count: int, min: float, precision: int) -> list:
        ''' Divide a total amount into multiple item amount based on item number
            E.g.:
                Input: total_amount = 10, item_num = 3, min_amount = 2, amount_prevision = 2
                Output: [3.33, 3.33, 3.34]

                Input: total_amount = 10, item_num = 3, min_amount = 5, amount_prevision = 0
                Output: [5, 5, 0]
        '''
        parts = []
        average = round(total / part_count, precision)
        remain = total
        for idx in range(part_count):
            if average >= min:
                if remain >= min:
                    if remain >= average:
                        parts.append(average)
                    else:
                        parts.append(remain)
                else:
                    if len(parts) >= 1:
                        parts[-1] += remain
            else:
                if remain >= min:
                    parts.append(min)
                else:
                    if len(parts) >= 1:
                        parts[-1] += remain

            remain = round(total - sum(parts), precision)
            if remain <= 0:
                break

            # If remaining is not 0, add all of them to the last item
            if (idx == part_count - 1) and (remain > 0) and (len(parts) >= 1):
                parts[-1] += remain

        while len(parts) < part_count:
            parts.append(0)
        return parts

    def is_within_range(num1: float, num2: float, max_diff_percent: float):
        ''' If the diff of two numbers exceed a max percent, they're 'not within range'
        '''
        if not num1 or not num2:
            return False

        diff1 = abs(num1 - num2) / num1 * 100
        diff2 = abs(num1 - num2) / num2 * 100
        if diff1 <= max_diff_percent and diff2 <= max_diff_percent:
            return True
        return False

class List:
    def find(item, alist: list):
        if not alist:
            return None
        for item in alist:
            if item == item:
                return item
        return None

    def find_next(item, alist: list, offset: int, circular=False):
        '''
            Find the item after 'item' from list 'alist'. The distance between the found item and 'item' is defined by number 'offset'
            If no item is found because 'offset' exceeds 'alist' range, return the last item (if circular=False) or the first item (if circular=True)
            If 'item' doesn't exist in 'alist', return None
        '''
        try:
            leng = len(alist)
            for i in range(leng):
                if item == alist[i]:
                    return alist[i + offset]
        except IndexError:
            if circular:
                return alist[0]
            else:
                return alist[-1]
        return None

    def remove_duplicate(alist: list):
        return list(dict.fromkeys(alist))

    def shrink(alist: list, length: int) -> list:
        ''' Shrink a list into a smaller list which has a "length".
            Redundant items at the beginning of the list will be removed.
            - Input: [89, 12, 43, 55, 77, 98]
            - Output: [55, 77, 98]
        '''
        if not alist:
            return []

        if not length:
            return alist

        length = len(alist)
        if length <= length:
            return alist

        for _ in range(0, length - length):
            alist.pop(0)    # Always remove the first item
        return alist

    def split(alist: list, length: int):
        ''' Split a list into multiple sub-lists according to a specified length.
           -  Input: length: 5, alist: [23, 45, 12, 8, 19, 5, 67, 87, 34, 21, 56, 76, 89, 12, 43, 55, 77, 98]
            - Output: [[23, 45, 12], [8, 19, 5], [67, 87, 34], [21, 56, 76], [89, 12, 43, 55, 77, 98]]

            - Input: length: 5, alist: [23, 45, 12, 8]
            - Output: [[23], [45], [12], [8], []]

            - Input: length: 5, alist: []
            - Output: [[], [], [], [], []]
        '''
        lists = []
        if not alist:
            for _ in range(length):
                lists.append([])
        elif length == 0:
            lists.append([])
        elif length == 1:
            lists.append(alist)
        else:
            count = len(alist) // length
            if count == 0:
                count = 1
            idx = 0
            step = 0
            while True:
                blist = alist[step : step+count]
                if len(lists) < length:
                    lists.append(blist)
                else:
                    lists[-1] += blist
                    break
                idx += 1
                step += count

        return lists

class Conversion:
    def dict_to_obj(dic: dict) -> object:
        ''' Work for both simple and nested dict '''
        class obj:
            def __init__(self, dic):
                self.__dict__.update(dic)
        return json.loads(json.dumps(dic, ensure_ascii=False), object_hook=obj)

    def object_to_dict(obj: object) -> dict:
        if isinstance(obj, dict):
            return {k: Conversion.object_to_dict(v) for k, v in obj.items()}
        elif hasattr(obj, "__dict__"):
            return {k: Conversion.object_to_dict(v) for k, v in obj.__dict__.items()}
        elif isinstance(obj, list):
            return [Conversion.object_to_dict(i) for i in obj]
        else:
            return obj

    def objects_to_dicts(obj: object) -> list:
        if isinstance(obj, dict):
            return {k: Conversion.object_to_dict(v) for k, v in obj.items()}
        elif hasattr(obj, "__dict__"):
            return {k: Conversion.object_to_dict(v) for k, v in obj.__dict__.items()}
        elif isinstance(obj, list):
            return [Conversion.object_to_dict(i) for i in obj]
        else:
            return obj

    def object_to_json(obj: object) -> str:
        ''' Work for both simple and nested object'''
        def serialize(val):
            if hasattr(val, '__dict__'):
                return val.__dict__
            return val

        json_str = None
        if obj:
            json_str = json.dumps(obj.__dict__, default=serialize, indent=4)
        return json_str

class Command:
    def parse(cmd: str) -> list:
        ''' Parse a command string into multiple parameters.
            Parameters are separated by one or more spaces.
            For items with space(s) between, but emplaced in a douple quote, treat them as on parameter.
            - Input: /track usdt "my channel"
            - Output: ['/track', 'usdt', 'my channel']
        '''
        params = []
        param = ''
        index = 0
        quote = False

        for c in cmd:
            if c == '"':
                if quote:
                    quote = False
                    if param: params.append(param)
                    param = ''
                else:
                    quote = True
                    if param: params.append(param)
                    param = ''
            elif c != ' ':
                param += c
            elif c == ' ':
                if quote:
                    param += c
                else:
                    if param: params.append(param)
                    param = ''
            if len(cmd) == index+1:
                if param: params.append(param)
            index += 1
        return params
