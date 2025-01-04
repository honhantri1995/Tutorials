from multiprocessing import Lock

from logger import Logger

LOG_FILE_PATH = './log/program.log'
logger_lock = Lock()

logger = Logger.get_instance(log_path=LOG_FILE_PATH, lock=logger_lock)

def write_log():
    logger = Logger.get_instance()
    logger.debug('This is debug log')       # Note: This won't be printed due to "logging.setLevel(logging.INFO)"
    logger.info('This is info log')
    logger.info2('This is info2 log')
    logger.warning('This is warning log')
    logger.error('This is error log')
    logger.critical('This is critical log')

write_log()