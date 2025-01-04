import cython

class SomeClass1:
    def process(self):

        # i: cython.int # here
        # loops: cython.int # and here

        print('Processing SomeClass1 ...')
        a = 'a string'
        loops = 0
        for i in range(10000000):
            b = a
            loops += 1
        return loops