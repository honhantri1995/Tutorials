import os
import inspect
import logging

import utils

LOG_EXTENSION = 'log'
MAX_LOG_FILE_SIZE_IN_BYTE = 5 * 1000000     # 5 Mb

class Logger():
    __instance = None

    @staticmethod
    def get_instance(log_path='', lock=None):
        if not Logger.__instance:
            Logger(log_path, lock)
        return Logger.__instance

    def __init__(self, log_path, lock=None):
        ''' Virtually private constructor
        '''
        if Logger.__instance:
            raise Exception("Logger class is a singleton!")
        Logger.__instance = self

        # REMEMBER: Because of Singleton, 'log_path' and 'lock' only needed for the FIRST call of "Logger.get_instance()" in the whole process
        if not log_path:
            raise Exception("Logger class must have a log path!")
        self.file_path = log_path

        if not lock:
            raise Exception("Logger class must have a process lock!")
        self.lock = lock

        self.logging = None
        self.log_dirpath = utils.get_dir_path_from_file_path(self.file_path)
        self.log_extension = LOG_EXTENSION
        self.max_file_size_in_byte = MAX_LOG_FILE_SIZE_IN_BYTE

        self.__create_dir(self.log_dirpath)
        self.__configure_logger()

    def __configure_logger(self):
        self.logging = logging.getLogger()
        self.logging.setLevel(logging.INFO)         # Log level INFO or above will be outputted
        filehandler = logging.FileHandler(filename=self.file_path, mode='a', encoding='utf-8')
        formatter = logging.Formatter('[%(asctime)s.%(msecs)03d] [%(levelname)s] [%(process)d] [%(thread)d] %(message)s', datefmt='%Y-%m-%d %H:%M:%S')
        filehandler.setFormatter(formatter)
        self.logging.addHandler(filehandler)

    @staticmethod
    def __get_callstack(level: int):
        file_1 = line_1 = func_1 = ''

        # stack[1] gives previous function ('self.info' or 'self.error' in our case)
        # stack[2] gives before previous function
        # And so on ...

        try:
            stack = inspect.stack()
            if level == 0:
                file_1 = os.path.basename(stack[2][1])    # Only get file name from path
                line_1 = stack[2][2]
                func_1 = stack[2][3]
            elif level == 1:
                file_1 = os.path.basename(stack[3][1])    # Only get file name from path
                line_1 = stack[3][2]
                func_1 = stack[3][3]
            elif level == 2:
                file_1 = os.path.basename(stack[4][1])    # Only get file name from path
                line_1 = stack[4][2]
                func_1 = stack[4][3]

        except Exception:
            pass

        return file_1, line_1, func_1

    def __create_dir(self, path):
        if not os.path.isdir(path):     # If no dir is found, create it
            os.mkdir(path)

    def info(self, msg, callstack_level=0):
        ''' Print both console logs and file logs
        '''
        print(f'[INFO]\t\t{msg}')

        callstack = self.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        with self.lock:
            self.create_new_log_file_if_needed()
            self.logging.info(full_msg)

    def info2(self, msg, callstack_level=0):
        callstack = self.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        with self.lock:
            self.create_new_log_file_if_needed()
            self.logging.info(full_msg)

    def warning(self, msg, callstack_level=0):
        ''' Print both console logs and file logs
        '''
        print(f'[WARNING]\t{msg}')

        callstack = self.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        with self.lock:
            self.create_new_log_file_if_needed()
            self.logging.warning(full_msg)

    def error(self, msg, callstack_level=0):
        ''' Print both console logs and file logs
        '''
        print(f'[ERROR]\t\t{msg}')

        callstack = self.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        # callstack = self.__get_callstack(callstack_level) + self.__get_callstack(callstack_level + 1)
        # full_msg = "[{}:{} {}() <- {}:{} {}()] {}".format(*callstack, msg)

        with self.lock:
            self.create_new_log_file_if_needed()
            self.logging.error(full_msg)

    def critical(self, msg, callstack_level=0):
        ''' Print both console logs and file logs
        '''
        print(f'[CRITICAL]\t{msg}')

        callstack = self.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        with self.lock:
            self.create_new_log_file_if_needed()
            self.logging.critical(full_msg)

    def debug(self, msg, callstack_level=0):
        callstack = self.__get_callstack(callstack_level)
        full_msg = "[{}:{} {}()] {}".format(*callstack, msg)

        with self.lock:
            self.logging.debug(full_msg)

    def create_new_log_file_if_needed(self):
        try:
            if utils.get_file_size(self.file_path) >= self.max_file_size_in_byte:
                # Release handle of the current log file
                logging.shutdown()

                # Change name of current log file
                src = self.file_path
                dst = '{}_{}.{}'.format(utils.remove_extension_from_filepath(self.file_path),
                                        utils.get_current_time_s(format=utils.DATETIME_SECOND_NOSPACE_FORMAT),
                                        self.log_extension)
                os.rename(src, dst)

        except Exception as ex:
            # Note: Don't self.error() here because this will cause non-stop recursive
            print(f'Failed to create new log file. Exception: {ex}')
