def join(a, b):
    def decide(i):
        return a if i == 0 else b
    return decide;

def first(fn):
    return fn(0);

def second(fn):
    return fn(1);

test_arr = join(1,2);
