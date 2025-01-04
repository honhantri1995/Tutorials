from multiprocessing import Queue

class ProcessSharedData:
    class LogAndOther:
        log_queue = Queue()         # Other processes --> Log
