import os
import logging
import logging.handlers
from multiprocessing import Queue

class LogDriver():
    ''' Use this class in a new process.
        This process will receive log messages from other processes via a common multiprocess queue.
        Then write log to a single text file. 
    '''
    @staticmethod
    def configure_logger_for_listener(logpath):
        try:
            with open(logpath, "a", encoding="utf-8") as file:
                file.write('\n\n========================== PROGRAM START ===========================\n')
        except Exception:
            pass

        MAX_FILE_SIZE = 10000000     # 10Mb
        MAX_FILE_NUM = 10

        # If dir have not existed, create it
        dirpath = os.path.dirname(os.path.abspath(logpath))
        if not os.path.isdir(dirpath):
            os.mkdir(dirpath)

        filehandler = logging.handlers.RotatingFileHandler(logpath, maxBytes=MAX_FILE_SIZE, backupCount=MAX_FILE_NUM, mode='a', encoding='utf-8')
        formatter = logging.Formatter('[%(asctime)s.%(msecs)03d] [%(levelname)s] [%(process)d:%(processName)s] [%(thread)d] %(message)s', datefmt='%Y-%m-%d %H:%M:%S')
        filehandler.setFormatter(formatter)

        logger = logging.getLogger()
        logger.addHandler(filehandler)

    @staticmethod
    def configure_logger_for_worker(queue: Queue):
        queuehandler = logging.handlers.QueueHandler(queue)

        logger = logging.getLogger()
        logger.addHandler(queuehandler)
        logger.setLevel(logging.INFO)         # Log level INFO or above will be outputted

    @staticmethod
    def start_listener(queue):
        while True:
            record = queue.get()
            logger = logging.getLogger(record.name)
            logger.handle(record)