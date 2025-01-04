
from multiprocessing import Process, Queue
import time

from logger import Logger
from log_driver import LogDriver
from process_shared_data import ProcessSharedData

def write_log():
    Logger.debug('This is debug log')       # Note: This won't be printed due to "logging.setLevel(logging.INFO)"
    Logger.info('This is info log')
    Logger.warn('This is warning log')
    Logger.error('This is error log')
    Logger.fatal('This is fatal log')

def log_process(log_queue: Queue, configure_logger):
    configure_logger('program.log')
    LogDriver.start_listener(log_queue)

def process1(log_queue: Queue, configure_logger):
    configure_logger(log_queue)
    write_log()
    time.sleep(5)

def process2(log_queue: Queue, configure_logger):
    configure_logger(log_queue)
    write_log()
    time.sleep(5)

def main():
    processes = []
    processes.append(Process(target=log_process,
                             name='LogP',
                             args=(ProcessSharedData.LogAndOther.log_queue,
                                   LogDriver.configure_logger_for_listener, )))
    processes.append(Process(target=process1,
                             name='Process-1',
                             args=(ProcessSharedData.LogAndOther.log_queue,
                                   LogDriver.configure_logger_for_worker, )))
    processes.append(Process(target=process2,
                             name='Process-2',
                             args=(ProcessSharedData.LogAndOther.log_queue,
                                   LogDriver.configure_logger_for_worker, )))
    for p in processes: p.start()
    for p in processes: p.join()

if __name__ == "__main__":
    main()
