DESCRIPTION = "I am the second recipe"
PR = "r1"

# Inherit "mybuild" class. So "myclass_do_build" becomes the default build task.
inherit mybuild

# A pure python function takes an argument and runs the python "dir" function on this argument and prints the result.
def pyfunc(o):
    print (dir(o))

# A bitbake python function is added and registered as a task that needs to be executed before the build function.
python do_mypatch () {
    bb.note ("Running mypatch")
    # Calls pyfunc and passes the global bitbake variable d.
    # Note: d (datastore) is defined by bitbake and is always available.
    pyfunc(d) 
}

# The "mypatch" function is registered as a task that needs to be executed before the "build" function.
addtask mypatch before do_build