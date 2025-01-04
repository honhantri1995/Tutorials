
from logger import Logger

Logger.configure('a/program.log')

def write_log():
    Logger.debug('This is debug log')       # Note: This won't be printed due to "logging.setLevel(logging.INFO)"
    Logger.info('This is info log')
    Logger.warn('This is warning log')
    Logger.error('This is error log')
    Logger.fatal('This is fatal log')

write_log()