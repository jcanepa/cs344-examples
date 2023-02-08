class Foo:
    pass

def bar(o): # o = f
    o.baz = 12

f = Foo()
bar(f)
print(f.baz)