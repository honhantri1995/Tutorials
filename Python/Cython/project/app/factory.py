import datetime
from app.some_package import SomeClass1
from app.other_classes import OtherClass1

def run():
    print('Running ...')
    some_class1 = SomeClass1()
    ts = datetime.datetime.now()
    loops = some_class1.process()
    print('Ready in: {} seconds, loops = {}'.\
        format((datetime.datetime.now() - ts).total_seconds(), loops))


    other_class1 = OtherClass1()
    ts = datetime.datetime.now()
    loops = other_class1.process()
    print('Ready in: {} seconds, loops = {}'.\
        format((datetime.datetime.now() - ts).total_seconds(), loops))