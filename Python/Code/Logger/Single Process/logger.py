import os
import inspect
import logging
import logging.handlers

MAX_FILE_SIZE = 10000000     # 10Mb
MAX_FILE_NUM = 10

class Logger():
    ''' Write logs to text file.
        Also, print some logs to console.
    '''
    @staticmethod
    def configure(filepath: str):
        # If dir or file have not existed, create it
        dirpath = os.path.dirname(os.path.abspath(filepath))
        if not os.path.isdir(dirpath):
            os.mkdir(dirpath)
        if not os.path.isfile(filepath):
            open(filepath, 'w', encoding='utf-8').close()

        logger = logging.getLogger()
        logger.setLevel(logging.INFO)         # Log level INFO or above will be outputted
        filehandler = logging.handlers.RotatingFileHandler(filepath, maxBytes=MAX_FILE_SIZE, backupCount=MAX_FILE_NUM, mode='a', encoding='utf-8')
        formatter = logging.Formatter('[%(asctime)s.%(msecs)03d] [%(levelname)s] [%(process)d:%(processName)s] [%(thread)d] %(message)s', datefmt='%Y-%m-%d %H:%M:%S')
        filehandler.setFormatter(formatter)
        logger.addHandler(filehandler)

    @staticmethod
    def __get_callstack(level: int):
        file_1 = line_1 = func_1 = ''

        # stack[1] gives previous function ('Logger.info' or 'Logger.error' in our case)
        # stack[2] gives before previous function
        # And so on ...
        try:
            stack = inspect.stack()
            if level == 0:
                file_1 = Logger.__get_filename_followed_by_parent_dir(stack[2][1])
                line_1 = stack[2][2]
                func_1 = stack[2][3]
            elif level == 1:
                file_1 = Logger.__get_filename_followed_by_parent_dir(stack[3][1])
                line_1 = stack[3][2]
                func_1 = stack[3][3]
            elif level == 2:
                file_1 = Logger.__get_filename_followed_by_parent_dir(stack[4][1])
                line_1 = stack[4][2]
                func_1 = stack[4][3]
        except Exception:
            pass
        return file_1, line_1, func_1

    @staticmethod
    def __get_filename_followed_by_parent_dir(path: str):
        parts = os.path.split(path)
        filepath = parts[-1]
        dirpath = os.path.split(parts[-2])[-1]
        return f'{dirpath}\{filepath}'

    @staticmethod
    def debug(msg: str, callstack_level=0):
        callstack = Logger.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        logger = logging.getLogger()
        logger.log(logging.DEBUG, full_msg)

    @staticmethod
    def info(msg: str, callstack_level=0):
        ''' Print both console logs and file logs
        '''
        print(f'[INFO]\t{msg}')

        callstack = Logger.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        logger = logging.getLogger()
        logger.log(logging.INFO, full_msg)

    @staticmethod
    def warn(msg: str, callstack_level=0):
        ''' Print both console logs and file logs
        '''
        print(f'[WARN]\t{msg}')

        callstack = Logger.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        logger = logging.getLogger()
        logger.log(logging.WARNING, full_msg)

    @staticmethod
    def error(msg: str, callstack_level=0, traceback=False):
        ''' Print both console logs and file logs
        '''
        # Print traceback prettily
        # if traceback:
        #     import better_exchook
        #     better_exchook.install()  # will just do: sys.excepthook = better_exchook
        #     better_exchook.better_exchook(*sys.exc_info())

        print(f'[ERROR]\t{msg}')

        callstack = Logger.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        logger = logging.getLogger()
        logger.log(logging.ERROR, full_msg)

    @staticmethod
    def fatal(msg: str, callstack_level=0, traceback=False):
        ''' Print both console logs and file logs
        '''
        # Print traceback prettily
        # if traceback:
        #     import better_exchook
        #     better_exchook.install()  # will just do: sys.excepthook = better_exchook
        #     better_exchook.better_exchook(*sys.exc_info())

        print(f'[FATAL]\t{msg}')

        callstack = Logger.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        logger = logging.getLogger()
        logger.log(logging.FATAL, full_msg)
